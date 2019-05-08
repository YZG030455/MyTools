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

    void setStart();
    void setStop();


private slots:
    void slotSendToNetWork(QByteArray buff);

protected:
    void run();

private:
    QString getLocalIp();

private:
    QTcpSocket *m_tcpClient;
};

#endif // TCPCLIENTTHREAD_H
