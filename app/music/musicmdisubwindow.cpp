#include "musicmdisubwindow.h"

#include <QDebug>

MusicMdiSubWindow::MusicMdiSubWindow(QWidget *parent, Qt::WindowFlags flags)
    : QMdiSubWindow(parent, flags)
{
    setWindowTitle("music");

    this->initMdiSubWindow();
}

MusicMdiSubWindow::~MusicMdiSubWindow()
{

}

/**
 * @brief 点击播放按钮 进行播放
 */
void MusicMdiSubWindow::slotPlayBtnClick()
{
    m_MediaPlayer->play();
}

/**
 * @brief MusicMdiSubWindow::slotStopBtnClick
 */
void MusicMdiSubWindow::slotStopBtnClick()
{
    m_MediaPlayer->stop();
}

/**
 * @brief MusicMdiSubWindow::sloySpinBoxvalueChanged
 * @param index
 */
void MusicMdiSubWindow::sloySpinBoxvalueChanged(int index)
{
//    m_MediaPlayer->setLoopCount(index);
}

/**
 * @brief 初始化音乐播放器窗口
 */
void MusicMdiSubWindow::initMdiSubWindow()
{

    m_btnPlay = new QPushButton();
    m_btnPlay->setText("播放");
    connect(m_btnPlay, SIGNAL(clicked(bool)), this, SLOT(slotPlayBtnClick()));

    m_btnStop =  new QPushButton();
    m_btnStop->setText("停止");
    connect(m_btnStop, SIGNAL(clicked(bool)), this, SLOT(slotStopBtnClick()));
    m_SpinBox = new QSpinBox();
//    connect(m_SpinBox, SIGNAL(valueChanged(int)), this, SLOT());

    QVBoxLayout *t_layout = new QVBoxLayout();
    t_layout->addWidget(m_btnPlay);
    t_layout->addWidget(m_btnStop);
    QWidget *t_mainWidget = new QWidget();
    t_mainWidget->setLayout(t_layout);

    this->setWidget(t_mainWidget);
}
