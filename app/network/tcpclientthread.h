/*!
 *  @brief      创建TCP客户端
 *  @details
 *  @author    yzg
 *  @version
 *  @date       20190425
 *  @warning
 *  @copyright  NanJing RenGu.
 *  @note
 */
#ifndef TCPCLIENTTHREAD_H
#define TCPCLIENTTHREAD_H

#include <QThread>
#include <QAbstractSocket>

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
    void slotTcpSocketStateChange(QAbstractSocket::SocketState state);
    void slotTcpSocketLink();
    void slotTcpSocketDisLink();
    void slotSocketReadyRead();

protected:
    void run();

private:
    QString getLocalIp();

private:
    QTcpSocket *m_tcpSocket;        /*! <创建Socket通信> */
    QString m_localIp ;             /*! <本地ip> */
    quint16 m_localPort;            /*! <本地端口> */
    QString m_targetIp;             /*! <目标Ip> */
    quint16 m_targetPort;           /*! <目标端口> */

};

#endif // TCPCLIENTTHREAD_H
