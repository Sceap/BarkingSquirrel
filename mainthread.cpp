#include "mainthread.h"


void mainThread::run()
{
    while(1) {
        emit updateData();
        msleep(10);
    }
}
