#include "fileviewer.h"
#include "ui_fileviewer.h"
#include <Windows.h>

#include <iostream>
#include <fstream>
using namespace std;

FileViewer::FileViewer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FileViewer)
{
    ui->setupUi(this);

    graph[0] = ui->Accel_XY;
    graph[1] = ui->Accel_X_Y;
    graph[2] = ui->Accel_Z;
    graph[3] = ui->Gyro_X;
    graph[4] = ui->Gyro_Y;
    graph[5] = ui->Gyro_Z;

    for(int i=0;i<16;i++){
        x[i] = new QVector<double>();
        y[i] = new QVector<double>();
    }


    // The pen is used to draw a dot on XY graphs
    QPen pen;
    pen.setColor(QColor(229,115,115,255));
    pen.setWidth(10);
    pen.setCapStyle(Qt::RoundCap);
    // The line is used to draw classic graphs
    QPen line;
    line.setColor(QColor(25,118,210,255));
    line.setWidth(1);
    QPen line_red;
    line_red.setColor(QColor(210,25,118,255));
    line_red.setWidth(1);
    QPen line_green;
    line_green.setColor(QColor(118,210,25,255));
    line_green.setWidth(1);


    // Populating the XY graph
    // Only one curve on this graph : X axis /Y axis of accelerometer
    graph[0]->addGraph();
    // Draw a red dot
    graph[0]->graph(0)->setPen(pen);
    // Setting the labels of each axis, as well
    // as the range
    graph[0]->xAxis->setLabel("X");
    graph[0]->yAxis->setLabel("Y");
    graph[0]->xAxis->setRange(-10000,10000);
    graph[0]->yAxis->setRange(-10000,10000);
    // Activating the zoom and drag interraction in vertical and horizontal mode
    graph[0]->setInteraction(QCP::iRangeDrag, true);
    graph[0]->setInteraction(QCP::iRangeZoom, true);

    graph[1]->addGraph();
    graph[1]->addGraph();
    // Setting the labels of each axis, as well
    // as the range
    graph[1]->xAxis->setLabel("t");
    graph[1]->yAxis->setLabel("X & Y");
    graph[1]->yAxis->setRange(-24000,24000);
    graph[1]->graph(0)->setPen(line);
    graph[1]->graph(1)->setPen(line_red);
    // The X Axis should display time (text)
    graph[1]->setLocale(QLocale(QLocale::English, QLocale::Canada));
    graph[1]->xAxis->setTickLabelType(QCPAxis::ltDateTime);
    graph[1]->xAxis->setDateTimeFormat("hh:mm:ss");
    graph[1]->xAxis->setDateTimeSpec(Qt::OffsetFromUTC);
    // Activating the zoom and drag interraction in vertical mode
    graph[1]->setInteraction(QCP::iRangeDrag, true);
    graph[1]->setInteraction(QCP::iRangeZoom, true);
    graph[1]->yAxis->axisRect()->setRangeZoom(Qt::Horizontal);
    graph[1]->setFocusPolicy(Qt::StrongFocus);

    QString label[16] = {
        "Z",             // Accelerometer's axis
        "X","Y","Z"     // Gyroscope's three axis
    };
    for(int i=2;i<6;i++) {
        // Only one curve on those graphs : axis/time
        graph[i]->addGraph();
        // The datas are stored in x[1] (time) and y[i] vectors
    //    graph[i]->graph(0)->setData(*x[1],*y[i]);
        // Setting the labels of each axis, as well
        // as the range
        graph[i]->xAxis->setLabel("t");
        graph[i]->yAxis->setLabel(label[i-2]);
        graph[i]->yAxis->setRange(-24000,24000);
        graph[i]->graph(0)->setPen(line);
        // The X Axis should display time (text)
        graph[i]->setLocale(QLocale(QLocale::English, QLocale::Canada));
        graph[i]->xAxis->setTickLabelType(QCPAxis::ltDateTime);
        graph[i]->xAxis->setDateTimeFormat("hh:mm:ss");
        graph[i]->xAxis->setDateTimeSpec(Qt::OffsetFromUTC);
        // Activating the zoom and drag interraction in vertical mode
        graph[i]->setInteraction(QCP::iRangeDrag, true);
        graph[i]->setInteraction(QCP::iRangeZoom, true);
        graph[i]->yAxis->axisRect()->setRangeZoom(Qt::Horizontal);
        graph[i]->setFocusPolicy(Qt::StrongFocus);
    }

    connect(ui->Accel_X_Y, SIGNAL(mouseMove(QMouseEvent*)), this, SLOT(mouseRelease(QMouseEvent*)));
}

FileViewer::~FileViewer()
{
    for(int i=0;i<16;i++){
       delete x[i];
       delete y[i];
    }

    delete ui;
}




bool cursorEnabled=true;

