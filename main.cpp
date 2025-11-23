#include <QApplication>
#include "MainWindow.h"
#include "mapa.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow window;
    window.show();   // Muestra la ventana principal
    return app.exec();  // Ejecuta el bucle de eventos de Qt
}
