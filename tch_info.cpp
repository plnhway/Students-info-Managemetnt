#include "tch_info.h"
#include "ui_tch_info.h"
#include <QSqlQuery>
#include <QDebug>
tch_info::tch_info(qint32 tno,QWidget *parent) :
    QWidget(parent),Tno(tno),
    ui(new Ui::tch_info)
{
    ui->setupUi(this);
    this->setWindowTitle("教师信息界面");
    if(QSqlDatabase::contains("qt_sql_default_connection"))
        conn.db = QSqlDatabase::database("qt_sql_default_connection");
    else
        conn.connection();
    QSqlQuery query(conn.db);
    QString sqlstr = "select * from weiay_Teachers08 where way_Tno08 = :user;";
    query.prepare(sqlstr);
    query.bindValue(":user",Tno);
    query.exec();
    query.first();
    ui->name->setText(query.value(2).toString());
    ui->age->setText(QString::number(query.value(4).toInt()));
    ui->sex->setText(query.value(3).toString());
    ui->title->setText(query.value(6).toString());
    ui->telnum->setText(query.value(5).toString());

    QString path = ":/images/tch/" + query.value(0).toString() + ".jpg";
    QPixmap *pixmap = new QPixmap(path);
    pixmap->scaled(ui->label->size(), Qt::KeepAspectRatio);
    ui->picture->setScaledContents(true);
    ui->picture->setPixmap(*pixmap);
}

tch_info::~tch_info()
{
    delete ui;
}

void tch_info::on_search_clicked()
{
    tch_info::tc = new tchCour(Tno);
    tc->show();
}
