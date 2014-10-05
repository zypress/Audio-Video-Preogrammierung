
#include "ui_mainwindow.h"
#include "fenster.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->button, SIGNAL(clicked()), this, SLOT(openSecondWindow()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openSecondWindow()
{
    Fenster *f = new Fenster();
    f->show();
}
