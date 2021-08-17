#ifndef MESSAGEBOX_H
#define MESSAGEBOX_H

#include <QDialog>

namespace Ui {
class Messagebox;
}

class Messagebox : public QDialog
{
    Q_OBJECT

public:
    explicit Messagebox(QWidget *parent = 0);
    ~Messagebox();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::Messagebox *ui;
};

#endif // MESSAGEBOX_H
