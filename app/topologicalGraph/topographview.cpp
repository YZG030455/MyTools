#include "topographview.h"

#in

TopoGraphView::TopoGraphView(QWidget *parent)
    : QGraphicsView(parent)
{

    initView();
}

TopoGraphView::~TopoGraphView()
{

}

/**
 * @brief 初始化拓扑图视图窗口
 */
void TopoGraphView::initView()
{

    m_scene = new QGraphicsScene();
    this->setScene(m_scene);
}
