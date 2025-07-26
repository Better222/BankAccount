#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <QMutex>
#include <QThread>
#include <QDebug>

class BankAccount
{
public:
    BankAccount(int balance);
    void deposit(int amount);
    void withdraw(int amount);
private:
    int m_balance;
    QMutex m_mutex;
};

#endif // BANKACCOUNT_H
