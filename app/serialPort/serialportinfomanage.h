/*!
 *  @brief    用于串口信息管理
 *  @details
 *  @author
 *  @version
 *  @date
 *  @warning
 *  @copyright NanJing RenGu.
 *  @note
 */
#ifndef SERIALPORTINFOMANAGE_H
#define SERIALPORTINFOMANAGE_H

#include <QObject>

class SerialPortInfoManage : public QObject
{
    Q_OBJECT
public:
    static SerialPortInfoManage *instance();

    void setSendToSerialPortInfo(QByteArray buff);
    void setReceiveSerialPortInfo(QByteArray buff);
    void setOperationInfo(QString info);

signals:
    void signalSendToSerialPortInfo(QByteArray buff);
    void signalReceiveSerialPortInfo(QByteArray buff);
    void signalOperationInfo(QString info);

public slots:

private:
    explicit SerialPortInfoManage(QObject *parent = 0);
};

#endif // SERIALPORTINFOMANAGE_H
