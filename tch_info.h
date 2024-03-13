#ifndef TCH_INFO_H
#define TCH_INFO_H

#include <QWidget>
#include <sqlcon.h>
#include <tchcour.h>
namespace Ui {
class tch_info;
}

class tch_info : public QWidget
{
    Q_OBJECT

public:
    explicit tch_info(qint32 tno,QWidget *parent = 0);
    ~tch_info();

private slots:
    void on_search_clicked();

private:
    Ui::tch_info *ui;
    sqlcon conn;
    tchCour *tc;
    qint32 Tno;
};

#endif // TCH_INFO_H
