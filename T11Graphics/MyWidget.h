#ifndef MYWIDGET_H
#define MYWIDGET_H
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsLineItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsItemAnimation>
#include <QTimeLine>
#include <QPixmap>
#include <QPainter>

// 打印相关 需要在.pro文件添加 printsupport
#include <QPrinter>
#include <QPrintPreviewDialog>  // 打印预览
#include <QPrintDialog>         // 打印

#include <QTimer>

class MyWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MyWidget(QWidget *parent = 0);

    void paintEvent(QPaintEvent *event);

    void resizeEvent(QResizeEvent *event);

    void mousePressEvent(QMouseEvent *event);

    QGraphicsScene* _scene;  //data modal

    QGraphicsView* _view;   // show th data model

    QTimer* _timer;

signals:

public slots:
    void slotPaintRequested(QPrinter*);

    void slotTimeout();
};

#endif // MYWIDGET_H
