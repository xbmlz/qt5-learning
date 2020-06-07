#include "MyWidget.h"
#include <QApplication>
#include <QPainter>

MyWidget::MyWidget(QWidget *parent) : QWidget(parent)
{

}

void MyWidget::paintEvent(QPaintEvent *event)
{
    // 提升效率
    QPixmap pixmap(size());
    pixmap.fill();
    QPainter p(&pixmap);

    // 设置画布原点
    p.translate(100, 100);
    // 高级变换
    QTransform transform;
    transform.translate(50, 50);
    p.setTransform(transform);
    // 消除锯齿
    p.setRenderHint(QPainter::Antialiasing);
    // 定义绘制的笔
    p.setPen(QPen(Qt::red, 2, Qt::DashDotLine));
    // 定义画刷
    p.setBrush(Qt::yellow);
    // 绘制线段
    p.drawLine(QPoint(0, 0), QPoint(100, 100));
    // 绘制圆
    p.drawEllipse(QPoint(100, 300), 50, 50);
    // 绘制文字
    p.drawText(QPoint(100, 200), "Hello World");
    p.end();
    p.begin(this);
    p.drawPixmap(0, 0, pixmap);
}

int main(int args, char* argv[])
{
    QApplication app(args, argv);

    MyWidget w;
    w.show();

    return app.exec();
}
