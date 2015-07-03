/********************************************************************************************************************************
*     _____       _  _____      ____          _                       _____                      _    _____                     *
*    |  __ \     ( )/ ____|    / __ \        | |                     / ____|                    | |  / ____|                    *
*    | |  | |_ __|/| (___     | |  | |_ __ __| | ___ _ __ ___       | (___  _ __ ___   __ _ _ __| |_| |     __ _ _ __   ___     *
*    | |  | | '__|  \___ \    | |  | | '__/ _` |/ _ \ '__/ __|       \___ \| '_ ` _ \ / _` | '__| __| |    / _` | '_ \ / _ \    *
*    | |__| | |     ____) |   | |__| | | | (_| |  __/ |  \__ \       ____) | | | | | | (_| | |  | |_| |___| (_| | | | |  __/    *
*    |_____/|_|    |_____/     \____/|_|  \__,_|\___|_|  |___/      |_____/|_| |_| |_|\__,_|_|   \__|\_____\__,_|_| |_|\___|    *
*                                                                                                                               *
*   2015                                                                                                                        *
*                                                                                                                               *
*   Project updated by Jeremie VAN DER SANDE (jeremie.vandersande@gmail.com) (remplace if needed)                               *
*   Internship (June..August) at UNB, Fredericton                                                                               *
*                                                                                                                               *
*********************************************************************************************************************************
*                                                                                                                               *
*   This file is used to define the UART communication protocole. It uses Regular Expressions for pattern recognition and easy  *
*   extraction of data                                                                                                          *
*                                                                                                                               *
*   The protocole can work in two main modes: Variable Length and Fixed Length. Fixed Length is the recommended one for the best*
*   experience. See "protocole.h" for the mode toggle                                                                           *
*                                                                                                                               *
********************************************************************************************************************************/


#include "protocole.h"
#include <QDebug>
#include <Windows.h>


// Creates and configure the serial port.
Protocole::Protocole()
{
    port = new QSerialPort();

    rx = new QRegExp();
    setBufferedValue(9999999);

    nbValues = 0;

    synced = false;
}

Protocole::~Protocole()
{
    port->close();
    delete port;
}


// Sets the regEx of the received string
// The regEx is set to detect a certain type
// of frame: |val0,val1,...,valn|
// Each frame is enclosed in '|' character
// The values are comma-separated, and each
// value can be positive (with or without a trailing '+')
// or negative (with a trailing '-')
// Values must be decimal, otherwise the
// frame will not be detected
//
// This function generates this type of RegEx
// based on the nbValues parameter. In order to
// add a value, use either addValue() (one value)
// or addValues(n) (n values)
//
// setRegEx() is automatically called when
// calling addValue(). It should not have to be
// called manually
void Protocole::setRegEx() {
    QString regex = "\\|";

    for(int i=0;i<nbValues;i++) {
        regex += "([-\\+]*[0-9]+)";
        if(i<nbValues-1)
            regex+=",";
    }

    regex+="\\|";

    this->rx->setPattern(regex);
}


// Adds a value to the RegEx
void Protocole::addValue() {
    nbValues++;
    setRegEx();
}

// Adds n values to the RegEx
void Protocole::addValues(int n) {
    for(int i=0;i<n;i++) {
        addValue();
    }
}

// Sets the bufferedValue, needed for the
// acknowledge of a frame in the read buffer.
// In Variable Length mode, bufferedValue can
// help reducing the overflow of data
// In Fixed Length mode, bufferedValue should
// be set to the exact length of a frame
void Protocole::setBufferedValue(int buff) {
    bufferedValue = buff;
}


