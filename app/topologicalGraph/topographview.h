/*!
 *  @brief
 *  @details
 *  @author
 *  @version
 *  @date
 *  @warning
 *  @copyright NanJing RenGu.
 *  @note
 */
#ifndef TOPOGRAPHVIEW_H
#define TOPOGRAPHVIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsLineItem>
#include <QGraphicsPixmapItem>

class TopoGraphView : public QGraphicsView
{
    Q_OBJECT
public:
    TopoGraphView(QWidget *parent = Q_NULLPTR);
    ~TopoGraphView();


    void initView();

private:
    QGraphicsScene *m_scene;

};

#endif // TOPOGRAPHVIEW_H
