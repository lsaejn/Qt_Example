#pragma once

#include <QtWidgets/QWidget>

class QLineEdit;
class QLineEdit_Alime : public QWidget
{
    Q_OBJECT

public:
    QLineEdit_Alime(QWidget *parent = Q_NULLPTR);
public slots:
    void onSearch();
    void onAction(bool);
    
private:
    QLineEdit* edit;
};
