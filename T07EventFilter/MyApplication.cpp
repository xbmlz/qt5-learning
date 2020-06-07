#include "MyApplication.h"
#include <QEvent>
#include <QDebug>

// 监听窗口事件
bool MyApplication::notify(QObject *o, QEvent *e)
{
    if (this->topLevelWidgets().count() > 0)
    {
        QWidget* mainWnd = this->topLevelWidgets().at(0);
        if (o == (QObject*) mainWnd && e->type() == QEvent::MouseButtonPress)
        {
            qDebug() << "main window is clicked";
        }
    }
    return QApplication::notify(o, e);
}
