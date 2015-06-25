#include "dialogabout.h"
#include "ui_dialogabout.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

DialogAbout::DialogAbout(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAbout)
{
    ui->setupUi(this);
    QFile file("C:\\Users\\eric.roach\\Documents\\roc\\LICENSE");
    if(!file.open(QIODevice::ReadOnly))
         QMessageBox::information(0,"info",file.errorString());

     QTextStream in(&file);

     ui->textBrowser->setText(in.readAll());

}

DialogAbout::~DialogAbout()
{
    delete ui;
}


void DialogAbout::on_pushButton_clicked()
{
    QFile file("C:\\Users\\eric.roach\\Documents\\roc\\LICENSE");
    if(!file.open(QIODevice::ReadOnly))
         QMessageBox::information(0,"info",file.errorString());

     QTextStream in(&file);

     ui->textBrowser->setText(in.readAll());
}
