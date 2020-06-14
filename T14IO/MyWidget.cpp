#include "MyWidget.h"
#include <QApplication>
#include <QFile>
#include <QBuffer>
#include <QDebug>
#include <QLabel>
#include <QTextStream>
#include <QDataStream>

MyWidget::MyWidget(QWidget *parent) : QWidget(parent)
{
    // QFile
    QFile file("../../IO.txt");
    file.open(QIODevice::ReadWrite);
    file.write("This is a test text");
    file.close();
    // QByteArray
    QString str("你好");
    QByteArray ba("你好");
    qDebug() << str.size() << ba.size();
    // QBuffer
    QBuffer buffer;
    buffer.open(QIODevice::ReadWrite);
    buffer.write("Hello World");
    buffer.close();
    qDebug() << buffer.buffer();
    // 模拟发送
    QBuffer buffer2;
    buffer2.open(QIODevice::ReadWrite);
    QPixmap pixmap("../../IO.jpg");
    pixmap.save(&buffer2, "JPG");
    buffer2.close();
    QPixmap pixmap2;
    pixmap2.loadFromData(buffer2.buffer());

    QLabel* label = new QLabel(this);
    label->setPixmap(pixmap2);

    qDebug() << buffer2.buffer().size();

    // QTextStream
    QFile file2("../../IO.txt");
    file2.open(QIODevice::ReadWrite);
    QTextStream testStream(&file2);
    testStream << 1 << "abc" << 2;

    // QDataStream
    QDataStream dataStream(&file2);
    dataStream << 1 << "abc" << 1.2 << QString("abc") << QPoint(1, 1);
    file2.close();

    // read
    QFile file3("../../IO.txt");
    file3.open(QIODevice::ReadWrite);
    QDataStream dataStream2(&file3);
    int i;
    char* buf;
    double d;
    QString str2;
    QPoint pt;

    dataStream2 >> i >> buf >> d >> str2 >> pt;

    qDebug() << i << buf << d << str2 << pt;
    file3.close();

    // virtual memory

}

int main(int args, char** argv)
{
    QApplication app(args, argv);

    MyWidget w;
    w.show();

    app.exec();
}
