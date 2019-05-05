/*!
 *  @brief
 *  @details
 *  @author
 *  @version   1.0
 *  @date
 *  @warning
 *  @copyright NanJing RenGu.
 *  @note
 */
#ifndef TABLEVIEW_H
#define TABLEVIEW_H

#include <QTableView>

class TableView : public QTableView
{
    Q_OBJECT
public:
    TableView(QWidget *parent = Q_NULLPTR);
    ~TableView();

private:
    void initTableView();

private:

};

#endif // TABLEVIEW_H
