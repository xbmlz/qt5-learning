#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>

class MyWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MyWidget(QWidget *parent = 0);

    // widgets evnt handler
    bool event(QEvent *);

    // 鼠标按下
    void mousePressEvent(QMouseEvent *);
    // 鼠标弹起
    void mouseReleaseEvent(QMouseEvent *);
    // 鼠标移动
    void mouseMoveEvent(QMouseEvent *);
    // 鼠标双击
    // void mouseDoubleClickEvent(QMouseEvent *);
    // 键盘按下
    void keyPressEvent(QKeyEvent *);
    // 键盘弹起
    void keyReleaseEvent(QKeyEvent *);
signals:

public slots:
};

#endif // MYWIDGET_H
