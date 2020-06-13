#ifndef MYVIEW_H
#define MYVIEW_H

#include <QWidget>

class MyView : public QWidget
{
    Q_OBJECT
public:
    explicit MyView(QWidget *parent = 0);

    void paintEvent(QPaintEvent *event);

signals:

public slots:
};

#endif // MYVIEW_H
