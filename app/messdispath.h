/*!
 *  @brief     单例模式： 用于管理发送与节水
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

signals:
    void signalLogInfo(QString strLog);

public slots:

private:
    explicit MessDispath(QObject *parent = 0);
};

#endif // MESSDISPATH_H
