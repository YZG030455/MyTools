#include "udpsocketthread.h"
#include "messdispath.h"

#include <QDebug>
#include <QUdpSocket>
#include <QHostInfo>

UdpSocketThread::UdpSocketThread(QObject *parent)
    : QThread(parent)
{
    m_pUnicastUdpSocket = NULL;
    m_pBroadcastUdpSocket = NULL;
    m_pMulticastUdpSocket = NULL;

    this->initUdpSocketThread();
}

UdpSocketThread::~UdpSocketThread()
{

}
/**
 * @brief
 */
void UdpSocketThread::initUdpSocketThread()
{
    m_localIp = getLocalIp();
    m_localPort = 6800;
    /*! <单播> */
    initUnicastUdpSocket();
    /*! <广播> */
    initBroadcastUdpSocket();
    /*! <组播> */
    initMulticastUdpSocket();
}

/**
 * @brief 初始化 单播模式
 */
void UdpSocketThread::initUnicastUdpSocket()
{
    m_pUnicastUdpSocket = new QUdpSocket(this);
    /*! <绑定本机端口> */
    bool bind = m_pUnicastUdpSocket->bind(m_localPort);
    if(bind)
    {

    }
    else {

    }

    /*! <信号与槽> */
    connect(MessDispath::instance(), SIGNAL(signalSendTonetWork(QByteArray)), this, SLOT(slotSendToUnicastSocket(QByteArray)));
    connect(m_pUnicastUdpSocket, SIGNAL(stateChanged(QAbstractSocket::SocketState)),
            this, SLOT(slotUdpSocketStateChange(QAbstractSocket::SocketState)));
    slotUdpSocketStateChange(m_pUnicastUdpSocket->state());
    connect(m_pUnicastUdpSocket, SIGNAL(readyRead()), this, SLOT(slotUnicastSocketReadyRead()));
}

/**
 * @brief 初始化广播模式
 */
void UdpSocketThread::initBroadcastUdpSocket()
{
    m_pBroadcastUdpSocket = new QUdpSocket(this);
    /*! <绑定本机端口> */
    bool bind = m_pBroadcastUdpSocket->bind(m_localPort);
    if(bind)
    {

    }
    else {

    }

    /*! <信号与槽> */
    connect(MessDispath::instance(), SIGNAL(signalSendTonetWork(QByteArray)), this, SLOT(slotSendToBroadcastSocket(QByteArray)));
    connect(m_pBroadcastUdpSocket, SIGNAL(stateChanged(QAbstractSocket::SocketState)),
            this, SLOT(slotUdpSocketStateChange(QAbstractSocket::SocketState)));
    slotUdpSocketStateChange(m_pBroadcastUdpSocket->state());
    connect(m_pBroadcastUdpSocket, SIGNAL(readyRead()), this, SLOT(slotUnicastSocketReadyRead()));
}

/**
 * @brief 初始化组播模式
 */
void UdpSocketThread::initMulticastUdpSocket()
{
    /*! <组播Ip> */
    QString t_GroupIp = QString("1.1.1.1");
    m_GroupIp = QHostAddress(t_GroupIp);
    /*! <组播端口> */
    m_groupPort =  6800;

    m_pMulticastUdpSocket = new QUdpSocket(this);
    m_pMulticastUdpSocket->setSocketOption(QAbstractSocket::MulticastTtlOption, 1);

    /*! <绑定本机端口> */
    bool bind = m_pMulticastUdpSocket->bind(QHostAddress::AnyIPv4, m_groupPort, QUdpSocket::ShareAddress);
    if(bind)
    {
        /*! <加入多播组> */
        m_pMulticastUdpSocket->joinMulticastGroup(m_GroupIp);
    }
    else {

    }

    /*! <信号与槽> */
    connect(MessDispath::instance(), SIGNAL(signalSendTonetWork(QByteArray)), this, SLOT(slotSendToMulticastSocket(QByteArray)));
    connect(m_pMulticastUdpSocket, SIGNAL(stateChanged(QAbstractSocket::SocketState)),
            this, SLOT(slotUdpSocketStateChange(QAbstractSocket::SocketState)));
    slotUdpSocketStateChange(m_pMulticastUdpSocket->state());
    connect(m_pMulticastUdpSocket, SIGNAL(readyRead()), this, SLOT(slotUnicastSocketReadyRead()));
}

/**
 * @brief 开启线程
 */
