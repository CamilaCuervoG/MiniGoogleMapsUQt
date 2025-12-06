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
#include "Mapa.h"

// Constructor de la ventana principal
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
    , mapa(12)  // Inicializa el mapa con 12 nodos
{
    ui->setupUi(this); // Carga el diseño del UI

    // Tamaño fijo de la ventana principal
    setFixedSize(1280, 720);

    // Centrar la ventana en pantalla
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();
    int x = (screenGeometry.width() - width()) / 2;
    int y = (screenGeometry.height() - height()) / 2;
    move(x, y);

    // Configuración visual de la ventana
    setWindowFlags(Qt::Dialog | Qt::WindowTitleHint | Qt::WindowCloseButtonHint);
    setWindowTitle("Menu Principal");

    // Conexión de botones a funciones
    connect(ui->btnRutaAB, &QPushButton::clicked, this, &MainWindow::abrirRutaAB);
    connect(ui->btnBuscar, &QPushButton::clicked, this, &MainWindow::abrirBuscarLugar);
    connect(ui->btnLugarBloque, &QPushButton::clicked, this, &MainWindow::abrirLugarBloque);

    // Estilo del botón 1: Ruta AB
    ui->btnRutaAB->setStyleSheet(
        "QPushButton {"
        "font: 16px 'Courier New';"
        "color: white;"
        "background-color: #003366;"  // Azul institucional
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

    // Estilo del botón 2: Buscar lugar
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

    // Estilo del botón 3: Lugar por bloques
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

// Destructor
MainWindow::~MainWindow()
{
    delete ui;
}

// Abrir ventana "Ruta AB" (MenuPrincipal)
void MainWindow::abrirRutaAB() {
    MenuPrincipal *menu = new MenuPrincipal(this);

    this->hide(); // Oculta MainWindow

    menu->show(); // Muestra la ventana de rutas

    // Cuando MenuPrincipal se destruya, cerrar la principal
    connect(menu, &QWidget::destroyed, this, &QWidget::close);
}

// Abrir ventana para seleccionar Lugar por Bloque
void MainWindow::abrirLugarBloque() {
    LugarBloque *lugar = new LugarBloque(this);

    lugar->show(); // Mostrar la ventana del bloque
    this->hide(); // Ocultar MainWindow

    // Cuando LugarBloque se cierre, cerrar MainWindow
    connect(lugar, &QWidget::destroyed, this, &QWidget::close);
}

// Abrir buscador de lugares
void MainWindow::abrirBuscarLugar() {
    BuscarLugar *buscar = new BuscarLugar();

    this->hide(); // Oculta la ventana principal

    buscar->setAttribute(Qt::WA_DeleteOnClose); // Se borrará solo cuando la cierren

    // Al cerrar, volver a mostrar MainWindow
    connect(buscar, &QWidget::destroyed, this, [this]() {
        this->show();
    });

    buscar->show(); // Mostrar ventana de búsqueda
}
