#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <QDialog>

namespace Ui {
class Geometry;
}

class Geometry : public QDialog
{
    Q_OBJECT

public:
    explicit Geometry(QWidget *parent = 0);
    ~Geometry();
    void updateLabel();
private:
    Ui::Geometry *ui;
protected:
  void moveEvent(QMoveEvent*);
  void resizeEvent(QResizeEvent *);

};

#endif // GEOMETRY_H
