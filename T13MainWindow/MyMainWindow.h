#ifndef MYMAINWINDOW_H
#define MYMAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QLabel>
#include <QSystemTrayIcon>

#include "MyView.h"

class MyMainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MyMainWindow(QWidget *parent = 0);

    QLabel* _label;

    QMenu* _menu;

    MyView* _view;

    QSystemTrayIcon* _tray;

    bool event(QEvent *event);

    bool eventFilter(QObject *watched, QEvent *event);

    void paintEvent(QPaintEvent *event);

    void mousePressEvent(QMouseEvent *event);
signals:

public slots:
    void slotOpen();

    void slotTrayActivated(QSystemTrayIcon::ActivationReason reason);
};

#endif // MYMAINWINDOW_H
