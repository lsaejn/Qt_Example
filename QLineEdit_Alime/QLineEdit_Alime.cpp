#include "QLineEdit_Alime.h"
#include <QLayout>
#include <QLineEdit>
#include <QAction>
/*
QLineEdit: ��������
ʹ�ó���:������

//https://blog.csdn.net/liang19890820/article/details/52044639
*/

QLineEdit_Alime::QLineEdit_Alime(QWidget *parent)
    : QWidget(parent)
{
    resize(400, 200);
    edit = new QLineEdit(this);
    edit->move(100, 100);

    edit->setPlaceholderText(u8"���ֲ���Ǹ");
    //edit->setEchoMode(QLineEdit::Password);
    edit->setDragEnabled(1);
    edit->setMaxLength(5);

    // ���action
    QAction* pLeadingAction = new QAction(this);
    pLeadingAction->setIcon(QIcon(":/QLineEdit_Alime/logo"));

    edit->addAction(pLeadingAction, QLineEdit::LeadingPosition);
    QAction* pTrailingAction = edit->addAction(QIcon(":/QLineEdit_Alime/logo"), QLineEdit::TrailingPosition);

    // �����źźͲ�
    bool succ=connect(pTrailingAction, SIGNAL(triggered(bool)), this, SLOT(onAction(bool)));
    succ = connect(pLeadingAction, SIGNAL(triggered(bool)), this, SLOT(onAction(bool)));
    succ=connect(edit, &QLineEdit::returnPressed, this, &QLineEdit_Alime::onSearch);
}

//
void QLineEdit_Alime::onAction(bool checked)
{
    QString strText = edit->text();
}

void QLineEdit_Alime::onSearch()
{
    QString strText = edit->text();
    strText = "";
}
