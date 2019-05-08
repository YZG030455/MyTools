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
#include <QAbstractSocket>

class QTcpServer;
class QTcpSocket;
class TcpServerThread : public QThread
{
    Q_OBJECT
public:
    TcpServerThread(QObject *parent = Q_NULLPTR);
    ~TcpServerThread();

    void initTcpServer();

private slots:
    void slotTcpServerConnection();
    void slotSocketStateChange(QAbstractSocket::SocketState state);
    void slotSocketLink();
    void slotSocketDisLink();
    void slotSendToNetwork(QByteArray buff);
    void slotReceiveNetwork();

protected:
    void run();

private:
    QString getLocalIp();

private:
    QTcpServer *m_tcpServer;        /*! <Tcp服务器> */
    QTcpSocket *m_tcpSocket;        /*! <TCP通信的Socket> */

    QString m_localIp ;             /*! <本地ip> */
    quint16 m_localPort;            /*! <本地端口> */
    QString m_targetIp;             /*! <目标Ip> */
    quint16 m_targetPort;           /*! <目标端口> */
};

#endif // TCPSERVERTHREAD_H
