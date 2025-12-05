#ifndef TARJETALUGAR_H
#define TARJETALUGAR_H

#include <QDialog>
#include <QString>

namespace Ui {
class TarjetaLugar;
}

class TarjetaLugar : public QDialog
{
    Q_OBJECT

public:
    explicit TarjetaLugar(QWidget *parent = nullptr);
    ~TarjetaLugar();

    void setInfo(const QString &nombre,
                 const QString &bloque,
                 const QString &piso,
                 const QString &correo,
                 const QString &descripcion);

private:
    Ui::TarjetaLugar *ui;
};

#endif // TARJETALUGAR_H
