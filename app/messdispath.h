/*!
 *  @brief     单例模式： 用于管理发送与接受
 *  @details
 *  @author
 *  @version
 *  @date
 *  @warning
 *  @copyright NanJing RenGu.
 *  @note
 */
#ifndef MESSDISPATH_H
#define MESSDISPATH_H

#include <QObject>

class MessDispath : public QObject
{
    Q_OBJECT
public:
    static MessDispath *instance();

    void setLogInfo(QString str);
    void setSendTonetWork(QByteArray buff);
    void setReceiveNetWork(QByteArray buff);

signals:
    void signalLogInfo(QString strLog);
    void signalSendTonetWork(QByteArray buff);
    void signalReceiveNetWork(QByteArray buff);

public slots:

private:
    explicit MessDispath(QObject *parent = 0);
};

#endif // MESSDISPATH_H
