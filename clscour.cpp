#include "clscour.h"
#include "ui_clscour.h"
#include <QSqlQuery>
ClsCour::ClsCour(qint32 sno,QWidget *parent) :
    QWidget(parent),Sno(sno),
    ui(new Ui::ClsCour)
{
    ui->setupUi(this);
    this->setWindowTitle("班级课程");
    m_filter = new QSortFilterProxyModel(this);
    if(QSqlDatabase::contains("qt_sql_default_connection"))
        conn.db = QSqlDatabase::database("qt_sql_default_connection");
    else
        conn.connection();
    QString sqlstr = "select * from ClsCourses;";
    query_model = new QSqlQueryModel(ui->tableView);
    query_model->setQuery(sqlstr);
    ui->lineEdit->setPlaceholderText("前匹配搜索");
    query_model->setHeaderData(0,Qt::Horizontal,QObject::tr("班级编号"));
    query_model->setHeaderData(1,Qt::Horizontal,QObject::tr("班级年级"));
    query_model->setHeaderData(2,Qt::Horizontal,QObject::tr("班级专业"));
    query_model->setHeaderData(3,Qt::Horizontal,QObject::tr("课程名"));
    query_model->setHeaderData(4,Qt::Horizontal,QObject::tr("课程学时"));
    query_model->setHeaderData(5,Qt::Horizontal,QObject::tr("课程学分"));
    query_model->setHeaderData(6,Qt::Horizontal,QObject::tr("考察方式"));
    query_model->setHeaderData(7,Qt::Horizontal,QObject::tr("开设时期"));
    ui->tableView->setModel(m_filter);
    m_filter->setSourceModel(query_model);
    ui->tableView->setColumnHidden(0,1);
}

ClsCour::~ClsCour()
{
    delete ui;
}

void ClsCour::on_search_clicked()
{
    QString str = ui->lineEdit->text();
    m_filter->setFilterKeyColumn(2);
    m_filter->setFilterRegExp(str);
}

void ClsCour::on_lineEdit_textChanged(const QString &arg1)
{
    QString str = ui->lineEdit->text();
    m_filter->setFilterKeyColumn(2);
    m_filter->setFilterRegExp(str);
}
