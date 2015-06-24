#ifndef PROTOCOLE_H
#define PROTOCOLE_H

#include <QThread>
#include <QTimer>
#include <QVector>
#include <QRegExp>
#include <QString>

#include <QSerialPort>


// 1 :  Variable Length, can cause random crashes but can be used with
//      frames of unknown/variables lengths
// 0 :  Fixed Length (recommended), more robust and quicker, must set the
//      BufferedValue to the exact length of the frame to detect
#define VARIABLE_LENGTH 0

class Protocole : public QThread
{
    Q_OBJECT

    public:
        Protocole();
        ~Protocole();

        void send_str(const char * str);
        void send_char(char str);

        void addValue();
        void addValues(int n);

        void setRegEx();

        void setBufferedValue(int buff);

        QSerialPort *port;

        int nbValues;

        QVector<double> values[16];
        QVector<QString> strings;

        double lastValue[16];
        QString lastString;

    private:
        QRegExp *rx;
        QString oldPattern;
        int bufferedValue;


    protected:
        void run();

    signals:
        void dataRec(QString buff);
        void sensorChanged(int n, int value);
        void posChanged(qreal x, qreal y, qreal t);
        void dataSin(double d, double t);
        void dataCos(double d);
        void updateData();
};

#endif // PROTOCOLE_H
