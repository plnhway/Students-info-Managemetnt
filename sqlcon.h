#ifndef SQLCON_H
#define SQLCON_H
#include <string>
#include<QString>
#include<QSqlDatabase>
class sqlcon
{
public:
    void connection();
    void close();
    QSqlDatabase db;
};

#endif // SQLCON_H
