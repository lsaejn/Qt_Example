#pragma once

/*
本工程致力于打造一个仿网易的音乐播放器。
这个解决方案是各个子功能的实现。

其中，以Alime为结尾的，是QT控件/样式相关的学习
即:
布局:
Vertical Layout
Horizontal Layout
Grid Layout
Form Layout

占位
Horizontal Spacer
Vertical Spacer

按钮
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

容器
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

输入
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

辅助
HorizontalScrollBar
VerticalScrollBar
HorizontalSilder            --QMusicView
VerticalSlider
KeySequenceEdit

显示
Label                            --Qlabel_Alime
TextBrowser
GraphicView
CalendarWidget
LCDNumber   没例子，因为使用范围太小
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
