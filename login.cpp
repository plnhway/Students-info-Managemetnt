#include "login.h"
#include "ui_login.h"
#include<iostream>
#include <QDebug>
#include <QSqlQuery>
#include <stu_info.h>
Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    this->setWindowTitle("学生成绩管理系统");
    ui->login_button->setStyleSheet("QPushButton{font: 25 14pt '微软雅黑 Light';color: rgb(255,255,255);background-color: rgb(20,196,188);"
                                    "border: none;border-radius:15px;}"
                                    "QPushButton:hover{background-color: rgb(22,218,208);}"//hover
                                    "QPushButton:pressed{background-color: rgb(17,171,164);}");
this->setStyleSheet("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(251,102,102, 200), stop:1 rgba(20,196,188, 210));");
    ui->password->setEchoMode(QLineEdit::Password);
    ui->user->setStyleSheet("font: 25 14pt '微软雅黑 Light';" //字体
                                    "color: rgb(31,31,31);"		//字体颜色
                                    "padding-left:20px;"       //内边距-字体缩进
                                    "background-color: rgb(255, 255, 255);" //背景颜色
                                    "border:2px solid rgb(20,196,188);border-radius:15px;");//边框粗细-颜色-圆角设置
    ui->password->setStyleSheet("font: 25 14pt '微软雅黑 Light';" //字体
                                            "color: rgb(31,31,31);"
                                            "padding-left:20px;"
                                            "background-color: rgb(255, 255, 255);"
                                            "border:2px solid rgb(20,196,188);border-radius:15px;");
    ui->login_button->setText("Login");
    ui->user->setPlaceholderText("账户名");
    ui->password->setPlaceholderText("密码");
}

Login::~Login()
{
    delete ui;
}

void Login::on_login_button_clicked()
{
    QString user = ui->user->text();
    QString password = ui->password->text();
    qDebug()<<password;
    conn.connection();
    QSqlQuery query;
    QString str = "SELECT * FROM weiay_Login08 where way_Lgnm08 =" +user+";";
    query.exec(str); //进行执行
    qDebug()<<query.isActive();//确保查询了
    query.first();
    qDebug()<<query.value(1).toString();
    if(user != "admin" && password == query.value(1).toString())//密码输入正确
    {
            //则进入到学生信息展示窗口，否之则展示教师的授课情况和个人信息
            qDebug()<<"Show students's information!";
            qint32 Sno = query.value(0).toInt();
            qDebug()<<Sno;
            sin= new Stu_info(Sno);
            sin->show();
            this->close();
    }
    else{
        if(user != "admin")
        {
            qDebug()<<"Incorrect Password!!!";
            query.finish();
            query.clear();
            QString tchstr = "select * from weiay_Teachers08 where way_Tno08 = :tno;";
            query.prepare(tchstr);
            query.bindValue(":tno",user);
            query.exec();
            query.first();
            if(password == query.value(1).toString())
            {
                qDebug()<<"Show teachers's information!";
                qint32 tno = query.value(0).toInt();
                qDebug()<<tno;
                tin = new tch_info(tno);
                tin->show();
                this->close();
            }
        }
        else
        {
            qDebug()<<"Incorrect tch Password!";
        }
    }
    if(user == "admin"&& password =="admin")
    {
        adn = new admin();
        qDebug()<<"Show admin's form!";
        this->close();
        adn->show();
    }
}
