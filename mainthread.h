#ifndef MAINTHREAD_H
#define MAINTHREAD_H

#include <QThread>

class mainThread : public QThread
{
    Q_OBJECT

protected:
    void run();

signals:
    void updateData();
};
#endif // MAINTHREAD_H
