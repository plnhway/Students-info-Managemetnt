#ifndef ADMIN_H
#define ADMIN_H

#include <QWidget>
#include <admin.h>
#include <sqlcon.h>
#include <QSortFilterProxyModel>
#include <QtSql/QSqlQueryModel>
#include <QtSql/QSqlTableModel>
namespace Ui {
class admin;
}

class admin : public QWidget
{
    Q_OBJECT

public:
    explicit admin(QWidget *parent = 0);
    ~admin();

private slots:

    void on_avg_clicked();

    void on_Maintable_clicked();

    void on_login_show_clicked();

    void on_stu_info_clicked();

    void on_tch_clicked();

    void on_class_2_clicked();

    void on_courses_clicked();

    void on_clscours_clicked();

    void on_area_clicked();



    void on_insert_clicked();

    void on_submit_clicked();

    void on_delete_2_clicked();

    void on_cancer_clicked();

    void on_search_clicked();

private:
    Ui::admin *ui;
    QSortFilterProxyModel *m_filter;
    QSqlQueryModel * query_model;
    QSqlTableModel * table_model;
    sqlcon conn;
};

#endif // ADMIN_H






