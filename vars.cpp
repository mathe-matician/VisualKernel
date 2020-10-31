#include "vars.hpp"
#include <QVector>

const QVector<int> VK_IDENTITY = {0, 0, 0, 0, 1, 0, 0, 0, 0};
const QVector<int> VK_SHARPEN = {-1, -1, -1, -1, 5, -1, -1, -1, -1};
const QVector<int> VK_EDGE_DETECT1 = {1, 0, -1, 0, 0, 0, -1, 0, 1};
const QVector<int> VK_EDGE_DETECT2 = {0, -1, 0, -1, 4, -1, 0, -1, 0};
const QVector<int> VK_EDGE_DETECT3 = {-1, -1, -1, -1, 8, -1, -1, -1, -1};
const QVector<int> VK_BOX_BLUR = {1, 1, 1, 1, 1, 1, 1, 1, 1}; // 1/9
const QVector<int> VK_GAUSSIAN_BLUR_3X3 = {1, 2, 1, 2, 4, 2, 1, 2, 1}; // 1/16
const QVector<int> VK_GAUSSIAN_BLUR_5x5 = {1, 4, 6, 4, 1, 4, 16, 24, 16, 4, 6, 24, 36, 24, 6, 4, 16, 24, 16, 4, 1, 4, 6, 4, 1}; // 1/256
const QVector<QVector<int>> VK_KERNELS = {VK_IDENTITY, VK_SHARPEN, VK_EDGE_DETECT1, VK_EDGE_DETECT2, VK_EDGE_DETECT3, VK_BOX_BLUR, VK_GAUSSIAN_BLUR_3X3, VK_GAUSSIAN_BLUR_5x5};

const QString Identity = "Identity";
const QString Sharpen = "Sharpen";
const QString Edge_Detect1 = "Edge Detect 1";
const QString Edge_Detect2 = "Edge Detect 2";
const QString Edge_Detect3 = "Edge Detect 3";
const QString Box_Blur = "Box Blur";
const QString Gaussian_Blur3x3 = "Gaussian Blur 3x3";
const QString Gaussian_Blur5x5 = "Gaussian Blur 5x5";
const QVector<QString> VK_KERNEL_NAMES = {Identity, Sharpen, Edge_Detect1, Edge_Detect2, Edge_Detect3, Box_Blur, Gaussian_Blur3x3, Gaussian_Blur5x5};
