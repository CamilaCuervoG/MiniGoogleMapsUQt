#include "buscarlugar.h"
#include "ui_buscarlugar.h"

BuscarLugar::BuscarLugar(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::BuscarLugar)
{
    ui->setupUi(this);
}

BuscarLugar::~BuscarLugar()
{
    delete ui;
}
