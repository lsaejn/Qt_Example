#include "QProgressBar_Alime.h"

#include <QprogressBar>
#include <QLayout>
#include <QPushButton>

#include <chrono>
#include <thread>

QProgressBar_Alime::QProgressBar_Alime(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    setObjectName(u8"QProgressBar_Alime");

    QVBoxLayout* vlay = new QVBoxLayout(this);

    QProgressBar* pProgressBar = new QProgressBar(this);
    pProgressBar->setOrientation(Qt::Horizontal);  // 水平方向
    pProgressBar->setMinimum(0);  // 最小值
    pProgressBar->setMaximum(100);  // 最大值
    pProgressBar->setValue(50);  // 当前进度
    vlay->addWidget(pProgressBar);

    QProgressBar* pProgressBar2 = new QProgressBar(this);
    pProgressBar2->setOrientation(Qt::Horizontal);  // 水平方向
    pProgressBar2->setMinimum(0);  // 最小值
    pProgressBar2->setMaximum(100);  // 最大值
    pProgressBar2->setValue(50);  // 当前进度
    pProgressBar2->setInvertedAppearance(true);  // 反方向
    vlay->addWidget(pProgressBar2);

    pProgressBar3 = new QProgressBar(this);
    pProgressBar3->setOrientation(Qt::Horizontal);  // 水平方向
    pProgressBar3->setMinimum(0);  // 最小值
    pProgressBar3->setMaximum(100);  // 最大值
    pProgressBar3->setValue(0);  // 当前进度
    double dProgress = (pProgressBar3->value() - pProgressBar3->minimum()) * 100.0/ (pProgressBar3->maximum() - pProgressBar3->minimum());
    pProgressBar3->setFormat(QString::fromLocal8Bit("当前进度为：%1%").arg(QString::number(dProgress, 'f', 1)));
    pProgressBar3->setAlignment(Qt::AlignRight | Qt::AlignVCenter);  // 对齐方式
    vlay->addWidget(pProgressBar3);

    QProgressBar* pProgressBar4 = new QProgressBar(this);
    pProgressBar4->setOrientation(Qt::Horizontal);  // 水平方向
    pProgressBar4->setMinimum(0);  // 最小值
    pProgressBar4->setMaximum(0);  // 最大值
    vlay->addWidget(pProgressBar4);

    QPushButton* btn = new QPushButton(this);
    vlay->addWidget(btn);
    //btn->setObjectName(u8"blueButton");
    btn->setText(u8"fuck");
   // connect(btn, &QPushButton::clicked, this, &QProgressBar_Alime::btnClicked, Qt::QueuedConnection);
    connect(btn, SIGNAL(clicked(bool)), this, SLOT(startThread()));
}


void QProgressBar_Alime::btnClicked(bool checked)
{
   // 崩溃，看起来QT里不能直接操作线程对象，需要发信号。而发信号又需要在类定义。这么看的话，
    //std::thread的便利性得不到利用
    //std::thread t([this]() {
    //    for (int i = 0; i != 100; ++i)
    //    {
    //        std::this_thread::sleep_for(std::chrono::seconds(1));
    //        pProgressBar3->setValue(i);
    //    }
    //    });
    //t.detach();
}

#include "workThread.h"
void QProgressBar_Alime::startThread()
{
    WorkerThread* workerThread = new WorkerThread(this);

    //收到worker的resultReady信号时，调用本线程的handleResults槽函数
    connect(workerThread, SIGNAL(resultReady(int)), this, SLOT(handleResults(int)));
    //子线程结束后，自动销毁
    connect(workerThread, SIGNAL(finished()), workerThread, SLOT(deleteLater()));
    workerThread->start();
}

void QProgressBar_Alime::handleResults(int value)
{
    qDebug() << "Handle Thread : " << QThread::currentThreadId();
    pProgressBar3->setValue(value);
    double dProgress = (pProgressBar3->value() - pProgressBar3->minimum()) * 100.0 / (pProgressBar3->maximum() - pProgressBar3->minimum());
    pProgressBar3->setFormat(QString::fromLocal8Bit("当前进度为：%1%").arg(QString::number(dProgress, 'f', 1)));
}
