#ifndef STANDDIALOG_H
#define STANDDIALOG_H

#include <QDialog>

namespace Ui {
class standDialog;
}

class standDialog : public QDialog
{
    Q_OBJECT
public:
    explicit standDialog(QWidget *parent = 0);
    ~standDialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::standDialog *ui;
};

#endif // STANDDIALOG_H
