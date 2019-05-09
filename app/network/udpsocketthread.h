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
#include <QAbstractSocket>
#include <QHostAddress>

class QUdpSocket;
class UdpSocketThread : public QThread
{
    Q_OBJECT
public:
    UdpSocketThread(QObject *parent = Q_NULLPTR);
    ~UdpSocketThread();

    void initUdpSocketThread();
    void initUnicastUdpSocket();
    void initBroadcastUdpSocket();
    void initMulticastUdpSocket();

    void startThread();
    void stopThread();

public slots:
    void slotSendToUnicastSocket(QByteArray buff);
    void slotUnicastSocketReadyRead();
    void slotSendToBroadcastSocket(QByteArray buff);
    void slotBroadcastSocketReadyRead();
    void slotSendToMulticastSocket(QByteArray buff);
    void slotMulticastSocketReadyRead();
    void slotUdpSocketStateChange(QAbstractSocket::SocketState state);

protected:
    void run();

private:
    QString getLocalIp();
    void setStopUdpSocket();

private:
    QUdpSocket *m_pUnicastUdpSocket;        /*! <单播模式> */
    QUdpSocket *m_pBroadcastUdpSocket;      /*! <广播模式> */
    QUdpSocket *m_pMulticastUdpSocket;      /*! <组播模式> */

    QString m_localIp ;             /*! <本地ip> */
    quint16 m_localPort;            /*! <本地端口> */
    QString m_targetIp;             /*! <目标Ip> */
    quint16 m_targetPort;           /*! <目标端口> */

    QHostAddress m_GroupIp;         /*! <组播Ip> */
    quint16 m_groupPort;            /*! <组播端口> */

};

#endif // UDPSOCKETTHREAD_H
