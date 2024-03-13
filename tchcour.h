#ifndef TCHCOUR_H
#define TCHCOUR_H

#include <QWidget>
#include <sqlcon.h>
#include <QtSql/QSqlTableModel>
#include <QSortFilterProxyModel>
namespace Ui {
class tchCour;
}

class tchCour : public QWidget
{
    Q_OBJECT

public:
    explicit tchCour(qint32 tno,QWidget *parent = 0);
    ~tchCour();

private:
    Ui::tchCour *ui;
    QSortFilterProxyModel *m_filter;
    QSqlQueryModel * query_model;
    sqlcon conn;
    qint32 Tno;
};

#endif // TCHCOUR_H
