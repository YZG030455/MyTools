#include "tcpserverthread.h"
#include "messdispath.h"

#include <QDebug>
#include <QTcpServer>
#include <QTcpSocket>
#include <QHostInfo>

TcpServerThread::TcpServerThread(QObject *parent)
    : QThread(parent)
{

    m_tcpServer = NULL;
    m_tcpSocket = NULL;

    initTcpServer();

}

TcpServerThread::~TcpServerThread()
{

}

/**
 * @brief 初始化Tcp服务器
 */
void TcpServerThread::initTcpServer()
{
    m_localIp = getLocalIp();
    m_localPort = 6800;
    m_tcpServer = new QTcpServer();

    /*! <将字符串Ip转化为> */
    QHostAddress t_localHostAddress(m_localIp);
    m_tcpServer->listen(t_localHostAddress, m_localPort);   // 开始监听

    /*! <信号与槽> */
    connect(MessDispath::instance(), SIGNAL(signalSendTonetWork(QByteArray)), this, SLOT(slotSendToNetwork(QByteArray)));
    connect(m_tcpServer, SIGNAL(newConnection()), this, SLOT(slotTcpServerConnection()));
}

/**
 * @brief 在Tcp服务器每次新连接可用时发出 信号
 */
void TcpServerThread::slotTcpServerConnection()
{
    m_tcpSocket = m_tcpServer->nextPendingConnection();     // 获取Socket

    connect(m_tcpSocket, SIGNAL(connected()), this, SLOT(slotSocketLink()));
    connect(m_tcpSocket, SIGNAL(disconnected()), this, SLOT(slotSocketDisLink()));
    connect(m_tcpSocket, SIGNAL(stateChanged(QAbstractSocket::SocketState)), this, SLOT(slotSocketStateChange(QAbstractSocket::SocketState)));
    connect(m_tcpSocket, SIGNAL(readyRead()), this, SLOT(slotReceiveNetwork()));
}

/**
 * @brief 网络状态改变
 * @param state
 */
void TcpServerThread::slotSocketStateChange(QAbstractSocket::SocketState state)
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
 * @brief 网络连接
 */
void TcpServerThread::slotSocketLink()
{
    qDebug() << "NetWork link";
}

/**
 * @brief 网络断开连接
 */
void TcpServerThread::slotSocketDisLink()
{
    qDebug() << "NetWork Dis link";
}

/**
 * @brief 发送信息到网络Scoket
 * @param buff
 */
void TcpServerThread::slotSendToNetwork(QByteArray buff)
{
    /*! <将发送的信息写入管道中> */
    m_tcpSocket->write(buff);
}

/**
 * @brief 接收网络信息
 */
void TcpServerThread::slotReceiveNetwork()
{
    while (m_tcpSocket->canReadLine())
    {
        /*! <读取缓冲行信息> */
       MessDispath::instance()->setReceiveNetWork(m_tcpSocket->readLine());
    }
}

/**
 * @brief
 */
void TcpServerThread::run()
{

}

/**
 * @brief 获取本地Ip
 * @return
 */
QString TcpServerThread::getLocalIp()
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
