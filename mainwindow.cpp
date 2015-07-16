/********************************************************************************************************************************
*     _____       _  _____      ____          _                       _____                      _    _____                     *
*    |  __ \     ( )/ ____|    / __ \        | |                     / ____|                    | |  / ____|                    *
*    | |  | |_ __|/| (___     | |  | |_ __ __| | ___ _ __ ___       | (___  _ __ ___   __ _ _ __| |_| |     __ _ _ __   ___     *
*    | |  | | '__|  \___ \    | |  | | '__/ _` |/ _ \ '__/ __|       \___ \| '_ ` _ \ / _` | '__| __| |    / _` | '_ \ / _ \    *
*    | |__| | |     ____) |   | |__| | | | (_| |  __/ |  \__ \       ____) | | | | | | (_| | |  | |_| |___| (_| | | | |  __/    *
*    |_____/|_|    |_____/     \____/|_|  \__,_|\___|_|  |___/      |_____/|_| |_| |_|\__,_|_|   \__|\_____\__,_|_| |_|\___|    *
*                                                                                                                               *
*   2015                                                                                                                        *
*                                                                                                                               *
*   Project updated by Jeremie VAN DER SANDE (jeremie.vandersande@gmail.com) (remplace if needed)                               *
*   Internship (June..August) at UNB, Fredericton                                                                               *
*                                                                                                                               *
*********************************************************************************************************************************
*                                                                                                                               *
*   This Qt Project has been developped in order to provide a logging software for the developers at Dr'S Orders                *
*   It provides an easy way to connect to the smartCane, either through USB or Bluetooth connection, using Serial Port (UART)   *
*   protocole                                                                                                                   *
*   Data is then displayed in different way, including a console and various graphs                                             *
*   The software can also be used to send commands to the Cane - for instance sync the embedded clock module                    *
*                                                                                                                               *
*   This is the Main Qt file, implementing the interface of the software and instantiating every class needed for the software  *
*   to work. For the UART protocole details, see "protocole.h" and "protocole.cpp"                                              *
*                                                                                                                               *
********************************************************************************************************************************/

#include "mainwindow.h"
#include "ui_mainwindow.h"

