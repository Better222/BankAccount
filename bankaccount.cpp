#include "bankaccount.h"

BankAccount::BankAccount(int balance):m_balance(balance)
{

}
//存款
void BankAccount::deposit(int amount)
{
    QMutexLocker locker(&m_mutex);
    m_balance += amount;
    qDebug() << "Deposited:" << amount
             << "Balance:" << m_balance
             << "Thread:" << QThread::currentThread();
}
//取款
void BankAccount::withdraw(int amount)
{
    QMutexLocker locker(&m_mutex);
    if (m_balance >= amount)
        m_balance -= amount;
    qDebug() << "withdraw:" << amount
             << "Balance:" << m_balance
             << "Thread:" << QThread::currentThread();
}
