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
    explicit LugarBloque(MainWindow *main, QWidget *parent = nullptr);
    ~LugarBloque();

private slots:
    void cargarEspacios(int index);
    void mostrarBloque(int index);
    void regresarMenuPrincipal();

private:
    Ui::LugarBloque *ui;
    Mapa mapa;
    MainWindow *mainWindow; // puntero al MainWindow original

    // Widgets
    QVBoxLayout *layoutBotones;
    QLabel *labelImagenBloque;
    QListWidget *listEspacios;

    QWidget *widgetBotones;
    QVBoxLayout *layoutPrincipal;

};

#endif // LUGARBLOQUE_H