mainWindow::mainWindow() : QMainWindow(),
    ui(new Ui::MainWindow)
{
    this->setMinimumSize(1000,500);
    // Creating the general UI
    ui->setupUi(this);

    // Making last minute adjustments and
    // initializing some parts of the UI
    ui->tabWidget->setCurrentIndex(0);
    ui->fileName->setText("log_file");
    ui->actionDisconnect->setEnabled(false);

    // Creating the logger file instance
    log = new QFile();

    // Creating the session file instance
    session = new QFile("session.dat");


    // Creating the QVector of double needed to store the graphs
    // points
    y[0] = new QVector<double>(2);
    x[0] = new QVector<double>(2);

    x[1] = new QVector<double>(200);

    y[1] = new QVector<double>(200);
    y[2] = new QVector<double>(200);
    y[3] = new QVector<double>(200);

    y[4] = new QVector<double>(200);
    y[5] = new QVector<double>(200);
    y[6] = new QVector<double>(200);

    y[7] = new QVector<double>(200);

    // The SettingsDialog instance handles the serial port configuration
    // window
    settings = new SettingsDialog();
    file_viewer = new FileViewer();

    // The Protocole instance handles the communication through the selected
    // serial port and parses the data received through a RegEx string
    protocole = new Protocole();


    // Now that everything's ready, try restoring
    // an existing session
    restoreSession();

    // Connecting all the commands button
    QSignalMapper * cmdMap = new QSignalMapper(this);

    connect(ui->cmdFreq,SIGNAL(clicked()),cmdMap,SLOT(map()));
    connect(ui->cmdBurst,SIGNAL(clicked()),cmdMap,SLOT(map()));
    connect(ui->cmdStream,SIGNAL(clicked()),cmdMap,SLOT(map()));
    cmdMap -> setMapping (ui->cmdFreq, "FRQ") ;
    cmdMap -> setMapping (ui->cmdBurst, "BST") ;
    cmdMap -> setMapping (ui->cmdStream, "STR") ;
    connect(cmdMap,SIGNAL(mapped(QString)),this,SLOT(sendCommandBox(QString)));

    // Connecting the buttons for RTC sync
    connect(ui->sendTime,SIGNAL(clicked()),this,SLOT(sendRTCTime()));
    connect(ui->getTime,SIGNAL(clicked()),this,SLOT(getRTCTime()));
    connect(ui->syncSysTime,SIGNAL(clicked()),this,SLOT(getSysTime()));

    // Connecting the button to fetch the last logged frames
    // into the console
    connect(ui->logUpdate,SIGNAL(clicked()),this,SLOT(update_c()));

    // Connecting the buttons used to connect to and configure
    // the serial port
    connect(ui->actionConnect, SIGNAL(clicked()), this, SLOT(openSerialPort()));
    connect(ui->actionDisconnect, SIGNAL(clicked()), this, SLOT(closeSerialPort()));
    connect(ui->actionConfigure, SIGNAL(clicked()), settings, SLOT(show()));
    connect(ui->cmdCustomSend,SIGNAL(clicked()),this,SLOT(sendCustomCommand()));

    connect(ui->applyLog, SIGNAL(clicked()),this,SLOT(applyLog()));


    logMap = new QSignalMapper(this);
    logMap->setMapping(ui->viewLog,logDirectory);
    connect(ui->viewLog,SIGNAL(clicked()),logMap,SLOT(map()));
    connect(logMap,SIGNAL(mapped(QString)),file_viewer,SLOT(show_dialog(QString)));

    // Connectring the button to change the log directory
    connect(ui->changeDirectory,SIGNAL(clicked()),this,SLOT(changeLogDirectory()));

    // Creating graphs instances by linking them to UI elements
    graph[0] = ui->graphXY;
    graph[1] = ui->graphXAxis;
    graph[2] = ui->graphYAxis;
    graph[3] = ui->graphZAxis;
    graph[4] = ui->gyroX;
    graph[5] = ui->gyroY;
    graph[6] = ui->gyroZ;
    graph[7] = ui->weightGraph;

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


    // Graph 1 to 6 stores the accelerometer and gyroscope
    // axis, and share similar settings.
    // Their label can be set directly in the next array
    QString label[16] = {
        "",
        "X","Y","Z",    // Accelerometer's three axis
        "X","Y","Z"     // Gyroscope's three axis
    };
    for(int i=1;i<8;i++) {
        // Only one curve on those graphs : axis/time
        graph[i]->addGraph();
        // The datas are stored in x[1] (time) and y[i] vectors
        graph[i]->graph(0)->setData(*x[1],*y[i]);
        graph[i]->graph(0)->setPen(line);
        // Setting the labels of each axis, as well
        // as the range
        graph[i]->xAxis->setLabel("t");
        graph[i]->yAxis->setLabel(label[i]);
        graph[i]->yAxis->setRange(-32000,32000);
        // The X Axis should display time (text)
        graph[i]->setLocale(QLocale(QLocale::English, QLocale::Canada));
        graph[i]->xAxis->setTickLabelType(QCPAxis::ltDateTime);
        graph[i]->xAxis->setDateTimeFormat("hh:mm:ss");
        graph[i]->xAxis->setDateTimeSpec(Qt::OffsetFromUTC);
        // Activating the zoom and drag interraction in vertical mode
        graph[i]->setInteraction(QCP::iRangeDrag, true);
        graph[i]->setInteraction(QCP::iRangeZoom, true);
        graph[i]->yAxis->axisRect()->setRangeDrag(Qt::Vertical);
        graph[i]->yAxis->axisRect()->setRangeZoom(Qt::Vertical);
    }
    graph[2]->graph(0)->setPen(line_green);
    graph[3]->graph(0)->setPen(line_red);
    graph[5]->graph(0)->setPen(line_green);
    graph[6]->graph(0)->setPen(line_red);

    graph[7]->yAxis->setRange(0,600);

    // Populating the XY graph
    // Only one curve on this graph : X axis /Y axis of accelerometer
    graph[0]->addGraph();
    // The datas are stored in x[0] and y[0] vectors
    graph[0]->graph(0)->setData(*x[0],*y[0]);
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

    // For each graph, making the lines lighter in order to clean up the view
    for(int i=0;i<8;i++) {
        graph[i]->xAxis->setBasePen(QPen(QColor(195,195,195)));
        graph[i]->xAxis->setTickPen(QPen(QColor(195,195,195)));
        graph[i]->xAxis->setSubTickPen(QPen(QColor(195,195,195)));
        graph[i]->yAxis->setBasePen(QPen(QColor(195,195,195)));
        graph[i]->yAxis->setTickPen(QPen(QColor(195,195,195)));
        graph[i]->yAxis->setSubTickPen(QPen(QColor(195,195,195)));
    }

    // For every setting that should be saved, connecting the saveSession slot to
    // the state change signal
    connect(ui->appendDate,SIGNAL(stateChanged(int)),this,SLOT(saveSession()));
    connect(ui->logToFile,SIGNAL(stateChanged(int)),this,SLOT(saveSession()));
    connect(ui->fileName,SIGNAL(textChanged(QString)),this,SLOT(saveSession()));
    connect(ui->cmdValue,SIGNAL(valueChanged(int)),this,SLOT(saveSession()));
    connect(settings,SIGNAL(updated()),this,SLOT(saveSession()));

    // Addding Window's title
    setWindowTitle("Doctor's Orders Data Logger");



    // Creating a Timer for frame fetching
    serialFetch = new QTimer();
    serialFetch->setInterval(2);
    connect(serialFetch,SIGNAL(timeout()),protocole,SLOT(fetch()));

    // Creating a Timer for GUI update
    guiUpdate = new QTimer();
    guiUpdate->setInterval(50);
    connect(guiUpdate,SIGNAL(timeout()),this,SLOT(update()));

    // Connecting the serial port to the updateData slot
    connect(protocole,SIGNAL(updateData()),this,SLOT(updateData()));

}


