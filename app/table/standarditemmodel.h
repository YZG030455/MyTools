/*!
 *  @brief
 *  @details
 *  @author
 *  @version   1.0
 *  @date       20190327
 *  @warning
 *  @copyright NanJing RenGu.
 *  @note
 */
#ifndef STANDARDITEMMODEL_H
#define STANDARDITEMMODEL_H

#include <QStandardItemModel>

class StandardItemModel : public QStandardItemModel
{
    Q_OBJECT
public:
    StandardItemModel(QObject *parent = Q_NULLPTR);
    ~StandardItemModel();


private:
   void initStandardItemModel();



};

#endif // STANDARDITEMMODEL_H
