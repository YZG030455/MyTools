/*!
 *  @brief      该文件为选择分页窗口模块
 *  @details
 *  @author    尹志刚
 *  @version   1.0
 *  @date      2018.12.25
 *  @warning
 *  @copyright NanJing RenGu.
 */
#include "switchpagewidget.h"
//#include "tools/tableview.h"
//#include "graph/graphicsview.h"

#include <QDebug>
#include <QSpinBox>
#include <QPushButton>
#include <QBoxLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>

class SwitchPageWidgetPrivate
{
public:
    SwitchPageWidgetPrivate();

    void initSwitchPageWidget();
    void setLayout();
    void setPageNumAppearPos(SwitchPageWidget::PageNumAppearPos eAppearPos);
    void setDisplayNums(SwitchPageWidget::DisplayNums eDisplayNums);

private:
    SwitchPageWidget *q_ptr;
    Q_DECLARE_PUBLIC(SwitchPageWidget)

    QPushButton *m_pBtnFirstPage;
    QPushButton *m_pBtnPrePage;
    QPushButton *m_pBtnNextPage;
    QPushButton *m_pBtnLastPage;
    QPushButton *m_pBtnJumpPage;
    QSpinBox  * m_pSpinBox;
    QBoxLayout *m_pLayout;          //布局

    SwitchPageWidget::PageNumAppearPos m_eAppearPos;
    SwitchPageWidget::DisplayNums m_eDisplayNums;

    int m_iTotalPage;
    int m_iCurPage;
    int m_iLastPage;
    Qt::Orientation mOrientation;
//    TableView *m_pTableView;
//    GraphicsView *m_pGraphicsView;
};

SwitchPageWidgetPrivate::SwitchPageWidgetPrivate()
{
    m_pBtnFirstPage = NULL;
    m_pBtnPrePage = NULL;
    m_pBtnNextPage = NULL;
    m_pBtnLastPage = NULL;
    m_pBtnJumpPage = NULL;
    m_pSpinBox = NULL;
    m_pLayout = NULL;
    mOrientation = Qt::Horizontal;
    m_eAppearPos = SwitchPageWidget::PageNumAppearAtMiddle;
//    m_pTableView = NULL;
    m_iCurPage = 1;
    m_iTotalPage = 1;
    m_iLastPage = 1;
}

void SwitchPageWidgetPrivate::initSwitchPageWidget()
{
    m_pBtnFirstPage = new QPushButton();
    m_pBtnFirstPage->setText(QObject::tr("Home"));
    m_pBtnFirstPage->setEnabled(false);

    m_pBtnPrePage = new QPushButton();
    m_pBtnPrePage->setText(QObject::tr("Page up"));
    m_pBtnPrePage->setEnabled(false);

    m_pBtnNextPage = new QPushButton();
    m_pBtnNextPage->setText(QObject::tr("Page down"));
    m_pBtnNextPage->setEnabled(false);

    m_pBtnLastPage = new QPushButton();
    m_pBtnLastPage->setText(QObject::tr("End"));
    m_pBtnLastPage->setEnabled(false);

    m_pBtnJumpPage = new QPushButton();
    m_pBtnJumpPage->setText(QObject::tr("Skip"));
    m_pBtnJumpPage->setEnabled(false);

    m_pSpinBox = new QSpinBox();
    m_pSpinBox->setFixedWidth(40);
    m_pSpinBox->setAlignment(Qt::AlignCenter);
    m_pSpinBox->setMinimumHeight(22);
    m_pSpinBox->setRange(1,1);
    m_pSpinBox->setSuffix("/1");
    m_pSpinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);

    setLayout();
    /**/
    QObject::connect(m_pBtnFirstPage, SIGNAL(clicked()), q_ptr, SLOT(slotSwitchToFirst()));
    QObject::connect(m_pBtnPrePage, SIGNAL(clicked()), q_ptr, SLOT(slotSwitchToPrevious()));
    QObject::connect(m_pBtnNextPage, SIGNAL(clicked()), q_ptr, SLOT(slotSwitchToNext()));
    QObject::connect(m_pBtnLastPage, SIGNAL(clicked()), q_ptr, SLOT(slotSwitchToLast()));
    QObject::connect(m_pBtnJumpPage, SIGNAL(clicked()), q_ptr, SLOT(slotSwitchTo()));
}