/* Update is called in order to update the GUI          */
/* with the information collected since the last        */
/* update                                               */
void mainWindow::update() {
    // It is no use updating graphs that aren't
    // visible
    int graphs = -1;
    if(ui->tabWidget->currentIndex()==0) {
        graph[7]->graph(0)->setData(*x[1],*y[7]);
        graph[7]->xAxis->setRange(x[1]->at(0),x[1]->last());
        graph[7]->replot();
        ui->weightBar->setValue((int)y[7]->last());
    }
    if(ui->tabWidget->currentIndex()==1)
        graphs = 0;
    if(ui->tabWidget->currentIndex()==2)
        graphs = 3;

    if(ui->tabWidget->currentIndex()==3) {
        ui->statusLogBluetooth->setChecked(((protocole->lastStatus)&(0x0800))!=0);
        ui->statusLogUSB->setChecked(((protocole->lastStatus)&(0x1000))!=0);
        ui->statusLogSD->setChecked(((protocole->lastStatus)&(0x0400))!=0);
    }

    if(graphs!=-1)
    for(int i=1+graphs;i<4+graphs;i++) {
        graph[i]->graph(0)->setData(*x[1],*y[i]);
        graph[i]->xAxis->setRange(x[1]->at(0),x[1]->last());
        graph[i]->replot();
    }
    if(graphs==0) {
        graph[0]->graph(0)->setData(*x[0],*y[0]);
        graph[0]->replot();
    }
}

