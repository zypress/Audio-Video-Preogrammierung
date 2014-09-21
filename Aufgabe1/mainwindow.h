#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <opencv2/opencv.hpp>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_kreise_clicked();

    void on_btn_zebra_clicked();

    void on_btn_schach_clicked();

    void on_btn_rndBunt_clicked();

    void on_btn_schachBunt_clicked();

private:
    void zebraImage();
    void showMat(const cv::Mat& mat);
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
