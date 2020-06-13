#include "MyWidget.h"
#include <QApplication>
#include <QMouseEvent>
#include <QDebug>

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent)
{
    QGraphicsLineItem* lineItem;
    QGraphicsTextItem* textItem;

    _view = new QGraphicsView(this);
    _view->setScene(_scene = new QGraphicsScene);

    _scene->addItem(lineItem = new QGraphicsLineItem(QLineF(QPointF(0, 0), QPointF(100, 100))));
    _scene->addItem(textItem = new QGraphicsTextItem("Hello World"));
    textItem->setPos(QPointF(200, 300));
    textItem->setFont(QFont("微软雅黑", 30, 600));
    textItem->setDefaultTextColor(Qt::red);

    // animation
    QGraphicsItemAnimation* animation = new QGraphicsItemAnimation;
    animation->setItem(textItem);

    QTimeLine* timeLine = new QTimeLine(3000);
    timeLine->setLoopCount(1);

    animation->setTimeLine(timeLine);
    animation->setTranslationAt(1, 200, 200);

//    timeLine->start();
}

void MyWidget::paintEvent(QPaintEvent *event)
{

}

void MyWidget::resizeEvent(QResizeEvent *event)
{
    _view->setGeometry(QRect(QPoint(0, 0), size()));
}

void MyWidget::mousePressEvent(QMouseEvent *event)
{
    // 右键保存为图片
    if (event->button() == Qt::RightButton)
    {
        qDebug() << "right click";
        // 保存为图片
        QPixmap pixmap(size());
        QPainter painter(&pixmap);
        painter.fillRect(QRect(0, 0, size().width(), size().height()), Qt::white);
        _view->render(&painter);
        pixmap.save("./temp.png");
    }

    // shift + 鼠标左键
    if (event->modifiers() == Qt::ShiftModifier) {
        // 打印预览
        QPrintPreviewDialog dialog;
        connect(&dialog, SIGNAL(paintRequested(QPrinter*)), this, SLOT(slotPaintRequested(QPrinter*)));
        dialog.exec();

        // 打印
//        QPrintDialog dialog;
//        connect(&dialog, SIGNAL(accepted(QPainter*)), this, SLOT(slotPaintRequested(QPrinter*)));
//        dialog.exec();
    }

    // 定时器
    _timer = new QTimer();
    _timer->setInterval(1000); //每多少毫秒执行一次
    connect(_timer, SIGNAL(timeout()), this, SLOT(slotTimeout()));

    // _timer->start();

    // 只执行一次
    QTimer::singleShot(1000, this, SLOT(slotTimeout()));
}

void MyWidget::slotTimeout()
{
    qDebug() << "Timeout";
}

void MyWidget::slotPaintRequested(QPrinter *printer)
{
    QPainter painter(printer);
    _scene->render(&painter);
    // 打印FUCK
    painter.drawText(QPoint(100, 100), "FUCK");
}

/* QPixmap, QImage, QBitmap, QPicture */
int main(int args, char** argv)
{
    QApplication app(args, argv);

    MyWidget w;
    w.showMaximized();

    return app.exec();
}