/* Update_c allows to display the latest frames         */
/* in the console. It is called manually when clicking  */
/* on "Fetch frames". It can also be linked to a timer, */
/* but it isn't recommended                             */
void mainWindow::update_c() {
    ui->logConsole->setPlainText(str);

    str = "";
}


void mainWindow::applyLog() {
    QString usbStr = "#USB0000";
    usbStr += (ui->logUSB->isChecked()?"1":"0");
    QString bluStr = "#BLU0000";
    bluStr += (ui->logBluetooth->isChecked()?"1":"0");
    QString sdcStr = "#SDC0000";
    sdcStr += (ui->logToFileSD->isChecked()?"1":"0");

    protocole->send_str(usbStr.toLatin1().data());
    protocole->send_char('.');
    protocole->send_str(bluStr.toLatin1().data());
    protocole->send_char('.');
    protocole->send_str(sdcStr.toLatin1().data());
}


/* Restore session opens the session data file as       */
/* ReadOnly and updates every settings with the ones    */
/* stored in the filr                                   */
void mainWindow::restoreSession() {
    session->open(QIODevice::ReadOnly);
    QTextStream sessionLine(session);

    ui->fileName->setText(sessionLine.readLine());
    ui->logToFile->setChecked(((QString(sessionLine.readLine()) == "true") ? true : false));
    ui->appendDate->setChecked(((QString(sessionLine.readLine()) == "true") ? true : false));
    ui->cmdValue->setValue(sessionLine.readLine().toShort());
    protocole->port->setPortName(QString(sessionLine.readLine()));
    protocole->port->setBaudRate(sessionLine.readLine().toLong());
    protocole->port->setDataBits((QSerialPort::DataBits)sessionLine.readLine().toInt());
    protocole->port->setParity((QSerialPort::Parity)sessionLine.readLine().toShort());
    protocole->port->setStopBits((QSerialPort::StopBits)sessionLine.readLine().toShort());
    protocole->port->setFlowControl((QSerialPort::FlowControl)sessionLine.readLine().toShort());
    settings->setDefaults(protocole->port);
    logDirectory = sessionLine.readLine();
    session->close();
}

/* Save session opens the session data file as          */
/* WriteOnly and erases its content with the latest     */
/* configuration                                        */
void mainWindow::saveSession() {
    session->open(QIODevice::WriteOnly);
    QTextStream sessionLine(session);

    sessionLine << ui->fileName->text() << endl;
    sessionLine << (ui->logToFile->isChecked()?"true":"false") << endl;
    sessionLine << (ui->appendDate->isChecked()?"true":"false") << endl;
    sessionLine << (ui->cmdValue->value()) << endl;
    sessionLine << settings->settings().name << endl;
    sessionLine << settings->settings().baudRate << endl;
    sessionLine << settings->settings().dataBits << endl;
    sessionLine << settings->settings().parity << endl;
    sessionLine << settings->settings().stopBits << endl;
    sessionLine << settings->settings().flowControl << endl;
    sessionLine << logDirectory << endl;

    session->close();
}

void mainWindow::changeLogDirectory() {
    QDir dir("./");
    QString myDir = dir.relativeFilePath(QFileDialog::getExistingDirectory(this,
                                                tr("Open Log"), logDirectory));
    if(myDir.at(0)=='.'&&myDir.at(1)=='.') {
        qDebug() << myDir;
        myDir = dir.absoluteFilePath(myDir);
    }
    logDirectory = myDir;
    logMap->setMapping(ui->viewLog,logDirectory);
    saveSession();
}

/*  Simple function used to extract the date from       */
/*  a frame                                             */
/*  returns the time in seconds                         */
/*  Only works for the time, not the date               */
double getDate(QString date) {
    double hour = 0;
    double minute = 0;
    double sec = 0;
    double csec = 0;

    int inc = 1;


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

    return hour*3600+minute*60+sec*1+csec*.01;
}