void SwitchPageWidgetPrivate::setLayout()
{
    QWidget * container = new QWidget(); //

    if(mOrientation == Qt::Horizontal)
    {
        m_pLayout = new QHBoxLayout();
    }
    else if (mOrientation == Qt::Vertical)
    {
        m_pLayout = new QVBoxLayout();
    }
    m_pLayout->addStretch(1);
    setPageNumAppearPos(m_eAppearPos);
    m_pLayout->addStretch(1);
    m_pLayout->setContentsMargins(0,0,0,0);
    container->setLayout(m_pLayout);
    /* 主布局 */
    //    QHBoxLayout *pMainLayout = new QHBoxLayout();
    //    pMainLayout->setContentsMargins(0,0,0,0);
    //    pMainLayout->addWidget(container);
    q_ptr->setLayout(m_pLayout);
    /* 设置 跳转的页数 */
    //    setDisplayNums(m_eDisplayNums);

}
/* 跳转位置 */
void SwitchPageWidgetPrivate::setPageNumAppearPos(SwitchPageWidget::PageNumAppearPos eAppearPos)
{
    switch (eAppearPos)
    {
    case SwitchPageWidget::PageNumAppearAtStart:    //首页
    {
        m_pLayout->addWidget(m_pSpinBox);
        m_pLayout->addWidget(m_pBtnJumpPage);
        m_pLayout->addWidget(m_pBtnFirstPage);
        m_pLayout->addWidget(m_pBtnPrePage);
        m_pLayout->addWidget(m_pBtnNextPage);
        m_pLayout->addWidget(m_pBtnLastPage);
        break;
    }
    case SwitchPageWidget::PageNumAppearAtMiddle:   //中间
    {
        m_pLayout->addWidget(m_pBtnFirstPage);
        m_pLayout->addWidget(m_pBtnPrePage);
        m_pLayout->addWidget(m_pSpinBox);
        m_pLayout->addWidget(m_pBtnJumpPage);
        m_pLayout->addWidget(m_pBtnNextPage);
        m_pLayout->addWidget(m_pBtnLastPage);
        break;
    }
    case SwitchPageWidget::PageNumAppearAtEnd:      //尾页
    {
        m_pLayout->addWidget(m_pBtnFirstPage);
        m_pLayout->addWidget(m_pBtnPrePage);
        m_pLayout->addWidget(m_pBtnNextPage);
        m_pLayout->addWidget(m_pBtnLastPage);
        m_pLayout->addWidget(m_pSpinBox);
        m_pLayout->addWidget(m_pBtnJumpPage);
        break;
    }
    default:
        break;
    }

}
/* 跳转页数 */
void SwitchPageWidgetPrivate::setDisplayNums(SwitchPageWidget::DisplayNums eDisplayNums)
{
    switch (eDisplayNums)
    {
    case SwitchPageWidget::DisplayPreAndNextNoPageJump:
    {
        m_pBtnFirstPage->hide();
        m_pBtnJumpPage->hide();
        m_pBtnLastPage->hide();
        break;
    }
    case SwitchPageWidget::DisplayAllNoPageJump:
    {
        m_pBtnJumpPage->hide();
        break;
    }
    case SwitchPageWidget::DisplayAllWithPageJump:
    {

        break;
    }
    default:
        break;
    }
}

SwitchPageWidget::SwitchPageWidget(QWidget *parent)
    : QWidget(parent)
{
    d_ptr = new SwitchPageWidgetPrivate();
    d_ptr->q_ptr = this;
    d_ptr->initSwitchPageWidget();
}

SwitchPageWidget::~SwitchPageWidget()
{
    if(d_ptr)
    {
        delete d_ptr;
        d_ptr = NULL;
    }
}

void SwitchPageWidget::setbindInfoWidget(TableView *pTableView)
{
    Q_ASSERT(pTableView);
//    d_ptr->m_pTableView = pTableView;
}

void SwitchPageWidget::setbindGraphWidget(GraphicsView *pGraphicsView)
{
    Q_ASSERT(pGraphicsView);
//    d_ptr->m_pGraphicsView = pGraphicsView;
}
/*设置页面总数*/
void SwitchPageWidget::setTotalPagesNum(int iTotalpagesNum)
{
    if(d_ptr->m_iTotalPage == iTotalpagesNum || iTotalpagesNum < 1)
    {
        return;
    }
    d_ptr->m_iTotalPage = iTotalpagesNum;
    if(iTotalpagesNum < d_ptr->m_iCurPage)
    {
        d_ptr->m_iCurPage = d_ptr->m_iTotalPage;
        d_ptr->m_pBtnNextPage->setEnabled(false);
    }
    else
    {
        d_ptr->m_pBtnJumpPage->setEnabled(true);
        d_ptr->m_pBtnNextPage->setEnabled(true);
        d_ptr->m_pBtnLastPage->setEnabled(true);
    }

    if(d_ptr->m_iCurPage == 1)
    {
        d_ptr->m_pBtnPrePage->setEnabled(false);
    }
    else
    {
        d_ptr->m_pBtnPrePage->setEnabled(false);
    }

    d_ptr->m_pSpinBox->setRange(1, d_ptr->m_iTotalPage);
    d_ptr->m_pSpinBox->setSuffix(QString("/ %1").arg(d_ptr->m_iTotalPage));
}
/* 当前页数 */
int SwitchPageWidget::getCurPageNum()
{
    return d_ptr->m_iCurPage;
}

void SwitchPageWidget::setCurPageNum(int iCurPageNum)
{
    d_ptr->m_iCurPage = iCurPageNum;
}
/* 前一次页数 */
int SwitchPageWidget::getLastPageNum()
{
    return d_ptr->m_iLastPage;
}

void SwitchPageWidget::setLastPageNum(int iLastPageNum)
{
    d_ptr->m_iLastPage = iLastPageNum;
}

