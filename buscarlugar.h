#ifndef BUSCARLUGAR_H
#define BUSCARLUGAR_H

#include <QWidget>
#include <QListWidgetItem>

struct Lugar {
    QString nombre;
    QString bloque;
    QString piso;
    QString correo;
    QString descripcion;
};

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

    void configurarEstilos();
    void realizarBusqueda();
    void mostrarDialogo(QListWidgetItem *item);
    void regresarMenuPrincipal();
};

#endif // BUSCARLUGAR_H