/*  updateData is a Slot that can either be called      */
/*  periodically through a Timer, or directly from the  */
/*  Protocole's run function                            */
/*  It calls every update function in order to update   */
/*  the latest information gotten through the serial    */
/*  connection                                          */
void mainWindow::updateData() {
    // Getting the current date if needed for the log file
    QString date = QDateTime::currentDateTime().toString("_MM_dd_yyyy");

    // Opening a log file if required
    if(ui->logToFile->isChecked()) {
        // Adding the date to the name if needed
        if(ui->appendDate->isChecked())
            log = new QFile(ui->fileName->text()+date+".txt");
        else
            log = new QFile(ui->fileName->text()+".txt");

        // Always open as Append
        log->open(QIODevice::Append);
    }

    QDateTime d = QDateTime::currentDateTime();
    // Updating the different datas
    updateYAxis(protocole->lastValue[5]);
    updateXAxis(protocole->lastValue[4],/*d.toMSecsSinceEpoch());//*/getDate(protocole->lastString));
    updateTimeGraph(protocole->lastValue[6],3);
    for(int i=4;i<7;i++)
        updateTimeGraph(protocole->lastValue[i-3],i);

    updateTimeGraph(600-protocole->lastValue[7],7);

    updateConsole(protocole->lastString);

    // Logging to the file
    if(ui->logToFile->isChecked())
        log->write(protocole->lastString.toLatin1()+"\n");


    // Closing the file if it had been opened
    if(ui->logToFile->isChecked())
        log->close();
}


/*  Sends a command through the UART                    */
void mainWindow::sendCommand(QString cmd) {
    protocole->send_str(QString("#"+cmd).toLatin1());
    qDebug() << QString("#"+cmd).toLatin1();
}

/*  Sends a command through the UART using the cmdValue */
void mainWindow::sendCommandBox(QString cmd) {
    QString number = QString("%1").arg(ui->cmdValue->value(), 5, 10, QChar('0'));
    sendCommand(QString(cmd+number));
}

void mainWindow::sendCustomCommand() {
    sendCommand(ui->cmdCustom->text());
}

/*  Getting the system time and sending it to the RTC   */
void mainWindow::getSysTime() {
    QDateTime now = QDateTime::currentDateTime();
    ui->RTCYear->setValue(now.date().toString("yy").toInt());
    ui->RTCMonth->setValue(now.date().toString("MM").toInt());
    ui->RTCDay->setValue(now.date().toString("dd").toInt());
    ui->RTCHour->setValue(now.time().toString("hh").toInt());
    ui->RTCMinute->setValue(now.time().toString("mm").toInt());
    ui->RTCSecond->setValue(now.time().toString("ss").toInt());
    sendRTCTime();
}

/*  Getting the latest RTC time received in order to see*/
/*  if it needs to be synced again                      */
void mainWindow::getRTCTime() {
    QString now = protocole->lastString;
    ui->RTCYear->setValue(now.mid(3,2).toInt());
    ui->RTCMonth->setValue(now.mid(5,2).toInt());
    ui->RTCDay->setValue(now.mid(7,2).toInt());
    ui->RTCHour->setValue(now.mid(9,2).toInt());
    ui->RTCMinute->setValue(now.mid(11,2).toInt());
    ui->RTCSecond->setValue(now.mid(13,2).toInt());
}

/*  Sending the time to the RTC                         */
void mainWindow::sendRTCTime() {
    sendCommand("YRS"+QString("%1").arg(ui->RTCYear->value(), 5, 10, QChar('0')));
    protocole->send_char('.');
    sendCommand("MTH"+QString("%1").arg(ui->RTCMonth->value(), 5, 10, QChar('0')));
    protocole->send_char('.');
    sendCommand("DYS"+QString("%1").arg(ui->RTCDay->value(), 5, 10, QChar('0')));
    protocole->send_char('.');
    sendCommand("HRS"+QString("%1").arg(ui->RTCHour->value(), 5, 10, QChar('0')));
    protocole->send_char('.');
    sendCommand("MNS"+QString("%1").arg(ui->RTCMinute->value(), 5, 10, QChar('0')));
    protocole->send_char('.');
    sendCommand("SEC"+QString("%1").arg(ui->RTCSecond->value(), 5, 10, QChar('0')));
    protocole->send_char('.');
}


