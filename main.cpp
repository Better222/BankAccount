#include "worker.h"
#include "bankaccount.h"
#include <QObject>
#include <QCoreApplication>

int main(int argc,char* argv[])
{
    QCoreApplication a(argc,argv);
    BankAccount acc(1000);
    //创建5个线程来存取钱
    QList<QThread*> threads;
    for(int i = 0; i < 5; i++)
    {
        Worker* worker = new Worker(acc,i);
        QThread *thread = new QThread;
        worker->moveToThread(thread);
        // 连接信号槽
        QObject::connect(thread, &QThread::started, worker, &Worker::run);
        QObject::connect(worker, &Worker::finished, thread, &QThread::quit);
        QObject::connect(thread, &QThread::finished, worker, &QObject::deleteLater);
        QObject::connect(thread, &QThread::finished, thread, &QObject::deleteLater);
        thread->start();
        threads.append(thread);

    }

    return a.exec();
}
