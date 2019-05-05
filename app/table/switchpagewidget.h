/*!
 *  @brief      该文件为选择分页窗口模块
 *  @details
 *  @author    尹志刚
 *  @version   1.0
 *  @date      2018.12.25
 *  @warning
 *  @copyright NanJing RenGu.
 */
#ifndef SWITCHPAGEWIDGET_H
#define SWITCHPAGEWIDGET_H
#include "global.h"

#include <QWidget>

class GraphicsView;
class TableView;
class SwitchPageWidgetPrivate;
class SwitchPageWidget : public QWidget
{
    Q_OBJECT

    //brief 页面跳转显示位置
    enum PageNumAppearPos
    {
        PageNumAppearAtStart,         /*!< 开始 */
        PageNumAppearAtMiddle,        /*!< 中间 */
        PageNumAppearAtEnd            /*!< 结尾 */
    };
    /* 跳转页数 */
    enum DisplayNums
    {
        DisplayPreAndNextNoPageJump,          //仅显示上下页切换按钮且无页面跳转
        DisplayAllNoPageJump,                 //显示首页，上下页，和尾页无页面跳转
        DisplayAllWithPageJump                //显示首页，上下页且支持页面跳转
    };
public:
    SwitchPageWidget(QWidget *parent = 0);
    ~SwitchPageWidget();

    void setbindInfoWidget(TableView *pTableView);
    void setbindGraphWidget(GraphicsView *pGraphicsView);
    /* 设置页面总数 */
    void setTotalPagesNum(int iTotalpagesNum);
    /* 获取当前页数 */
    int getCurPageNum();
    void setCurPageNum(int iCurPageNum);
    /* 获取上一页数 */
    int getLastPageNum();
    void setLastPageNum(int iLastPageNum);
signals:

public slots:
    void slotSwitchToFirst();
    void slotSwitchToPrevious();
    void slotSwitchTo();
    void slotSwitchToNext();
    void slotSwitchToLast();

private:
    void updataBindWidget();

private:
    SwitchPageWidgetPrivate *d_ptr;
    Q_DECLARE_PRIVATE(SwitchPageWidget)
};

#endif // SWITCHPAGEWIDGET_H
