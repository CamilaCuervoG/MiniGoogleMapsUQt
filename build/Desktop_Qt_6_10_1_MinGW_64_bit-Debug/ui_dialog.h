/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
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

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(400, 300);
        verticalLayoutWidget = new QWidget(Dialog);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(30, 30, 160, 139));
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


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        lblNombre->setText(QCoreApplication::translate("Dialog", "TextLabel", nullptr));
        lblBloque->setText(QCoreApplication::translate("Dialog", "TextLabel", nullptr));
        lblPiso->setText(QCoreApplication::translate("Dialog", "TextLabel", nullptr));
        lblCorreo->setText(QCoreApplication::translate("Dialog", "TextLabel", nullptr));
        btnCerrar->setText(QCoreApplication::translate("Dialog", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
