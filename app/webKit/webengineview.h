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
#ifndef WEBENGINEVIEW_H
#define WEBENGINEVIEW_H

#include <QWebEngineView>

class WebEngineView : public QWebEngineView
{
    Q_OBJECT
public:
    WebEngineView(QWidget *parent = Q_NULLPTR);
};

#endif // WEBENGINEVIEW_H
