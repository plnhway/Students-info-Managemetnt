#include "tchcour.h"
#include "ui_tchcour.h"
#include <QSqlQuery>
#include <QDebug>
tchCour::tchCour(qint32 tno,QWidget *parent) :
    QWidget(parent),Tno(tno),
    ui(new Ui::tchCour)
{
    ui->setupUi(this);
    if(QSqlDatabase::contains("qt_sql_default_connection"))
        conn.db = QSqlDatabase::database("qt_sql_default_connection");
    else
        conn.connection();
    this->setWindowTitle("教师授课");
    QString str = "Select * from Tch_Courses where Tch_Courses.way_Tno08 = " + QString::number(Tno);
    qDebug()<<Tno;
    query_model = new QSqlQueryModel(ui->tableView);
    query_model->setQuery(str);
    query_model->setHeaderData(1,Qt::Horizontal,QObject::tr("教师姓名"));
    query_model->setHeaderData(3,Qt::Horizontal,QObject::tr("课程学时"));
    query_model->setHeaderData(2,Qt::Horizontal,QObject::tr("课程名"));
    query_model->setHeaderData(4,Qt::Horizontal,QObject::tr("考察方式"));
    query_model->setHeaderData(5,Qt::Horizontal,QObject::tr("课程学分"));
    query_model->setHeaderData(6,Qt::Horizontal,QObject::tr("开设学期"));
    query_model->setHeaderData(7,Qt::Horizontal,QObject::tr("授课班级年纪"));
    query_model->setHeaderData(8,Qt::Horizontal,QObject::tr("授课班级专业"));
    ui->tableView->setModel(query_model);
}

tchCour::~tchCour()
{
    delete ui;
}
