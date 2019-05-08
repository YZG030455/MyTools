#include "tcpclientthread.h"

#include <QDebug>
#include <QTcpSocket>

TcpClientThread::TcpClientThread(QObject *parent)
    : QThread(parent)
{
    m_tcpClient = NULL;

}

TcpClientThread::~TcpClientThread()
{

}

/**
 * @brief 初始化Tcp客户端
 */
void TcpClientThread::initTcpClient()
{
    m_tcpClient = new  QTcpSocket();

}

/**
 * @brief 开启线程
 */
void TcpClientThread::setStart()
{

}

void TcpClientThread::setStop()
{

}

/**
 * @brief 用于向scoket 发送信息
 * @param buff
 */
void TcpClientThread::slotSendToNetWork(QByteArray buff)
{

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
