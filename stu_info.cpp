#include "stu_info.h"
#include "ui_stu_info.h"
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
Stu_info::Stu_info(qint32 sno,QWidget *parent) :
    QWidget(parent),Sno(sno),
    ui(new Ui::Stu_info)
{
    ui->setupUi(this);
    this->setWindowTitle("学生信息界面");
    qDebug()<<Sno;
    if(QSqlDatabase::contains("qt_sql_default_connection"))
        conn.db = QSqlDatabase::database("qt_sql_default_connection");
    else
        conn.connection();
    QSqlQuery query(conn.db);
    QString sqlstr = "select * from Stu_info where way_sno08 = :user;";
    query.prepare(sqlstr);
    query.bindValue(":user",Sno);
    query.exec();
    query.first();
    ui->name->setText(query.value(1).toString());
    ui->sex->setText(query.value(2).toString());
    ui->age->setText(QString::number(query.value(3).toInt()));
    ui->year->setText(QString::number(query.value(7).toInt()));
    ui->area->setText(query.value(4).toString());
    ui->degree->setText(query.value(6).toString());

    QString path = ":/images/stu/" + query.value(0).toString() + ".png";
    QPixmap *pixmap = new QPixmap(path);
    pixmap->scaled(ui->label->size(), Qt::KeepAspectRatio);
    ui->picture->setScaledContents(true);
    ui->picture->setPixmap(*pixmap);
}

Stu_info::~Stu_info()
{
    delete ui;
}

void Stu_info::on_info_clicked()
{
    scour = new stu_cour(Stu_info::Sno);
    scour->show();
}

void Stu_info::on_clscour_clicked()
{
    clscour = new ClsCour(Sno);
    clscour->show();
}
