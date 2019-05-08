/*!
 *  @brief   为显示拓扑图提供显示窗口
 *  @details
 *  @author
 *  @version
 *  @date
 *  @warning
 *  @copyright NanJing RenGu.
 *  @note
 */
#ifndef TOPOGRAPHWIDGET_H
#define TOPOGRAPHWIDGET_H

#include <QMdiSubWindow>

#include "topographview.h"

class TopoGraphWidget : public QMdiSubWindow
{
    Q_OBJECT
public:
    TopoGraphWidget(QWidget *parent = Q_NULLPTR, Qt::WindowFlags flags = Qt::WindowFlags());
    ~TopoGraphWidget();

    void initWidegt();

signals:

private slots:

private:
    TopoGraphView *m_topoGraphView;

};

#endif // TOPOGRAPHWIDGET_H
