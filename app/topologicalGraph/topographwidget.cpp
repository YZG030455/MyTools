#include "topographwidget.h"

TopoGraphWidget::TopoGraphWidget(QWidget *parent, Qt::WindowFlags flags)
    : QMdiSubWindow(parent, flags)
{
    this->setWindowTitle(QStringLiteral("Topo Graph"));
    /*! <初始化窗口> */
    this->initWidegt();
}

TopoGraphWidget::~TopoGraphWidget()
{

}

/**
 * @brief 初始化窗口
 */
void TopoGraphWidget::initWidegt()
{
    m_topoGraphView = new TopoGraphView();
    this->setWidget(m_topoGraphView);
}