/*  This function update the values related to the      */
/*  accelerometer's X Axis (X graph, XY graph)          */
void mainWindow::updateXAxis(double value, double time) {
    static int sinceLastOvershoot = 100;
    static int overshootCounter = 0;
    static double lastValue = 0;

    if(abs(value-lastValue)>1000) {
        overshootCounter++;
        sinceLastOvershoot = 0;
    }

    sinceLastOvershoot++;
    if(sinceLastOvershoot > 10) {
        overshootCounter = 0;
    }

    if(overshootCounter >= 25) {
        qDebug() << "Instability on X axis detected";
    }

    lastValue = value;

    // Remove the first value from X graph
    (*y[1]).remove(0,1);
    // Append the new value at the end of X graph
    (*y[1]).append(value);

    // Remove both points from XY graph
    (*x[0]).remove(0,2);
    // Append the new value to both points in XY graph
    (*x[0]).append(value);
    (*x[0]).append(value);

    // Remove the first date
    (*x[1]).remove(0,1);
    // Append the new date to the end
    (*x[1]).append(time);
}

/*  This function update the values related to the      */
/*  accelerometer's Y Axis (Y graph, XY graph)          */
void mainWindow::updateYAxis(double value) {
    static int sinceLastOvershoot = 100;
    static int overshootCounter = 0;
    static double lastValue = 0;

    if(abs(value-lastValue)>1000) {
        overshootCounter++;
        sinceLastOvershoot = 0;
    }

    sinceLastOvershoot++;
    if(sinceLastOvershoot > 10) {
        overshootCounter = 0;
    }

    lastValue = value;

    if(overshootCounter >= 25) {
        qDebug() << "Instability on Y axis detected";
    }


    // Remove first value from Y graph
    (*y[2]).remove(0,1);
    // Append new value to the end of Y graph
    (*y[2]).append(value);

    // Remove both points from XY graph
    (*y[0]).remove(0,2);
    // Append the new value to both points in XY graph
    (*y[0]).append(value);
    (*y[0]).append(value);
}



/*  This function update the values stored in the graph */
/*  'graph'                                             */
void mainWindow::updateTimeGraph(double value, int graph) {
    // Remove first value from Y graph
    (*y[graph]).remove(0,1);
    // Append new value to the end of Y graph
    (*y[graph]).append(value);
}



/*  This function updates the console display with the  */
/*  last received string.                               */
void mainWindow::updateConsole(QString new_str) {
    if(str!="")
        str.append("\n\n");
    str.append(new_str);
}


/*  OpenSerialPort allows the user to connect to the    */
/*  port whose settings were defined in the setting     */
/*  dialog                                              */
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
        ui->actionConnect->setEnabled(false);
        ui->actionDisconnect->setEnabled(true);
        ui->actionConfigure->setEnabled(false);
    } else {
        QMessageBox::critical(this, tr("Error"), protocole->port->errorString());
    }

    if(protocole->port->isOpen()) {
        guiUpdate->start();
        serialFetch->start();
    }
}

/*  CloseSerialPort closes a currently open port        */
void mainWindow::closeSerialPort()
{
    guiUpdate->stop();
    serialFetch->stop();

    if (protocole->port->isOpen())
        protocole->port->close();
    ui->actionConnect->setEnabled(true);
    ui->actionDisconnect->setEnabled(false);
    ui->actionConfigure->setEnabled(true);
}
