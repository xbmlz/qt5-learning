#include "MyButton.h"
#include <QPainter>
#include <QDebug>
#include <QMouseEvent>

MyButton::MyButton(QWidget *parent) : QWidget(parent), _rect(0, 0, 100, 30)
{
    this->setGeometry(_rect);
}

MyButton::MyButton(const QString &text, QWidget *parent) :
    QWidget(parent), _text(text), _rect(0, 0, 100, 30)
{
    this->setGeometry(_rect);
}

void MyButton::mousePressEvent(QMouseEvent *)
{
    _pressed = true;
    update();
}

void MyButton::mouseReleaseEvent(QMouseEvent *e)
{
    _pressed = false;
    update();
    // callback handler
    // 只有鼠标在button内按下才会激活clicked
    if (_rect.contains(e->pos()))
        emit clicked();
}

void MyButton::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    if (_pressed)
        p.setBrush(Qt::blue);
    else
        p.setBrush(Qt::gray);
    p.drawRect(_rect);
    p.drawText(_rect, _text, QTextOption(Qt::AlignCenter));
}
