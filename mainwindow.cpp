#include "mainwindow.h"

mainWindow::mainWindow() : QWidget()
{
    this->setMinimumSize(1000,500);

    /// Creating the logger file instance
    log = new QFile();

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
    protocole->addValues(8);


    // Set how much bytes Port has to read before
    // taking them into account.
    // A higher value will delay the redraw
    // A lower value will cause some lag if many
    // bytes are received in a small amount of time
    //
    // When using Fixed Length frames, the value should
    // be the exact length of the frame.
    protocole->setBufferedValue(67);

    // Creating a textEdit in order to log datas
    textEdit = new QTextEdit;
    textEdit->setMaximumWidth(200);

    // Creating a checkbox to allow logging in local file
    logToFile = new QCheckBox;
    logToFile->setChecked(false);
    logToFile->setText("Log to file");

    // Creating a lineedit for entering the local file's name
    fileName = new QLineEdit;
    fileName->setText("file_log");
    QLabel * txt = new QLabel;
    txt->setText(".txt");

    // Creating a checkbox to allow appending the date to the file's name
    appendDate = new QCheckBox;
    appendDate->setText("Append date to filename");
    appendDate->setChecked(false);


    // Creating the different buttons used to connect to and
    // configure the serial port
    actionConnect = new QPushButton("Connect");
    actionDisconnect = new QPushButton("Disconnect");
    actionDisconnect->setEnabled(false);
    actionConfigure = new QPushButton("Configure Port");
    // Creating new buttons for the toolbar and adding action to them
    stopStart = new QPushButton("Stop/Start");
    connect(stopStart,SIGNAL(clicked()),this,SLOT(startStop()));
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
    graph[0]->yAxis->setRange(-10000,10000);
    // The X Axis should display time (text)
    graph[0]->setLocale(QLocale(QLocale::English, QLocale::Canada));
    graph[0]->xAxis->setTickLabelType(QCPAxis::ltDateTime);
    graph[0]->xAxis->setDateTimeFormat("hh:mm:ss");
    graph[0]->xAxis->setDateTimeSpec(Qt::OffsetFromUTC);
    graph[0]->xAxis->setAutoTickStep(false);
    graph[0]->xAxis->setTickStep(2);
    graph[0]->xAxis->setSubTickCount(10);
    // Activating the zoom and drag interraction in vertical mode
    graph[0]->setInteraction(QCP::iRangeDrag, true);
    graph[0]->setInteraction(QCP::iRangeZoom, true);
    graph[0]->yAxis->axisRect()->setRangeDrag(Qt::Vertical);
    graph[0]->yAxis->axisRect()->setRangeZoom(Qt::Vertical);


    // Populating the second graph
    // Only one curve on this graph : Y axis of accelerometer /time
    graph[1]->addGraph();
    // The datas are stored in x[0] and y[1] vectors
    graph[1]->graph(0)->setData(*x[0],*y[1]);
    // Setting the labels of each axis, as well
    // as the range
    graph[1]->xAxis->setLabel("t");
    graph[1]->yAxis->setLabel("y");
    graph[1]->yAxis->setRange(-10000,10000);
    // The X Axis should display time (text)
    graph[1]->setLocale(QLocale(QLocale::English, QLocale::Canada));
    graph[1]->xAxis->setTickLabelType(QCPAxis::ltDateTime);
    graph[1]->xAxis->setDateTimeFormat("hh:mm:ss");
    graph[1]->xAxis->setDateTimeSpec(Qt::OffsetFromUTC);
    graph[1]->xAxis->setAutoTickStep(false);
    graph[1]->xAxis->setTickStep(2);
    graph[1]->xAxis->setSubTickCount(10);
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
    QHBoxLayout *port_bar = new QHBoxLayout;
    QHBoxLayout *log_bar = new QHBoxLayout;
    QVBoxLayout *cmd_bar = new QVBoxLayout;
    // Layout is everything below the toolbar, ordered horizontaly
    QHBoxLayout *layout = new QHBoxLayout;
    // The following layouts are for tabs
    QHBoxLayout *accelerometer = new QHBoxLayout;
    QHBoxLayout *advanced_cmd = new QHBoxLayout;
    // Graph_layout contains multiple graphs vertically
    QVBoxLayout *graph_layout = new QVBoxLayout;

    // The three select GroupBoxes allow a self-explanatory
    // separation of the toolbar
    QGroupBox * selectPort = new QGroupBox;
    selectPort->setTitle("Serial Port");
    QGroupBox * selectLog = new QGroupBox;
    selectLog->setTitle("Log File");
    QGroupBox * selectCmd = new QGroupBox;
    selectCmd->setTitle("Send command");

    // Those two nested layouts are used for the log file
    // configuration
    QVBoxLayout * log_zone = new QVBoxLayout;
    QHBoxLayout * log_buttons = new QHBoxLayout;

    // Those three nested layouts are used for the commands
    QHBoxLayout * cmd_line1 = new QHBoxLayout;
    QHBoxLayout * cmd_line2 = new QHBoxLayout;

    // Creating all the commands button
    QPushButton * stopButton = new QPushButton("STOP");
    QPushButton * startButton = new QPushButton("START");
    QPushButton * burstButton = new QPushButton("BURST");
    QPushButton * streamButton = new QPushButton("STREAM");


    // Creating a SpinBox for the command value (must be numbers!)
    QLabel * cmdLabel = new QLabel("Command value: ");
    QSpinBox * cmdValue = new QSpinBox;
    cmdValue->setMinimum(0);
    cmdValue->setMaximum(65535);
    cmdValue->setValue(0);

    // Creating a lineEdit for custom commands
    QLabel * cmdCustomLabel = new QLabel("Custom command: ");
    QLineEdit * cmdCustom = new QLineEdit;
    QPushButton * cmdCustomSend = new QPushButton("Send");


    // Configuring the layouts

    // Adding every widget on the toolbar
    port_bar->addWidget(actionConnect);
    port_bar->addWidget(actionDisconnect);
    port_bar->addWidget(actionConfigure);

    log_buttons->addWidget(logToFile);
    log_buttons->addWidget(appendDate);
    log_zone->addWidget(fileName);
    log_zone->addLayout(log_buttons);
    log_bar->addLayout(log_zone);

    cmd_line1->addWidget(startButton);
    cmd_line1->addWidget(stopButton);
    cmd_line1->addWidget(burstButton);
    cmd_line1->addWidget(streamButton);
    cmd_line1->addStretch(1);
    cmd_line1->addWidget(cmdLabel);
    cmd_line1->addWidget(cmdValue);

    cmd_line2->addWidget(cmdCustomLabel);
    cmd_line2->addWidget(cmdCustom);
    cmd_line2->addWidget(cmdCustomSend);
    cmd_line2->addStretch(1);

    cmd_bar->addLayout(cmd_line1);
    cmd_bar->addLayout(cmd_line2);

    // Populating every select GroupBox
    selectPort->setLayout(port_bar);
    selectLog->setLayout(log_bar);
    selectCmd->setLayout(cmd_bar);

    // Adding the GroupBoxes to the toolbar
    toolbar->addWidget(selectPort);
    toolbar->addSpacing(32);
    toolbar->addWidget(selectLog);
    toolbar->addSpacing(32);
    toolbar->addWidget(selectCmd);
    toolbar->addStretch(1);


    // Adding the textEdit (console) and the graphs
    layout->addWidget(textEdit);
    graph_layout->addWidget(graph[0]);
    graph_layout->addWidget(graph[1]);
    accelerometer->addLayout(graph_layout);
    accelerometer->addWidget(graph[2]);

    // Creating the tab widget
    QTabWidget * screenTab = new QTabWidget(this);
    // Creating the different tabs
    QWidget * accelerometerTab = new QWidget;
    QWidget * advancedCommandTab = new QWidget;

    // Setting the tabs layouts
    accelerometerTab->setLayout(accelerometer);
    advancedCommandTab->setLayout(advanced_cmd);

    // Adding the tabs to the tab widget
    screenTab->addTab(accelerometerTab,QString("Accelerometer"));
    screenTab->addTab(advancedCommandTab,QString("Advanced Commands"));

    // Adding the tab widget to the main layout
    layout->addWidget(screenTab);

    // Adding everything in the main layout
    screen->addLayout(toolbar);
    screen->addLayout(layout);

    // Addding the layout to the Window
    setLayout(screen);

    // Addding Window's title
    setWindowTitle("Doctor's Order Data Logger");

#if VARIABLE_LENGTH == 1
    // Starting a Timer for graph updates
    QTimer * timer = new QTimer();
    timer->setInterval(1);
    connect(timer,SIGNAL(timeout()),this,SLOT(updateData()));
    timer->start();
#else
    connect(protocole,SIGNAL(updateData()),this,SLOT(updateData()));
#endif
}


