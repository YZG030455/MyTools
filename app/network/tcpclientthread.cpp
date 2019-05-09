#include "tcpclientthread.h"
#include "messdispath.h"

#include <QDebug>
#include <QTcpSocket>
#include <QHostInfo>
#include <QHostAddress>

TcpClientThread::TcpClientThread(QObject *parent)
    : QThread(parent)
{
    m_tcpSocket = NULL;

    /*! <初始化Tcp客户端> */
    initTcpClient();
}

TcpClientThread::~TcpClientThread()
{

}

/**
 * @brief 初始化Tcp客户端
 */
void TcpClientThread::initTcpClient()
{
    m_tcpSocket = new  QTcpSocket();
    m_localIp = getLocalIp();

    /*! <信号与槽> */
    connect(MessDispath::instance(), SIGNAL(signalSendTonetWork(QByteArray)), this, SLOT(slotSendToNetWork(QByteArray)));
    connect(m_tcpSocket, SIGNAL(connected()), this, SLOT(slotTcpSocketLink()));
    connect(m_tcpSocket, SIGNAL(disconnected()), this, SLOT(slotTcpSocketDisLink()));
    connect(m_tcpSocket, SIGNAL(stateChanged(QAbstractSocket::SocketState)), this, SLOT(slotTcpSocketStateChange(QAbstractSocket::SocketState)));
    connect(m_tcpSocket, SIGNAL(readyRead()), this, SLOT(slotSocketReadyRead()));
}

/**
 * @brief 开启线程
 */
void TcpClientThread::setStart()
{

}

/**
 * @brief 关闭线程
 */
void TcpClientThread::setStop()
{

}

/**
 * @brief 用于向scoket 发送信息
 * @param buff
 */
void TcpClientThread::slotSendToNetWork(QByteArray buff)
{
    m_tcpSocket->write(buff);
}

/**
 * @brief 查看网络状态
 * @param state
 */
void TcpClientThread::slotTcpSocketStateChange(QAbstractSocket::SocketState state)
{
    switch (state) {
    case QAbstractSocket::UnconnectedState:
    {

        break;
    }
    case QAbstractSocket::HostLookupState:
    {

        break;
    }
    case QAbstractSocket::ConnectingState:
    {

        break;
    }
    case QAbstractSocket::ConnectedState:
    {

        break;
    }
    case QAbstractSocket::BoundState:
    {

        break;
    }
    case QAbstractSocket::ClosingState:
    {

        break;
    }
    case QAbstractSocket::ListeningState:
    {

        break;
    }
    default:
        break;
    }
}

/**
 * @brief 连接网络
 */
void TcpClientThread::slotTcpSocketLink()
{

}

/**
 * @brief 断开连接
 */
void TcpClientThread::slotTcpSocketDisLink()
{

}

/**
 * @brief 读取接收到的网络信息
 */
void TcpClientThread::slotSocketReadyRead()
{
    while (m_tcpSocket->canReadLine()) {
        QByteArray buff = m_tcpSocket->readLine();
    }
}

/**
 * @brief 任务线程
 */
void TcpClientThread::run()
{

}

/**
 * @brief 获取本地Ip
 * @return
 */
QString TcpClientThread::getLocalIp()
{
    QString localIp;
    // 获取本机IPV4地址
    QString hostName = QHostInfo::localHostName();  // 本地主机名
    QHostInfo hostinfo = QHostInfo::fromName(hostName);
    QList<QHostAddress >  listAddresss =  hostinfo.addresses();
    if( !listAddresss.isEmpty() )
    {
        for(int i = 0; i < listAddresss.size(); i++ )
        {
            QHostAddress hostAddress = listAddresss.at(i);
            if(QAbstractSocket::IPv4Protocol == hostAddress.protocol())
            {
                localIp = hostAddress.toString();
                break;
            }
        }
    }
    return localIp;
}
