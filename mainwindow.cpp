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
//Change this to load media - so you can apply the kernel to images or video
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

    //set start up kernel as Identity
    ui->spinBox4->setValue(1);
}

//get all values in spinboxes in the UI, store in QVector, return QVector.
QVector<int> MainWindow::Kernel_Gather_Values()
{
    QVector<int> l_spinboxvalues;
    for (auto i : findChildren<QSpinBox*>())
        l_spinboxvalues.push_back(i->value());

    return l_spinboxvalues;
}

//gets all values in spinboxes
//iterates through all pre-set kernels
//if kernel exists, change label to tell user what it is
void MainWindow::KernelTypeCheck()
{
    QVector<int> l_kernel = Kernel_Gather_Values();
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

//test message box
void MainWindow::on_pushButton_clicked()
{
    QMessageBox::about(this, "TITLE", "MOTHER FUCKER GET THE FUCK OUT OF HERE!");
}