/*  Simple function used to extract the date from   */
/*  a frame                                         */
/*  returns the time in seconds                     */
/*  Only works for the time, not the date           */
double getDate(QString date) {
    double hour = 0;
    double minute = 0;
    double sec = 0;
    double csec = 0;

    hour += date.at(9).toLatin1()-'0';
    hour *= 10;
    hour += date.at(10).toLatin1()-'0';

    minute += date.at(11).toLatin1()-'0';
    minute *= 10;
    minute += date.at(12).toLatin1()-'0';

    sec += date.at(13).toLatin1()-'0';
    sec *= 10;
    sec += date.at(14).toLatin1()-'0';

    csec += date.at(15).toLatin1()-'0';
    csec *= 10;
    csec += date.at(16).toLatin1()-'0';

    return hour*3600+minute*60+sec*1+csec*.01;
}

/*  updateData is a Slot that can either be called  */
/*  periodically through a Timer, or directly from  */
/*  the Protocole's run function                    */
/*  It calls every update function in order to      */
/*  display the latest information gotten through   */
/*  the serial connection                           */
void mainWindow::updateData() {
    // lastString is used in Variable Length mode to
    // keep track of read strings and values.
    static int lastString = 0;

    // Getting the current date if needed for the log file
    QString date = QDateTime::currentDateTime().toString("_MM_dd_yyyy");

    // Opening a log file if required
    if(logToFile->isChecked()) {
        // Adding the date to the name if needed
        if(appendDate->isChecked())
            log = new QFile(fileName->text()+date+".txt");
        else
            log = new QFile(fileName->text()+".txt");

        // Always open as Append
        log->open(QIODevice::Append);
    }

    // If using variable length, first check if there's any
    // strings available, then check if those strings are newer
    // than the last one read
    // The nested for/if statement allows a burst of up to 8 values
    // but still stops as soon as all values are read
    //
    // Then, empties the different values if too much data is stored
#if VARIABLE_LENGTH == 1
    if(!protocole->strings.isEmpty()) {
        for(int i=0; i<8&&lastString<protocole->strings.size()&&lastString<protocole->values[5].size(); i++) {
            time = getDate(protocole->strings.at(lastString));
            updateYAxis(protocole->values[2].at(lastString));
            updateXAxis(protocole->values[1].at(lastString),time);
            updateConsole(protocole->strings.at(lastString++));
            if(logToFile->isChecked())
            log->write(protocole->strings.at(lastString).toLatin1()+"\n");
        }

        if(protocole->strings.size()>4096) {
            for (int i = 0; i < lastString; i++) {
                protocole->values[1].removeFirst();
                protocole->values[2].removeFirst();
                protocole->strings.removeFirst();
            }
            lastString = 0;
        }
    }
#else
    // If using fixed length (recommended), simply update with
    // the last value available (updateData called from the Protocole's run)
    updateYAxis(protocole->lastValue[2]);
    updateXAxis(protocole->lastValue[1],getDate(protocole->lastString));
    updateConsole(protocole->lastString);

    if(logToFile->isChecked())
    log->write(protocole->lastString.toLatin1()+"\n");
#endif

    // Closing the file if it had been opened
    if(logToFile->isChecked())
    log->close();
}


