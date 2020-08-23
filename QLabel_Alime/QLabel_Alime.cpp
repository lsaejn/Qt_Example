#include "QLabel_Alime.h"
#include <QLabel>
#include <QLayout>


//https://blog.csdn.net/liang19890820/article/details/50866096
QLabel_Alime::QLabel_Alime(QWidget *parent)
    : QWidget(parent)
{
    //为了达到拉伸效果，我们放到一个Hbox里
    QHBoxLayout* layout = new QHBoxLayout(this);
    QLabel* pLabel1 = new QLabel(this);
    layout->addWidget(pLabel1);
    pLabel1->setWordWrap(true);
    //QLabel没有设置行间距的函数，所以这种办法是行不通的。
    QString strText = QStringLiteral("一去二三里，烟村四五家。亭台六七座，八九十枝花。");
    QString strHeightText = "<p style=\"line-height:%1%\">%2<p>";
    strText = strHeightText.arg(100).arg(strText);
    pLabel1->setText(strText);
    pLabel1->setAlignment(Qt::AlignCenter);
    

}
