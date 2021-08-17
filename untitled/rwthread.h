#ifndef RWTHREAD_H
#define RWTHREAD_H

#include<QRunnable>
#include<QString>
class Rwthread : public QRunnable
{
public:
    Rwthread(int id);

    void run() Q_DECL_OVERRIDE;
    int id;
    QString user_outline;
    QString user_outline2;
private:

};

#endif // RWTHREAD_H
