#include "formMenuPrincipal.h"
#include "ui_formMenuPrincipal.h"

formMenuPrincipal::formMenuPrincipal(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::formMenuPrincipal)
{
    ui->setupUi(this);
}

formMenuPrincipal::~formMenuPrincipal()
{
    delete ui;
}
