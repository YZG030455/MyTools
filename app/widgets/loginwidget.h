/*!
 *  @brief   该窗口为用户登陆界面
 *  @details
 *  @author
 *  @version   1.0
 *  @date    20190326
 *  @warning
 *  @copyright NanJing RenGu.
 *  @note
 */
#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QWidget>
#include <QSharedPointer>


class LoginWidget : public QWidget
{
    Q_OBJECT
public:
    explicit LoginWidget(QWidget *parent = 0);
    ~LoginWidget();
signals:

public slots:
    void slotLoginBtnClick();

private:
    void initLoginWidget();

private:


};

#endif // LOGINWIDGET_H
