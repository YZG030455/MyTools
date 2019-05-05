#include "loginwidget.h"
#include <QDebug>
#include <QLabel>
#include <QPushButton>
#include <QCheckBox>
#include <QComboBox>
#include <QLineEdit>
#include <QVBoxLayout>  /*!< 垂直  */
#include <QHBoxLayout>  /*!< 水平  */
#include <QGridLayout>  /*!< 网格  */

LoginWidget::LoginWidget(QWidget *parent)
    : QWidget(parent)
{
    this->setWindowTitle(QStringLiteral("登陆"));

    this->initLoginWidget();
}

LoginWidget::~LoginWidget()
{

}

void LoginWidget::slotLoginBtnClick()
{

}

void LoginWidget::initLoginWidget()
{

    QLabel *loginLabel = new QLabel(QStringLiteral("登陆"));


    QLabel *nameLabel = new QLabel(QStringLiteral("用户名"));
    QComboBox * nameComboBox = new QComboBox();
    QLabel *passwordLabel = new QLabel(QStringLiteral("用户名"));
    QLineEdit * passwordLineEdit = new QLineEdit();


    QPushButton *loginBtn = new QPushButton(QStringLiteral("登陆"));
    connect(loginBtn, SIGNAL(clicked(bool)), this, SLOT(slotLoginBtnClick()));

    /*!< 登陆窗口主布局  */
    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addWidget(loginLabel);
    mainLayout->addWidget(loginBtn);
    this->setLayout(mainLayout);
}
