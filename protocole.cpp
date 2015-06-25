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


// Creates and configure the serial port.
Protocole::Protocole()
{
    port = new QSerialPort();

    rx = new QRegExp();
    setBufferedValue(9999999);

    nbValues = 0;
}

Protocole::~Protocole()
{
    port->close();
    this->terminate();
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

// Reads the current received buffer, and
// empties it every time it reaches the read buffer
// value
// In Variable Length mode, updates when possible
// the values vector buffers and the strings vector buffer
// A Timer must be used in MainWindow in order to periodically
// use and clear those vectors
// In Fixed Length mode, updates every time the values variables
// and the string variable, then emit an updateData signal catchable
// by the MainWindow class
void Protocole::run()
{
    static char buff[1048576];
    static long long pos = 0;
    static long long decal = 0;
    static QString buffer("");
    static QByteArray ba;
    while(1)
    {
        if(port->bytesAvailable()>=bufferedValue+10)
        {
#if VARIABLE_LENGTH == 1
            decal += port->readLine(buff+decal,port->bytesAvailable()+1);
            pos = 0;
        }
#else
        port->readLine(buff,port->bytesAvailable()+1);
#endif

#if VARIABLE_LENGTH == 1
        for(int i=0;i<10&&((pos = rx->indexIn(buff, pos)) > -1);i++) {

            strings.append(QString(rx->cap(0)));


            for(int j=0;j<nbValues;j++)
                values[j].append(rx->cap(j+1).toDouble());

#else
        if((rx->indexIn(buff, 0)) > -1) {
            lastString = QString(rx->cap(0));
            for(int j=0;j<nbValues;j++)
                lastValue[j] = (rx->cap(j+1).toDouble());

            emit(updateData());
#endif


#if VARIABLE_LENGTH == 1
            buffer = QString::fromLocal8Bit(buff);
            buffer.remove(pos,rx->matchedLength());

            pos = 0;

            ba = buffer.toLocal8Bit();
            strcpy(buff,ba.data());

            decal -= rx->matchedLength();
#endif
        } else {
           port->readAll();
        }
        }
    }
}


// Sends a string through the serial port
void Protocole::send_str(const char  *str) {
    char buff;
    while(buff=*(str++))
        port->putChar(buff);
}

// Sends a char through the serial port
void Protocole::send_char(char str) {
    port->putChar(str);
}
