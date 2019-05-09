/*!
 *  @brief    串口信息及串口的结构体； 串口报文
 *  @details
 *  @author
 *  @version
 *  @date
 *  @warning
 *  @copyright NanJing RenGu.
 *  @note
 */
#ifndef SERIALPORTGLOBAL_H
#define SERIALPORTGLOBAL_H

#include <QObject>
#include <QString>
#include <QSerialPort>

/**
 * @brief 串口基本信息
 */
struct SerialPortInfo{
    QString name;       //串口名
    qint32 baudRate;
    QString stringBaudRate;
    QSerialPort::DataBits dataBits;
    QString stringDataBits;
    QSerialPort::Parity parity;
    QString stringParity;
    QSerialPort::StopBits stopBits;
    QString stringStopBits;
    QSerialPort::FlowControl flowControl;
    QString stringFlowControl;
    bool localEchoEnabled;
};

class SerialPortGlobal
{
public:
    SerialPortGlobal();
};

#endif // SERIALPORTGLOBAL_H
