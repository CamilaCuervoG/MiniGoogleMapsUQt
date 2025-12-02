#ifndef BUSCARLUGAR_H
#define BUSCARLUGAR_H

#include <QWidget>

namespace Ui {
class BuscarLugar;
}

class BuscarLugar : public QWidget
{
    Q_OBJECT

public:
    explicit BuscarLugar(QWidget *parent = nullptr);
    ~BuscarLugar();

private:
    Ui::BuscarLugar *ui;
};

#endif // BUSCARLUGAR_H
