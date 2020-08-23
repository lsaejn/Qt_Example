#pragma once

#include <QtWidgets/QWidget>

/*
使用toolbox+groupbox+pushbutton的组合看起来要更好一些
但是，使用label+QListWidget的组合更方便。
*/

//#include "ui_QListWidget_Alime.h"
class QListWidget;
class QListWidget_Alime : public QWidget
{
    Q_OBJECT

public:
    QListWidget_Alime(QWidget *parent = Q_NULLPTR);

public slots:
    void OnListItemClicked(const QModelIndex&);

private:
//Ui::QListWidget_AlimeClass ui;
    QListWidget* listWidget_mymusic;
};
