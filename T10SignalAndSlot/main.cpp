#include <QCoreApplication>
#include "MySignal.h"
#include "MySlot.h"

int main(int args, char** argv)
{
    QCoreApplication app(args, argv);

    // 1. 信号的定义必须在signals保留字下，不需要实现
    MySignal signal;
    // 2. 槽的定义必须在slots保留字下，需要实现
    MySlot slot;
    // 3. 信号和槽通过QObject::connect连接
    QObject::connect(&signal, SIGNAL(signal()), &slot, SLOT(slot()));
    // 4. 当信号被触发时，槽函数被调用
    emit signal.signal();

    // 1. 信号和槽是QT的拓展，实现信号和槽必须是QObject的子类
    // 2. 实现信号和槽的类，必须以宏Q_OBJECT开始
    // 3. 连接信号和槽，要用到SIGNAL和SLOT宏，将函数转换为字符串
    // 4. 一个信号可以和多个槽连接，槽函数调用的顺序是不确定的
    // 5. 多个信号可以同时连接同一个槽
    // 6. 信号可以连接多个信号，形成信号传导
    // 7. 信号和槽的参数应该一样多，而且类型必须相同
    // 8. 信号和槽都可以重载
    // 9. 信号和槽都可以有默认参数
    // 10. 槽函数可以想普通函数一样被调用
    // 11. 在槽函数中调用sender可以获得信号调用者
    // 总结：一个类(QObejct)，三个宏(Q_OBJECT、SIGNAL、SLOT)，三个保留字(signals, slots, emit)
    return app.exec();
}
