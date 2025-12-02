#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QScreen>
#include <QGuiApplication>
#include <sstream>
#include <string>
#include <QString>
#include "menuprincipal.h"
#include "buscarlugar.h"
#include "lugarbloque.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setFixedSize(1280, 720);
    // Centrar ventana
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();
    int x = (screenGeometry.width() - width()) / 2;
    int y = (screenGeometry.height() - height()) / 2;
    move(x, y);

    setWindowFlags(Qt::Dialog | Qt::WindowTitleHint | Qt::WindowCloseButtonHint);
    setWindowTitle("Menu Principal");

    connect(ui->btnRutaAB, &QPushButton::clicked, this, &MainWindow::abrirRutaAB);
    connect(ui->btnBuscar, &QPushButton::clicked, this, &MainWindow::abrirBuscar);
    connect(ui->btnLugarBloque, &QPushButton::clicked, this, &MainWindow::abrirLugarBloque);

    ui->btnRutaAB->setStyleSheet(
        "QPushButton {"
        "font: 16px 'Courier New';"
        "color: white;"
        "background-color: #003366;"  // azul IUSH
        "border-radius: 15px;"
        "padding: 10px 20px;"
        "border: none;"
        "}"
        "QPushButton:hover {"
        "background-color: #8A2BE2;;"
        "}"
        "QPushButton:pressed {"
        "background-color: #1E90FF;"
        "}"
        );

    // Botón 2: Calcular Ruta
    ui->btnBuscar->setStyleSheet(
        "QPushButton {"
        "font: 16px 'Courier New';"
        "color: white;"
        "background-color: #7B1FA2;"   // morado base diferente
        "border-radius: 15px;"
        "padding: 10px 20px;"
        "border: none;"
        "}"
        "QPushButton:hover {"
        "background-color: #9C27B0;"   // morado más claro
        "}"
        "QPushButton:pressed {"
        "background-color: #2196F3;"   // azul al presionar
        "}"
        );

    // Botón 3: Salir
    ui->btnLugarBloque->setStyleSheet(
        "QPushButton {"
        "font: 16px 'Courier New';"
        "color: white;"
        "background-color: #4B0082;"   // morado oscuro
        "border-radius: 15px;"
        "padding: 10px 20px;"
        "border: none;"
        "}"
        "QPushButton:hover {"
        "background-color: #6A0DAD;"   // morado más claro
        "}"
        "QPushButton:pressed {"
        "background-color: #1E90FF;"   // azul al presionar
        "}"
        );

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::abrirRutaAB() {
    // Crear la nueva ventana
    MenuPrincipal *menu = new MenuPrincipal(this);

    this->hide(); // si quieres ocultar MainWindow

    // Mostrar la nueva ventana
    menu->show();

    // Ocultar la ventana actual
    this->hide();

    // Opcional: cuando se cierre la nueva ventana, cerrar la app completa
    connect(menu, &QWidget::destroyed, this, &QWidget::close);
}

void MainWindow::abrirLugarBloque() {
    // Crear la nueva ventana
    BuscarLugar *buscar = new BuscarLugar(this);


    // Mostrar la nueva ventana
    buscar->show();

    // Ocultar la ventana actual
    this->hide();

    // Opcional: cuando se cierre la nueva ventana, cerrar la app completa
    connect(buscar, &QWidget::destroyed, this, &QWidget::close);
}

void MainWindow::abrirBuscar() {
    // Crear la nueva ventana
    LugarBloque *lugar = new LugarBloque(this);

    // Mostrar la nueva ventana
    lugar->show();

    // Ocultar la ventana actual
    this->hide();

    // Opcional: cuando se cierre la nueva ventana, cerrar la app completa
    connect(lugar, &QWidget::destroyed, this, &QWidget::close);
}
