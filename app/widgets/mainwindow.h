/*!
 *  @brief   主窗口配置
 *  @details
 *  @author
 *  @version   1.0
 *  @date
 *  @warning
 *  @copyright NanJing RenGu.
 *  @note
 */
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QDockWidget>
#include <QMdiArea>
#include <QMdiSubWindow>
#include <QLabel>

#include <widgets/dockwidget/filetreedockwidget.h>
#include <widgets/dockwidget/loginfodockwidget.h>

class MdiArea;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void slotVideoActTriggered();
    void slotMusicActTriggered();
    void slotUpdateDateTime();
private:
    void initMainWindow();
    void initAction();
    void initMenu();
    void initToolTip();
    void initStatusTip();

    void createDockWidget();
    void createMdiArea();
    void locadStyleSheet();

private:
    Ui::MainWindow *ui;

    /*!<  文件 */
    QAction * openAct;
    QAction * newAct;
    QAction * saveAct;
    QAction * saveAsAct;

    /*!< 工具  */
    QAction *videoAct;
    QAction *musicAct;

    QAction *helpAct;
    QAction *aboutAct;

    QMenu *fileMenu;
    QMenu *toolsMenu;
    QMenu *netWorkMenu;
    QMenu *helpMenu;

    MdiArea *m_pMdiArea;

    /* 状态栏显示系统时间 */
    QLabel *m_timeLabel;
};

#endif // MAINWINDOW_H
