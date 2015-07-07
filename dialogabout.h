#ifndef MYDIALOG_H
#define MYDIALOG_H

#include <QDialog>

namespace Ui {
class DialogAbout;
}

class DialogAbout : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAbout(QWidget *parent = 0);
    ~DialogAbout();

private slots:

    void on_pushButton_clicked();

    void on_textEdit_textChanged();

private:
    Ui::DialogAbout *ui;
};

#endif // DialogAbout_H
