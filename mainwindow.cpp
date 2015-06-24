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
    ui->setupUi(this);

    ui->tabWidget->setCurrentIndex(0);


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

    initActionsConnections();

    // Creating all the commands button
    QSignalMapper * cmdMap = new QSignalMapper(this);

    connect(ui->cmdStop,SIGNAL(clicked()),cmdMap,SLOT(map()));
    connect(ui->cmdStart,SIGNAL(clicked()),cmdMap,SLOT(map()));
    connect(ui->cmdBurst,SIGNAL(clicked()),cmdMap,SLOT(map()));
    connect(ui->cmdStream,SIGNAL(clicked()),cmdMap,SLOT(map()));
    cmdMap -> setMapping (ui->cmdStop, "STO") ;
    cmdMap -> setMapping (ui->cmdStart, "STA") ;
    cmdMap -> setMapping (ui->cmdBurst, "BST") ;
    cmdMap -> setMapping (ui->cmdStream, "STR") ;
    connect(cmdMap,SIGNAL(mapped(QString)),this,SLOT(sendCommandBox(QString)));


    connect(ui->sendTime,SIGNAL(clicked()),this,SLOT(sendRTCTime()));
    connect(ui->getTime,SIGNAL(clicked()),this,SLOT(getRTCTime()));
    connect(ui->syncSysTime,SIGNAL(clicked()),this,SLOT(getSysTime()));


    // Creating graphs instances
    graph[0] = ui->graphXAxis;
    graph[1] = ui->graphYAxis;
    graph[2] = ui->graphXY;

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
    graph[0]->yAxis->setLabel("X");
    graph[0]->yAxis->setRange(-10000,10000);
    // The X Axis should display time (text)
    graph[0]->setLocale(QLocale(QLocale::English, QLocale::Canada));
    graph[0]->xAxis->setTickLabelType(QCPAxis::ltDateTime);
    graph[0]->xAxis->setDateTimeFormat("hh:mm:ss");
    graph[0]->xAxis->setDateTimeSpec(Qt::OffsetFromUTC);
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
    graph[1]->yAxis->setLabel("Y");
    graph[1]->yAxis->setRange(-10000,10000);
    // The X Axis should display time (text)
    graph[1]->setLocale(QLocale(QLocale::English, QLocale::Canada));
    graph[1]->xAxis->setTickLabelType(QCPAxis::ltDateTime);
    graph[1]->xAxis->setDateTimeFormat("hh:mm:ss");
    graph[1]->xAxis->setDateTimeSpec(Qt::OffsetFromUTC);
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
    graph[2]->xAxis->setLabel("X");
    graph[2]->yAxis->setLabel("Y");
    graph[2]->xAxis->setRange(-10000,10000);
    graph[2]->yAxis->setRange(-10000,10000);
    // Activating the zoom and drag interraction in vertical and horizontal mode
    graph[2]->setInteraction(QCP::iRangeDrag, true);
    graph[2]->setInteraction(QCP::iRangeZoom, true);


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
    if(ui->logToFile->isChecked()) {
        // Adding the date to the name if needed
        if(ui->appendDate->isChecked())
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
        for(int i=0; i<8&&lastString<protocole->strings.size()&&lastString<protocole->values[protocole->nbValues-1].size(); i++) {
            time = getDate(protocole->strings.at(lastString));
            updateYAxis(protocole->values[5].at(lastString));
            updateXAxis(protocole->values[4].at(lastString),0);
            updateConsole(protocole->strings.at(lastString++));
            if(ui->logToFile->isChecked())
            log->write(protocole->strings.at(lastString).toLatin1()+"\n");
        }

        if(protocole->strings.size()>4096) {
            for (int i = 0; i < lastString; i++) {
                for(int j=0; j<protocole->nbValues;j++)
                 protocole->values[j].removeFirst();
                protocole->strings.removeFirst();
            }
            lastString = 0;
        }
    }
#else
    // If using fixed length (recommended), simply update with
    // the last value available (updateData called from the Protocole's run)
    updateYAxis(protocole->lastValue[5]);
    updateXAxis(protocole->lastValue[4],getDate(protocole->lastString));
    updateConsole(protocole->lastString);

    if(ui->logToFile->isChecked())
    log->write(protocole->lastString.toLatin1()+"\n");
#endif

    // Closing the file if it had been opened
    if(ui->logToFile->isChecked())
    log->close();
}


/*  Sends a command through the UART                */
void mainWindow::sendCommand(QString cmd) {
    protocole->send_str(QString("#"+cmd).toLatin1());
    qDebug() << QString("#"+cmd).toLatin1();
}

void mainWindow::sendCommandBox(QString cmd) {
    QString number = QString("%1").arg(ui->cmdValue->value(), 5, 10, QChar('0'));
    sendCommand(QString(cmd+number));
}

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
void mainWindow::getRTCTime() {
    QString now = protocole->lastString;
    ui->RTCYear->setValue(now.mid(3,2).toInt());
    ui->RTCMonth->setValue(now.mid(5,2).toInt());
    ui->RTCDay->setValue(now.mid(7,2).toInt());
    ui->RTCHour->setValue(now.mid(9,2).toInt());
    ui->RTCMinute->setValue(now.mid(11,2).toInt());
    ui->RTCSecond->setValue(now.mid(13,2).toInt());
}
void mainWindow::sendRTCTime() {
    sendCommand("YRS"+QString("%1").arg(ui->RTCYear->value(), 5, 10, QChar('0')));
    sendCommand("MTH"+QString("%1").arg(ui->RTCMonth->value(), 5, 10, QChar('0')));
    sendCommand("DYS"+QString("%1").arg(ui->RTCDay->value(), 5, 10, QChar('0')));
    sendCommand("HRS"+QString("%1").arg(ui->RTCHour->value(), 5, 10, QChar('0')));
    sendCommand("MNS"+QString("%1").arg(ui->RTCMinute->value(), 5, 10, QChar('0')));
    sendCommand("SEC"+QString("%1").arg(ui->RTCSecond->value(), 5, 10, QChar('0')));
}

/*  Serial port buttons connects                    */
void mainWindow::initActionsConnections()
{
    connect(ui->actionConnect, SIGNAL(clicked()), this, SLOT(openSerialPort()));
    connect(ui->actionDisconnect, SIGNAL(clicked()), this, SLOT(closeSerialPort()));
    connect(ui->actionConfigure, SIGNAL(clicked()), settings, SLOT(show()));
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
    refresh = (refresh+1)%1;

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
    refresh = (refresh+1)%1;
}

/*  This function updates the console display with  */
/*  the last received string. Every 2000 lines, the */
/*  console is cleared to avoid overcharging        */
void mainWindow::updateConsole(QString str) {
    static int log = 0;

    ui->logConsole->append(str+"\n");

    if(!log) {
        ui->logConsole->clear();
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
        ui->actionConnect->setEnabled(false);
        ui->actionDisconnect->setEnabled(true);
        ui->actionConfigure->setEnabled(false);
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
    ui->actionConnect->setEnabled(true);
    ui->actionDisconnect->setEnabled(false);
    ui->actionConfigure->setEnabled(true);
}
