#pragma once

#include <QtWidgets/QWidget>

/*
ʹ��toolbox+groupbox+pushbutton����Ͽ�����Ҫ����һЩ
���ǣ�ʹ��label+QListWidget����ϸ����㡣
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
