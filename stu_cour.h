#ifndef STU_COUR_H
#define STU_COUR_H

#include <QWidget>
#include <sqlcon.h>
#include <qsortfilterproxymodel.h>
#include <QtSql/QSqlQueryModel>
namespace Ui {
class stu_cour;
}

class stu_cour : public QWidget
{
    Q_OBJECT

public:
    explicit stu_cour(qint32 sno,QWidget *parent = 0);
    ~stu_cour();

private slots:
    void on_combox_currentIndexChanged(int index);

private:
    Ui::stu_cour *ui;
    QSortFilterProxyModel *m_filter;
    QSqlQueryModel * query_model;
    qint32 Sno;
    sqlcon conn;
};

#endif // STU_COUR_H
