#include "aboutit.h"
#include "ui_aboutit.h"

Aboutit::Aboutit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Aboutit)
{
    ui->setupUi(this);
}

Aboutit::~Aboutit()
{
    delete ui;
}