/*  Serial port buttons connects                    */
void mainWindow::initActionsConnections()
{
    connect(actionConnect, SIGNAL(clicked()), this, SLOT(openSerialPort()));
    connect(actionDisconnect, SIGNAL(clicked()), this, SLOT(closeSerialPort()));
    connect(actionConfigure, SIGNAL(clicked()), settings, SLOT(show()));
}


/*  This function update the values related to the  */
/*  accelerometer's X Axis (X graph, XY graph)      */
void mainWindow::updateXAxis(double value, double time) {
    static int refresh = 0;

    // Remove the first value from X graph
    (*y[0]).remove(0,1);
    // Append the new value at the end of X graph
    (*y[0]).append(value);

    // Remove both points from XY graph
    (*x[2]).remove(0,2);
    // Append the new value to both points in XY graph
    (*x[2]).append(value);
    (*x[2]).append(value);

    // Remove the first date
    (*x[0]).remove(0,1);
    // Append the new date to the end
    (*x[0]).append(time);

    // Once every two new data, update the display
    if(!refresh) {
        graph[0]->graph(0)->setData(*x[0],*y[0]);
        graph[0]->xAxis->setRange(x[0]->first(),x[0]->last());
        graph[0]->replot();
        graph[2]->graph(0)->setData(*x[2],*y[2]);
        graph[2]->replot();
    }
    refresh = (refresh+1)%2;

}

/*  This function update the values related to the  */
/*  accelerometer's Y Axis (Y graph, XY graph)      */
void mainWindow::updateYAxis(double value) {
    static int refresh = 0;

    // Remove first value from Y graph
    (*y[1]).remove(0,1);
    // Append new value to the end of Y graph
    (*y[1]).append(value);

    // Remove both points from XY graph
    (*y[2]).remove(0,2);
    // Append the new value to both points in XY graph
    (*y[2]).append(value);
    (*y[2]).append(value);

    // Once every two new data, update the display
    if(!refresh) {
        graph[1]->graph(0)->setData(*x[0],*y[1]);
        graph[1]->xAxis->setRange(x[0]->at(0),x[0]->last());
        graph[1]->replot();
    }
    refresh = (refresh+1)%2;
}

/*  This function updates the console display with  */
/*  the last received string. Every 2000 lines, the */
/*  console is cleared to avoid overcharging        */
void mainWindow::updateConsole(QString str) {
    static int log = 0;

    textEdit->append(str+"\n");

    if(!log) {
        textEdit->clear();
    }
    log = (log+1)%2000;
}


/*  OpenSerialPort allows the user to connect to    */
/*  the port whose settings were defined in the     */
/*  setting dialog                                  */
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

/*  CloseSerialPort closes a currently open port    */
void mainWindow::closeSerialPort()
{
    protocole->terminate();

    if (protocole->port->isOpen())
        protocole->port->close();
    actionConnect->setEnabled(true);
    actionDisconnect->setEnabled(false);
    actionConfigure->setEnabled(true);
}