void FileViewer::ManageCursor(QCustomPlot *customPlot, QCPCursor *cursor, double px, double py, QPen pen)
{
    double py_2;
    if(cursorEnabled)
    {
        py = (customPlot->graph(0)->data()->lowerBound(px).value().value);
        py_2 = (customPlot->graph(1)->data()->lowerBound(px).value().value);

        if(cursor->vLine) customPlot->removeItem(cursor->vLine);
        cursor->vLine = new QCPItemLine(customPlot);
        customPlot->addItem(cursor->vLine);
        cursor->vLine->setPen(pen);
        cursor->vLine->start->setCoords( px, QCPRange::minRange);
        cursor->vLine->end->setCoords( px, QCPRange::maxRange);

        x[0]->resize(0);
        x[0]->append(py);
        x[0]->append(py);
        y[0]->resize(0);
        y[0]->append(py_2);
        y[0]->append(py_2);

        graph[0]->graph(0)->setData(*x[0],*y[0]);
        graph[0]->replot();
    }
}

void FileViewer::mouseRelease(QMouseEvent* event)
{
    QCustomPlot *customPlot=ui->Accel_X_Y;
    static QCPCursor cursor1, cursor2;
    double x=customPlot->xAxis->pixelToCoord(event->pos().x());
    double y=customPlot->yAxis->pixelToCoord(event->pos().y());

    ManageCursor(customPlot, &cursor1, x, y, QPen(Qt::black));

    customPlot->replot();
    cursorEnabled=true;
}


/*  Simple function used to extract the date from       */
/*  a frame                                             */
/*  returns the time in seconds                         */
/*  Only works for the time, not the date               */
double getDateLog(QString date) {
    double day = 0;
    double hour = 0;
    double minute = 0;
    double sec = 0;
    double csec = 0;

    int inc = 0;

    day += date.at(6+inc).toLatin1()-'0';
    day *= 10;
    day += date.at(7+inc).toLatin1()-'0';

    hour += date.at(8+inc).toLatin1()-'0';
    hour *= 10;
    hour += date.at(9+inc).toLatin1()-'0';

    minute += date.at(10+inc).toLatin1()-'0';
    minute *= 10;
    minute += date.at(11+inc).toLatin1()-'0';

    sec += date.at(12+inc).toLatin1()-'0';
    sec *= 10;
    sec += date.at(13+inc).toLatin1()-'0';

    csec += date.at(14+inc).toLatin1()-'0';
    csec *= 10;
    csec += date.at(15+inc).toLatin1()-'0';

    return day*24*3600+hour*3600+minute*60+sec*1+csec*.01;
}

void FileViewer::showEvent(QShowEvent *)
{
    char myStr[200];
    QStringList str;
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open Log"), "./", tr("Text Files (*.txt)"));

    setWindowTitle("File Log: "+fileName);
    ifstream myfile (fileName.toLatin1().data());
    if (myfile.is_open())
    {

        QRegExp * rx = new QRegExp();
        rx->setPattern("([-\\+]*[0-9]+),([-\\+]*[0-9]+),([-\\+]*[0-9]+),([-\\+]*[0-9]+),([-\\+]*[0-9]+),([-\\+]*[0-9]+),([-\\+]*[0-9]+),([-\\+]*[0-9]+)");
        x[1]->resize(0);
        for(int j=1;j<8;j++)
            y[j]->resize(0);
        qDebug() << "file opened";
        while(!myfile.eof()) {
            int i = 0;
        myStr[i]=myfile.get();
        while(!myfile.eof()&&(myStr[i]!=0x0D) && myStr[i]!='\n') {
            i++;
            myStr[i] = myfile.get();
        }
        myStr[i] = 0;
    //  while ( myfile.getline(myStr,200) )
    //  {
        // First of all we check if the frame matches the regEx
        // If it does, we update the different values with the one
        // from the frame
        if((rx->indexIn(myStr, 0)) > -1) {
            str.append(QString(rx->cap(0)));

            x[1]->append(getDateLog(rx->cap(1)));
            for(int j=1;j<8;j++)
                y[j]->append(rx->cap(j+1).toDouble());



        // If the frame doesn't match the regEx, either that one
        // frame was false and the rest of the buffer is corrupted,
        // or the sync process didn't match the actual frame set up
        // Either way, time to resync the system.
        } else {
            qDebug() << "Error on RegEx";
            //break;
        }
        }

      qDebug() << "file closed";
      myfile.close();
    }
    else
        qDebug() << "Unable to open file";



    graph[1]->graph(0)->setData(*x[1],*y[4]);
    graph[1]->graph(1)->setData(*x[1],*y[5]);
    graph[1]->replot();
    graph[1]->xAxis->setRange(x[1]->last()-200,x[1]->last());
    graph[2]->graph(0)->setData(*x[1],*y[6]);
    graph[2]->replot();
    graph[2]->xAxis->setRange(x[1]->last()-200,x[1]->last());

    graph[3]->graph(0)->setData(*x[1],*y[1]);
    graph[3]->replot();
    graph[3]->xAxis->setRange(x[1]->last()-200,x[1]->last());
    graph[4]->graph(0)->setData(*x[1],*y[2]);
    graph[4]->replot();
    graph[4]->xAxis->setRange(x[1]->last()-200,x[1]->last());
    graph[5]->graph(0)->setData(*x[1],*y[3]);
    graph[5]->replot();
    graph[5]->xAxis->setRange(x[1]->last()-200,x[1]->last());

    ui->logFrame->clear();
    ui->logFrame->addItems(str);
}
