#ifndef PROTOCOLE_H
#define PROTOCOLE_H

#include <QWidget>
#include <QRegExp>
#include <QString>

#include <QSerialPort>


// 1 :  Variable Length, can cause random crashes but can be used with
//      frames of unknown/variables lengths
// 0 :  Fixed Length (recommended), more robust and quicker, must set the
//      BufferedValue to the exact length of the frame to detect
#define VARIABLE_LENGTH 0

class Protocole : public QWidget
{
    Q_OBJECT

    public:
        Protocole();
        ~Protocole();

        void send_str(const char * str);
        void send_char(char str);

        QSerialPort *port;

        double lastValue[16];
        QString lastString;
        unsigned short lastStatus;
    private:
        QRegExp *rx;
        int bufferedValue;


        enum {
            init,
            sepOrLSB,
            LSB,
            syncing,
            synced
        } state;
        int frameLength;
        int nbValue;

        QString pattern;

    private slots:
        void fetch();

    signals:
        void updateData();
};

#endif // PROTOCOLE_H
