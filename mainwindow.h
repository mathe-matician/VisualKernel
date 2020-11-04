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

    void on_actionIdentity_triggered();

    void on_actionSharpen_triggered();

    void on_actionEdge_Detect_1_triggered();

    void on_actionEdge_Detect_2_triggered();

    void on_actionEdge_Detect_3_triggered();

    void on_actionBox_Blur_triggered();

    void on_actionGaussian_Blur_3x3_triggered();

    void on_action5x5_triggered();

    void on_action3x3_triggered();

    void on_actionGaussian_Blur_5x5_triggered();

private:
    cv::Mat m_image;
    Ui::MainWindow *ui;
    void MainWindowStyleSheet();
    //void WidgetStyleSheet();
    void SpinBoxInit();
    void KernelTypeCheck();
    QVector<int> Kernel_Gather_Values_3X3();
    void SetSpinBoxKernel(const QVector<int> a_kernel);
    QRect GetScreenSize();
};
#endif // MAINWINDOW_H
