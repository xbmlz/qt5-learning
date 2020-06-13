#include "MyMainWindow.h"
#include <QApplication>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include <QStatusBar>
#include <QAction>
#include <QKeySequence>
#include <QPainter>
#include <QMouseEvent>
#include <QCursor>
#include <QFileDialog>
#include <QDebug>
#include <QIcon>

MyMainWindow::MyMainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    // 添加菜单栏
    QMenuBar* pMenuBar = menuBar();
    QMenu* menu = pMenuBar->addMenu("File");
    _menu = menu;
    QAction* openAction = menu->addAction("Open", this, SLOT(slotOpen()), QKeySequence::Open);
    QAction* saveAction = menu->addAction("Save", this, SLOT(slotOpen()), QKeySequence::Save);
    menu->addSeparator();
    QAction* closeAction = menu->addAction("Exit", this, SLOT(close()), QKeySequence::Close);
    closeAction->setToolTip("close window");

    // toolbar
    QToolBar* pToolbar =  this->addToolBar("toolbar");
    pToolbar->addAction(openAction);
    pToolbar->addAction(saveAction);
    pToolbar->addAction(closeAction);

    // statusbar
    QStatusBar* pStatusBar = this->statusBar();
    pStatusBar->addWidget(_label = new QLabel("OK"));

    // 剩余区域
    _view = new MyView;
    this->setCentralWidget(_view);

    // 系统托盘
    _tray = new QSystemTrayIcon();
    _tray->setIcon(QIcon("../../qt32.ico"));
    _tray->setToolTip("this is system tray");
    _tray->show();
    // 右键菜单
    _tray->setContextMenu(_menu);
    connect(_tray, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(slotTrayActivated(QSystemTrayIcon::ActivationReason)));

    // install even filter
    this->installEventFilter(this);
}

void MyMainWindow::slotTrayActivated(QSystemTrayIcon::ActivationReason reason)
{
    if (reason == QSystemTrayIcon::Trigger)
    {
        if (this->isHidden()) this->show();
        else this->hide();
    }
}

void MyMainWindow::mousePressEvent(QMouseEvent *event)
{
    // 右键菜单
    if (event->button() == Qt::RightButton)
        // 鼠标当前位置QCursor::pos()
        _menu->exec(QCursor::pos());
}

bool MyMainWindow::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == (QObject*)this && event->type() == QEvent::Close)
    {
        return true;
    }
    return QMainWindow::eventFilter(watched, event);
}


bool MyMainWindow::event(QEvent *event)
{
    if (event->type() == QEvent::Close)
    {
        return true;
    }
    return QMainWindow::event(event);
}

void MyMainWindow::paintEvent(QPaintEvent *)
{

}

void MyMainWindow::slotOpen()
{
    QString fileName = QFileDialog::getOpenFileName();
    qDebug() << "Open file is :" << fileName;
}

int main(int args, char** argv)
{
    QApplication app(args, argv);

    MyMainWindow w;

    w.show();

    return app.exec();
}
