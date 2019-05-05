/*!
 *  @brief      创建TCP客户端
 *  @details
 *  @author
 *  @version
 *  @date       20190425
 *  @warning
 *  @copyright NanJing RenGu.
 *  @note
 */
#ifndef TCPCLIENTTHREAD_H
#define TCPCLIENTTHREAD_H

#include <QThread>

class QTcpSocket;
class TcpClientThread : public QThread
{
    Q_OBJECT
public:
    TcpClientThread(QObject *parent = Q_NULLPTR);
    ~TcpClientThread();

    void initTcpClient();

protected:
    void run();

private:
    QTcpSocket *m_tcpClient;
};

#endif // TCPCLIENTTHREAD_H
