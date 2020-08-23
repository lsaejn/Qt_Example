#include "QPushButton_Alime.h"
#include <QPushButton>
#include <QLayout>
#include <QMenu>

QPushButton_Alime::QPushButton_Alime(QWidget *parent)
    : QWidget(parent)
{
    //setStyleSheet("QPushButton:{background-color: rgb(0,0,0)}");

    QHBoxLayout* layout = new QHBoxLayout(this);

    QPushButton* btn = new QPushButton(this);
    btn->setText(u8"设置");

    btn->setStyleSheet("QPushButton{background-color:rgba(0,0,0,0);color:white; border-radius: 1px;  border: 1px rgb(85, 170, 255); \
    border-style: solid; padding:2px 2px;}"
    "QPushButton:hover{background-color:white; color: black;}"
    "QPushButton:pressed{background-color:rgb(85, 170, 255);\
    border-style: inset; }");

    QMenu* pMenu = new QMenu(this);
    pMenu->addAction(u8"设置");
    pMenu->addAction(u8"版本检测");
    pMenu->addSeparator();
    pMenu->addAction(u8"关于我们");
    pMenu->addAction(u8"退出");

    btn->setMenu(pMenu);

    layout->addWidget(btn);    
}
