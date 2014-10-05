#include "fenster.h"
#include "ui_fenster.h"

Fenster::Fenster(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Fenster)
{
    ui->setupUi(this);
}

Fenster::~Fenster()
{
    delete ui;
}
