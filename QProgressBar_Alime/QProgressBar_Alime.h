#pragma once

#include <QtWidgets/QWidget>
#include "ui_QProgressBar_Alime.h"

class QProgressBar;

class QProgressBar_Alime : public QWidget
{
    Q_OBJECT

public:
    QProgressBar_Alime(QWidget *parent = Q_NULLPTR);

public slots:
    void btnClicked(bool checked);
    void startThread();
    void handleResults(int value);

private:
    Ui::QProgressBar_AlimeClass ui;
    QProgressBar* pProgressBar3;
};
