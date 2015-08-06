#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialogabout.h"
#include "dialogloadsettings.h"
#include "dialogsavesettings.h"
//following QStatusBartutorial
#include <QtGui>
#include <QtCore>
#include <QtWidgets>
//including the process to link to external source
#include <qprocess.h>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QFileDialog>
#include <QApplication>
#include <QTabWidget>
#include <visa.h> // include VISA header file

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionAbout_triggered()
{
    dia_about = new DialogAbout(this);
    dia_about->show();
}

void MainWindow::on_actionLoad_Settings_triggered()
{
    //copy and paste from ORC project
    QString pathplusfilename=QFileDialog::getOpenFileName(
                this,
                tr("Open File"),
                "C://",
                "All files (*.*)"
                );

    QFile myfile(pathplusfilename); // connect the file in disk to the memory block allocated for myfile
    char firstSetting[128]; char secondSetting[128]; char thirdSetting[128]; char fourthSetting[128];
    if (myfile.open(QFile::ReadOnly)){

        // read the first line to a variable called firstSettings
        qint64 lineLength = myfile.readLine(firstSetting,30);
        if (lineLength != -1) ui->lineEdit->setText(firstSetting);

        lineLength = myfile.readLine(secondSetting,30);
        if (lineLength != -1) ui->lineEdit_2->setText(secondSetting);

        lineLength = myfile.readLine(thirdSetting,40);
        if (lineLength != -1) ui->lineEdit_3->setText(thirdSetting);

        lineLength = myfile.readLine(fourthSetting,40);
        if (lineLength != -1) ui->lineEdit_4->setText(fourthSetting);

    }
}
void MainWindow::on_actionSave_Settings_triggered()
{
    QString filename=QFileDialog::getSaveFileName(this, tr("Save File"), "C://", "All files (*.*)");

    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) return;
    QTextStream out(&file);

    QString setting1 = ui->lineEdit->text();
    out << setting1 << "\n";

    QString setting2 = ui->lineEdit_2->text();
    out << setting2 << "\n";

    QString setting3 = ui->lineEdit_3->text();
    out << setting3 << "\n";

    QString setting4 = ui->lineEdit_4->text();
    out << setting4 << "\n";
}

//Agilent VISA User's Guide
void MainWindow::on_actionLink_1_triggered()
{
    QProcess *process = new QProcess(this);
    QString command = "C:/Program Files (x86)/Mozilla Firefox/firefox.exe";
    QStringList args;
    args<<"http://cp.literature.agilent.com/litweb/pdf/5188-5798.pdf";
    process->start(command, args);
}

//Oscilloscope user's guide
void MainWindow::on_actionDigital_Oscilloscope_User_s_Guide_triggered()
{
    QProcess *process = new QProcess(this);
    QString command = "C:/Program Files (x86)/Mozilla Firefox/firefox.exe";
    QStringList args;
    args<<"http://www.berkeleynucleonics.com/resources/Scope_Manual.pdf";
    process->start(command, args);
}

//UltraSigma User's Guide
void MainWindow::on_actionUltraSigma_User_s_Guide_triggered()
{
    QProcess *process = new QProcess(this);
    QString command = "C:/Program Files (x86)/Mozilla Firefox/firefox.exe";
    QStringList args;
    args<<"Need address here";
    process->start(command, args);
}

void MainWindow::on_actionConnect_triggered()
{
    // open resource manager
    ViStatus stat = viOpenDefaultRM(&rscmng);

    // search for the oscilloscope
    ViChar viFound[VI_FIND_BUFLEN];
    ViUInt32 nFound;
    ViFindList listOfFound;
    stat = viFindRsrc(rscmng, (ViString)"USB?*", &listOfFound, &nFound, viFound);
    qDebug()<<stat;

    if (stat!=0) {
        ui->statusBar->showMessage("Please connect scope to PC");
        viClose(rscmng);
        return;
    }
    qDebug()<<nFound;

    if (nFound==0) {
        ui->statusBar->showMessage("No scope found");
        viClose(rscmng);
        return;
    } else if (nFound>1) {
        ui->statusBar->showMessage("More than 1 scopes found");
        viClose(rscmng);
        return;
    }
    qDebug()<<viFound;

    // connect to the oscilloscope
    ViUInt32 openTimeout=1000;
    stat = viOpen(rscmng, viFound, VI_NULL, openTimeout, &osc);
    if (stat!=0) return;

    viSetAttribute(osc, VI_ATTR_TMO_VALUE, 1);//set timeout value

    char buf[256] = {0};

    // communicate
    viPrintf(osc, (ViString)"*IDN?\n");
    viScanf(osc,(ViString)"%t",&buf);
    ui->statusBar->showMessage(buf);

    viPrintf(osc, (ViString)":WAV:DATA?");
    viScanf(osc,(ViString)"%t",&buf);
    ui->lineEdit->setText(buf);
   }

void MainWindow::on_actionDisconnect_triggered()
{
    // close VI sessions
    viClose(osc);
    viClose(rscmng);
}

void MainWindow::on_Run_clicked()
{
    // Run
    viPrintf(osc, (ViString)":RUN\n");
}

void MainWindow::on_Stop_clicked()
{
    // Stop
    viPrintf(osc, (ViString)":STOP\n");
}

void MainWindow::on_ReadSettings_clicked()
{
    char buf[256] = {0};

    // Operation Complete
    viPrintf(osc, (ViString)"*OPC?\n");
    viScanf(osc,(ViString)"%t",&buf);

    // Get x axis units; :TIMebase[:MAIN]:SCALe?
    viPrintf(osc, (ViString)":tim:scal?\n");
    viScanf(osc,(ViString)"%t", &buf);
    ui->lineEdit->setText(buf);

    // Get y axis scale maybe; :CHANnel<n>:SCALe?
    viPrintf(osc, (ViString)":CHANnel1:SCALe?\n");
    viScanf(osc, (ViString)"%t", &buf);
    ui->lineEdit_2->setText(buf);

    // Get Offset; :TIMebase[:MAIN]:OFFSet?
    viPrintf(osc, (ViString)":tim:pos?\n");
    viScanf(osc, (ViString)"%t", &buf);
    ui->lineEdit_3->setText(buf);

    // Timebase:HREF:MODE?
    viPrintf(osc, (ViString)":TIMebase:RANGe?\n");
    viScanf(osc, (ViString)"%t", &buf);
    ui->lineEdit_4->setText(buf);
}





