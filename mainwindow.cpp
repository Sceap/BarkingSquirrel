#include "mainwindow.h"

mainWindow::mainWindow() : QWidget()
{
    this->setMinimumSize(1000,500);
    x = new QVector<double>(100);
    y = new QVector<double>(100);
    x_cos = new QVector<double>(100);
    y_cos = new QVector<double>(100);
    xy_y = new QVector<double>(2);
    xy_x = new QVector<double>(2);

    settings = new SettingsDialog();

    // Create a Serial Protocol (COM5)
    protocole = new Protocole();

    protocole->initValue(0,100);
    protocole->initValue(1,100);
    protocole->initValue(2,100);
    protocole->initValue(3,100);
    protocole->initValue(4,2);
    protocole->initValue(5,2);


    protocole->setRegEx("\\|([-\\+]*[0-9]+),([-\\+]*[0-9]+),([-\\+]*[0-9]+),([-\\+]*[0-9]+),([-\\+]*[0-9]+),([-\\+]*[0-9]+),([-\\+]*[0-9]+),([-\\+]*[0-9]+)\\|");

    // Set how much bytes Port has to read before
    // taking them into account.
    // A higher value will miss some values
    // A lower value will cause some lag if many
    // bytes are received in a small amount of time
    protocole->setBufferedValue(1);

    // Create a textEdit in order to log datas
    textEdit = new QTextEdit();
    textEdit->setMaximumWidth(300);



    actionConnect = new QPushButton("Connect");
    actionDisconnect = new QPushButton("Disconnect");
    actionDisconnect->setEnabled(false);
    actionConfigure = new QPushButton("Configure Port");
    actionQuit = new QPushButton("Quit");
    initActionsConnections();

    // Creating graphs instances
    graph = new QCustomPlot();
    graph_cos = new QCustomPlot();
    graph_xy = new QCustomPlot();


    for (int i=0; i<100; ++i)
    {
      (*x)[i] = i; // x goes from -1 to 1
      (*x_cos)[i] = i; // x goes from -1 to 1
    }


    // create graph and assign data to it:
    graph->addGraph();
    // give the axes some labels:
    graph->graph(0)->setData(*x,*y);
    QPen pen;
    pen.setColor(QColor(255,0,0,255));
    pen.setWidth(10);
    pen.setCapStyle(Qt::RoundCap);
    graph->xAxis->setLabel("x");
    graph->yAxis->setLabel("y");
    graph->xAxis->setRange(0,100);
    graph->yAxis->setRange(-10000,10000);
    // set axes ranges, so we see all data:
    graph->replot();
    graph->setInteraction(QCP::iRangeDrag, true);
    graph->setInteraction(QCP::iRangeZoom, true);
    graph->xAxis->axisRect()->setRangeDrag(Qt::Vertical);
    graph->yAxis->axisRect()->setRangeDrag(Qt::Vertical);
    graph->xAxis->axisRect()->setRangeZoom(Qt::Vertical);
    graph->yAxis->axisRect()->setRangeZoom(Qt::Vertical);


    // create graph and assign data to it:
    graph_cos->addGraph();
    // give the axes some labels:
    graph_cos->graph(0)->setData(*x,*y_cos);
    graph_cos->xAxis->setLabel("x");
    graph_cos->yAxis->setLabel("y");
    graph_cos->xAxis->setRange(0,100);
    graph_cos->yAxis->setRange(-10000,10000);
    // set axes ranges, so we see all data:
    graph_cos->replot();
    graph_cos->setInteraction(QCP::iRangeDrag, true);
    graph_cos->setInteraction(QCP::iRangeZoom, true);
    graph_cos->xAxis->axisRect()->setRangeDrag(Qt::Vertical);
    graph_cos->yAxis->axisRect()->setRangeDrag(Qt::Vertical);
    graph_cos->xAxis->axisRect()->setRangeZoom(Qt::Vertical);
    graph_cos->yAxis->axisRect()->setRangeZoom(Qt::Vertical);

    graph_xy->addGraph();
    graph_xy->graph(0)->setData(*xy_x,*xy_y);
    graph_xy->graph(0)->setPen(pen);
    graph_xy->xAxis->setLabel("x");
    graph_xy->yAxis->setLabel("y");
    graph_xy->xAxis->setRange(-10000,10000);
    graph_xy->yAxis->setRange(-10000,10000);
    graph_xy->replot();

    // Create the layouts
    QVBoxLayout *screen = new QVBoxLayout;
    QHBoxLayout *toolbar = new QHBoxLayout;
    QHBoxLayout *layout = new QHBoxLayout;
    QVBoxLayout *graph_layout = new QVBoxLayout;

    // Configure the layouts
    QPushButton *stopStart = new QPushButton("Stop/Start");
    toolbar->addWidget(stopStart);
    toolbar->addWidget(actionConnect);
    toolbar->addWidget(actionDisconnect);
    toolbar->addWidget(actionConfigure);
    toolbar->addWidget(actionQuit);


    connect(stopStart,SIGNAL(clicked()),this,SLOT(startStop()));

    layout->addWidget(textEdit);
    graph_layout->addWidget(graph);
    graph_layout->addWidget(graph_cos);
    layout->addLayout(graph_layout);

    screen->addLayout(toolbar);
    screen->addLayout(layout);

    layout->addWidget(graph_xy);

    // Add the layout to the Window
    setLayout(screen);

    // Add Window's title
    setWindowTitle("Doctor's Order Data Logger");

    // Start a Timer for graph updates
    QTimer * timer = new QTimer();
    timer->setInterval(1);
    connect(timer,SIGNAL(timeout()),this,SLOT(updateData()));
    timer->start();
}

