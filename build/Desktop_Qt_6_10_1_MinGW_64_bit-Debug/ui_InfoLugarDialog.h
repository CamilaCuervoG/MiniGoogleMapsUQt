/********************************************************************************
** Form generated from reading UI file 'InfoLugarDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFOLUGARDIALOG_H
#define UI_INFOLUGARDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InfoLugarDialog
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *lblNombre;
    QLabel *lblBloque;
    QLabel *lblPiso;
    QLabel *lblCorreo;
    QTextEdit *txtDescripcion;
    QPushButton *btnCerrar;

    void setupUi(QDialog *InfoLugarDialog)
    {
        if (InfoLugarDialog->objectName().isEmpty())
            InfoLugarDialog->setObjectName("InfoLugarDialog");
        InfoLugarDialog->resize(400, 300);
        verticalLayoutWidget = new QWidget(InfoLugarDialog);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(40, 40, 301, 221));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        lblNombre = new QLabel(verticalLayoutWidget);
        lblNombre->setObjectName("lblNombre");

        verticalLayout->addWidget(lblNombre);

        lblBloque = new QLabel(verticalLayoutWidget);
        lblBloque->setObjectName("lblBloque");

        verticalLayout->addWidget(lblBloque);

        lblPiso = new QLabel(verticalLayoutWidget);
        lblPiso->setObjectName("lblPiso");

        verticalLayout->addWidget(lblPiso);

        lblCorreo = new QLabel(verticalLayoutWidget);
        lblCorreo->setObjectName("lblCorreo");

        verticalLayout->addWidget(lblCorreo);

        txtDescripcion = new QTextEdit(verticalLayoutWidget);
        txtDescripcion->setObjectName("txtDescripcion");

        verticalLayout->addWidget(txtDescripcion);

        btnCerrar = new QPushButton(verticalLayoutWidget);
        btnCerrar->setObjectName("btnCerrar");

        verticalLayout->addWidget(btnCerrar);


        retranslateUi(InfoLugarDialog);

        QMetaObject::connectSlotsByName(InfoLugarDialog);
    } // setupUi

    void retranslateUi(QDialog *InfoLugarDialog)
    {
        InfoLugarDialog->setWindowTitle(QCoreApplication::translate("InfoLugarDialog", "Dialog", nullptr));
        lblNombre->setText(QCoreApplication::translate("InfoLugarDialog", "TextLabel", nullptr));
        lblBloque->setText(QCoreApplication::translate("InfoLugarDialog", "TextLabel", nullptr));
        lblPiso->setText(QCoreApplication::translate("InfoLugarDialog", "TextLabel", nullptr));
        lblCorreo->setText(QCoreApplication::translate("InfoLugarDialog", "TextLabel", nullptr));
        btnCerrar->setText(QCoreApplication::translate("InfoLugarDialog", "Regresar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InfoLugarDialog: public Ui_InfoLugarDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFOLUGARDIALOG_H
