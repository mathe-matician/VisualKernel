#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace cv;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //MainWindow::setStyleSheet("background-color: yellow");
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


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
    //nothign yet
}
