#include "mainwindow.h"
#include "ui_mainwindow.h"
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

void MainWindow::zebraImage(){
    Scalar white = Scalar(255, 255, 255);

    Mat image(400, 400, CV_8UC3, white);

    Scalar black = Scalar(0, 0, 0);

   for (int i=0; i<400; i+=10) {
        if((i/10)%2==0){
       rectangle(image, Point(i,0), Point(i+10,400), black, CV_FILLED );
        }
    }

    showMat(image);
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


void MainWindow::on_btn_zebra_clicked()
{
    zebraImage();
}

void MainWindow::on_btn_schach_clicked()
{
    Scalar white = Scalar(255, 255, 255);

    Mat image(400, 400, CV_8UC3, white);

    Scalar black = Scalar(0, 0, 0);

   for (int i=0; i<400; i+=20) {
       for (int j = 0; j<400; j+=20) {
          if(((j+i)/20)%2!=0){
          rectangle(image, Point(i,j), Point(i+20,j+20), black, CV_FILLED );
          }
       }
    }

    showMat(image);
}

void MainWindow::on_kreise_clicked()
{
    Scalar white = Scalar(255, 255, 255);

    Mat image(400, 400, CV_8UC3, white);

    Scalar black = Scalar(0,0,0);

    for(int i=10; i<200; i+=20){
        circle(image, Point(200,200), i, black, 2);
    }

    showMat(image);
}

void MainWindow::on_btn_rndBunt_clicked()
{
    Scalar white = Scalar(255, 255, 255);

    Mat image(400, 400, CV_8UC3, white);

    for(int i=0; i<1000; i++){
        Scalar rnd_Color = Scalar(rand()%255,rand()%255,rand()%255);
        circle(image, Point(rand()%400,rand()%400), 10, rnd_Color, CV_FILLED );
    }

    showMat(image);
}

void MainWindow::on_btn_schachBunt_clicked()
{
   Scalar white = Scalar(255, 255, 255);

   Mat image(400, 400, CV_8UC3, white);

   Scalar black = Scalar(0,0,0);

   for (int i=0; i<400; i+=20) {
       for (int j = 0; j<400; j+=20) {
          Scalar rnd_Color = Scalar(rand()%255,rand()%255,rand()%255);
          rectangle(image, Point(i,j), Point(i+20,j+20), rnd_Color, CV_FILLED );
          rectangle(image, Point(i,j), Point(i+20,j+20), black, 1);
       }
    }
    showMat(image);
}
