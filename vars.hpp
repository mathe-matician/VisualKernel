#ifndef MACROS_HPP
#define MACROS_HPP

#include <QVector>
#include <QString>
extern const QVector<int> VK_IDENTITY;
extern const QVector<int> VK_SHARPEN;
extern const QVector<int> VK_EDGE_DETECT1;
extern const QVector<int> VK_EDGE_DETECT2;
extern const QVector<int> VK_EDGE_DETECT3;
extern const QVector<int> VK_BOX_BLUR;
extern const QVector<int> VK_GAUSSIAN_BLUR_3X3;
extern const QVector<int> VK_GAUSSIAN_BLUR_5X5;
extern const QVector<QVector<int>> VK_KERNELS;

extern const QString Identity;
extern const QString Sharpen;
extern const QString Edge_Detect1;
extern const QString Edge_Detect2;
extern const QString Edge_Detect3;
extern const QString Box_Blur;
extern const QString Gaussian_Blur3x3;
extern const QString Gaussian_Blur5x5;
extern const QVector<QString> VK_KERNEL_NAMES;

#endif // MACROS_HPP
