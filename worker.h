#ifndef WORKER_H
#define WORKER_H
#include "bankaccount.h"
#include <QObject>

class Worker:public QObject
{
     Q_OBJECT // 必须包含 Q_OBJECT 宏
public:
    explicit Worker(BankAccount&bank,int id,QObject* parent = nullptr);
    void run();
signals:
    void finished(); // 声明完成信号
private:
     BankAccount& account;
     int threadId;
};

#endif // WORKER_H