// Dummy frames used in order to debug
// the GUI update and threading system
char dummy[61][68] = {
    "|0015061817280004,-00131,+00076,+00051,+00296,+00016,+17020,-03936|",
    "|0015061817280005,-00126,+00083,+00052,+00220,-00068,+17024,-03936|",
    "|0015061817280006,-00137,+00072,+00043,+00216,-00008,+17232,-03936|",
    "|0015061817280007,-00128,+00077,+00047,+00332,-00092,+16992,-03904|",
    "|0015061817280008,-00136,+00086,+00040,+00280,+00012,+17068,-03936|",
    "|0015061817280009,-00140,+00076,+00046,+00312,-00064,+17088,-03904|",
    "|0015061817280010,-00133,+00082,+00044,+00280,+00032,+17088,-03936|",
    "|0015061817280011,-00127,+00067,+00050,+00304,+00028,+17112,-03936|",
    "|0015061817280012,-00132,+00081,+00049,+00232,-00036,+17144,-03936|",
    "|0015061817280013,-00115,+00087,+00047,+00260,-00104,+16880,-03936|",
    "|0015061817280014,-00138,+00079,+00050,+00284,-00088,+17184,-03904|",
    "|0015061817280015,-00126,+00090,+00054,+00416,-00040,+16840,-03936|",
    "|0015061817280016,-00149,+00076,+00045,+00264,-00032,+17296,-03904|",
    "|0015061817280017,-00137,+00072,+00044,+00272,-00024,+17040,-03904|",
    "|0015061817280018,-00133,+00077,+00049,+00316,-00116,+17164,-03936|",
    "|0015061817280019,-00135,+00076,+00039,+00312,-00032,+17088,-03968|",
    "|0015061817280020,-00122,+00074,+00050,+00440,-00084,+17200,-03936|",
    "|0015061817280021,-00135,+00082,+00050,+00176,+00028,+17068,-03936|",
    "|0015061817280022,-00142,+00082,+00053,+00208,-00068,+17124,-03936|",
    "|0015061817280023,-00142,+00084,+00049,+00408,-00020,+17064,-03936|",
    "|0015061817280024,-00139,+00075,+00041,+00360,-00108,+17060,-03904|",
    "|0015061817280025,-00129,+00081,+00049,+00296,+00004,+17168,-03904|",
    "|0015061817280026,-00121,+00078,+00044,+00340,-00076,+17092,-03904|",
    "|0015061817280027,-00128,+00079,+00053,+00372,-00044,+16924,-03936|",
    "|0015061817280028,-00123,+00076,+00047,+00364,-00032,+17204,-03936|",
    "|0015061817280029,-00125,+00073,+00055,+00356,+00016,+17112,-03936|",
    "|0015061817280030,-00128,+00075,+00047,+00504,-00024,+17140,-03904|",
    "|0015061817280031,-00134,+00074,+00047,+00364,-00024,+17172,-03936|",
    "|0015061817280032,-00141,+00075,+00046,+00276,-00036,+17140,-03904|",
    "|0015061817280033,-00141,+00075,+00046,+00276,-00036,+17140,-03904|",
    "|0015061817280034,-00129,+00075,+00046,+00196,+00016,+17112,-03936|",
    "|0015061817280035,-00120,+00074,+00047,+00328,+00016,+16968,-03936|",
    "|0015061817280036,-00140,+00070,+00048,+00264,+00036,+17208,-03936|",
    "|0015061817280037,-00115,+00074,+00047,+00284,-00048,+17172,-03936|",
    "|0015061817280038,-00131,+00072,+00045,+00256,-00028,+17116,-03936|",
    "|0015061817280039,-00136,+00080,+00050,+00280,-00088,+17020,-03904|",
    "|0015061817280040,-00125,+00079,+00055,+00228,+00124,+17028,-03936|",
    "|0015061817280041,-00138,+00075,+00050,+00380,-00040,+17164,-03936|",
    "|0015061817280042,-00139,+00072,+00044,+00332,-00036,+17052,-03904|",
    "|0015061817280043,-00121,+00073,+00053,+00228,-00164,+17164,-03936|",
    "|0015061817280044,-00135,+00084,+00053,+00264,+00036,+17080,-03936|",
    "|0015061817280045,-00134,+00078,+00046,+00268,-00100,+17096,-03936|",
    "|0015061817280046,-00144,+00083,+00045,+00300,-00060,+16968,-03936|",
    "|0015061817280047,-00141,+00071,+00052,+00256,+00004,+17132,-03904|",
    "|0015061817280048,-00136,+00066,+00055,+00268,-00068,+17240,-03936|",
    "|0015061817280049,-00132,+00073,+00039,+00284,+00008,+17116,-03936|",
    "|0015061817280050,-00137,+00069,+00058,+00212,-00088,+17004,-03904|",
    "|0015061817280051,-00131,+00083,+00058,+00356,-00020,+17000,-03936|",
    "|0015061817280052,-00147,+00073,+00049,+00244,-00088,+17176,-03936|",
    "|0015061817280053,-00130,+00074,+00053,+00332,-00080,+17100,-03936|",
    "|0015061817280054,-00127,+00070,+00049,+00312,-00032,+17172,-03936|",
    "|0015061817280055,-00118,+00075,+00051,+00328,+00044,+16864,-03936|",
    "|0015061817280056,-00130,+00065,+00050,+00240,+00064,+17112,-03936|",
    "|0015061817280057,-00127,+00073,+00057,+00372,-00044,+17072,-03936|",
    "|0015061817280059,-00120,+00078,+00047,+00304,+00004,+17160,-03936|",
    "|0015061817280060,-00118,+00073,+00049,+00252,-00064,+16976,-03936|",
    "|0015061817280061,-00139,+00077,+00050,+00360,+00020,+17060,-03936|",
    "|0015061817280062,-00122,+00081,+00047,+00340,-00044,+16972,-03936|",
    "|0015061817280063,-00127,+00069,+00042,+00352,+00024,+17032,-03936|",
    "|0015061817280064,-00129,+00079,+00044,+00240,+00004,+16944,-03904|"
};

