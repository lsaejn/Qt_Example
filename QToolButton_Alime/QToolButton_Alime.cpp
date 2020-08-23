#include "QToolButton_Alime.h"
#include <QLayout>
#include <QAction>
//https://blog.csdn.net/liang19890820/article/details/51770925

QToolButton_Alime::QToolButton_Alime(QWidget *parent)
    : QWidget(parent)
{
    btn = new QToolButton(this);
    btn->setStyleSheet("QToolButton{border: none; background: rgb(68, 69, 73); color: rgb(0, 160, 230);}");
    //btn->setArrowType(Qt::LeftArrow);
    btn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    //QAction* pAction = new QAction(this);
    //pAction->setText(QString::fromLocal8Bit("一去丶二三里"));
    //pAction->setIcon(QIcon(u8":/images/爱心.png"));
    //btn->setIconSize(QSize(48, 48));
    //pAction->setToolTip(QString::fromLocal8Bit("青春不老，奋斗不止！"));
    //btn->setDefaultAction(pAction);
    //btn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    //auto action = btn->defaultAction();

    btn->setIcon(QIcon(u8":/images/爱心.png"));
    btn->setText("fuck");
    btn->setToolTip("tips");

    QHBoxLayout* layout = new QHBoxLayout(this);
    layout->addWidget(btn);
}
