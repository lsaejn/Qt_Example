#include "QtSlider.h"
#include <QIcon>
#include <QLayout>
#include <QpushButton>
#include <QLabel>
//#include <QProgressbar>
#include <QSlider>

QtSlider::QtSlider(QWidget* parent)
    : QWidget(parent)
{
    resize(600, 100);
    setStyleSheet("background:rgba(45,45,45,255);");
    QHBoxLayout* hLayout = new QHBoxLayout(this);
    hLayout->setContentsMargins(0, 0, 0, 0);
    
    QPushButton* backward = new QPushButton(this);
    backward->setFixedSize(20, 20);
    QIcon btn_icon;
    btn_icon.addFile(":/backward");
    backward->setIcon(btn_icon);
    backward->setIconSize(QSize(16, 16));
    backward->setStyleSheet("background-color: rgba(0,0,0,0);");
    hLayout->addWidget(backward);

    QPushButton* play = new QPushButton(this);
    play->setFixedSize(24, 24);
    QIcon btn_icon2;
    btn_icon2.addFile(":/play");
    play->setIcon(btn_icon2);
    play->setIconSize(QSize(20, 20));
    play->setStyleSheet("background-color: rgba(255,255,255,30);");
    hLayout->addWidget(play);

    QPushButton* forward = new QPushButton(this);
    forward->setFixedSize(20, 20);
    QIcon btn_icon3;
    btn_icon3.addFile(":/forward");
    forward->setIcon(btn_icon3);
    forward->setIconSize(QSize(16, 16));
    forward->setStyleSheet("background-color: rgba(0,0,0,0);");
    hLayout->addWidget(forward);

    QLabel* timePlayed = new QLabel(this);
    timePlayed->setText("00:00");
    hLayout->addWidget(timePlayed);

    QSlider* musicSlider = new QSlider(this);
    musicSlider->setPageStep(3);
    musicSlider->setRange(0, 100); //设置进度条最小值和最大值(取值范围)
    musicSlider->setOrientation(Qt::Horizontal);
    //https://blog.csdn.net/Qyee16/article/details/51660665?utm_medium=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-1.channel_param&depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-1.channel_param
    musicSlider->setStyleSheet("QSlider{background-color: rgba(0,0,0,0); max-width:100px; border:none;} \
        QSlider::add-page:horizontal{background:#18181a; height:3px; border-radius: 3px;} \
        QSlider::sub-page:horizontal{background-color:#008aff; height:10px;border-radius:3px;} \
        QSlider::groove:horizontal{background:#18181a; height:3px; border-radius: 3px;} \
        QSlider::handle:horizontal{width: 12px; margin-top:-5px; margin-bottom:-4px; border-radius:6px; background:qradialgradient(spread:pad,cx:0.5,cy:0.5,radius:0.5,fx:0.5,fy:0.5,stop:0.6 #565656,stop:0.8 #565656);border-image: url(:/drager);}");
    hLayout->addWidget(musicSlider);
    
    QLabel* timeLeft = new QLabel(this);
    timeLeft->setText("04::33");
    timeLeft->setMargin(0);
    hLayout->addWidget(timeLeft);

    QPushButton* volume = new QPushButton(this);
    volume->setFixedSize(20, 20);
    QIcon btn_icon4;
    btn_icon4.addFile(":/volume");
    volume->setIcon(btn_icon4);
    volume->setIconSize(QSize(20, 20));
    volume->setStyleSheet("background-color: rgba(0,0,0,0);");
    hLayout->addWidget(volume);

    QSlider* volumeSlider = new QSlider(this);
    volumeSlider->setOrientation(Qt::Vertical);
    volumeSlider->setStyleSheet("QSlider{background-color: rgba(0,0,0,0); max-height:50px; border:none;} \
        QSlider::add-page:vertical{background:#008aff; width:3px; border-radius: 3px;} \
        QSlider::sub-page:vertical{background-color:#18181a; width:8px; border-radius:3px;} \
        QSlider::groove:vertical{background:#D8D8D8; width:3px; border-radius: 3px;} \
        QSlider::handle:vertical{height: 12px; margin-left:-5px; margin-right:-4px; border-radius:6px; background:qradialgradient(spread:pad,cx:0.5,cy:0.5,radius:0.5,fx:0.5,fy:0.5,stop:0.6 #565656,stop:0.8 #565656);border-image: url(:/drager);}");

    hLayout->addWidget(volumeSlider);
    

    QPushButton* circle = new QPushButton(this);
    circle->setFixedSize(20, 20);
    QIcon btn_icon5;
    btn_icon5.addFile(":/circle");
    circle->setIcon(btn_icon5);
    circle->setIconSize(QSize(16, 16));
    circle->setStyleSheet("background-color: rgba(0,0,0,0);");
    hLayout->addWidget(circle);
    hLayout->addStretch();



}

