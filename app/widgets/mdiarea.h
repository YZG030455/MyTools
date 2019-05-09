/*!
 *  @brief   MdiArea窗口模块 为
 *  @details
 *  @author
 *  @version
 *  @date
 *  @warning
 *  @copyright NanJing RenGu.
 *  @note
 */
#ifndef MDIAREA_H
#define MDIAREA_H

#include <QMdiArea>

class MdiArea : public QMdiArea
{
    Q_OBJECT
public:
    MdiArea(QWidget *parent = Q_NULLPTR);
    ~MdiArea();

signals:

private slots:


private:
    void initMdiArea();


private:

};

#endif // MDIAREA_H
