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
    pProgressBar->setOrientation(Qt::Horizontal);  // ˮƽ����
    pProgressBar->setMinimum(0);  // ��Сֵ
    pProgressBar->setMaximum(100);  // ���ֵ
    pProgressBar->setValue(50);  // ��ǰ����
    vlay->addWidget(pProgressBar);

    QProgressBar* pProgressBar2 = new QProgressBar(this);
    pProgressBar2->setOrientation(Qt::Horizontal);  // ˮƽ����
    pProgressBar2->setMinimum(0);  // ��Сֵ
    pProgressBar2->setMaximum(100);  // ���ֵ
    pProgressBar2->setValue(50);  // ��ǰ����
    pProgressBar2->setInvertedAppearance(true);  // ������
    vlay->addWidget(pProgressBar2);

    pProgressBar3 = new QProgressBar(this);
    pProgressBar3->setOrientation(Qt::Horizontal);  // ˮƽ����
    pProgressBar3->setMinimum(0);  // ��Сֵ
    pProgressBar3->setMaximum(100);  // ���ֵ
    pProgressBar3->setValue(0);  // ��ǰ����
    double dProgress = (pProgressBar3->value() - pProgressBar3->minimum()) * 100.0/ (pProgressBar3->maximum() - pProgressBar3->minimum());
    pProgressBar3->setFormat(QString::fromLocal8Bit("��ǰ����Ϊ��%1%").arg(QString::number(dProgress, 'f', 1)));
    pProgressBar3->setAlignment(Qt::AlignRight | Qt::AlignVCenter);  // ���뷽ʽ
    vlay->addWidget(pProgressBar3);

    QProgressBar* pProgressBar4 = new QProgressBar(this);
    pProgressBar4->setOrientation(Qt::Horizontal);  // ˮƽ����
    pProgressBar4->setMinimum(0);  // ��Сֵ
    pProgressBar4->setMaximum(0);  // ���ֵ
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
   // ������������QT�ﲻ��ֱ�Ӳ����̶߳�����Ҫ���źš������ź�����Ҫ���ඨ�塣��ô���Ļ���
    //std::thread�ı����Եò�������
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

    //�յ�worker��resultReady�ź�ʱ�����ñ��̵߳�handleResults�ۺ���
    connect(workerThread, SIGNAL(resultReady(int)), this, SLOT(handleResults(int)));
    //���߳̽������Զ�����
    connect(workerThread, SIGNAL(finished()), workerThread, SLOT(deleteLater()));
    workerThread->start();
}

void QProgressBar_Alime::handleResults(int value)
{
    qDebug() << "Handle Thread : " << QThread::currentThreadId();
    pProgressBar3->setValue(value);
    double dProgress = (pProgressBar3->value() - pProgressBar3->minimum()) * 100.0 / (pProgressBar3->maximum() - pProgressBar3->minimum());
    pProgressBar3->setFormat(QString::fromLocal8Bit("��ǰ����Ϊ��%1%").arg(QString::number(dProgress, 'f', 1)));
}
