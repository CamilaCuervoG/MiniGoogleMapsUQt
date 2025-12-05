#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "Mapa.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT    // <--- ESTE ES EL QUE FALTA

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void abrirRutaAB();
    void abrirLugarBloque();
    void abrirBuscarLugar();

private:
    Ui::MainWindow *ui;
    Mapa mapa;

};

#endif // MAINWINDOW_H
