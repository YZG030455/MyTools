/*!
 *  @brief      创建TCP服务器线程
 *  @details
 *  @author
 *  @version
 *  @date       20190425
 *  @warning
 *  @copyright NanJing RenGu.
 *  @note
 */
#ifndef TCPSERVERTHREAD_H
#define TCPSERVERTHREAD_H

#include <QThread>

class QTcpServer;
class QTcpSocket;
class TcpServerThread : public QThread
{
    Q_OBJECT
public:
    TcpServerThread(QObject *parent = Q_NULLPTR);
    ~TcpServerThread();

    void initTcpServer();

protected:
    void run();

private:
    QTcpServer *m_tcpServer;
    QTcpSocket *m_tcpSocket;

};

#endif // TCPSERVERTHREAD_H
