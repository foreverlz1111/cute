#ifndef ABOUTIT_H
#define ABOUTIT_H

#include <QDialog>

namespace Ui {
class Aboutit;
}

class Aboutit : public QDialog
{
    Q_OBJECT

public:
    explicit Aboutit(QWidget *parent = 0);
    ~Aboutit();

private:
    Ui::Aboutit *ui;
};

#endif // ABOUTIT_H
