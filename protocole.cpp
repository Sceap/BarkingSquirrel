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
    setRegEx("");
    setBufferedValue(9999999);
}

Protocole::~Protocole()
{
    port->close();
    //this->terminate();
    delete port;
}

// Sets (and resets) the port name
void Protocole::setPort(const QString pName) {
    port->setPortName(pName);
    port->close();
    port->open(QIODevice::ReadWrite);
}


// Sets the regEx of the received string
void Protocole::setRegEx(QString pattern) {
    oldPattern = pattern;
    for(int i=0;i<sensors.size();i++) {
        pattern += ".*s";
        pattern += (i+'0');
        pattern += ":([0-9]*)";
    }
    this->rx->setPattern(pattern);
}


// Adds a sensor to the RegEx
void Protocole::addSensor() {
    sensors.append(sensors.size());
    setRegEx(oldPattern);
}

// Adds n sensors to the RegEx
void Protocole::addSensors(int n) {
    for(int i=0;i<n;i++) {
        addSensor();
    }
}

void Protocole::setBufferedValue(int buff) {
    bufferedValue = buff;
}


void Protocole::initValue(int id, int nb_values) {
    //values[id] = new QVector<double>();
}

// Reads the current received buffer, and
// empty it every time it reaches the read buffer
// value
// Emits signals, the first one with the first
// three values (x, y and angle), then as musch
// signals as there are sensors in the RegEx

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
            decal += port->readLine(buff+decal,port->bytesAvailable()+1);
            pos = 0;
        }

        for(int i=0;i<10&&((pos = rx->indexIn(buff, pos)) > -1);i++) {
            strings.append(QString(rx->cap(0)));

            values[0].append(rx->cap(1).toInt());
            values[1].append(rx->cap(5).toInt());
            values[2].append(rx->cap(6).toInt());
            values[3].append(rx->cap(4).toInt());
            values[4].append(rx->cap(5).toInt());
            values[5].append(rx->cap(6).toInt());


            buffer = QString::fromLocal8Bit(buff);
            buffer.remove(pos,rx->matchedLength());

            pos = 0;

            ba = buffer.toLocal8Bit();
            strcpy(buff,ba.data());

            decal -= rx->matchedLength();
        }
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
