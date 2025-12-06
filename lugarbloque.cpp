#include "lugarbloque.h"
#include "ui_lugarbloque.h"
#include "mainwindow.h"
#include <QPixmap>
#include <QPalette>
#include <QScreen>
#include <QGuiApplication>
#include "mapa.h"
#include <QButtonGroup>

LugarBloque::LugarBloque(MainWindow *main, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LugarBloque)
    , mapa(12)         // Se crea un mapa independiente con 12 nodos
    , mainWindow(main) // Se guarda la referencia al MainWindow original
{
    ui->setupUi(this);

    setFixedSize(1280, 720); // Tamaño fijo de la ventana

    // --- CENTRAR LA VENTANA ---
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();
    int x = (screenGeometry.width() - width()) / 2;
    int y = (screenGeometry.height() - height()) / 2;
    move(x, y);

    // --- FONDO DE PANTALLA ---
    QPixmap fondo(":/img/img/lugarBloque.png");
    fondo = fondo.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, fondo);
    this->setPalette(palette);

    // Ventana tipo diálogo con botón de cerrar
    setWindowFlags(Qt::Dialog | Qt::WindowTitleHint | Qt::WindowCloseButtonHint);
    setWindowTitle("Bloques y Espacios");

    // --- EVENTO BOTÓN REGRESAR ---
    connect(ui->btnRegresar, &QPushButton::clicked, this, &LugarBloque::regresarMenuPrincipal);

    // --- ESTILO DEL BOTÓN REGRESAR ---
    QString btnRegresar = R"(
        QPushButton {
            font: 15px 'Courier New';
            color: white;
            background-color: #1A356A;
            border-radius: 15px;
            padding: 10px 10px;
            border: none;
            outline: none; /* <- esto quita el delineado feo */
        }
        QPushButton:hover {
            background-color: #8666a6;
            font-weight: bold;
        }
        QPushButton:pressed {
            background-color: #7B1FA2;
        }
    )";
    ui->btnRegresar->setStyleSheet(btnRegresar);

    // --- Hacer botoncitos seleccionables ---
    ui->btnAdmin1->setCheckable(true);
    ui->btnAdmin2->setCheckable(true);
    ui->btnAdmin3->setCheckable(true);
    ui->btnTEC->setCheckable(true);
    ui->btnACA1->setCheckable(true);
    ui->btnACA2->setCheckable(true);

    // --- Grupo para que solo uno esté seleccionado ---
    QButtonGroup *menuGroup = new QButtonGroup(this);
    menuGroup->setExclusive(true);
    menuGroup->addButton(ui->btnAdmin1);
    menuGroup->addButton(ui->btnAdmin2);
    menuGroup->addButton(ui->btnAdmin3);
    menuGroup->addButton(ui->btnTEC);
    menuGroup->addButton(ui->btnACA1);
    menuGroup->addButton(ui->btnACA2);

    // --- ESTILO DE LOS BOTONES DEL MENÚ ---
    QString btnStyle = R"(
    QPushButton {
        font: 15px 'Courier New';
        color: black;
        background-color: #F2F2F2;
        border-radius: 8px;
        padding: 5px 20px;
        border: none;
        outline: none; /* <- esto quita el delineado al recibir foco */
    }
    QPushButton:hover {
        background-color: #7e3c8c;
        color: white;
    }

    /* Estado seleccionado permanente */
    QPushButton:checked {
        background-color: #4B0082;
        color: white;
    }

    QPushButton:pressed {
        background-color: #4B0082;
    }
)";
    ui->btnAdmin1->setStyleSheet(btnStyle);
    ui->btnAdmin2->setStyleSheet(btnStyle);
    ui->btnAdmin3->setStyleSheet(btnStyle);
    ui->btnTEC->setStyleSheet(btnStyle);
    ui->btnACA1->setStyleSheet(btnStyle);
    ui->btnACA2->setStyleSheet(btnStyle);

    // --- CREACIÓN DE BLOQUES Y SUS ESPACIOS ---
    // (cada bloque se crea y se le agregan sus espacios)
    // luego se agregan al mapa interno

    // 1
    Bloque admin1("ADMIN1");
    admin1.agregarEspacio("Lider deporte - 101");
    admin1.agregarEspacio("Dirección Bienestar Institucional - 102");
    admin1.agregarEspacio("Archivo - 103");
    admin1.agregarEspacio("Lider Centro Egresados - 104");
    admin1.agregarEspacio("Sistema de Gestión Integral - 105");
    admin1.agregarEspacio("Lider Infraestructura - 107");
    admin1.agregarEspacio("Lider Talento Humano - 108");
    admin1.agregarEspacio("Lider Centro de Pedagogía - 205");
    admin1.agregarEspacio("Lider Psicología - 208");
    admin1.agregarEspacio("Lider Centro de Ext. y Proy. Social - 209");
    admin1.agregarEspacio("Oficina Pastoral - 210");
    admin1.agregarEspacio("Lider de Centro de Internacionalización - 212");
    admin1.agregarEspacio("Vicerrectoria Academica - 307");
    admin1.agregarEspacio("Dirección Pastoral - 306");

    // 2
    Bloque admin2("ADMIN2");
    admin2.agregarEspacio("Gimnasio - 6to piso");
    admin2.agregarEspacio("Escuela de ciencias creativas - 5to piso");
    admin2.agregarEspacio("Escuela de Artes - 4to piso");
    admin2.agregarEspacio("Inglés - 3cer piso");
    admin2.agregarEspacio("Escuela de Administración - 3cer piso");
    admin2.agregarEspacio("Sala de Docentes - 3cer piso");
    admin2.agregarEspacio("Auditorio Auxiliar - 2do piso");
    admin2.agregarEspacio("Laboratorio de Automatización ARUS - 1mer piso");

    // 3
    Bloque admin3("ADMIN3");
    admin3.agregarEspacio("Tesoreria/Recaudo - 1mer piso");
    admin3.agregarEspacio("Mercadeo - 1mer piso");
    admin3.agregarEspacio("Atención al usuario - 1mer piso");
    admin3.agregarEspacio("Permanencia y graduación con calidad - 1mer piso");
    admin3.agregarEspacio("Gestión profesoral - 1mer piso");
    admin3.agregarEspacio("Facturación y Cartera - 1mer piso");
    admin3.agregarEspacio("Admisiones y Registros - 1mer piso ");
    admin3.agregarEspacio("Centro documental - 1mer piso");
    admin3.agregarEspacio("Infraestructura Fisica - 2do piso");
    admin3.agregarEspacio("Contabilidad Institucional - 2do piso");
    admin3.agregarEspacio("Adquisición de Bienes y Servicios - 2do piso");
    admin3.agregarEspacio("Contabilidad Liceo - 2do piso");
    admin3.agregarEspacio("Taleo Humano - 2do piso");
    admin3.agregarEspacio("Contabilidad Institución Universitaria - 2do piso");
    admin3.agregarEspacio("Talento Humano - 2do piso");
    admin3.agregarEspacio("Activos Fijos - 2do piso");
    admin3.agregarEspacio("Causación - 2do piso");
    admin3.agregarEspacio("Contabilidad Presupuesto - 2do piso");
    admin3.agregarEspacio("Tesorería / Pagos - 2do piso");
    admin3.agregarEspacio("Centro Documental Financiero - 2do piso");
    admin3.agregarEspacio("Vicerrectoría Administrativa y Financiera - 2do piso");

    // 4
    Bloque tec("TEC");
    tec.agregarEspacio("Cuarto Fotografico - 301");
    tec.agregarEspacio("Laboratorio de simulación - 303");
    tec.agregarEspacio("Archivo - 304");
    tec.agregarEspacio("Laboratorio Automatización - 305");
    tec.agregarEspacio("Laboratorio de Electronica - 306");
    tec.agregarEspacio("Laboratorio de STEAN - 307");
    tec.agregarEspacio("Laboratorio de STEAM - 308");
    tec.agregarEspacio("Centro de Virtualidad - 404");
    tec.agregarEspacio("Laboratorio y Fabricación de Software - 405");
    tec.agregarEspacio("Infraestructura y Desarrollo Tec. - 406");
    tec.agregarEspacio("Laboratorio de Software - 509");
    tec.agregarEspacio("Laboratorio de Software - 510");

    // 5
    Bloque aca1("ACA1");
    aca1.agregarEspacio("Centro de Conciliación - 1mer piso");
    aca1.agregarEspacio("Atención al Usuario - 1mer piso");
    aca1.agregarEspacio("Consultorio Jurídico - 1mer piso");
    aca1.agregarEspacio("Sala de Oralidad - 1mer piso");
    aca1.agregarEspacio("DEIA - 103");
    aca1.agregarEspacio("Sala de Descanso - 102");

    // 6
    Bloque aca2("ACA2");
    aca2.agregarEspacio("Biblioteca - 2do piso");
    aca2.agregarEspacio("Salon de Videojuegos Inder - 201");

    // --- Se agregan los bloques al mapa ---
    mapa.agregarBloque(admin1);
    mapa.agregarBloque(admin2);
    mapa.agregarBloque(admin3);
    mapa.agregarBloque(tec);
    mapa.agregarBloque(aca1);
    mapa.agregarBloque(aca2);

    // --- Eventos de los botones: mostrar cada bloque ---
    connect(ui->btnAdmin1, &QPushButton::clicked, this, [=]() {
        mostrarBloque(0); // índice 0 = bloqueAdmin1 en mapa
    });
    connect(ui->btnAdmin2, &QPushButton::clicked, this, [=]() {
        mostrarBloque(1); // índice 1 = bloqueAdmin2
    });
    connect(ui->btnAdmin3, &QPushButton::clicked, this, [=]() {
        mostrarBloque(2); // índice 2 = bloqueAdmin3
    });
    connect(ui->btnTEC, &QPushButton::clicked, this, [=]() {
        mostrarBloque(3); // bloqueTEC
    });
    connect(ui->btnACA1, &QPushButton::clicked, this, [=]() {
        mostrarBloque(4); // bloqueACA1
    });
    connect(ui->btnACA2, &QPushButton::clicked, this, [=]() {
        mostrarBloque(5); // bloqueACA2
    });

    // --- Cargar automáticamente el primer bloque ---
    if (!mapa.getBloques().empty()) {
        cargarEspacios(0);
    }

    // Estilo de la imagen del bloque (actualmente no tiene nada personalizado)
    ui->labelImagenBloque->setStyleSheet(R"(
        QLabel {

        }
    )");

    // --- ESTILO DE LA LISTA DE ESPACIOS ---
    ui->listEspacios->setStyleSheet(R"(
        QListWidget {
            background-color: transparent;
            padding: 8px;
            font: 12px 'Courier New';
            color: black;
            outline: 0;
        }

        QListWidget::item {
            background-color: #F2F2F2;
            border-radius: 8px;
            margin-bottom: 3px;

        }

        QListWidget::item:hover {
            background-color: #7e3c8c;
            color: white;
        }

        QListWidget::item:selected {
            background-color: #4B0082;
            color: white;
        }

        QListWidget::item:selected:!active {
            background-color: #9C27B0;
        }
        )");

    // --- Tamaño de imagen del bloque ---
    ui->labelImagenBloque->setScaledContents(true);

    // Imagen inicial por defecto (campus general)
    if(!mapa.getBloques().empty()) {
        QPixmap pix(":/img/img/campus.png"); // Imagen inicial
        ui->labelImagenBloque->setPixmap(pix.scaled(ui->labelImagenBloque->size(), Qt::KeepAspectRatio));
    }

}

