/*!
 *  @brief      创建UdpSocket线程（创建线程的一）
 *  @details
 *  @author
 *  @version
 *  @date
 *  @warning
 *  @copyright NanJing RenGu.
 *  @note
 */
#ifndef UDPSOCKETTHREAD_H
#define UDPSOCKETTHREAD_H

#include <QThread>

class QUdpSocket;
class UdpSocketThread : public QThread
{
    Q_OBJECT
public:
    UdpSocketThread(QObject *parent = Q_NULLPTR);
    ~UdpSocketThread();

      void initUdpSocketThread();

      void startThread();
      void stopThread();

public slots:


protected:
    void run();

private:

private:
    QUdpSocket *m_pUdpSocket;

};

#endif // UDPSOCKETTHREAD_H
