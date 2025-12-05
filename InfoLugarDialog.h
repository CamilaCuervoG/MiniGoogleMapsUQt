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
    explicit InfoLugarDialog(QWidget *parent = nullptr);
    ~InfoLugarDialog();

    void setInfo(const QString &nombre,
                 const QString &bloque,
                 const QString &piso,
                 const QString &correo,
                 const QString &descripcion);

private:
    Ui::InfoLugarDialog *ui;
};

#endif // INFOLUGARDIALOG_H
