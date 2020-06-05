// 应用程序抽象类
#include <QApplication>
// 窗口抽象类
#include <QWidget>
// 输入框抽象类
#include <QLineEdit>
#include <QCompleter>

int main(int argc, char* argv[]) {

    QApplication app(argc, argv);
    // 构造窗口对象
    QWidget w;
    // 构造文本框对象
    QLineEdit edit;
    edit.setParent(&w);
//    edit.setEchoMode(QLineEdit::PasswordEchoOnEdit);
    edit.setPlaceholderText("请输入姓名");
    // 获取内容
//    edit.text();
    // 自动提示
    QCompleter completer(QStringList() << "Tom" << "Jack" << "Dick");
    // 匹配模式:包含
    completer.setFilterMode(Qt::MatchContains);
    edit.setCompleter(&completer);
    // 设置窗口标题
    w.setWindowTitle("Hello World");
    // 显示窗口
    w.show();

    // QT对C++的拓展(信号(事件)->槽(事件对应方法))
    // std::bind -> std::function
    // QObject::connect(&button, SIGNAL(clicked()), &w, SLOT(close()));

    // exec()中包含一个消息系统
    return app.exec();
}
