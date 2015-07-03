#include "qzoomplot.h"



QZoomPlot::~QZoomPlot()
{

}


void QZoomPlot::keyPressEvent ( QKeyEvent * event ) {
    qDebug() << event->key();
    if(event->key()==Qt::Key_Plus || event->key()==Qt::Key_Minus) {
        QCPRange oldRange = this->yAxis->range();

        if(event->key()==Qt::Key_Plus) {
            oldRange.lower+=500;
            oldRange.upper-=500;
        } else {
            oldRange.lower-=500;
            oldRange.upper+=500;
        }

        this->yAxis->setRange(oldRange);
        this->replot();
    }
}
