#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "mapa.h"

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
    void on_btnDFS_clicked();
    void on_btnDijkstra_clicked();

private:
    Ui::MainWindow *ui;
    Mapa mapa;
};

#endif // MAINWINDOW_H
