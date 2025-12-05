/********************************************************************************
** Form generated from reading UI file 'buscarlugar.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUSCARLUGAR_H
#define UI_BUSCARLUGAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BuscarLugar
{
public:
    QWidget *widget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *txtBuscar;
    QPushButton *btnBuscar;
    QListWidget *listResultados;
    QPushButton *btnRegresar;
    QLabel *lblFondo;

    void setupUi(QWidget *BuscarLugar)
    {
        if (BuscarLugar->objectName().isEmpty())
            BuscarLugar->setObjectName("BuscarLugar");
        BuscarLugar->resize(1280, 720);
        BuscarLugar->setMinimumSize(QSize(1280, 720));
        BuscarLugar->setMaximumSize(QSize(1280, 720));
        widget = new QWidget(BuscarLugar);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(324, 70, 621, 581));
        widget->setStyleSheet(QString::fromUtf8(""));
        verticalLayoutWidget = new QWidget(widget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(20, 20, 581, 541));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        txtBuscar = new QLineEdit(verticalLayoutWidget);
        txtBuscar->setObjectName("txtBuscar");
        txtBuscar->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    font: 16px 'Courier New';\n"
"    padding: 8px 12px;\n"
"    border-radius: 15px;\n"
"    border: 2px solid #7e3c8c;\n"
"    background-color: rgba(255,255,255,0.9);\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #4B0082;\n"
"    background-color: rgba(255,255,255,1);\n"
"}\n"
""));

        horizontalLayout_2->addWidget(txtBuscar);

        btnBuscar = new QPushButton(verticalLayoutWidget);
        btnBuscar->setObjectName("btnBuscar");
        btnBuscar->setStyleSheet(QString::fromUtf8("    QPushButton {\n"
"    font: 16px 'Courier New';\n"
"    color: white;\n"
"    border-radius: 15px;\n"
"    padding: 10px 25px;\n"
"    background-color: #7e3c8c; /* morado */\n"
"    }"));

        horizontalLayout_2->addWidget(btnBuscar);


        verticalLayout->addLayout(horizontalLayout_2);

        listResultados = new QListWidget(verticalLayoutWidget);
        listResultados->setObjectName("listResultados");
        listResultados->setStyleSheet(QString::fromUtf8("        QListWidget {\n"
"            background-color: rgba(245,245,245,0.85);\n"
"            border-radius: 15px;\n"
"            padding: 5px;\n"
"            font: 14px 'Courier New';\n"
"        }"));

        verticalLayout->addWidget(listResultados);

        btnRegresar = new QPushButton(verticalLayoutWidget);
        btnRegresar->setObjectName("btnRegresar");
        btnRegresar->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"            font: 14px 'Courier New';\n"
"            color: white;\n"
"            background-color: #1A356A;\n"
"            border-radius: 15px;\n"
"            padding: 10px 10px;\n"
"            border: none;\n"
"        }"));

        verticalLayout->addWidget(btnRegresar);

        lblFondo = new QLabel(BuscarLugar);
        lblFondo->setObjectName("lblFondo");
        lblFondo->setGeometry(QRect(0, 0, 1280, 720));
        lblFondo->setMinimumSize(QSize(1280, 720));
        lblFondo->setMaximumSize(QSize(1280, 720));
        lblFondo->setPixmap(QPixmap(QString::fromUtf8(":/img/img/IUSH.png")));
        lblFondo->setScaledContents(true);
        lblFondo->raise();
        widget->raise();

        retranslateUi(BuscarLugar);

        QMetaObject::connectSlotsByName(BuscarLugar);
    } // setupUi

    void retranslateUi(QWidget *BuscarLugar)
    {
        BuscarLugar->setWindowTitle(QCoreApplication::translate("BuscarLugar", "Form", nullptr));
        btnBuscar->setText(QCoreApplication::translate("BuscarLugar", "Buscar", nullptr));
        btnRegresar->setText(QCoreApplication::translate("BuscarLugar", "Regresar al menu principal", nullptr));
        lblFondo->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class BuscarLugar: public Ui_BuscarLugar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUSCARLUGAR_H
