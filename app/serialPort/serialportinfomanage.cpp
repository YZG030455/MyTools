#include "serialportinfomanage.h"

#include <QDebug>

static SerialPortInfoManage *G_SerialPortInfoManage = NULL;
/**
 * @brief 创建单例模式
 * @return
 */
SerialPortInfoManage *SerialPortInfoManage::instance()
{
    if(G_SerialPortInfoManage == NULL)
    {
        new SerialPortInfoManage();
    }
    return G_SerialPortInfoManage;
}

/**
 * @brief 设置发送到串口的信息
 * @param buff
 */
void SerialPortInfoManage::setSendToSerialPortInfo(QByteArray buff)
{
    emit signalSendToSerialPortInfo(buff);
}

/**
 * @brief 接收串口信息
 * @param buff
 */
void SerialPortInfoManage::setReceiveSerialPortInfo(QByteArray buff)
{
    emit signalReceiveSerialPortInfo(buff);
}

/**
 * @brief 串口操作信息
 * @param info
 */
void SerialPortInfoManage::setOperationInfo(QString info)
{
    emit signalOperationInfo(info);
}

SerialPortInfoManage::SerialPortInfoManage(QObject *parent)
    : QObject(parent)
{
    G_SerialPortInfoManage = this;
}
