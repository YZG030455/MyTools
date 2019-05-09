#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QApplication>
#include <QString>
#include <QFile>
#include <QMessageBox>
#include <QTimer>
#include <QDateTime>

#include <QDomDocument>
#include <QFile>

#include "widgets/mdiarea.h"

#include "graph/graphmdisubwindow.h"
#include "table/tablemdisubwindow.h"
#include "music/musicmdisubwindow.h"
#include "topologicalGraph/topographwidget.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle(QStringLiteral("工具软件"));
    resize(800,640);

    initMainWindow();

    this->initAction();
    this->initMenu();
    initToolTip();
    initStatusTip();

    this->createDockWidget();
    this->createMdiArea();

//    locadStyleSheet();
    /*!< 刷新时间 */
    QTimer *t_time = new QTimer(this);
    t_time->start(1000);
    connect(t_time, SIGNAL(timeout()), this, SLOT(slotUpdateDateTime()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotVideoActTriggered()
{

}

void MainWindow::slotMusicActTriggered()
{

}

/**
 * @brief 刷新时间
 */
void MainWindow::slotUpdateDateTime()
{
    QDateTime dataTime = QDateTime::currentDateTime();
    QString timeStr = dataTime.toString("yyyy-MM-dd hh:mm:ss");
    m_timeLabel->setText(timeStr);
}

void MainWindow::initMainWindow()
{

}

/**
 * @brief MainWindow::initAction
 */
void MainWindow::initAction()
{
    /*!< 文件菜单栏  */
    openAct = new QAction(QStringLiteral("打开文件"), this);
    newAct = new QAction(QStringLiteral("新建文件"), this);
    saveAct = new QAction(QIcon(":/images/resource/images/save.png"),QStringLiteral("保存"), this);

    /*!< 工具栏 */
    videoAct = new QAction(QStringLiteral("视频播放器"), this);
    connect(videoAct, SIGNAL(triggered(bool)), this, SLOT(slotVideoActTriggered()));
    musicAct = new QAction(QStringLiteral("音乐播放器"), this);
    connect(musicAct, SIGNAL(triggered(bool)), this, SLOT(slotMusicActTriggered()));

    /*!< 帮助菜单栏  */
    helpAct = new QAction(QStringLiteral("帮助手册(&H)"), this);
    aboutAct = new QAction(QStringLiteral("关于(&A)"), this);

}

/**
 * @brief MainWindow::initMenu
 */
void MainWindow::initMenu()
{
    /*!< 文件菜单栏  */
    fileMenu  = ui->menuBar->addMenu(QStringLiteral("文件(&F)"));
    fileMenu->addAction(openAct);
    fileMenu->addAction(newAct);
    fileMenu->addAction(saveAct);
    /*!< 工具菜单栏  */
    toolsMenu = ui->menuBar->addMenu(QStringLiteral("工具(&T)"));

    /*!< 工具菜单栏  */
    netWorkMenu = ui->menuBar->addMenu(QStringLiteral("网络(N)"));

    /*!< 帮助菜单栏  */
    helpMenu = ui->menuBar->addMenu(QStringLiteral("帮助(&H)"));
    helpMenu->addAction(helpAct);
    helpMenu->addAction(aboutAct);
}

/**
 * @brief 工具栏
 */
void MainWindow::initToolTip()
{
    ui->mainToolBar->addAction(openAct);
    ui->mainToolBar->addAction(saveAct);
}

/**
 * @brief 状态栏
 */
void MainWindow::initStatusTip()
{
    m_timeLabel = new QLabel();
    ui->statusBar->addWidget(m_timeLabel);
}

/**
 * @brief 创建停靠窗口
 */
void MainWindow::createDockWidget()
{
    /*! <结构树> */
    FileTreeDockWidget *fileWidget = new FileTreeDockWidget();
    fileWidget->setWindowTitle("12");
    this->addDockWidget(Qt::LeftDockWidgetArea, fileWidget);
    /*! <操作日志> */
    LogInfoDockWidget *t_LogInfoDockWidget = new LogInfoDockWidget();
    t_LogInfoDockWidget->setWindowTitle("LogInfo");
    this->addDockWidget(Qt::BottomDockWidgetArea, t_LogInfoDockWidget);
}

/**
 * @brief 创建Mdi窗口
 */
void MainWindow::createMdiArea()
{
    m_pMdiArea = new MdiArea();


    QMdiArea *mdiArea = new QMdiArea();
    QMdiSubWindow *mdiSubWindow1 = new QMdiSubWindow();
    mdiSubWindow1->setWindowTitle(QStringLiteral("子窗口1"));
    mdiArea->addSubWindow(mdiSubWindow1);

    MusicMdiSubWindow *mdiSubWindow2 = new MusicMdiSubWindow();
    mdiSubWindow2->setWindowTitle(QStringLiteral("音乐"));
    mdiArea->addSubWindow(mdiSubWindow2);

    /*!< 图表子窗口 */
    GraphMdiSubWindow *graphMdiSubWindow = new GraphMdiSubWindow();
    mdiArea->addSubWindow(graphMdiSubWindow);

    /*!< 表格窗口 */
    TableMdiSubWindow * tableMdiSubWindow = new TableMdiSubWindow();
    mdiArea->addSubWindow(tableMdiSubWindow);

    /*! <拓扑图窗口> */
    TopoGraphWidget * t_TopoGraphWidget = new TopoGraphWidget();
    mdiArea->addSubWindow(t_TopoGraphWidget);

    /*! <设置窗口属性> */
    mdiArea->setActiveSubWindow(tableMdiSubWindow);      //激活图表子窗口
    mdiArea->setViewMode(QMdiArea::TabbedView);                    //添加"表格"
    mdiArea->setTabsClosable(false);                               //默认否，设为true时，tab上方形成一个关闭小按钮
    mdiArea->setTabsMovable(true);

    this->setCentralWidget(mdiArea);
}

/**
 * @brief 加载样式表
 */
void MainWindow:: locadStyleSheet()
{
    QString styleSheetPath = QString(":/styleSheet/resource/styleSheet/StyleSheet.qss");
    //    QString styleSheetPath = QString(":/styleSheet/resource/styleSheet/Black.qss");

    QFile styleFile(styleSheetPath);

    bool t_bOpen =  styleFile.open(QFile::ReadOnly);
    if(t_bOpen)
    {
        QString styleSheet = this->styleSheet();
        styleSheet += QLatin1String(styleFile.readAll());
        this->setStyleSheet(styleSheet);
        styleFile.close();
    }
    else {

    }
}

