#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mydialog.h"
//Tutorial 25
#include <QtCore>
#include <QtGui>
#include <QLabel>
#include <QProgressBar>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionAbout_triggered();

private:
    Ui::MainWindow *ui;
    MyDialog *mDialog;

    //tutorial 25
    QLabel *Statlabel;
    QProgressBar *StatProgress;
};

#endif // MAINWINDOW_H
