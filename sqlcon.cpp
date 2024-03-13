#include"sqlcon.h"
#include<QSqlQuery>
#include<QDebug>
void sqlcon::connection()
{
    db = QSqlDatabase::addDatabase("QODBC");
    qDebug()<<"ODBC driver?"<<db.isValid();
    db.setHostName("localhost");
    db.setDatabaseName("scms");
    db.setUserName("sa");
    db.setPassword("w148134451");
    if(!db.open())
        qDebug()<<QString("Error:Failed to connect database,please contact with your teachers!!");
    else
        qDebug()<<QString("Database connect successful!!!");
}
void sqlcon::close()
{
    db.close();
    db.removeDatabase("QODBC");
}
