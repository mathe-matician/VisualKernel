#ifndef IMAGE_H
#define IMAGE_H
#include <QString>
#include <QPixmap>

class Image
{
    QString m_fileName;
    QPixmap m_pixMap;
    int m_height;
    int m_width;

public:
    Image();
    Image(QString a_fileName);

private:
    QPixmap GetPixMap(QString a_fileName);
    void GetHeight();
    void GetWidth();
    template <typename T> void Resize(const T a_width, const T a_height);
};

#endif // IMAGE_H
