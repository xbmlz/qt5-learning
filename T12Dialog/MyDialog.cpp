#include "MyDialog.h"
#include <QApplication>
#include <QPushButton>
#include <QDebug>
#include <QFileDialog>
#include <QFileInfo>
#include <QColorDialog>
#include <QFontDialog>
#include <QMessageBox>

MyDialog::MyDialog(QWidget *parent) :
    QDialog(parent)
{
    QPushButton* button = new QPushButton("Click me", this);
    connect(button, SIGNAL(clicked()), this, SLOT(slotButtonClick()));
}

void MyDialog::slotButtonClick()
{
    QDialog* dlg = new QDialog();
    // exec中的消息循环接管app.exec中的消息循环
    int ret;
    QPushButton* button = new QPushButton("Accepted", dlg);
    connect(button, SIGNAL(clicked()), dlg, SLOT(accept()));

    // 如果dialog是通过show()显示，可以通过close来关闭窗口
//    dlg->show();
    // 如果dilog是通过exec()显示，可以通过accept或者reject来关闭窗口
    ret = dlg->exec();
    if (ret == QDialog::Accepted)
    {
        qDebug() << "Accepted";
    }
    if (ret == QDialog::Rejected)
    {
        qDebug() << "Rejected";
    }

    // 保存选择
    QString fileName = QFileDialog::getSaveFileName(NULL, "Select file for save", _strDir, "Png file (*.png)");
    // 选择文件
    //QString fileName = QFileDialog::getOpenFileName(NULL, "Select file for save", _strDir, "Png file (*.png)");
    // 选择文件(多选)
    QStringList fileNames = QFileDialog::getOpenFileNames(NULL, "Select file for save", _strDir, "Png file (*.png)");
    // 选择目录
    QString dirName = QFileDialog::getExistingDirectory();
    if (fileName.isEmpty())
    {
        qDebug() << "Select none";
        return;
    }
    qDebug() << fileName;
    QFileInfo fileInfo(fileName);
    _strDir = fileInfo.filePath();

    // 颜色选择框
    QColorDialog colorDlg;
    colorDlg.exec();
    QColor color = colorDlg.selectedColor();

    // 字体选择框
    QFontDialog fontDlg;
    fontDlg.exec();
    QFont font = fontDlg.selectedFont();

    //提示框
    QMessageBox::information(this, "Info", "this a info message");
    QMessageBox::warning(this, "Warning", "this a warning message");
    QMessageBox::critical(this, "Critical", "this a critical message");

    // 询问框
    int ret = QMessageBox::question(this, "???", "realy", QMessageBox::Yes | QMessageBox::YesAll | QMessageBox::No);
    if (ret == QMessageBox::Yes)
    {
        qDebug() << "user select yes";
    }
    if (ret == QMessageBox::YesAll)
    {
       qDebug() << "user select yesall";
    }
    if (ret == QMessageBox::No)
    {
        qDebug() << "user select no";
    }

}

int main(int args, char** argv)
{
    QApplication app(args, argv);
    MyDialog dlg;
    dlg.show();

    return app.exec();
}
