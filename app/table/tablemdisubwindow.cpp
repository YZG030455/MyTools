#include "tablemdisubwindow.h"

#include <QDebug>
#include <QPushButton>

#include "tableview.h"
#include "standarditemmodel.h"


TableMdiSubWindow::TableMdiSubWindow(QWidget *parent, Qt::WindowFlags flags)
    : QMdiSubWindow(parent, flags)
{
    this->setWindowTitle(QStringLiteral("表格窗口"));

    initTableMdiSubWindow();
}

TableMdiSubWindow::~TableMdiSubWindow()
{

}

void TableMdiSubWindow::initTableMdiSubWindow()
{
    TableView *tableView = new TableView();
    StandardItemModel *model = new StandardItemModel();

    model->setColumnCount(50);
    model->setRowCount(20);

    tableView->setModel(model);
    this->setWidget(tableView);




}
