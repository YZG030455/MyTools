#include "tcpserverthread.h"

#include <QDebug>
#include <QTcpServer>
#include <QTcpSocket>

TcpServerThread::TcpServerThread(QObject *parent)
    : QThread(parent)
{

    m_tcpServer = NULL;
    m_tcpSocket = NULL;

}

TcpServerThread::~TcpServerThread()
{

}

/**
 * @brief 初始化Tcp服务器
 */
void TcpServerThread::initTcpServer()
{
   m_tcpServer = new QTcpServer();
}

void TcpServerThread::run()
{

}
