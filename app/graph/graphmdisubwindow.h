#ifndef GRAPHMDISUBWINDOW_H
#define GRAPHMDISUBWINDOW_H

#include <QMdiSubWindow>

class GraphMdiSubWindowPrivate;
class GraphMdiSubWindow : public QMdiSubWindow
{
    Q_OBJECT
public:
    GraphMdiSubWindow(QWidget *parent = Q_NULLPTR, Qt::WindowFlags flags = Qt::WindowFlags());
    ~GraphMdiSubWindow();

private:
   void iniGraphMdiSubWindow();

private:


};

#endif // GRAPHMDISUBWINDOW_H