LugarBloque::~LugarBloque()
{
    delete ui;
}

// --- Cargar espacios de un bloque y su imagen ---
void LugarBloque::cargarEspacios(int index)
{
    if (index < 0 || index >= mapa.getBloques().size())
        return;

    const auto &bloque = mapa.getBloques()[index];

    // Cargar imagen del bloque
        QString nombreImg = QString(":/img/img/")
        + QString::fromStdString(bloque.getNombre())
        + ".png";

    QPixmap pix(nombreImg);
    if(!pix.isNull())
        ui->labelImagenBloque->setPixmap(pix.scaled(ui->labelImagenBloque->size(), Qt::KeepAspectRatio));

    // Llenar la lista
    ui->listEspacios->clear();
    for (const auto &esp : bloque.getEspacios()) {
        ui->listEspacios->addItem(QString::fromStdString(esp));
    }
}

// --- Regresar al menú principal ---
void LugarBloque::regresarMenuPrincipal() {
    if(mainWindow) {
        mainWindow->show(); // mostramos el MainWindow original
    }
    this->close(); // cerramos LugarBloque actual
}

// --- Mostrar un bloque al hacer clic ---
void LugarBloque::mostrarBloque(int index) {
    if (index < 0 || index >= mapa.getBloques().size())
        return;

    const auto &bloque = mapa.getBloques()[index];

    // Mostrar imagen del bloque
    QString nombreImg = QString(":/img/img/") + QString::fromStdString(bloque.getNombre()) + ".png";
    QPixmap pix(nombreImg);
    if(!pix.isNull())
        ui->labelImagenBloque->setPixmap(pix.scaled(
            ui->labelImagenBloque->size(),
            Qt::KeepAspectRatio,
            Qt::SmoothTransformation
        ));

    // Mostrar lista de espacios
    ui->listEspacios->clear();
    for (const auto &espacio : bloque.getEspacios()) {
        ui->listEspacios->addItem(QString::fromStdString(espacio));
    }
}
