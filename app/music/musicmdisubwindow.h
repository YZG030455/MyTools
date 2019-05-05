#ifndef MUSICMDISUBWINDOW_H
#define MUSICMDISUBWINDOW_H

#include <QMdiSubWindow>
#include <QPushButton>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMediaPlayer>
#include <QSpinBox>

class MusicMdiSubWindow : public QMdiSubWindow
{
    Q_OBJECT
public:
    MusicMdiSubWindow(QWidget *parent = Q_NULLPTR, Qt::WindowFlags flags = Qt::WindowFlags());
    ~MusicMdiSubWindow();

private slots:

    void slotPlayBtnClick();
    void slotStopBtnClick();
    void sloySpinBoxvalueChanged(int index);

private:
    void initMdiSubWindow();

private:
    QPushButton *m_btnPlay;
    QPushButton *m_btnStop;
    QSpinBox *m_SpinBox;
    QMediaPlayer *m_MediaPlayer;

};

#endif // MUSICMDISUBWINDOW_H
