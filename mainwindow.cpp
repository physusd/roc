#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mydialog.h"
//following QStatusBartutorial
#include <QtGui>
#include <QTCore>


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
 mDialog = new MyDialog(this);
 mDialog->show();

 //after tutorial
 //ui->statusBar->showMessage("Progress");
}
