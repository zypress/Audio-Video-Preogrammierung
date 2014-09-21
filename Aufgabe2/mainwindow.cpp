#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showMat(const Mat &mat){
    // convert Mat object to QImage object
    QImage image( mat.data, mat.cols, mat.rows, mat.step, QImage::Format_RGB888 );
    image = image.rgbSwapped();

    // convert QImage object to QPixmap object
    QPixmap pixmap = QPixmap::fromImage(image);

    // set QPixmap object for QLabel
    ui->imageLabel->setPixmap(pixmap);
}

void MainWindow::on_action_ffnen_triggered()

{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Image"), "F:/bilder/deviants/", tr("Image Files(*.png *.jpg *.bmp)"));
    Mat image(800, 600, CV_8UC3);
    showMat(cv::imread(fileName.QString::toStdString()));
}
