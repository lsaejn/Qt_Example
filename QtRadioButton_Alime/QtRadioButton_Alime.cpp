#include "QtRadioButton_Alime.h"
#include <QRadioButton>
#include <QLayout>
#include <QButtonGroup>

QtRadioButton_Alime::QtRadioButton_Alime(QWidget *parent)
    : QWidget(parent)
{
    resize(400, 200);
    QHBoxLayout* layout = new QHBoxLayout(this);

    setStyleSheet("QRadioButton{ spacing: 2px; color: #1296db;} \
        QRadioButton::indicator {width: 45px; height: 45px;} \
        QRadioButton::indicator:unchecked {image:url(:/no); } \
        QRadioButton::indicator:unchecked:hover {image: url(:/no);} \
        QRadioButton::indicator:unchecked:pressed{image: url(:/no);}\
        QRadioButton::indicator:checked{image: url(:/yes);}\
        QRadioButton::indicator:checked:hover{image: url(:/yes);}\
        QRadioButton::indicator:checked:pressed{ image: url(:/yes);}");

    m_pButtonGroup = new QButtonGroup(this);
    m_pButtonGroup->setExclusive(false);

    QRadioButton* radioButton1 = new QRadioButton(this);
    radioButton1->setText("btn1");
    radioButton1->setToolTip("btn1");
    layout->addWidget(radioButton1);

    QRadioButton* radioButton2 = new QRadioButton(this);
    radioButton2->setText("btn2");
    radioButton2->setToolTip("btn2");
    layout->addWidget(radioButton2);

    QRadioButton* radioButton3 = new QRadioButton(this);
    radioButton3->setText("btn3");
    radioButton3->setToolTip("btn3");
    layout->addWidget(radioButton3);

    m_pButtonGroup->addButton(radioButton1);
    m_pButtonGroup->addButton(radioButton2);
    m_pButtonGroup->addButton(radioButton3);

    bool ret=connect(radioButton3, SIGNAL(toggled(bool)), this, SLOT(checked(bool)));

    connect(m_pButtonGroup, SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(buttonClicked(QAbstractButton*)));

}

#include <Qdebug>
void QtRadioButton_Alime::buttonClicked(QAbstractButton* button)
{
    auto str= button->text();

    qDebug() << QString("Clicked Button : %1").arg(button->text());

    // 遍历按钮，获取选中状态
    QList<QAbstractButton*> list = m_pButtonGroup->buttons();
    foreach(QAbstractButton * pButton, list)
    {
        QString strStatus = pButton->isChecked() ? "Checked" : "Unchecked";
        qDebug() << QString("Button : %1 is %2").arg(button->text()).arg(strStatus);
    }
}

void QtRadioButton_Alime::checked(bool)
{
    qDebug() << QString("Clicked Button : %1").arg("3");
}
