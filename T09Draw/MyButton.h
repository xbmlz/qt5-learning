#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QWidget>

class MyButton : public QWidget
{
    Q_OBJECT
public:
    explicit MyButton(QWidget *parent = 0);

    MyButton(const QString& text, QWidget* parent = 0);

    QRect _rect;

    QString _text;

    // 按钮是否按下
    bool _pressed;

    void paintEvent(QPaintEvent *);

    void mousePressEvent(QMouseEvent *);

    void mouseReleaseEvent(QMouseEvent *);

signals:
    void clicked();

public slots:
};

#endif // MYBUTTON_H
