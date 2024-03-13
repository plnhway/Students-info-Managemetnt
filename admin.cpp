#include "admin.h"
#include "ui_admin.h"
#include <string>
#include <QDebug>
#include <QItemSelectionModel>
#include <QLabel>
#include <QModelIndexList>
#include <QSqlRecord>
#include <QSqlQuery>
admin::admin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::admin)
{
    ui->setupUi(this);
    this->setWindowTitle("管理员界面");
    m_filter = new QSortFilterProxyModel(this);
    if(QSqlDatabase::contains("qt_sql_default_connection"))
        conn.db = QSqlDatabase::database("qt_sql_default_connection");
    else
        conn.connection();
    if(conn.db.open())
        qDebug()<<conn.db.isOpen();
    query_model = new QSqlQueryModel(ui->sc);
    table_model = new QSqlTableModel(this);
    table_model->setTable("weiay_Students08");
    ui->sc->setModel(table_model);
    table_model->select();
    ui->sc->setSortingEnabled(true);
    ui->sc->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    table_model->setEditStrategy(QSqlTableModel::OnManualSubmit);
}

admin::~admin()
{
    delete ui;
}

void admin::on_delete_2_clicked()
{
    QItemSelectionModel *itemModel = ui->sc->selectionModel();
    QModelIndexList list = itemModel->selectedRows();
    for(int i= 0; i<list.size(); i++)
    {
        table_model->removeRow(list.at(i).row());
    }
}
void admin::on_cancer_clicked()
{
    table_model->revertAll();
}
void admin::on_insert_clicked()
{
    QSqlRecord record = table_model->record();
    int row = table_model->rowCount();
    table_model->insertRecord(row,record);
}
void admin::on_submit_clicked()
{
    table_model->submitAll();
}

void admin::on_avg_clicked()
{
    query_model->setQuery("Select * from avg_SC;");
    ui->sc->setModel(query_model);
    query_model->setHeaderData(0,Qt::Horizontal,QObject::tr("课程名称"));
    query_model->setHeaderData(1,Qt::Horizontal,QObject::tr("平均成绩"));
    ui->sc->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void admin::on_area_clicked()
{
    query_model->setQuery("Select * from view_Stu_areacount;");
    ui->sc->setModel(query_model);
    query_model->setHeaderData(0,Qt::Horizontal,QObject::tr("地区"));
    query_model->setHeaderData(1,Qt::Horizontal,QObject::tr("数量"));
}

void admin::on_Maintable_clicked()
{
    ui->sc->setModel(table_model);
    table_model->setTable("weiay_Sc08");
    QSqlQuery query(conn.db);
    query.exec("SET IDENTITY_INSERT on weiay_Sc08");
    table_model->select();
}


void admin::on_login_show_clicked()
{
    ui->sc->setModel(table_model);
    table_model->setTable("weiay_Login08");
    table_model->select();
}

void admin::on_stu_info_clicked()
{
    ui->sc->setModel(table_model);
    QSqlQuery query(conn.db);
    query.exec("SET IDENTITY_INSERT weiay_Students08 ON;");
    table_model->setTable("weiay_Students08");
    table_model->select();
}
void admin::on_tch_clicked()
{
    ui->sc->setModel(table_model);
    QSqlQuery query(conn.db);
    query.exec("SET IDENTITY_INSERT weiay_Teachers08 ON;");
    table_model->setTable("weiay_Teachers08");
    table_model->select();
}

void admin::on_class_2_clicked()
{
    ui->sc->setModel(table_model);
    QSqlQuery query(conn.db);
    query.exec("SET IDENTITY_INSERT weiay_Class08 ON;");
    table_model->setTable("weiay_Class08");
    table_model->select();
}

void admin::on_courses_clicked()
{
    ui->sc->setModel(table_model);
    QSqlQuery query(conn.db);
    query.exec("SET IDENTITY_INSERT weiay_Courses08 ON;");
    table_model->setTable("weiay_Courses08");
    table_model->select();
}

void admin::on_clscours_clicked()
{
    ui->sc->setModel(table_model);
    QSqlQuery query(conn.db);
    query.exec("SET IDENTITY_INSERT weiay_ClassCourses08 ON;");
    table_model->setTable("weiay_ClassCourses08");
    table_model->select();
}

void admin::on_search_clicked()
{
    QString key =ui->lineEdit->text();
    QString str = QString("way_Sno08 = '%1'").arg(key);
    table_model->setFilter(str);
    table_model->select();
}
