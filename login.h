#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <tch_info.h>
#include"sqlcon.h"
#include <stu_info.h>
#include <admin.h>
namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();

private slots:
    void on_login_button_clicked();

private:
    Ui::Login *ui;
    tch_info * tin;
    sqlcon conn;
    admin *adn;
    Stu_info * sin;
};

#endif // LOGIN_H
