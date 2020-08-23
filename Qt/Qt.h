#pragma once

/*
�����������ڴ���һ�������׵����ֲ�������
�����������Ǹ����ӹ��ܵ�ʵ�֡�

���У���AlimeΪ��β�ģ���QT�ؼ�/��ʽ��ص�ѧϰ
��:
����:
Vertical Layout
Horizontal Layout
Grid Layout
Form Layout

ռλ
Horizontal Spacer
Vertical Spacer

��ť
PushButton  --QPushButton_Alime
ToolButton  --QToolButton_Alime
RadioButton --QRadioButton_Alime
CheckBox    --QCheckBox_Alime
CommandLinkButton
DialogButtonBox


ListView
TreeView
TableView
ColumnView
UndoView


ListWidget  --QListWidget_Alime
TreeWidget
TableWidget

����
GroupBox
ScrollArea
ToolBox
TabWidget
StackedWidget
Frame
Widget
MDIArea
DockWidget
QAxWidget

����
ComboBox
FontComboBox
LineEdit    --QLineEdit_Alime
TextEdit
PlainTextEdit
SpinBox
DoubleSpinBox
TimeEdit
DateEdit
Date/TimeEdit
Dial

����
HorizontalScrollBar
VerticalScrollBar
HorizontalSilder            --QMusicView
VerticalSlider
KeySequenceEdit

��ʾ
Label                            --Qlabel_Alime
TextBrowser
GraphicView
CalendarWidget
LCDNumber   û���ӣ���Ϊʹ�÷�Χ̫С
ProgressBar

HorizontalLine
VerticalLine
OpenGLWidget
QQuickWidget
*/

#include <QtWidgets/QWidget>
#include "ui_Qt.h"

class Qt : public QWidget
{
    Q_OBJECT

public:
    Qt(QWidget *parent = Q_NULLPTR);

private:
    Ui::QtClass ui;
};
