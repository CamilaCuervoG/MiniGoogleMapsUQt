#ifndef LUGARBLOQUE_H
#define LUGARBLOQUE_H

#include <QWidget>

namespace Ui {
class LugarBloque;
}

class LugarBloque : public QWidget
{
    Q_OBJECT

public:
    explicit LugarBloque(QWidget *parent = nullptr);
    ~LugarBloque();

private:
    Ui::LugarBloque *ui;
};

#endif // LUGARBLOQUE_H
