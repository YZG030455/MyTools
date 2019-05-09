#include "serialport.h"
#include "serialportinfomanage.h"

#include <QDebug>

SerialPort::SerialPort(QObject *parent)
    : QObject(parent)
{
    m_pSerialPort = NULL;

    this->initSerialPort();
}

SerialPort::~SerialPort()
{

}

/**
 * @brief 设置串口信息
 */
void SerialPort::setSerialPortInfo(SerialPortInfo info)
{
    m_pSerialPort->setPortName(info.name);
}

/**
 * @brief 开启端口
 * @return
 */
void SerialPort::openSerialPort()
{
    if(m_pSerialPort->isOpen())
    {
        return ;
    }
    m_pSerialPort->open(QIODevice::ReadWrite);
}

/**
 * @brief 关闭串口
 * @return
 */
void SerialPort::closeSerialPort()
{
    if(m_pSerialPort->isOpen())
    {
        m_pSerialPort->close();
    }
}

/**
 * @brief 清空串口
 * @return
 */
bool SerialPort::clearSerialPort()
{
    return true;
}

/**
 * @brief 串口是否开启
 * @return
 */
bool SerialPort::isOpenSerialPort()
{
  return  m_pSerialPort->isOpen();
}

/**
 * @brief 将发送到串口的信息写到串口中
 * @param buff
 */
void SerialPort::slotSendToSerialPortInfo(QByteArray buff)
{
    m_pSerialPort->write(buff);
}

/**
 * @brief 读取串口信息
 */
void SerialPort::slotReceiveSerialPortInfo()
{
    QByteArray t_data = m_pSerialPort->readAll();
    SerialPortInfoManage::instance()->setReceiveSerialPortInfo(t_data);
}

/**
 * @brief 初始化窗口
 */
void SerialPort::initSerialPort()
{
    m_pSerialPort = new QSerialPort();

    /*! <信号与槽> */
    connect(SerialPortInfoManage::instance(), SIGNAL(signalSendToSerialPortInfo(QByteArray)),
            this, SLOT(slotSendToSerialPortInfo(QByteArray)));
    connect(m_pSerialPort, SIGNAL(readyRead()), this, SLOT(slotReceiveSerialPortInfo()));
}
