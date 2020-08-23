#pragma once

#include <QtWidgets/QWidget>

class QAbstractButton;
class QButtonGroup;
class QtRadioButton_Alime : public QWidget
{
    Q_OBJECT

public:
    QtRadioButton_Alime(QWidget *parent = Q_NULLPTR);

public slots:
    void buttonClicked(QAbstractButton*);
    void checked(bool);

private:
    QButtonGroup* m_pButtonGroup;
};
