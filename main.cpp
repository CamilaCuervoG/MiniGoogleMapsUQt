#include <QApplication>
#include "MainWindow.h"
#include "mapa.h"
#include "formMenuPrincipal.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    // Inicializa la aplicación Qt y permite manejar ventanas, eventos, etc.

    MainWindow window;
    // Crea la ventana principal de tu aplicación (MainWindow)

    window.show();      // Muestra la ventana principal
    return app.exec();  // Inicia el loop de eventos de Qt (la aplicación se queda corriendo) de Qt
}
