#include "QLabel_Alime.h"
#include <QLabel>
#include <QLayout>


//https://blog.csdn.net/liang19890820/article/details/50866096
QLabel_Alime::QLabel_Alime(QWidget *parent)
    : QWidget(parent)
{
    //Ϊ�˴ﵽ����Ч�������Ƿŵ�һ��Hbox��
    QHBoxLayout* layout = new QHBoxLayout(this);
    QLabel* pLabel1 = new QLabel(this);
    layout->addWidget(pLabel1);
    pLabel1->setWordWrap(true);
    //QLabelû�������м��ĺ������������ְ취���в�ͨ�ġ�
    QString strText = QStringLiteral("һȥ������̴�����ҡ�̨ͤ���������˾�ʮ֦����");
    QString strHeightText = "<p style=\"line-height:%1%\">%2<p>";
    strText = strHeightText.arg(100).arg(strText);
    pLabel1->setText(strText);
    pLabel1->setAlignment(Qt::AlignCenter);
    

}
