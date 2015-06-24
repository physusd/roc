#include "dialogsavesettings.h"
#include "ui_dialogsavesettings.h"

DialogSaveSettings::DialogSaveSettings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogSaveSettings)
{
    ui->setupUi(this);
}

DialogSaveSettings::~DialogSaveSettings()
{
    delete ui;
}
