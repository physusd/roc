#ifndef DIALOGSAVESETTINGS_H
#define DIALOGSAVESETTINGS_H

#include <QDialog>

namespace Ui {
class DialogSaveSettings;
}

class DialogSaveSettings : public QDialog
{
    Q_OBJECT

public:
    explicit DialogSaveSettings(QWidget *parent = 0);
    ~DialogSaveSettings();

private:
    Ui::DialogSaveSettings *ui;
};

#endif // DIALOGSAVESETTINGS_H
