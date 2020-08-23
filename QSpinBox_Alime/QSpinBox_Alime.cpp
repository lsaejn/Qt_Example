#include "QSpinBox_Alime.h"

#include <QSpinBox>
#include <QDebug>
#include <QLayout>

//https://doc.qt.io/archives/qt-5.6/stylesheet-examples.html
QSpinBox_Alime::QSpinBox_Alime(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout* layout = new QVBoxLayout(this);

    QSpinBox* pSpinBox = new QSpinBox(this);
    pSpinBox->setRange(20, 200);  // 范围
    pSpinBox->setSingleStep(10); // 步长
    pSpinBox->setValue(150);  // 当前值
    //pSpinBox->setPrefix("$ ");  // 前缀
    //pSpinBox->setSuffix(" %");  // 后缀
    pSpinBox->setWrapping(true);  // 开启循环

    layout->addWidget(pSpinBox);

    connect(pSpinBox, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged),
        [=](int value)
        {
            qDebug() << "Value : " << value;
            qDebug() << "Text : " << pSpinBox->text();
        });

    connect(pSpinBox, static_cast<void(QSpinBox::*)(const QString&)>(&QSpinBox::valueChanged),
        [=](const QString& text)
        {
            qDebug() << "Text Value : " << text;
            qDebug() << "Clean Text : " << pSpinBox->cleanText();
        });
}
