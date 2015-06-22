#include "mainwindow.h"

mainWindow::mainWindow() : QWidget()
{
    this->setMinimumSize(1000,500);

    // Creating the QVector of double needed to store the graphs
    // points
    x[0] = new QVector<double>(100);
    y[0] = new QVector<double>(100);
    y[1] = new QVector<double>(100);
    y[2] = new QVector<double>(2);
    x[2] = new QVector<double>(2);

    // The SettingsDialog instance handles the serial port configuration
    // window
    settings = new SettingsDialog();

    // The Protocole instance handles the communication through the selected
    // serial port and parses the data received through a RegEx string
    protocole = new Protocole();


    protocole->setRegEx("\\|([-\\+]*[0-9]+),([-\\+]*[0-9]+),([-\\+]*[0-9]+),([-\\+]*[0-9]+),([-\\+]*[0-9]+),([-\\+]*[0-9]+),([-\\+]*[0-9]+),([-\\+]*[0-9]+)\\|");


    // Set how much bytes Port has to read before
    // taking them into account.
    // A higher value will delay the redraw
    // A lower value will cause some lag if many
    // bytes are received in a small amount of time
    //
    // When using Fixed Length frames, the value should
    // be the length of the frame.
    protocole->setBufferedValue(1);

    // Creating a textEdit in order to log datas
    textEdit = new QTextEdit();
    textEdit->setMaximumWidth(200);


    // Creating the different buttons used to connect to and
    // configure the serial port
    actionConnect = new QPushButton("Connect");
    actionDisconnect = new QPushButton("Disconnect");
    actionDisconnect->setEnabled(false);
    actionConfigure = new QPushButton("Configure Port");
    actionQuit = new QPushButton("Quit");
    initActionsConnections();

    // Creating graphs instances
    graph[0] = new QCustomPlot();
    graph[1] = new QCustomPlot();
    graph[2] = new QCustomPlot();

    // The pen is used to draw a dot on XY graphs
    QPen pen;
    pen.setColor(QColor(255,0,0,255));
    pen.setWidth(10);
    pen.setCapStyle(Qt::RoundCap);


    // Populating the first graph
    // Only one curve on this graph : X axis of accelerometer /time
    graph[0]->addGraph();
    // The datas are stored in x[0] and y[0] vectors
    graph[0]->graph(0)->setData(*x[0],*y[0]);
    // Setting the labels of each axis, as well
    // as the range
    graph[0]->xAxis->setLabel("t");
    graph[0]->yAxis->setLabel("y");
    graph[0]->xAxis->setRange(0,100);
    graph[0]->yAxis->setRange(-10000,10000);
    // Activating the zoom and drag interraction in vertical mode
    graph[0]->setInteraction(QCP::iRangeDrag, true);
    graph[0]->setInteraction(QCP::iRangeZoom, true);
    graph[0]->yAxis->axisRect()->setRangeDrag(Qt::Vertical);
    graph[0]->xAxis->axisRect()->setRangeZoom(Qt::Vertical);


    // Populating the second graph
    // Only one curve on this graph : Y axis of accelerometer /time
    graph[1]->addGraph();
    // The datas are stored in x[0] and y[1] vectors
    graph[1]->graph(0)->setData(*x[0],*y[1]);
    // Setting the labels of each axis, as well
    // as the range
    graph[1]->xAxis->setLabel("t");
    graph[1]->yAxis->setLabel("y");
    graph[1]->xAxis->setRange(0,100);
    graph[1]->yAxis->setRange(-10000,10000);
    // Activating the zoom and drag interraction in vertical mode
    graph[1]->setInteraction(QCP::iRangeDrag, true);
    graph[1]->setInteraction(QCP::iRangeZoom, true);
    graph[1]->yAxis->axisRect()->setRangeDrag(Qt::Vertical);
    graph[1]->yAxis->axisRect()->setRangeZoom(Qt::Vertical);

    // Populating the third graph
    // Only one curve on this graph : X axis /Y axis of accelerometer
    graph[2]->addGraph();
    // The datas are stored in x[2] and y[2] vectors
    graph[2]->graph(0)->setData(*x[2],*y[2]);
    // Draw a red dot
    graph[2]->graph(0)->setPen(pen);
    // Setting the labels of each axis, as well
    // as the range
    graph[2]->xAxis->setLabel("x");
    graph[2]->yAxis->setLabel("y");
    graph[2]->xAxis->setRange(-10000,10000);
    graph[2]->yAxis->setRange(-10000,10000);
    // Activating the zoom and drag interraction in vertical and horizontal mode
    graph[2]->setInteraction(QCP::iRangeDrag, true);
    graph[2]->setInteraction(QCP::iRangeZoom, true);

    // Creating the layouts

    // Screen layout is the main window layout
    QVBoxLayout *screen = new QVBoxLayout;
    // Toolbar is the top bar containing all the buttons
    QHBoxLayout *toolbar = new QHBoxLayout;
    // Layout is everything below the toolbar, orderd horizontaly
    QHBoxLayout *layout = new QHBoxLayout;
    // Graph_layout contains multiple graphs vertically
    QVBoxLayout *graph_layout = new QVBoxLayout;

    // Configuring the layouts

    // Creating new buttons for the toolbar and adding action to them
    QPushButton *stopStart = new QPushButton("Stop/Start");
    connect(stopStart,SIGNAL(clicked()),this,SLOT(startStop()));
    // Adding every button on the toolbar
    toolbar->addWidget(stopStart);
    toolbar->addWidget(actionConnect);
    toolbar->addWidget(actionDisconnect);
    toolbar->addWidget(actionConfigure);
    toolbar->addWidget(actionQuit);

    // Adding the textEdit (console) and the graphs
    layout->addWidget(textEdit);
    graph_layout->addWidget(graph[0]);
    graph_layout->addWidget(graph[1]);
    layout->addLayout(graph_layout);
    layout->addWidget(graph[2]);

    // Adding everything in the main layoyt
    screen->addLayout(toolbar);
    screen->addLayout(layout);

    // Addding the layout to the Window
    setLayout(screen);

    // Addding Window's title
    setWindowTitle("Doctor's Order Data Logger");

    // Starting a Timer for graph updates
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

    (*y[0]).remove(0,1);
    (*y[0]).append(str);
    (*x[2]).remove(0,2);
    (*x[2]).append(str);
    (*x[2]).append(str);

    if(!refresh) {
        graph[0]->graph(0)->setData(*x[0],*y[0]);
        graph[0]->replot();
        graph[2]->graph(0)->setData(*x[2],*y[2]);
        graph[2]->replot();
    }
    refresh = (refresh+1)%2;

}

void mainWindow::changeDataCos(double str) {
    static int refresh = 0;

    (*y[1]).remove(0,1);
    (*y[1]).append(str);
    (*y[2]).remove(0,2);
    (*y[2]).append(str);
    (*y[2]).append(str);
    if(!refresh) {
        graph[1]->graph(0)->setData(*x[0],*y[1]);
        graph[1]->replot();
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
