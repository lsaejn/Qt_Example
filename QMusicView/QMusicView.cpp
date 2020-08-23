#include "QMusicView.h"
#include "qlayout.h"
#include <qpushbutton.h>
#include <QLabel>
#include <QSvgRenderer>
#include <QPainter>

QMusicView::QMusicView(QWidget *parent)
    : QWidget(parent)
{
    setStyleSheet("background:rgba(25,27,31,255);");

    setWindowTitle(u8"图片浏览器");//可执行程序标题
    setWindowIcon(QIcon(":/CdCoverSvg"));//":/likeThisMusic"

    //就是一个HBox包含3个VBox
    QHBoxLayout* mainBox = new QHBoxLayout(this);

    QVBoxLayout* leftVBox = new QVBoxLayout(this);
    leftVBox->setContentsMargins(0, 0, 0, 0);
    QLabel* label = new QLabel(this);

    QSvgRenderer* svgRender = new QSvgRenderer();
    svgRender->load(QString(":/CdCoverSvg"));

    //QPixmap CdImage(":/CdCoverSvg");
    //CdImage = CdImage.scaled({96,96}, Qt::KeepAspectRatio);
    QPixmap* CdImage = new QPixmap(60, 60);
    CdImage->fill(Qt::transparent);//设置背景透明
    QPainter p(CdImage);
    svgRender->render(&p);

    label->setPixmap(*CdImage);
    leftVBox->addWidget(label);


    QVBoxLayout* midVBox = new QVBoxLayout(this);
    midVBox->setMargin(0);
    midVBox->setSpacing(0);
    QLabel* musicName= new QLabel(this);
    musicName->setText(u8"我记得我曾经爱过");
    musicName->setStyleSheet("color:rgba(255,200,200,255);");
    QLabel* singer = new QLabel(this);
    singer->setStyleSheet("color:rgba(255,200,200,255);");
    singer->setText(u8"何润东");
    midVBox->addWidget(musicName);
    midVBox->addWidget(singer);

    QVBoxLayout* rightVBox = new QVBoxLayout(this);
    QPushButton* likeThis = new QPushButton(this);
    likeThis->setFixedSize(32, 32);
    QIcon btn_icon;
    btn_icon.addFile(":/likeThisMusic");
    likeThis->setIcon(btn_icon);
    likeThis->setIconSize(QSize(30, 30));
    likeThis->setStyleSheet("background-color: rgba(0,0,0,0);");
    //likeThis->setStyleSheet("QPushButton{background-color: rgba(0,0,0,0);\
    //    color: white; border-radius: 10px; border: none; \
    //    background-image: url(:/likeThisMusic);} \
    //    border-style: outset;}" 
    //    "QPushButton:hover{background-color:white; color: black;}"
    //    "QPushButton:pressed{background-color:rgb(85, 170, 255);\
    //    border-style: inset; }");
    
    QPushButton* forwardThis = new QPushButton(this);
    forwardThis->setFixedSize(32, 32);
    QIcon btn_icon2;
    btn_icon2.addFile(":/forwardThisMusic");
    forwardThis->setIcon(btn_icon2);
    forwardThis->setIconSize(QSize(30, 30));
    forwardThis->setStyleSheet("background-color: rgba(0,0,0,0);");

    rightVBox->addWidget(likeThis);
    rightVBox->addWidget(forwardThis);
    rightVBox->setMargin(0);
    rightVBox->setSpacing(0);

    mainBox->addLayout(leftVBox);
    mainBox->addLayout(midVBox);
    mainBox->addLayout(rightVBox);
}


