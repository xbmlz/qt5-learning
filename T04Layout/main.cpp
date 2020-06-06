// 应用程序抽象类
#include <QApplication>
// 窗口抽象类
#include <QWidget>
// 按钮抽象类
#include <QPushButton>
#include <QLineEdit>

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>



int main(int argc, char* argv[]) {

    QApplication app(argc, argv);
    // 构造窗口对象
    QWidget w;
    // 设置窗口标题
    w.setWindowTitle("Hello World");

    // 构造按钮对象
    QPushButton button;
    button.setText("Clicked me");
    button.setParent(&w);

    // 构建输入框
    QLineEdit edit;
    edit.setParent(&w);

    // 构建布局
//    QVBoxLayout layout;
//    layout.addWidget(&button);
//    layout.addWidget(&edit);
//    layout.addStretch(1);

    QGridLayout layout;
    layout.addWidget(&button, 0, 0);
    layout.addWidget(&edit, 0, 1);

    // 显示窗口
    w.show();
    // 给窗口设置布局
    w.setLayout(&layout);

    // QT对C++的拓展(信号(事件)->槽(事件对应方法))
    // std::bind -> std::function
    QObject::connect(&button, SIGNAL(clicked()), &w, SLOT(close()));

    // exec()中包含一个消息系统
    return app.exec();
}
