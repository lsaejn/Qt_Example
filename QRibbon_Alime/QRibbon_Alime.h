#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QRibbon_Alime.h"

class QRibbon_Alime : public QMainWindow
{
    Q_OBJECT

public:
    QRibbon_Alime(QWidget *parent = Q_NULLPTR);

private:
    Ui::QRibbon_AlimeClass ui;
};
