#ifndef MENUPRINCIPAL_H
#define MENUPRINCIPAL_H
#include "mapa.h"
#include "mainwindow.h"

#include <QWidget>

namespace Ui {
class MenuPrincipal;
}

class MenuPrincipal : public QWidget
{
    Q_OBJECT

public:
    // Constructor: recibo el MainWindow para poder volver a él desde este menú
    explicit MenuPrincipal(MainWindow *main, QWidget *parent = nullptr);

    // Destructor: libero la interfaz generada por Qt
    ~MenuPrincipal();

private slots:
    // Ejecuta y muestra el resultado del recorrido DFS
    void on_btnDFS_clicked();

    // Ejecuta Dijkstra para calcular la ruta más corta entre dos nodos
    void on_btnDijkstra_clicked();

    // Regresa al menú principal del MainWindow
    void regresarMenuPrincipal();

private:
    Ui::MenuPrincipal *ui;  // Interfaz gráfica creada con Qt Designer
    Mapa mapa;              // Mapa local para ejecutar DFS y Dijkstra
    MainWindow *mainWindow; // puntero al MainWindow original
};

#endif // MENUPRINCIPAL_H
