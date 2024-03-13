#include "stu_cour.h"
#include "ui_stu_cour.h"
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QtSql/QSqlTableModel>
stu_cour::stu_cour(qint32 sno, QWidget *parent) :
    QWidget(parent),Sno(sno),
    ui(new Ui::stu_cour)
{
    ui->setupUi(this);
    m_filter = new QSortFilterProxyModel(this);
    this->setWindowTitle("学生课程");
    if(QSqlDatabase::contains("qt_sql_default_connection"))
        conn.db = QSqlDatabase::database("qt_sql_default_connection");
    else
        conn.connection();
    QString sqlstr = "Select cname,Score,Tname,Cpoint,CStime,Year from Stu_Cours where way_sno08 = " + QString::number(Sno);
    qDebug()<<sqlstr;
    query_model = new QSqlQueryModel(ui->sc);
    query_model->setQuery(sqlstr);
    query_model->setHeaderData(0,Qt::Horizontal,QObject::tr("课程名"));
    query_model->setHeaderData(1,Qt::Horizontal,QObject::tr("分数"));
    query_model->setHeaderData(2,Qt::Horizontal,QObject::tr("授课教师"));
    query_model->setHeaderData(3,Qt::Horizontal,QObject::tr("学分"));
    query_model->setHeaderData(4,Qt::Horizontal,QObject::tr("开设时间"));
    query_model->setHeaderData(5,Qt::Horizontal,QObject::tr("修课时间"));
    ui->sc->setModel(m_filter);
    m_filter->setSourceModel(query_model);
    ui->sc->setSortingEnabled(true);
}

stu_cour::~stu_cour()
{
    delete ui;
}

void stu_cour::on_combox_currentIndexChanged(int index)
{
    int num = ui->combox->currentIndex();
    m_filter->setSourceModel(query_model);
    m_filter->setFilterKeyColumn(5);
    switch (num) {
    case 0:
        ui->sc->setModel(query_model);
        break;
    case 1:
        m_filter->setFilterRegExp("2022");
        break;
    case 2:
        m_filter->setFilterRegExp("2021");
        break;
    case 3:
        m_filter->setFilterRegExp("2020");
        break;
    case 4:
        m_filter->setFilterRegExp("2019");
        break;
    }
}
