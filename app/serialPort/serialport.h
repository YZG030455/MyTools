/*!
 *  @brief    串口通信
 *  @details
 *  @author
 *  @version
 *  @date
 *  @warning
 *  @copyright NanJing RenGu.
 *  @note
 */
#ifndef SERIALPORT_H
#define SERIALPORT_H

#include "widget/serialportglobal.h"

#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>


class SerialPort : public QObject
{
    Q_OBJECT
public:
    explicit SerialPort(QObject *parent = 0);
    ~SerialPort();

    void setSerialPortInfo(SerialPortInfo info);

    void openSerialPort();
    void closeSerialPort();
    bool clearSerialPort();
    bool isOpenSerialPort();

signals:

public slots:
    void slotSendToSerialPortInfo(QByteArray buff);
    void slotReceiveSerialPortInfo();

private:
    void initSerialPort();

private:
    QSerialPort *m_pSerialPort;   /*! <串口> */

};

#endif // SERIALPORT_H