/* 首页 */
void SwitchPageWidget::slotSwitchToFirst()
{
    d_ptr->m_iLastPage = d_ptr->m_iCurPage;
    d_ptr->m_iCurPage = 1;
    d_ptr->m_pBtnFirstPage->setEnabled(false);
    d_ptr->m_pBtnPrePage->setEnabled(false);
    d_ptr->m_pBtnNextPage->setEnabled(d_ptr->m_iTotalPage != 1);
    d_ptr->m_pBtnLastPage->setEnabled(d_ptr->m_iTotalPage != 1);
    d_ptr->m_pSpinBox->setValue(d_ptr->m_iCurPage);
    this->updataBindWidget();
}
/* 上一页 */
void SwitchPageWidget::slotSwitchToPrevious()
{
    d_ptr->m_iLastPage = d_ptr->m_iCurPage;
    d_ptr->m_pBtnNextPage->setEnabled(true);
    d_ptr->m_pBtnLastPage->setEnabled(true);

    if(d_ptr->m_iCurPage - 1 > 1)
    {
        d_ptr->m_iCurPage--;
        d_ptr->m_pBtnFirstPage->setEnabled(true);
        d_ptr->m_pBtnPrePage->setEnabled(true);
    }
    else
    {
        d_ptr->m_iCurPage = 1;
        d_ptr->m_pBtnFirstPage->setEnabled(false);
        d_ptr->m_pBtnPrePage->setEnabled(false);
    }
    d_ptr->m_pSpinBox->setValue(d_ptr->m_iCurPage);
    this->updataBindWidget();
}
/* 跳转到 */
void SwitchPageWidget::slotSwitchTo()
{
    d_ptr->m_iLastPage = d_ptr->m_iCurPage;
    d_ptr->m_iCurPage = d_ptr->m_pSpinBox->value();
    if(1 != d_ptr->m_iTotalPage )
    {
        if(1 == d_ptr->m_iCurPage)
        {
            d_ptr->m_pBtnFirstPage->setEnabled(false);
            d_ptr->m_pBtnPrePage->setEnabled(false);
            d_ptr->m_pBtnNextPage->setEnabled(true);
            d_ptr->m_pBtnLastPage->setEnabled(true);
        }
        else
        {
            if(d_ptr->m_iTotalPage == d_ptr->m_iCurPage)
            {
                d_ptr->m_pBtnFirstPage->setEnabled(true);
                d_ptr->m_pBtnPrePage->setEnabled(true);
                d_ptr->m_pBtnNextPage->setEnabled(false);
                d_ptr->m_pBtnLastPage->setEnabled(false);
            }
            else
            {
                d_ptr->m_pBtnFirstPage->setEnabled(true);
                d_ptr->m_pBtnPrePage->setEnabled(true);
                d_ptr->m_pBtnNextPage->setEnabled(true);
                d_ptr->m_pBtnLastPage->setEnabled(true);
            }
        }
    }
    updataBindWidget();
}
/* 下一页 */
void SwitchPageWidget::slotSwitchToNext()
{
    d_ptr->m_iLastPage = d_ptr->m_iCurPage;
    d_ptr->m_pBtnFirstPage->setEnabled(true);
    d_ptr->m_pBtnPrePage->setEnabled(true);
    if(d_ptr->m_iCurPage + 1 < d_ptr->m_iTotalPage)
    {
        d_ptr->m_iCurPage++;
        d_ptr->m_pBtnNextPage->setEnabled(true);
        d_ptr->m_pBtnLastPage->setEnabled(true);
    }
    else
    {
        d_ptr->m_iCurPage = d_ptr->m_iTotalPage;
        d_ptr->m_pBtnNextPage->setEnabled(false);
        d_ptr->m_pBtnLastPage->setEnabled(false);
    }
    d_ptr->m_pSpinBox->setValue(d_ptr->m_iCurPage);
    this->updataBindWidget();
}
/* 尾页 */
void SwitchPageWidget::slotSwitchToLast()
{
    d_ptr->m_iLastPage = d_ptr->m_iCurPage;
    d_ptr->m_iCurPage = d_ptr->m_iTotalPage;
    d_ptr->m_pBtnFirstPage->setEnabled(d_ptr->m_iTotalPage != 1);
    d_ptr->m_pBtnPrePage->setEnabled(d_ptr->m_iTotalPage != 1);
    d_ptr->m_pBtnNextPage->setEnabled(false);
    d_ptr->m_pBtnLastPage->setEnabled(false);
    d_ptr->m_pSpinBox->setValue(d_ptr->m_iCurPage);
    this->updataBindWidget();
}

void SwitchPageWidget::updataBindWidget()
{
//    d_ptr->m_pTableView->updateTablePageNum(d_ptr->m_iCurPage, d_ptr->m_iLastPage);
//    if(d_ptr->m_pGraphicsView == NULL)
//    {
//        return;
//    }
//    else
//    {
//       d_ptr->m_pGraphicsView->updateTablePageNum(d_ptr->m_iCurPage, d_ptr->m_iLastPage);
//    }
}





