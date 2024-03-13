#include "login.h"
#include <QApplication>
#include <QSql>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlQuery>
#include <QDebug>
#include <iostream>
#include <stu_info.h>

int main(int argc, char *argv[])
{
     QApplication a(argc, argv);
     Login login;
     login.show();
     return a.exec();
}
