#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//Tutorial 25
#include <QtCore>
#include <QtGui>
#include <QLabel>
#include <QProgressBar>

class DialogAbout;
class DialogLoadSettings;
class DialogSaveSettings;

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

    void on_actionLoad_Settings_triggered();

    void on_actionSave_Settings_triggered();

    void on_actionLink_1_triggered();

    void on_actionDigital_Oscilloscope_User_s_Guide_triggered();

    void on_actionUltraSigma_User_s_Guide_triggered();

private:
    Ui::MainWindow *ui;
    DialogAbout *dia_about;
    DialogLoadSettings *dia_load;
    DialogSaveSettings *dia_save;

    //tutorial 25
    QLabel *Statlabel;
    QProgressBar *StatProgress;
};

#endif // MAINWINDOW_H
