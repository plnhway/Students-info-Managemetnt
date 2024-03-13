#ifndef STU_INFO_H
#define STU_INFO_H

#include <QWidget>
#include <sqlcon.h>
#include <stu_cour.h>
#include <clscour.h>
namespace Ui {
class Stu_info;
}

class Stu_info : public QWidget
{
    Q_OBJECT

public:
    explicit Stu_info(qint32 Sno,QWidget *parent = 0);
    ~Stu_info();

private slots:
    void on_info_clicked();

    void on_clscour_clicked();

private:
    Ui::Stu_info *ui;
    stu_cour * scour;
    ClsCour * clscour;
    sqlcon conn;
    qint32 Sno;
};

#endif // STU_INFO_H
