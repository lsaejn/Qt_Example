#include "QDateEdit_QTimeEdit_Alime.h"

#include <QDateEdit>//same as #include <QTimeEdit>
#include <QTimeEdit>
#include <QLayout>
#include <QLabel>

QDateEdit_QTimeEdit_Alime::QDateEdit_QTimeEdit_Alime(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);

    setObjectName(u8"customWidget");

    QVBoxLayout* layout = new QVBoxLayout(this);
    QDateEdit* dateEdit = new QDateEdit(QDate::currentDate(), this);
    QTimeEdit* timeEdit = new QTimeEdit(QTime::currentTime(), this);
    dateEdit->setDisplayFormat("yyyy/MM/dd");
    timeEdit->setDisplayFormat("HH:mm:ss");


    QLabel* text = new QLabel(u8"Î¢ÈíÑÅºÚ", this);
    text->setObjectName(u8"blueLabel");
    layout->addWidget(dateEdit);
    layout->addWidget(timeEdit);
    layout->addWidget(text);
    
}
