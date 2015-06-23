#include "protocole.h"
#include <QDebug>
#include <QRegExp>


// Creates and configure the serial port.
Protocole::Protocole()
{
    port = new QSerialPort();
 //   values = new QVector< QVector<int> >();

    port->setPortName("COM3");
    port->setBaudRate(QSerialPort::Baud115200);
    port->setFlowControl(QSerialPort::NoFlowControl);
    port->setParity(QSerialPort::NoParity);
    port->setDataBits(QSerialPort::Data8);
    port->setStopBits(QSerialPort::OneStop);

    rx = new QRegExp();
    setBufferedValue(9999999);

    nbValues = 0;
}

Protocole::~Protocole()
{
    port->close();
    //this->terminate();
    delete port;
}


// Sets the regEx of the received string
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


// Adds a sensor to the RegEx
void Protocole::addValue() {
    nbValues++;
    setRegEx();
}

// Adds n sensors to the RegEx
void Protocole::addValues(int n) {
    for(int i=0;i<n;i++) {
        addValue();
    }
}

void Protocole::setBufferedValue(int buff) {
    bufferedValue = buff;
}

// Reads the current received buffer, and
// empty it every time it reaches the read buffer
// value
// Emits signals, the first one with the first
// three values (x, y and angle), then as musch
// signals as there are sensors in the RegEx
#define VARIABLE_LENGTH 0


#define SINUS 2
#define COSINUS 3
void Protocole::run()
{
    static char buff[1048576];
    static long long pos = 0;
    static long long decal = 0;
    static QString buffer("");
    static QByteArray ba;
    while(1)
    {
        if(port->bytesAvailable()>=bufferedValue)
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


            values[0].append(rx->cap(1).toInt());
            values[1].append(rx->cap(5).toInt());
            values[2].append(rx->cap(6).toInt());
            values[3].append(rx->cap(4).toInt());
            values[4].append(rx->cap(5).toInt());
            values[5].append(rx->cap(6).toInt());

#else
        if((rx->indexIn(buff, 0)) > -1) {
            lastString = QString(rx->cap(0));
            lastValue[0] = rx->cap(1).toDouble();
            lastValue[1] = rx->cap(5).toDouble();
            lastValue[2] = rx->cap(6).toDouble();
            lastValue[3] = rx->cap(4).toDouble();
            lastValue[4] = rx->cap(5).toDouble();
            lastValue[5] = rx->cap(6).toDouble();

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
#ifndef VARIABLE_LENGHT
        }
#endif
    }
}


// Sends a string through the serial port
void Protocole::send_str(const char  *str) {
    char buff;
    while(buff=*(str++))
        port->putChar(buff);
}

// Sends a char throught the serial port
void Protocole::send_char(char str) {
    port->putChar(str);
}
