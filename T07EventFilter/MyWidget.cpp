#include "MyWidget.h"
#include "MyApplication.h"
#include <QPushButton>
#include <QEvent>
#include <QDebug>

MyWidget::MyWidget(QWidget *parent) : QWidget(parent)
{
    QPushButton* button;
    button = new QPushButton("Close", this);
    connect(button, SIGNAL(clicked(bool)), this, SLOT(close()));
    _button = button;
    // 给button安装消息过滤器,过滤button的所有消息
    button->installEventFilter(this);
}

bool MyWidget::event(QEvent *event)
{
    if (event->type() == QEvent::User)
    {
        qDebug() << "revive event from application";
    }
    return QWidget::event(event);
}

bool MyWidget::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == (QObject*)_button && event->type() == QEvent::MouseButtonPress ||
            event->type() == QEvent::MouseButtonDblClick ||
            event->type() == QEvent::MouseButtonRelease)
    {
        return true;
    }
    return QWidget::eventFilter(watched, event);
}

int main(int argc, char* argv[])
{
   MyApplication app(argc, argv);
   MyWidget w;
   w.show();

   // 发送一个Event消息给Widget
   app.postEvent(&w, new QEvent(QEvent::User));

   return app.exec();
}
