#pragma once
#include <QMainWindow>
#include <QPushButton>
#include <QComboBox>
#include <QTextEdit>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "mapa.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Mapa* mapa;

    // Widgets
    QComboBox* comboOrigen;
    QComboBox* comboDestino;
    QPushButton* btnCalcularRuta;
    QPushButton* btnMostrarHistorial;
    QTextEdit* textOutput;

    void setupUI();
    void conectarSenales();

private slots:
    void calcularRuta();
    void mostrarHistorial();
};
