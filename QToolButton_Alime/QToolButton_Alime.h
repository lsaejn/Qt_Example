#pragma once

#include <QtWidgets/QWidget>

#include <QToolButton>
class QToolButton_Alime : public QWidget
{
    Q_OBJECT

public:
    QToolButton_Alime(QWidget *parent = Q_NULLPTR);

private:
    QToolButton *btn;
};
