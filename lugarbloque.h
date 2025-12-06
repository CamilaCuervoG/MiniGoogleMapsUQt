#ifndef LUGARBLOQUE_H
#define LUGARBLOQUE_H

#include "mapa.h"
#include "mainwindow.h"
#include <QListWidget>
#include <QPushButton>
#include <QLabel>
#include <QComboBox>
#include <QVBoxLayout>


#include <QWidget>

namespace Ui {
class LugarBloque;
}

class MainWindow;

class LugarBloque : public QWidget
{
    Q_OBJECT

public:
    // Constructor: recibo el MainWindow para poder regresar a él
    explicit LugarBloque(MainWindow *main, QWidget *parent = nullptr);

    // Destructor: libero la interfaz
    ~LugarBloque();

private slots:
    // Carga los espacios del bloque seleccionado
    void cargarEspacios(int index);

    // Muestra la información del bloque (incluye la imagen)
    void mostrarBloque(int index);

    // Regresa a la ventana principal
    void regresarMenuPrincipal();

private:
    Ui::LugarBloque *ui;    // Interfaz generada por Qt Designer
    Mapa mapa;              // Mapa que contiene los bloques y nodos del campus
    MainWindow *mainWindow; // puntero al MainWindow original

    // Widgets de la interfaz
    QVBoxLayout *layoutBotones; // Layout donde van los botones de bloques
    QLabel *labelImagenBloque;  // Etiqueta donde muestro la imagen del bloque
    QListWidget *listEspacios;  // Lista con los espacios del bloque

    QWidget *widgetBotones;       // Contenedor de los botones
    QVBoxLayout *layoutPrincipal; // Layout general del widget

};

#endif // LUGARBLOQUE_H
