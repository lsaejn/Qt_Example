#pragma once

#include <QThread>
#include <QDebug>

class WorkerThread : public QThread
{
    Q_OBJECT

public:
    explicit WorkerThread(QObject* parent = 0)
        : QThread(parent)
    {
        qDebug() << "Worker Thread : " << QThread::currentThreadId();
    }

protected:
    virtual void run() Q_DECL_OVERRIDE {
        qDebug() << "Worker Run Thread : " << QThread::currentThreadId();
        int nValue = 0;
        while (nValue < 100)
        {
            // ����50����
            msleep(50);
            ++nValue;

            // ׼������
            emit resultReady(nValue);
        }
    }
signals:
    void resultReady(int value);
};
