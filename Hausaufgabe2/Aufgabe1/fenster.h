#ifndef FENSTER_H
#define FENSTER_H

#include <QWidget>

namespace Ui {
class Fenster;
}

class Fenster : public QWidget
{
    Q_OBJECT

public:
    explicit Fenster(QWidget *parent = 0);
    ~Fenster();

private:
    Ui::Fenster *ui;
};

#endif // FENSTER_H
