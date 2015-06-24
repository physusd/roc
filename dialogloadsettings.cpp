#include "dialogloadsettings.h"
#include "ui_dialogloadsettings.h"

DialogLoadSettings::DialogLoadSettings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogLoadSettings)
{
    ui->setupUi(this);
}

DialogLoadSettings::~DialogLoadSettings()
{
    delete ui;
}
