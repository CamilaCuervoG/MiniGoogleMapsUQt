#ifndef BUSCARLUGAR_H
#define BUSCARLUGAR_H

#include <QWidget>
#include <QListWidgetItem>

// Estructura donde guardo la información de cada lugar del campus
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
    // Constructor: inicializo la ventana de búsqueda
    explicit BuscarLugar(QWidget *parent = nullptr);

    // Destructor: libero la interfaz generada por Qt
    ~BuscarLugar();

private:
    Ui::BuscarLugar *ui; // Puntero a la interfaz gráfica generada por Qt Designer

    // Configuro estilos visuales personalizados (colores, tamaños, etc.)
    void configurarEstilos();

    // Realizo la búsqueda según el texto ingresado por el usuario
    void realizarBusqueda();

    // Muestro un cuadro de diálogo cuando el usuario selecciona un elemento de la lista
    void mostrarDialogo(QListWidgetItem *item);

    // Regreso al menú principal desde esta ventana
    void regresarMenuPrincipal();
};

#endif // BUSCARLUGAR_H
