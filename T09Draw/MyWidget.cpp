#include "MyWidget.h"
#include <QApplication>
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>

MyWidget::MyWidget(QWidget *parent) : QWidget(parent)
{
    button = new MyButton("MyButton", this);
    button->setGeometry(30, 30, 100, 30);
    connect(button, SIGNAL(clicked()), this, SLOT(slotButtonClicked()));
}

void MyWidget::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    for (int i = 0; i < _lines.size(); ++i)
    {
        const QVector<QPoint>& line = _lines.at(i);
        for (int j = 0; j < line.size() - 1; ++j)
        {
            p.drawLine(line.at(j), line.at(j + 1));
        }
    }
}

void MyWidget::mousePressEvent(QMouseEvent *e)
{
    QVector<QPoint> line;
    _lines.append(line);

    QVector<QPoint>& lastLine = _lines.last();
    lastLine.append(e->pos());
}

void MyWidget::mouseMoveEvent(QMouseEvent *e)
{
    if (_lines.size() == 0)
    {
        QVector<QPoint> line;
        _lines.append(line);
    }
    QVector<QPoint>& lastLine = _lines.last();
    lastLine.append(e->pos());

    update();
}

void MyWidget::mouseReleaseEvent(QMouseEvent *e)
{
    QVector<QPoint>& lastLine = _lines.last();
    lastLine.append(e->pos());
}


void MyWidget::slotButtonClicked()
{
    qDebug() << "button is clicked";
}

int main(int args, char* argv[])
{
    QApplication app(args, argv);

    MyWidget w;
    w.show();

    return app.exec();
}
