#include "normas.h"
#include "ui_normas.h"

Normas::Normas(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Normas)
{
    ui->setupUi(this);
    ui->label->setStyleSheet("QLabel{image: url(:/new/prefix1/imagenes/reglas1.PNG)}");
    ui->label_2->setStyleSheet("QLabel{image: url(:/new/prefix1/imagenes/reglas2.PNG)}");
}

Normas::~Normas()
{
    delete ui;
}