void UdpSocketThread::startThread()
{

}

/**
 * @brief 关闭线程
 */
void UdpSocketThread::stopThread()
{

}

/**
 * @brief 发送信息到单播UdpSocket
 * @param buff
 */
void UdpSocketThread::slotSendToUnicastSocket(QByteArray buff)
{
    QHostAddress t_targetIp(m_targetIp);        //目标Ip
    m_pUnicastUdpSocket->writeDatagram(buff, t_targetIp, m_targetPort);
}

/**
 * @brief 读取单播管道的信息
 */
void UdpSocketThread::slotUnicastSocketReadyRead()
{
    while (m_pUnicastUdpSocket->hasPendingDatagrams())              //是否有待读取的传入数据
    {
        QByteArray buff;
        buff.resize(m_pUnicastUdpSocket->pendingDatagramSize());    // 返回待读取数据报的字节数
        //        QHostAddress peerAddr;    // 数据来源Ip
        //        quint16 peerPort;         // 数据来源端口
        //        m_pUnicastUdpSocket->readDatagram(buff.data(), buff.size(), peerAddr, peerPort);

        m_pUnicastUdpSocket->readDatagram(buff.data(), buff.size());

        MessDispath::instance()->setReceiveNetWork(buff);
    }
}

/**
 * @brief 发送信息到广播UdpSocket
 * @param buff
 */
void UdpSocketThread::slotSendToBroadcastSocket(QByteArray buff)
{
    m_pBroadcastUdpSocket->writeDatagram(buff, QHostAddress::Broadcast, m_targetPort);
}

/**
 * @brief 读取广播管道的信息
 */
void UdpSocketThread::slotBroadcastSocketReadyRead()
{
    while (m_pUnicastUdpSocket->hasPendingDatagrams())              //是否有待读取的传入数据
    {
        QByteArray buff;
        buff.resize(m_pBroadcastUdpSocket->pendingDatagramSize());    // 返回待读取数据报的字节数
        //        QHostAddress peerAddr;    // 数据来源Ip
        //        quint16 peerPort;         // 数据来源端口
        //        m_pBroadcastUdpSocket->readDatagram(buff.data(), buff.size(), peerAddr, peerPort);

        m_pBroadcastUdpSocket->readDatagram(buff.data(), buff.size());

        MessDispath::instance()->setReceiveNetWork(buff);
    }
}

/**
 * @brief 发送信息到组播UdpSocket
 * @param buff
 */
void UdpSocketThread::slotSendToMulticastSocket(QByteArray buff)
{
    m_pMulticastUdpSocket->writeDatagram(buff, m_GroupIp, m_groupPort);
}

/**
 * @brief 读取组播Socket信息
 */
void UdpSocketThread::slotMulticastSocketReadyRead()
{
    while (m_pMulticastUdpSocket->hasPendingDatagrams())              //是否有待读取的传入数据
    {
        QByteArray buff;
        buff.resize(m_pMulticastUdpSocket->pendingDatagramSize());    // 返回待读取数据报的字节数
        //        QHostAddress peerAddr;    // 数据来源Ip
        //        quint16 peerPort;         // 数据来源端口
        //        m_pBroadcastUdpSocket->readDatagram(buff.data(), buff.size(), peerAddr, peerPort);

        m_pMulticastUdpSocket->readDatagram(buff.data(), buff.size());

        MessDispath::instance()->setReceiveNetWork(buff);
    }
}

/**
 * @brief 查看网络连接状态
 * @param state
 */
void UdpSocketThread::slotUdpSocketStateChange(QAbstractSocket::SocketState state)
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
 * @brief 开启线程资源
 */
void UdpSocketThread::run()
{

}

/**
 * @brief 获取本地Ip
 * @return
 */
QString UdpSocketThread::getLocalIp()
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

/**
 * @brief 退出网络
 */
void UdpSocketThread::setStopUdpSocket()
{
    if (m_pUnicastUdpSocket != NULL)
    {
        m_pUnicastUdpSocket->abort();     //解除绑定
    }
    if (m_pBroadcastUdpSocket != NULL)
    {
        m_pBroadcastUdpSocket->abort();     //解除绑定
    }
    if (m_pMulticastUdpSocket != NULL)
    {
        m_pMulticastUdpSocket->leaveMulticastGroup(m_GroupIp);  // 退出组播
        m_pMulticastUdpSocket->abort();     //解除绑定
    }
}
