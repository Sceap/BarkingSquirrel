#ifndef QZOOMPLOT_H
#define QZOOMPLOT_H

#include "qcustomplot.h"


class QZoomPlot : public QCustomPlot
{
public:
    QZoomPlot( QWidget * parent) : QCustomPlot( parent ) {}
    ~QZoomPlot();
    void keyPressEvent ( QKeyEvent * event );
};

#endif // QZOOMPLOT_H
