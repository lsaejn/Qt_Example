#include "QCheckBox_Alime.h"
#include <QLabel>
#include <QLayout>
#include <QStyle>
//https://doc.qt.io/archives/qt-5.6/stylesheet-examples.html#customizing-qcheckbox
//https://blog.csdn.net/liang19890820/article/details/50976944
//https://blog.csdn.net/flfihpv259/article/details/53281813

QCheckBox_Alime::QCheckBox_Alime(QWidget *parent)
    : QWidget(parent)
{
    this->setStyleSheet("QCheckBox{color: rgb(0,162,232);}"
        "QCheckBox::indicator{width: 20px;height: 20px;}"
        "QCheckBox::indicator:unchecked{image: url(:/images/check-box-un.png);}"
        "QCheckBox::indicator:checked{image: url(:/images/check-box.png);}"
    );

    QHBoxLayout* layout = new QHBoxLayout(this);

    QLabel* label = new QLabel(this);
    label->setObjectName(u8"fuck");
    label->setText(u8"未被选中状态");
    //void stateChanged(int state)

    QCheckBox* pCheckBox = new QCheckBox(this);
    pCheckBox->setText(QString::fromLocal8Bit("两态复选框"));


    //pCheckBox->setTristate();

    layout->addWidget(pCheckBox);
    layout->addWidget(label);

    // 连接信号槽
    connect(pCheckBox, SIGNAL(stateChanged(int)), this, SLOT(onStateChanged(int)));
}


void QCheckBox_Alime::onStateChanged(int state)
{
    QList<QLabel*> labelList = findChildren<QLabel*>(u8"fuck");
    QLabel* label = labelList[0];

    if (state == Qt::Checked) // "选中"
    {
        label->setText("Checked");
    }
    else if (state == Qt::PartiallyChecked) // "半选"
    {
        label->setText("PartiallyChecked");
    }
    else // 未选中 - Qt::Unchecked
    {
        label->setText("Unchecked");
    }
}
