#include "QCommandLinkButton_Alime.h"

#include <QCommandLinkButton>
#include <QLayout>

//https://www.cnblogs.com/liming19680104/p/10770993.html
QCommandLinkButton_Alime::QCommandLinkButton_Alime(QWidget *parent)
    : QWidget(parent)
{
    QCommandLinkButton* btn = new QCommandLinkButton(this);
    btn->setText("Fuck");
    //btn->setIcon()

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(btn);
}
