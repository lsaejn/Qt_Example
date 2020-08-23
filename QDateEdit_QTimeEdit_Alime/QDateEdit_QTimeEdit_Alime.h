#pragma once

#include <QtWidgets/QWidget>
#include "ui_QDateEdit_QTimeEdit_Alime.h"

class QDateEdit_QTimeEdit_Alime : public QWidget
{
    Q_OBJECT

public:
    QDateEdit_QTimeEdit_Alime(QWidget *parent = Q_NULLPTR);

private:
    Ui::QDateEdit_QTimeEdit_AlimeClass ui;
};