void mainWindow::updateData() {
    static int lastString = 0, lastValue[5] = {0,0,0,0,0};
    if(!protocole->values[1].isEmpty()) {
         for(int i=0; i<8&&lastValue[1]<protocole->values[1].size(); i++) {
             changeData(protocole->values[1].at(lastValue[1]++),0);
         }

         if(protocole->values[1].size()>4096) {
             for (int i = 0; i < lastValue[1]; ++i)
                protocole->values[1].removeFirst();
             lastValue[1] = 0;
         }

     }

    if(!protocole->values[2].isEmpty()) {
         for(int i=0; i<8&&lastValue[2]<protocole->values[2].size(); i++) {
             changeDataCos(protocole->values[2].at(lastValue[2]++));
         }

         if(protocole->values[2].size()>4096) {
             for (int i = 0; i < lastValue[2]; i++)
                protocole->values[2].removeFirst();
             lastValue[2] = 0;
         }

     }

   if(!protocole->strings.isEmpty()) {
        for(int i=0; i<8&&lastString<protocole->strings.size(); i++) {
            appendHTML(protocole->strings.at(lastString++));
        }

        if(protocole->strings.size()>4096) {
            for (int i = 0; i < lastString; i++)
               protocole->strings.removeFirst();
            lastString = 0;
        }
    }

}

void mainWindow::initActionsConnections()
{
    connect(actionConnect, SIGNAL(clicked()), this, SLOT(openSerialPort()));
    connect(actionDisconnect, SIGNAL(clicked()), this, SLOT(closeSerialPort()));
    connect(actionQuit, SIGNAL(clicked()), this, SLOT(close()));
    connect(actionConfigure, SIGNAL(clicked()), settings, SLOT(show()));
}


void mainWindow::startStop() {
    static unsigned char cmd = '0';
    protocole->send_char(cmd);

    if(cmd=='0')
        cmd='1';
    else
        cmd='0';
}


void mainWindow::changeData(double str, double t) {
    static int refresh = 0;

    (*y).remove(0,1);
    (*y).append(str);
    (*xy_x).remove(0,2);
    (*xy_x).append(str);
    (*xy_x).append(str);

    if(!refresh) {
        graph->graph(0)->setData(*x,*y);
        graph->replot();
        graph_xy->graph(0)->setData(*xy_x,*xy_y);
        graph_xy->replot();
    }
    refresh = (refresh+1)%2;

}

void mainWindow::changeDataCos(double str) {
    static int refresh = 0;

    (*y_cos).remove(0,1);
    (*y_cos).append(str);
    (*xy_y).remove(0,2);
    (*xy_y).append(str);
    (*xy_y).append(str);
    if(!refresh) {
        graph_cos->graph(0)->setData(*x,*y_cos);
        graph_cos->replot();
    }
    refresh = (refresh+1)%2;
}
void mainWindow::appendHTML(QString str) {
    static int log = 0;

    textEdit->append(str+"\n");

    if(!log) {
        textEdit->clear();
    }
    log = (log+1)%2000;
}



void mainWindow::openSerialPort()
{
    SettingsDialog::Settings p = settings->settings();
    protocole->port->setPortName(p.name);
    protocole->port->setBaudRate(p.baudRate);
    protocole->port->setDataBits(p.dataBits);
    protocole->port->setParity(p.parity);
    protocole->port->setStopBits(p.stopBits);
    protocole->port->setFlowControl(p.flowControl);
    if (protocole->port->open(QIODevice::ReadWrite)) {
            actionConnect->setEnabled(false);
            actionDisconnect->setEnabled(true);
            actionConfigure->setEnabled(false);
    } else {
        QMessageBox::critical(this, tr("Error"), protocole->port->errorString());
    }

    protocole->start();
}

void mainWindow::closeSerialPort()
{
    protocole->terminate();

    if (protocole->port->isOpen())
        protocole->port->close();
    actionConnect->setEnabled(true);
    actionDisconnect->setEnabled(false);
    actionConfigure->setEnabled(true);
}
