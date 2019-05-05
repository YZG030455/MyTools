/*!
 *  @brief   创建网络线程
 *  @details
 *  @author
 *  @version
 *  @date
 *  @warning
 *  @copyright NanJing RenGu.
 *  @note
 */
#ifndef NETWORKTASKTHREAD_H
#define NETWORKTASKTHREAD_H

#include <QThread>

class NetworkTaskThread : public QThread
{
    Q_OBJECT
public:
    NetworkTaskThread(QObject *parent = Q_NULLPTR);
    ~NetworkTaskThread();

signals:

protected:
    virtual void run();

private slots:

private:

};

#endif // NETWORKTASKTHREAD_H
