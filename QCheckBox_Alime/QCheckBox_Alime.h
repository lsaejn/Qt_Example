#pragma once

#include <QtWidgets/QWidget>
#include <QCheckBox>


class QCheckBox_Alime : public QWidget
{
    Q_OBJECT

public:
    QCheckBox_Alime(QWidget *parent = Q_NULLPTR);
public slots:
    void onStateChanged(int state);
private:
    QCheckBox* checkbox;
};
