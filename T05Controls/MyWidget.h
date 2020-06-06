#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>

class MyWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MyWidget(QWidget *parent = 0);

signals:

public slots:
    // 定义槽函数
    void slotComboBoxIndexChanged(const QString&);
};

#endif // MYWIDGET_H
