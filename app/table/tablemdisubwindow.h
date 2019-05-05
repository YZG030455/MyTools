#ifndef TABLEMDISUBWINDOW_H
#define TABLEMDISUBWINDOW_H

#include <QMdiSubWindow>

class TableView;
class StandardItemModel;

class TableMdiSubWindow : public QMdiSubWindow
{
    Q_OBJECT
public:
    TableMdiSubWindow(QWidget *parent = Q_NULLPTR, Qt::WindowFlags flags = Qt::WindowFlags());
    ~TableMdiSubWindow();


private:
    void initTableMdiSubWindow();

private:


};

#endif // TABLEMDISUBWINDOW_H
