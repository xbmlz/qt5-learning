#include "MyWidget.h"
#include <QApplication>
#include <QEvent>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QDebug>

MyWidget::MyWidget(QWidget *parent) : QWidget(parent)
{
    // 鼠标不需要按下,就执行mouseMoveEvent
    this->setMouseTracking(true);
}
// QApplication -> event -> 具体的虚函数，通过重载具体的虚函数来实现对应消息的响应
// 截获所有widget消息
bool MyWidget::event(QEvent *e)
{
    return QWidget::event(e);
}

// 截获widget鼠标按下消息
void MyWidget::mousePressEvent(QMouseEvent *e)
{
    QPoint point = e->pos();
    qDebug() << point;
    if (e->button() == Qt::LeftButton) {

    }
    // shift + leftClick
    if (e->modifiers() == Qt::ShiftModifier)
    {
        qDebug() << "shift press";
    }
}

void MyWidget::mouseMoveEvent(QMouseEvent *e)
{
    qDebug() << "mouse move";
}

void MyWidget::mouseReleaseEvent(QMouseEvent *e)
{
    qDebug() << "mouse release";
}

void MyWidget::keyPressEvent(QKeyEvent *e)
{
    e->modifiers();
    int key = e->key();
    qDebug() << (char)key;
}

void MyWidget::keyReleaseEvent(QKeyEvent *e)
{}

int main(int argc, char* argv[])
{
   QApplication app(argc, argv);
   MyWidget w;
   w.show();

   return app.exec();
}
