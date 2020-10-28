#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_push1_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
          tr("Open Image"), ".",
          tr("Image Files (*.png *.jpg *.jpeg *.bmp)"));

    m_image = cv::imread(fileName.toStdString());
    cv::namedWindow("Original Image");
    cv::imshow("Original Image", m_image);
}

void MainWindow::on_push2_clicked()
{
    cv::flip(m_image, m_image,1);
    cv::namedWindow("Output Image");
    cv::imshow("Output Image", m_image);
}
