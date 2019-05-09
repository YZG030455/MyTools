#include "serialportmdisubwindow.h"

#include <QDebug>


SerialPortMdiSubWindow::SerialPortMdiSubWindow(QWidget *parent, Qt::WindowFlags flags)
    : QMdiSubWindow(parent, flags)
{


    initSerialPortMdiSubWindow();
}

SerialPortMdiSubWindow::~SerialPortMdiSubWindow()
{

}

/**
 * @brief 初始化窗口
 */
void SerialPortMdiSubWindow::initSerialPortMdiSubWindow()
{

}
