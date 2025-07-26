#include "worker.h"

Worker::Worker(BankAccount &bank, int id,QObject* parent)
    :QObject(parent),account(bank),threadId(id)
{
}

void Worker::run()
{
    qDebug()<<"run threadId:"<<threadId;
    for(int j = 0; j< 2; j++)
    {
        if(threadId % 2 == 0)
        {
            account.deposit(50);//存50
        }
        else
        {
            account.withdraw(30);//取30
        }
        QThread::msleep(10);
    }
    emit finished();
}
