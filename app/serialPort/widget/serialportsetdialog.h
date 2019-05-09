/*!
 *  @brief    串口参数配置窗口
 *  @details
 *  @author
 *  @version
 *  @date
 *  @warning
 *  @copyright NanJing RenGu.
 *  @note
 */
#ifndef SERIALPORTSETDIALOG_H
#define SERIALPORTSETDIALOG_H

#include <QDialog>

class SerialPortSetDialog : public QDialog
{
    Q_OBJECT
public:
    SerialPortSetDialog(QWidget *parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
    ~SerialPortSetDialog();


signals:

private slots:

private:
    void initDialog();

private:


};

#endif // SERIALPORTSETDIALOG_H
