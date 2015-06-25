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
//after tutorial for displaying file
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
//after "open file" dialog tutorial
#include <QFileDialog>

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

    //from a tutorial online
   //QFile file("C:\\Users\\eric.roach\\Documents\\roc");
   //if(!file.open(QIODevice::ReadOnly))
      //  QMessageBox::information(0,"info",file.errorString());

  //  QTextStream in(&file);

   // ui->textBrowser->setText(in.readAll());



    //string contentFromLICENSE;
   // ifstream inputfile("path/to/LICENSE");
//contestFromLICENSE<<inputfile;
//dia_about->tab(1)->SetContent(contestFromLICENSE);
}

void MainWindow::on_actionLoad_Settings_triggered()
{
    //dia_load = new DialogLoadSettings(this);
   // dia_load->show();
    //can have a dialog or can just open from the load settings itseself

      //a QMessage box can be used to show file name
        //see video QT C++ GUI Tutorial 24
    QString filename=QFileDialog::getOpenFileName(
                this,
                tr("Open File"),
                "C://",
                "All files (*.*)"
                );
}

void MainWindow::on_actionSave_Settings_triggered()
{
    dia_save = new DialogSaveSettings(this);
    dia_save->show();
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
