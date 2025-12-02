#include "lugarbloque.h"
#include "ui_lugarbloque.h"

LugarBloque::LugarBloque(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LugarBloque)
{
    ui->setupUi(this);
}

LugarBloque::~LugarBloque()
{
    delete ui;
}
