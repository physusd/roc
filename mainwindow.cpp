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
#include <QApplication>
#include <QTabWidget>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //After tutorial 25
    Statlabel = new QLabel(this);
    StatProgress = new QProgressBar(this);

    //QWidget *settings = new QWidget(this);
    //QTextEdit *setting1 = new QTextEdit(this);
    //settings->addRow("setting1:",setting1);
    //this->setCentralWidget(settings);


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
                //centralWidget->findChild<QTabWidget*>("tabWidget")->widget(0)->findChild<QLineEdit*>("lineEdit")->setText(firstSetting);

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
    //dia_save = new DialogSaveSettings(this);
    //dia_save->show();

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
