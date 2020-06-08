#ifndef MYWIDGET_H
#define MYWIDGET_H

#include "MyButton.h"
#include <QWidget>

class MyWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MyWidget(QWidget *parent = 0);

    void paintEvent(QPaintEvent *event);

    void mousePressEvent(QMouseEvent *event);

    void mouseMoveEvent(QMouseEvent *event);

    void mouseReleaseEvent(QMouseEvent *event);

    QVector<QVector<QPoint>> _lines;

    MyButton* button;
signals:

public slots:
     void slotButtonClicked();
};

#endif // MYWIDGET_H
