#include "InfoLugarDialog.h"
#include "ui_InfoLugarDialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InfoLugarDialog)
{
    ui->setupUi(this);

    // Estilo de tarjeta flotante
    setStyleSheet(R"(
        QWidget {
            background-color: #F2F1F3;
            border-radius: 15px;
        }
        QLabel {
            font: 14px 'Courier New';
            color: #211f43;
        }
        QPushButton {
            font: 14px 'Courier New';
            background-color: #7e3c8c;
            color: white;
            padding: 6px 14px;
            border-radius: 8px;
            border: none;
        }
        QPushButton:hover {
            background-color: #8c66a6;
        }
    )");

    setWindowFlags(Qt::Dialog | Qt::CustomizeWindowHint | Qt::WindowTitleHint);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::setInfo(const QString &nombre,
                           const QString &bloque,
                           const QString &piso,
                           const QString &correo,
                           const QString &descripcion)
{
    ui->lblNombre->setText(nombre);
    ui->lblBloque->setText("Bloque: " + bloque);
    ui->lblPiso->setText("Piso: " + piso);
    ui->lblCorreo->setText("Correo: " + correo);
    ui->txtDescripcion->setText(descripcion);
}
