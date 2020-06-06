#include "MyWidget.h"
#include <QApplication>

#include <QLabel>       // 标题
#include <QPushButton>  // 按钮
#include <QLineEdit>    // 输入框
#include <QComboBox>    // 选择器
#include <QRadioButton> // 单选框
#include <QCheckBox>    // 复选框
#include <QTextEdit>    // 富文本
#include <QTextBrowser> // 只读富文本
#include <QSlider>      // 滑块
#include <QSpinBox>     // 数字框(和滑块配合使用)
#include <QDateEdit>    // 日期选择
#include <QTimeEdit>    // 时间选择
#include <QDateTimeEdit>// 日期时间选择
#include <QGroupBox>    // 控件分组
#include <QLCDNumber>   // LCD数字显示

#include <QVBoxLayout>  // 垂直布局
#include <QHBoxLayout>  // 水平布局
#include <QCompleter>   // 提示

#include <QDebug>

MyWidget::MyWidget(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout* layout = new QVBoxLayout(this);

    QComboBox* combo;
    QLabel* label;
    QPushButton* button;
    QRadioButton* radio;
    QTextEdit* text;
    QSlider* slider;
    QSpinBox* spinBox;
    QGroupBox* group;
    QHBoxLayout* hBoxLayout;
    QLCDNumber* lcd;

    layout->addWidget(label = new QLabel("<a href=www.baidu.com>Baidu</a>"));
    // pro文件添加CONFIG += C++11
    connect(label, &QLabel::linkActivated, this, [](QString str) {
        qDebug() << str;
    });
    layout->addWidget(button = new QPushButton("Button"));
    // 设置Button样式(CSS)
    button->setStyleSheet("QPushButton {color: red}");

    layout->addWidget(new QLineEdit);
    layout->addWidget(combo = new QComboBox());
    layout->addWidget(radio = new QRadioButton("Radio"));
    // 获取radiod的选中状态
    connect(radio, &QRadioButton::clicked, [](bool v) {
        qDebug() << v;
    });
    connect(combo, SIGNAL(currentIndexChanged(QString)), this, SLOT(slotComboBoxIndexChanged(QString)));
    layout->addWidget(new QCheckBox("CheckBox"));
    layout->addWidget(text = new QTextEdit);
    text->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    layout->addWidget(new QTextBrowser);
    layout->addWidget(slider = new QSlider(Qt::Horizontal));
    layout->addWidget(spinBox = new QSpinBox);
    layout->addWidget(new QDateEdit);
    layout->addWidget(new QTimeEdit);
    layout->addWidget(new QDateTimeEdit);
    layout->addWidget(group = new QGroupBox("Some Items"));
    layout->addWidget(lcd = new QLCDNumber(10));

    // lcd number
    lcd->display(12345);
    lcd->setMode(QLCDNumber::Hex);
    lcd->setSegmentStyle(QLCDNumber::Flat);

    // groupbox
    group->setLayout(hBoxLayout = new QHBoxLayout);
    hBoxLayout->addWidget(new QSlider(Qt::Horizontal));
    hBoxLayout->addWidget(new QPushButton("Groupbox Button"));

    // slider
    slider->setMinimum(0);
    slider->setMaximum(100);

    // spin
    spinBox->setMinimum(0);
    spinBox->setMaximum(100);
    connect(slider,SIGNAL(valueChanged(int)), spinBox, SLOT(setValue(int)));
    connect(spinBox, SIGNAL(valueChanged(int)), slider, SLOT(setValue(int)));

    // combobox
    combo->addItem("Item 1");
    combo->addItem("Item 2");
    // 是否可编辑
    combo->setEditable(true);
    // 设置自动提示
    combo->setCompleter(new QCompleter(combo->model()));

    text->setText("<table border=1><tr><th>Head1</th><th>Head2</th></tr><tr><td>Vlaue1</td><td>Vlaue2</td></tr></table>");
}

void MyWidget::slotComboBoxIndexChanged(const QString &str)
{
    qDebug() << str;
}

int main(int argc, char* argv[])
{

    QApplication app(argc, argv);

    MyWidget w;
    w.show();

    return app.exec();
}
