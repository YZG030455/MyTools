/*!
 *  @brief    基于Http协议的网络
 *  @details
 *  @author   yzg
 *  @version
 *  @date     20190509
 *  @warning
 *  @copyright NanJing RenGu.
 *  @note
 */
#ifndef HTTPPROTOCOLTHREAD_H
#define HTTPPROTOCOLTHREAD_H

#include <QThread>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QNetworkAccessManager>

class HttpProtocolThread : public QThread
{
    Q_OBJECT
public:
    HttpProtocolThread(QObject *parent = Q_NULLPTR);
    ~HttpProtocolThread();

    void initHttpProtocolThread();

    void setStart();
    void setStop();

protected:
    void run();

private:

};

#endif // HTTPPROTOCOLTHREAD_H
