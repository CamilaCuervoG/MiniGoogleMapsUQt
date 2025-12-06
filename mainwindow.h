#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "Mapa.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    // Constructor: inicializo la ventana principal de la aplicación
    explicit MainWindow(QWidget *parent = nullptr);

    // Destructor: libero la interfaz y recursos asociados
    ~MainWindow();

private slots:
    // Abre la ventana donde muestro la ruta entre dos puntos (A → B)
    void abrirRutaAB();
    // Abre la ventana que permite explorar los bloques y sus lugares
    void abrirLugarBloque();
    // Abre la ventana para buscar un lugar por nombre
    void abrirBuscarLugar();

private:
    Ui::MainWindow *ui; // Interfaz gráfica creada por Qt Designer
    Mapa mapa;          // Mapa general del campus para toda la aplicación

};

#endif // MAINWINDOW_H
