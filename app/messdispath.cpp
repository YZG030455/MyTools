#include "messdispath.h"

#include <QDebug>

static MessDispath *G_MessDispath = NULL;

/**
 * @brief 创建单例对象
 * @return
 */
MessDispath *MessDispath::instance()
{
    if(G_MessDispath == NULL)
    {
        new MessDispath;
    }
    return G_MessDispath;
}

/**
 * @brief 设置操作信息: 发送到日志信息窗口
 * @param str 日志信息
 */
void MessDispath::setLogInfo(QString str)
{
    emit signalLogInfo(str);
}

/**
 * @brief 向网络接口发送数据
 * @param buff
 */
void MessDispath::setSendTonetWork(QByteArray buff)
{
    emit signalSendTonetWork(buff);
}

/**
 * @brief 接收网络Socket数据信息
 * @param buff
 */
void MessDispath::setReceiveNetWork(QByteArray buff)
{
    emit signalReceiveNetWork(buff);
}

MessDispath::MessDispath(QObject *parent)
    : QObject(parent)
{
    G_MessDispath = this;
}
