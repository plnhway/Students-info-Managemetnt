#ifndef CLSCOUR_H
#define CLSCOUR_H

#include <QWidget>
#include <sqlcon.h>
#include <QSortFilterProxyModel>
#include <QtSql/QSqlQueryModel>
namespace Ui {
class ClsCour;
}

class ClsCour : public QWidget
{
    Q_OBJECT

public:
    explicit ClsCour(qint32 sno,QWidget *parent = 0);
    ~ClsCour();

private slots:
    void on_search_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::ClsCour *ui;
    QSortFilterProxyModel *m_filter;
    QSqlQueryModel * query_model;
    qint32 Sno;
    sqlcon conn;
};

#endif // CLSCOUR_H
