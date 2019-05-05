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
 * @brief 任务线程
 */
void TcpClientThread::run()
{

}
