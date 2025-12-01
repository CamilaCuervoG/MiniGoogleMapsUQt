#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "Mapa.h"
#include <sstream>
#include <string>
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , mapa(12)
{
    ui->setupUi(this);

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

    //Corteria
    mapa.agregarConexion(0, 1, 1); //Porteria -> Entrada parqueadero 1min aprox
    mapa.agregarConexion(0, 2, 2); //Porteria -> Capilla
    mapa.agregarConexion(0, 3, 2); //Porteria -> Admin1
    mapa.agregarConexion(0, 5, 3); //Porteria -> Plazoleta
    mapa.agregarConexion(0, 11, 4); //Porteria -> Zona Libre

    //Entrada parqueader
    mapa.agregarConexion(1, 11, 2); //Parqueadero -> Zona Libre
    mapa.agregarConexion(1, 10, 3); //Parqueadero -> ACA2

    //Capilla
    mapa.agregarConexion(2, 4, 1); //Capilla -> Auditorio
    mapa.agregarConexion(2, 3, 2); //Capilla -> Admin1
    mapa.agregarConexion(2, 5, 3); //Capilla -> Plazoleta

    //Admin1
    mapa.agregarConexion(3, 4, 1); //Admin1 -> Auditorio
    mapa.agregarConexion(3, 5, 2); //Admin1 -> Plazoleta
    mapa.agregarConexion(3, 9, 3); //Admin1 -> Cafeteria

    //Auditorio
    mapa.agregarConexion(4, 5, 1); //Auditorio -> Plazoleta
    mapa.agregarConexion(4, 6, 1); //Auditorio -> TEC

    //Plazoleta
    mapa.agregarConexion(5, 6, 1); //Pazoleta -> TEC
    mapa.agregarConexion(5, 7, 2); //Pazoleta -> Admin2
    mapa.agregarConexion(5, 8, 1); //Pazoleta -> ACA1
    mapa.agregarConexion(5, 9, 2); //Pazoleta -> Cafetería

    //Tec
    mapa.agregarConexion(6, 7, 1); //Tec -> Admin2

    //Admin2
    mapa.agregarConexion(7, 8, 1); //Admin2 -> ACA1

    //ACA1
    mapa.agregarConexion(8, 9, 2); //ACA1 -> Cafetería

    //Cafetería
    mapa.agregarConexion(9, 10, 1); //Cafetería -> ACA2

    //ACA2
    mapa.agregarConexion(10, 11, 1); //ACA2 -> Zona libre


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

MainWindow::~MainWindow()
{    
    delete ui;
}

void MainWindow::on_btnDFS_clicked() {
    int inicio = ui->comboInicio->currentIndex();
    std::ostringstream oss;
    mapa.recorrerDFS(inicio, oss);
    ui->textResultado->setText(QString::fromStdString(oss.str()));
}

void MainWindow::on_btnDijkstra_clicked() {
    int origen = ui->comboInicio->currentIndex();
    int destino = ui->comboDestino->currentIndex();
    auto ruta = mapa.calcularRuta(origen, destino);

    std::ostringstream oss;
    mapa.mostrarRuta(ruta, oss);
    ui->textResultado->setText(QString::fromStdString(oss.str()));
}
