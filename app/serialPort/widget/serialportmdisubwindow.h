/*!
 *  @brief   为接收与发送串口信息提供显示的窗口
 *  @details
 *  @author   YZG
 *  @version
 *  @date     20190509
 *  @warning
 *  @copyright NanJing RenGu.
 *  @note
 */
#ifndef SERIALPORTMDISUBWINDOW_H
#define SERIALPORTMDISUBWINDOW_H

#include <QMdiSubWindow>

class SerialPortMdiSubWindow : public QMdiSubWindow
{
    Q_OBJECT
public:
    SerialPortMdiSubWindow(QWidget *parent = Q_NULLPTR, Qt::WindowFlags flags = Qt::WindowFlags());
    ~SerialPortMdiSubWindow();

signals:

private slots:

private:
    void initSerialPortMdiSubWindow();


private:

};

#endif // SERIALPORTMDISUBWINDOW_H
