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
    explicit MenuPrincipal(MainWindow *main, QWidget *parent = nullptr);
    ~MenuPrincipal();

private slots:
    void on_btnDFS_clicked();
    void on_btnDijkstra_clicked();
    void regresarMenuPrincipal();

private:
    Ui::MenuPrincipal *ui;
    Mapa mapa;
    MainWindow *mainWindow; // puntero al MainWindow original
};

#endif // MENUPRINCIPAL_H
