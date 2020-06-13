#ifndef MYDIALOG_H
#define MYDIALOG_H

#include <QDialog>

class MyDialog : public QDialog
{
    Q_OBJECT
public:
    explicit MyDialog(QWidget *parent = 0);

signals:

public slots:
    void slotButtonClick();
};

#endif // MYDIALOG_H
