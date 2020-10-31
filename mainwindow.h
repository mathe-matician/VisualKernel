#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QFileDialog>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <QSpinBox>
#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_loadimage_clicked();

    void on_applykernel_clicked();

    void on_pushButton_clicked();
    QVector<int> Kernel_Gather_Values();

private:
    cv::Mat m_image;
    Ui::MainWindow *ui;
    void MainWindowStyleSheet();
    void SpinBoxInit();
    void KernelTypeCheck();
};
#endif // MAINWINDOW_H
