#ifndef DIALOGLOADSETTINGS_H
#define DIALOGLOADSETTINGS_H

#include <QDialog>

namespace Ui {
class DialogLoadSettings;
}

class DialogLoadSettings : public QDialog
{
    Q_OBJECT

public:
    explicit DialogLoadSettings(QWidget *parent = 0);
    ~DialogLoadSettings();

private:
    Ui::DialogLoadSettings *ui;
};

#endif // DIALOGLOADSETTINGS_H