// The fetch slot is called as fast as possible in order
// to fetch data from the Serial port buffer.
// It also handles the detection of frame length and the
// number of comma separated values contained in each frame.
// In order for the sync process - and therefore the whole function -
// to work properly, each frame must be separated by an ASCII \n (0x0D)
// character
void Protocole::fetch() {
    // i is used to compute the time spent
    // between what the thread thinks is one
    // second, and the actual second
    //
    // If 1 thread-second is more than 1.5 real-second,
    // frames will be missed
    //
    // j is used to cycle through the dummy table
    // in debug mode
    static int i,j = 0;
    static int ms = GetTickCount();

    // buff stores the new frame to be treated
    static char buff[2048];

    // tmp is the character used for the syncing process
    char tmp;

    // The syncInProgress flag is set once a separator (0x0D)
    // is detected. It starts looking for the number of field (nbField)
    // and the length of a frame (frameLength)
    static bool syncInProgress = false;
    static short frameLength = 0;
    static short nbField = 0;

    i = (i+1)%200;
    j = (j+1)%61;

    /*
    nbValues = 8;
    setRegEx();

    if((rx->indexIn(dummy[j], 0)) > -1) {
        lastString = QString(rx->cap(0));

        for(int j=0;j<nbValues;j++)
            lastValue[j] = (rx->cap(j+1).toDouble());

        emit updateData();
    }
    */

    // Every thread-second, print the real-second
    if(!i) {
        qDebug() << "One sec : " << (GetTickCount() - ms);
        ms = GetTickCount();
    }

    // Below is the syncing FSM. If the thread is neither
    // syncing or synced, it has been unsynced or hasn't
    // been synced yet: start looking for the separator
    if(!syncInProgress&&!synced) {
        if(port->bytesAvailable()) {
            tmp = port->read(1).at(0);

            // The separator character starts the syncing process
            if(tmp==0x0D)
                syncInProgress = true;
        }
    // Once the separator is found, we can start counting
    // for characters in a frame, until the next separator
    // We also detect the number of fields in a frame
    } else if(!synced) {
        if(port->bytesAvailable()) {
            tmp = port->read(1).at(0);

            // each comma induce a new field
            if(tmp==',') {
                nbField++;
            }
            // a new separator value means that
            // the syncing is complete
            if(tmp==0x0D) {
                syncInProgress = false;
                synced = true;

                // Creating the right regEx...
                nbValues = nbField+1;
                setRegEx();
            }
            frameLength++;
        }
    // One the second separator has been found, we can start
    // reading frames out of the buffer
    } else if(synced) {
        if(port->bytesAvailable()>frameLength) {
            port->readLine(buff,frameLength+1);


            // First of all we check if the frame matches the regEx
            // If it does, we update the different values with the one
            // from the frame
            if((rx->indexIn(buff, 0)) > -1) {
                lastString = QString(rx->cap(0));

                for(int j=0;j<nbValues;j++)
                    lastValue[j] = (rx->cap(j+1).toDouble());

                emit updateData();

            // If the frame doesn't match the regEx, either that one
            // frame was false and the rest of the buffer is corrupted,
            // or the sync process didn't match the actual frame set up
            // Either way, time to resync the system.
            } else {
                synced = false;
                syncInProgress = false;
                frameLength = 0;
                nbField = 0;
                // The buffer is emptied before syncing again
                port->readAll();
            }
        }
    }
}


// Sends a string through the serial port
void Protocole::send_str(const char  *str) {
    char buff;
    while((buff=*(str++)))
        port->putChar(buff);
}

// Sends a char through the serial port
void Protocole::send_char(char str) {
    port->putChar(str);
}
