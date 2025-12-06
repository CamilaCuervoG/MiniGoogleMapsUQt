#ifndef INFOLUGARDIALOG_H
#define INFOLUGARDIALOG_H

#include <QDialog>

namespace Ui {
class InfoLugarDialog;
}

class InfoLugarDialog : public QDialog
{
    Q_OBJECT

public:
    // Constructor: inicializo el diálogo que muestra la información detallada del lugar
    explicit InfoLugarDialog(QWidget *parent = nullptr);

    // Destructor: libero los recursos de la interfaz
    ~InfoLugarDialog();

    // Método para cargar toda la información del lugar dentro del diálogo
    void setInfo(const QString &nombre,
                 const QString &bloque,
                 const QString &piso,
                 const QString &correo,
                 const QString &descripcion);

private:
    Ui::InfoLugarDialog *ui; // Puntero a la interfaz gráfica creada con Qt Designer
};

#endif // INFOLUGARDIALOG_H
