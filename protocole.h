#ifndef PROTOCOLE_H
#define PROTOCOLE_H

#include <QThread>
#include <QTimer>
#include <QVector>
#include <QRegExp>
#include <QString>

#include <QSerialPort>

class Protocole : public QThread
{
    Q_OBJECT

public:
    Protocole();
    ~Protocole();

    void send_str(const char * str);
    void send_char(char str);

    void setPort(const QString pName);
    void setRegEx(QString pattern);

    void addSensor();
    void addSensors(int n);

    void setBufferedValue(int buff);

    void initValue(int id, int nb_values);

    QSerialPort *port;

    QVector<double> values[16];
    QVector<QString> strings;
private:
    QRegExp *rx;
    QString oldPattern;
    int bufferedValue;
    QVector<int> sensors;


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
