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
#include <QDateTime>

// Creates and configure the serial port.
Protocole::Protocole()
{
    port = new QSerialPort();

    state = init;
    frameLength = 0;
    nbValue = 0;

    rx = new QRegExp();
}

Protocole::~Protocole()
{
    port->close();
    delete port;
}

// The fetch slot is called as fast as possible in order
// to fetch data from the Serial port buffer.
// It also handles the detection of frame length and the
// number of comma separated values contained in each frame.
// In order for the sync process - and therefore the whole function -
// to work properly, each frame must be separated by an ASCII \n (0x0D)
// character
/*
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

    /
    nbValues = 8;
    setRegEx();

    if((rx->indexIn(dummy[j], 0)) > -1) {
        lastString = QString(rx->cap(0));

        for(int j=0;j<nbValues;j++)
            lastValue[j] = (rx->cap(j+1).toDouble());

        emit updateData();
    }
    /

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
}*/


short extractValue(char * val) {
    return (
                (((((unsigned short) val[1])<<8)&0xFF00)        // Take the LSB, and shift it to MSB position
                |
                (~val[0])&0x00FF)                               // Take the MSB, invert the bits and put it in LSB position
            );
}

void Protocole::fetch(void) {
    char tmp, tmpMSB, tmpLSB;

    static int i,j = 0;
    static int ms = GetTickCount();


    i = (i+1)%500;

    // Every thread-second, print the real-second
    if(!i) {
        qDebug() << "One sec : " << (GetTickCount() - ms);
        ms = GetTickCount();
    }

    switch(state) {
        case init:
        if(port->bytesAvailable()) {
            frameLength = 0;
            nbValue = 0;
            tmp = port->read(1).at(0);
            if(tmp==0x7F)
                state = sepOrLSB;
        }
            break;
        case sepOrLSB:
        if(port->bytesAvailable()) {
            tmp = port->read(1).at(0);
            if(tmp==0x7F) {
                state = syncing;
            } else {
                port->read(1);
                state = LSB;
            }
        }
            break;
        case LSB:
        if(port->bytesAvailable()>2) {
            tmpMSB = port->read(1).at(0);
            tmpLSB = port->read(1).at(0);

            if(tmpMSB==0x7F && tmpLSB==0x7F) {
                state = syncing;
            }
        }
            break;
        case syncing:
        if(port->bytesAvailable()>2) {
            tmpMSB = port->read(1).at(0);
            tmpLSB = port->read(1).at(0);

            if(tmpMSB==0x7F && tmpLSB==0x7F) {
                state = synced;
                pattern = "";
                for(int i=0;i<nbValue;i++) {
                    pattern += "(..)";
                }
                pattern+="\x7F\x7F";

                rx = new QRegExp(pattern);
            } else {
                frameLength+=2;
                nbValue+=1;
            }
        }
            break;
        case synced:
        if(port->bytesAvailable()>frameLength+2) {

            QString buffer = "";
            for(int i=0;i<nbValue;i++) {
                buffer+= port->read(1).at(0);
                buffer+= port->read(1).at(0);
            }
            buffer+=port->read(1).at(0);
            buffer+=port->read(1).at(0);


            if(rx->indexIn((buffer),0)>-1) {

                int hour = ((unsigned char)rx->cap(2).toLatin1().data()[1]) >> 2;
                int min = ((unsigned char)rx->cap(2).toLatin1().data()[0]);


                int sec = ((unsigned char)rx->cap(3).toLatin1().data()[1]) >> 2;
                int csec = ((unsigned char)rx->cap(3).toLatin1().data()[0]);

                QDateTime d = QDateTime::currentDateTime();


                lastString = "|";
                lastString+=d.toString("yyyyMMdd");



                lastString+=QString("%1").arg(abs(hour)%24, 2, 10, QChar('0'));
                lastString+=QString("%1").arg(abs(min)%60, 2, 10, QChar('0'));
                lastString+=QString("%1").arg(abs(sec)%60, 2, 10, QChar('0'));
                lastString+=QString("%1").arg(abs(csec)%100, 2, 10, QChar('0'));


                lastString+=',';

                for(int i=3;i<nbValue-1;i++) {
                    lastValue[i-2] = extractValue(rx->cap(i+1).toLatin1().data());
                    if(lastValue[i-2]>0) {
                       lastString+="+";
                       lastString+=QString("%1").arg(((int)lastValue[i-2]), 5, 10, QChar('0'));
                    }
                    else {
                        lastString+="-";
                        lastString+=QString("%1").arg((-(int)lastValue[i-2]), 5, 10, QChar('0'));
                    }
                    if(i<nbValue)
                        lastString+=",";
                }
                lastStatus = extractValue(rx->cap(nbValue).toLatin1().data());
                lastString+=QString("%1").arg(((int)lastStatus), 5, 10, QChar('0'));

                lastString += "|";


                emit updateData();
            } else {
                state = init;
            }
        }
            break;
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
