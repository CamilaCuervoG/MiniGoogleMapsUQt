#include "infolugardialog.h"
#include "ui_infolugardialog.h"
#include <QGraphicsDropShadowEffect>

InfoLugarDialog::InfoLugarDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InfoLugarDialog)
{
    ui->setupUi(this);
    ui->txtDescripcion->setReadOnly(true);
    connect(ui->btnCerrar, &QPushButton::clicked, this, &QDialog::accept);

    // Estilos modernos para dialog
    setStyleSheet(R"(
        QDialog {
            background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 #ffffff, stop:1 #f0f0f0);
            border-radius: 20px;
            border: 2px solid #7e3c8c;
        }

        QLabel {
            font: 14px 'Courier New';
            color: #211f43;
        }

        QTextEdit {
            background-color: #ffffff;
            border: 1px solid #d3d3d3;
            border-radius: 10px;
            padding: 6px;
            font: 14px 'Courier New';
            color: #333333;
        }

        QPushButton {
            font: 14px 'Courier New';
            background-color: #7e3c8c;
            color: white;
            padding: 8px 20px;
            border-radius: 12px;
            border: none;
        }

        QPushButton:hover {
            background-color: #9c27b0;
            font-weight: bold;
        }

        QPushButton:pressed {
            background-color: #4B0082;
        }
    )");

    // Sombra suave alrededor del dialog
    QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect(this);
    shadow->setBlurRadius(25);
    shadow->setOffset(0, 5);
    shadow->setColor(QColor(0, 0, 0, 80));
    this->setGraphicsEffect(shadow);
}

InfoLugarDialog::~InfoLugarDialog()
{
    delete ui;
}

void InfoLugarDialog::setInfo(const QString &nombre,
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
