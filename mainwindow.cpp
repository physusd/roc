#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialogabout.h"
#include "dialogloadsettings.h"
//following QStatusBartutorial
#include <QtGui>
#include <QtCore>
#include <QtWidgets>
//including the process to link to external source
#include <qprocess.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //After tutorial 25
    Statlabel = new QLabel(this);
    StatProgress = new QProgressBar(this);

    ui->statusBar->addPermanentWidget(Statlabel);
    ui->statusBar->addPermanentWidget(StatProgress,1);
    StatProgress->setTextVisible(false);

    Statlabel->setText("Progress");
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
    dia_load = new DialogLoadSettings(this);
    dia_load->show();
}

void MainWindow::on_actionSave_Settings_triggered()
{
    QMessageBox::information(this,"Save Settings","Text Here");
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
