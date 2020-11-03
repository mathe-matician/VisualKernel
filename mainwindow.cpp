#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "vars.hpp"
#include <QMessageBox>
#include <QSpinBox>
#include <QVector>
#include <algorithm>

using namespace cv;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    MainWindowStyleSheet();
    ui->setupUi(this);
    SpinBoxInit();
    KernelTypeCheck();
}

MainWindow::~MainWindow()
{
    delete ui;
}

//TODO:
//have a max&min size for screen resize to fit picture
void MainWindow::on_loadimage_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Image"), ".", tr("Image Files (*.png *.jpg *.jpeg *.bmp)"));

    //m_image = cv::imread(fileName.toStdString());

        //change opencv BGR to RGB
    //cv::cvtColor(m_image, m_image, COLOR_BGR2RGB);

    //TODO: error handling for null/empty file
     QPixmap pic(fileName);
     ui->imgbox->setPixmap(pic);
     ui->imgbox->resize(pic.size());

     MainWindow::resize(pic.width() + 292, pic.height() + 10);

        //cv::namedWindow("Original Image");
        //cv::imshow("Original Image", m_image);
}

void MainWindow::on_applykernel_clicked()
{
    //TODO:
    //Conversion from opencv BGR to RGB or vice-versa
    //Convert QVector Kernel_Gather_Values() to OpenCV::Mat - needed?
    //Apply kernel to img
    //display image again in label(conversion might be needed again)
    //     -"Destructive" vs applying to Copy

    //TODO:
    //make this into separate thread
    //can add progress bar when applying kernel on large image - signal and slot business
}

void MainWindow::MainWindowStyleSheet()
{
    //test stylesheet stuff
    MainWindow::setStyleSheet("background-color: yellow");
}

//set
void MainWindow::SpinBoxInit()
{
    for (auto i : findChildren<QSpinBox*>())
        i->setMinimum(-256);

    ui->stackedWidget->setCurrentIndex(1);

    for (auto i : findChildren<QSpinBox*>())
        i->setMinimum(-256);
    ui->stackedWidget->setCurrentIndex(0);

    //set start up kernel as Identity
    ui->spinBox4->setValue(1);
}

//TODO:
//add 3x3 or 5x5
//get all values in spinboxes in the UI, store in QVector, return QVector.
QVector<int> MainWindow::Kernel_Gather_Values_3X3()
{
    //iterative approach won't work with ui->stackedWidget->currentWidget()->findChildren<QSpinBox*>()??
    QVector<int> l_spinboxvalues;
    l_spinboxvalues.push_back(ui->spinBox0->value());
    l_spinboxvalues.push_back(ui->spinBox1->value());
    l_spinboxvalues.push_back(ui->spinBox2->value());
    l_spinboxvalues.push_back(ui->spinBox3->value());
    l_spinboxvalues.push_back(ui->spinBox4->value());
    l_spinboxvalues.push_back(ui->spinBox5->value());
    l_spinboxvalues.push_back(ui->spinBox6->value());
    l_spinboxvalues.push_back(ui->spinBox7->value());
    l_spinboxvalues.push_back(ui->spinBox8->value());

    return l_spinboxvalues;
}

void MainWindow::SetSpinBoxKernel(const QVector<int> a_kernel)
{

    //does not get the right values
//    int j = 0;
//    for (auto i : ui->stackedWidget->currentWidget()->findChildren<QSpinBox*>())
//    {
//        i->setValue(a_kernel[j++]);
//    }

    //gets ALL spin boxes, page 1 and page 2
//    int j = 0;
//    for (auto i : ui->stackedWidget->indexOf())
//    {
//        i->setValue(a_kernel[j++]);
//    }

    ui->spinBox0->setValue(a_kernel[0]);
    ui->spinBox1->setValue(a_kernel[1]);
    ui->spinBox2->setValue(a_kernel[2]);
    ui->spinBox3->setValue(a_kernel[3]);
    ui->spinBox4->setValue(a_kernel[4]);
    ui->spinBox5->setValue(a_kernel[5]);
    ui->spinBox6->setValue(a_kernel[6]);
    ui->spinBox7->setValue(a_kernel[7]);
    ui->spinBox8->setValue(a_kernel[8]);
}

//gets all values in spinboxes
//iterates through all pre-set kernels
//if kernel exists, change label to tell user what it is
void MainWindow::KernelTypeCheck()
{
    QVector<int> l_kernel = Kernel_Gather_Values_3X3();
    QString l_returnString = "";

    for (int i = 0; i < VK_KERNELS.length(); i++)
    {
        if (std::equal(VK_KERNELS[i].begin(), VK_KERNELS[i].end(), l_kernel.begin()))
        {
            l_returnString = VK_KERNEL_NAMES[i];
        }
    }

    ui->label_2->setText(l_returnString);
}

void MainWindow::on_actionIdentity_triggered()
{
    SetSpinBoxKernel(VK_IDENTITY);
    KernelTypeCheck();
}

void MainWindow::on_actionSharpen_triggered()
{
    SetSpinBoxKernel(VK_SHARPEN);
    KernelTypeCheck();
}

void MainWindow::on_actionEdge_Detect_1_triggered()
{
    SetSpinBoxKernel(VK_EDGE_DETECT1);
    KernelTypeCheck();
}

void MainWindow::on_actionEdge_Detect_2_triggered()
{
    SetSpinBoxKernel(VK_EDGE_DETECT2);
    KernelTypeCheck();
}

void MainWindow::on_actionEdge_Detect_3_triggered()
{
    SetSpinBoxKernel(VK_EDGE_DETECT3);
    KernelTypeCheck();
}

void MainWindow::on_actionBox_Blur_triggered()
{
    SetSpinBoxKernel(VK_BOX_BLUR);
    KernelTypeCheck();
}

void MainWindow::on_actionGaussian_Blur_3x3_triggered()
{
    SetSpinBoxKernel(VK_GAUSSIAN_BLUR_3X3);
    KernelTypeCheck();
}

void MainWindow::on_action5x5_triggered()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_action3x3_triggered()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_actionGaussian_Blur_5x5_triggered()
{
    if (!ui->stackedWidget->currentIndex())
        ui->stackedWidget->setCurrentIndex(1);

    //apply 5x5 kernel
}
