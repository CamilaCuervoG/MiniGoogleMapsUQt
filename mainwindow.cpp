#include "MainWindow.h"
#include <QString>
#include <vector>
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    mapa = new Mapa(13);

    // Nombres de nodos
    mapa->setNombreNodo(0, "Portería");
    mapa->setNombreNodo(1, "Entrada Parqueadero");
    mapa->setNombreNodo(2, "Capilla");
    mapa->setNombreNodo(3, "Auditorio");
    mapa->setNombreNodo(4, "Bloque Tecnológico");
    mapa->setNombreNodo(5, "Admisiones 2");
    mapa->setNombreNodo(6, "Bloque Administrativo");
    mapa->setNombreNodo(7, "Bloque Académico 1");
    mapa->setNombreNodo(8, "Cafetería");
    mapa->setNombreNodo(9, "Biblioteca");
    mapa->setNombreNodo(10, "Bloque Académico 2");
    mapa->setNombreNodo(11, "Bloque Admisiones 1");
    mapa->setNombreNodo(12, "Plazoleta");

    // Conexiones
    mapa->agregarConexion(0, 1, 50);
    mapa->agregarConexion(1, 6, 40);
    mapa->agregarConexion(6, 7, 30);
    mapa->agregarConexion(7, 8, 20);
    mapa->agregarConexion(8, 9, 25);
    mapa->agregarConexion(7, 10, 35);
    mapa->agregarConexion(4, 3, 45);
    mapa->agregarConexion(5, 4, 40);
    mapa->agregarConexion(11, 5, 30);
    mapa->agregarConexion(9, 12, 20);
    mapa->agregarConexion(3, 12, 50);
    mapa->agregarConexion(2, 3, 20);

    setupUI();
    conectarSenales();
}

MainWindow::~MainWindow() {
    delete mapa;
}

// UI
void MainWindow::setupUI() {
    QWidget* central = new QWidget(this);
    QVBoxLayout* mainLayout = new QVBoxLayout();

    comboOrigen = new QComboBox();
    comboDestino = new QComboBox();

    for (int i = 0; i < 13; i++) {
        QString nombre = QString::fromStdString(mapa->getNombreNodo(i));
        comboOrigen->addItem(nombre);
        comboDestino->addItem(nombre);
    }

    btnCalcularRuta = new QPushButton("Calcular Ruta");
    btnMostrarHistorial = new QPushButton("Mostrar Historial");
    textOutput = new QTextEdit();
    textOutput->setReadOnly(true);

    mainLayout->addWidget(new QLabel("Origen:"));
    mainLayout->addWidget(comboOrigen);
    mainLayout->addWidget(new QLabel("Destino:"));
    mainLayout->addWidget(comboDestino);
    mainLayout->addWidget(btnCalcularRuta);
    mainLayout->addWidget(btnMostrarHistorial);
    mainLayout->addWidget(textOutput);

    central->setLayout(mainLayout);
    setCentralWidget(central);
    setWindowTitle("Mini Google Maps - Campus");
}

// Señales
void MainWindow::conectarSenales() {
    connect(btnCalcularRuta, &QPushButton::clicked, this, &MainWindow::calcularRuta);
    connect(btnMostrarHistorial, &QPushButton::clicked, this, &MainWindow::mostrarHistorial);
}

// Slots
void MainWindow::calcularRuta() {
    int origen = comboOrigen->currentIndex();
    int destino = comboDestino->currentIndex();

    auto ruta = mapa->calcularRuta(origen, destino);
    if (ruta.empty()) {
        textOutput->append("No se pudo calcular la ruta.\n");
        return;
    }

    QString texto = "Ruta calculada:\n";
    for (size_t i = 0; i < ruta.size(); i++) {
        texto += QString::fromStdString(mapa->getNombreNodo(ruta[i]));
        if (i + 1 < ruta.size()) texto += " -> ";
    }
    texto += "\n";
    textOutput->append(texto);
}

void MainWindow::mostrarHistorial() {
    textOutput->append("=== HISTORIAL DE RUTAS ===");
    std::vector<std::string> registros = mapa->getHistorial();
    if (registros.empty()) {
        textOutput->append("El historial está vacío.\n");
        return;
    }
    for (const auto& r : registros) {
        textOutput->append(QString::fromStdString(r));
    }
}
