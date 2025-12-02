#include "menuprincipal.h"
#include "ui_menuprincipal.h"
#include "mapa.h"
#include "mainwindow.h"
#include <sstream>
#include <string>
#include <QString>
#include <QPixmap>
#include <QPalette>
#include <QScreen>
#include <QGuiApplication>


MenuPrincipal::MenuPrincipal(MainWindow *main, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MenuPrincipal)
    , mapa(12)
    , mainWindow(main)
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

    connect(ui->btnRegresar, &QPushButton::clicked, this, &MenuPrincipal::regresarMenuPrincipal);

    ui->btnDFS->setStyleSheet(R"(
        QPushButton {
            font: 16px 'Courier New';
            color: white;
            background-color: #7B1FA2;   /* morado base */
            border-radius: 15px;
            padding: 10px 20px;
            border: none;
        }

        QPushButton:hover {
            background-color: #9C27B0;  /* morado más claro al pasar mouse */
        }

        QPushButton:pressed {
            background-color: #2196F3;  /* azul al presionar */
        }
        )"
        );
    ui->btnDijkstra->setStyleSheet(R"(
        QPushButton {
            font: 16px 'Courier New';
            color: white;
            background-color: #9B1FA2;   /* morado base */
            border-radius: 15px;
            padding: 10px 20px;
            border: none;
        }

        QPushButton:hover {
            background-color: #9C27B0;  /* morado más claro al pasar mouse */
        }

        QPushButton:pressed {
            background-color: #2196F3;  /* azul al presionar */
        }
        )"
        );

    QString comboStyle = R"(
        QComboBox {
            font: 16px 'Courier New';
            color: white;                              /* texto blanco */
            background-color: #032263; /*
            qproperty-alignment: 'AlignCenter';
            border-radius: 12px;
            padding: 8px 20px 8px 12px;               /* espacio interno */
            border: 2px solid rgba(100, 100, 150, 200); /* borde suave */
            min-width: 150px;
        }

        QComboBox:hover {
            background-color: rgba(155, 85, 200, 220); /* morado elegante al pasar el mouse */
            border: 2px solid rgba(120, 70, 150, 220);
        }

        QComboBox:pressed {
            background-color: rgba(130, 60, 180, 220); /* morado más oscuro al presionar */
        }

        QComboBox QAbstractItemView {
            background-color: white; /* lista con mismo azul clarito */
            border: 2px solid rgba(100, 100, 150, 200);
            border-radius: 12px;
            selection-background-color: rgba(155, 85, 200, 200); /* selección morado */
            selection-color: white;
            outline: 0;
            padding: 5px;
        }
        )";

    ui->comboInicio->setStyleSheet(comboStyle);
    ui->comboDestino->setStyleSheet(comboStyle);


    // Hacer que el QTextEdit no sea editable
    ui->textResultado->setReadOnly(true);

    // Estilo moderno y elegante
    ui->textResultado->setStyleSheet(R"(
        QTextEdit {
            font: 16px 'Courier New';
            color: #003366;                      /* texto azul IUSH */
            background-color: rgba(255, 255, 255, 180); /* fondo semi-transparente */
            border-radius: 15px;
            padding: 12px;
            border: 2px solid #7B1FA2;          /* borde morado */
            selection-background-color: rgba(155, 85, 200, 150); /* selección morado suave */
            selection-color: white;
        }
        QTextEdit:focus {
            border: 2px solid #9C27B0;           /* borde morado más vivo al enfocar */
        }
        )");

    // Cargar la imagen
    QPixmap fondo(":/img/img/rutaab.png"); // Ruta en el .qrc

    // Ajustar tamaño al widget
    fondo = fondo.scaled(this->size(), Qt::IgnoreAspectRatio);

    // Aplicar al fondo con QPalette
    QPalette palette;
    palette.setBrush(QPalette::Window, fondo);
    this->setPalette(palette);

    // Opcional: evitar que se pueda cambiar tamaño si quieres
    this->setFixedSize(this->size());

    //Nombres
    mapa.setNombreNodo(0, "Porteria");
    mapa.setNombreNodo(1, "Entrada parqueadero");
    mapa.setNombreNodo(2, "Capilla");
    mapa.setNombreNodo(3, "Bloque Administrativo 1");
    mapa.setNombreNodo(4, "Auditorio");
    mapa.setNombreNodo(5, "Plazoleta");
    mapa.setNombreNodo(6, "Bloque TEC.");
    mapa.setNombreNodo(7, "Bloque Administrativo 2");
    mapa.setNombreNodo(8, "Bloque ACA1");
    mapa.setNombreNodo(9, "Cafetería");
    mapa.setNombreNodo(10, " Bloque ACA2");
    mapa.setNombreNodo(11, " Zona Libre");

    //Conexiones todas son bidireccionales, por eso cuando ya pongo una no debo de replicarlo para la otra

    // Porteria
    mapa.agregarConexion(0, 1, 5);   // Porteria -> Entrada parqueadero 5m
    mapa.agregarConexion(0, 2, 21);  // Porteria -> Capilla 21m (sin cambio)
    mapa.agregarConexion(0, 3, 5);   // Porteria -> Admin1 5m (ajustado)
    mapa.agregarConexion(0, 5, 30);  // Porteria -> Plazoleta 30m (ajustado)
    mapa.agregarConexion(0, 11, 10); // Porteria -> Zona Libre 10m (ajustado)

    // Entrada parqueadero
    mapa.agregarConexion(1, 11, 7);  // Parqueadero -> Zona Libre 7m
    mapa.agregarConexion(1, 10, 30); // Parqueadero -> ACA2 30m

    // Capilla
    mapa.agregarConexion(2, 4, 10);  // Capilla -> Auditorio 10m
    mapa.agregarConexion(2, 3, 11);  // Capilla -> Admin1 11m
    mapa.agregarConexion(2, 5, 25);  // Capilla -> Plazoleta 25m

    // Admin1
    mapa.agregarConexion(3, 4, 18);  // Admin1 -> Auditorio 18m
    mapa.agregarConexion(3, 5, 25);  // Admin1 -> Plazoleta 25m (ajustado)
    mapa.agregarConexion(3, 9, 27);  // Admin1 -> Cafeteria 27m

    // Auditorio
    mapa.agregarConexion(4, 5, 18);  // Auditorio -> Plazoleta 18m
    mapa.agregarConexion(4, 6, 3);   // Auditorio -> TEC 3m

    // Plazoleta
    mapa.agregarConexion(5, 6, 22);  // Plazoleta -> TEC 22m
    mapa.agregarConexion(5, 7, 38);  // Plazoleta -> Admin2 38m
    mapa.agregarConexion(5, 8, 15);  // Plazoleta -> ACA1 15m (ajustado)
    mapa.agregarConexion(5, 9, 45);  // Plazoleta -> Cafetería 45m

    // Tec
    mapa.agregarConexion(6, 7, 36);  // Tec -> Admin2 36m

    // Admin2
    mapa.agregarConexion(7, 8, 6);   // Admin2 -> ACA1 6m

    // ACA1
    mapa.agregarConexion(8, 9, 38);  // ACA1 -> Cafetería 38m

    // Cafetería
    mapa.agregarConexion(9, 10, 11); // Cafetería -> ACA2 11m

    // ACA2
    mapa.agregarConexion(10, 11, 6); // ACA2 -> Zona libre 6m

    mapa.agregarZona("Cafetería", "Plazoleta Central");
    mapa.agregarZona("Auditorio", "Bloque Principal");
    mapa.agregarZona("Centro de Idiomas", "Bloque B");
    mapa.agregarZona("Biblioteca", "Bloque B");

    // Llenar ComboBoxes con los nombres de los nodos
    for (int i = 0; i < mapa.getCantidadNodos(); i++) {
        QString nombre = QString::fromStdString(mapa.getNombreNodo(i));
        ui->comboInicio->addItem(nombre);
        ui->comboDestino->addItem(nombre);
    }

}

MenuPrincipal::~MenuPrincipal()
{
    delete ui;
}

void MenuPrincipal::on_btnDFS_clicked() {
    int inicio = ui->comboInicio->currentIndex();
    std::ostringstream oss;
    mapa.recorrerDFS(inicio, oss);
    ui->textResultado->setText(QString::fromStdString(oss.str()));
}

void MenuPrincipal::on_btnDijkstra_clicked() {
    int origen = ui->comboInicio->currentIndex();
    int destino = ui->comboDestino->currentIndex();
    auto ruta = mapa.calcularRuta(origen, destino);

    std::ostringstream oss;
    mapa.mostrarRuta(ruta, oss);
    ui->textResultado->setText(QString::fromStdString(oss.str()));
}

void MenuPrincipal::regresarMenuPrincipal() {
    if(mainWindow) {
        mainWindow->show(); // mostramos el MainWindow original
    }
    this->close(); // cerramos MenuPrincipal actual
}
