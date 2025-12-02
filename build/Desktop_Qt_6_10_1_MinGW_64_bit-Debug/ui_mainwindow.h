/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *saludoMenuPrincipal;
    QLabel *label_2;
    QPushButton *btnRutaAB;
    QPushButton *btnBuscar;
    QPushButton *btnLugarBloque;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1280, 720);
        MainWindow->setMinimumSize(QSize(1280, 720));
        MainWindow->setMaximumSize(QSize(1280, 720));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setAutoFillBackground(false);
        centralwidget->setStyleSheet(QString::fromUtf8("#centralwidget {\n"
"    border-image: url(\":/img/img/MenuPrincipal.png\") 0 0 0 0 stretch stretch;\n"
"}\n"
""));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setEnabled(true);
        groupBox->setGeometry(QRect(430, 120, 421, 451));
        groupBox->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"   background-color: rgba(255,255,255,0.7);\n"
"    box-shadow: 0px 0px 15px rgba(0,0,0,50); /* Qt Designer ignora box-shadow */\n"
"    border: none;             \n"
"    border-radius: 15px;\n"
"    padding: 15px;\n"
"    /* sombra simulada */\n"
"    box-shadow: 0px 0px 15px rgba(0,0,0,50); /* Qt Designer ignora box-shadow */                   \n"
"	 margin-top: 0px;\n"
"}"));
        groupBox->setAlignment(Qt::AlignmentFlag::AlignCenter);
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(20, 20, 381, 411));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font: 24px 'Courier New';             /* fuente moderna */\n"
"    border-radius: 15px;                  /* bordes redondeados */\n"
"    padding: 20px;\n"
"}"));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label->setWordWrap(true);

        verticalLayout->addWidget(label);

        saludoMenuPrincipal = new QLabel(layoutWidget);
        saludoMenuPrincipal->setObjectName("saludoMenuPrincipal");
        saludoMenuPrincipal->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #000000; \n"
"    font: 10px 'Courier New';\n"
"}\n"
""));
        saludoMenuPrincipal->setAlignment(Qt::AlignmentFlag::AlignCenter);
        saludoMenuPrincipal->setWordWrap(true);

        verticalLayout->addWidget(saludoMenuPrincipal);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");
        label_2->setStyleSheet(QString::fromUtf8("font: 14px 'Courier New'; "));
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(label_2);

        btnRutaAB = new QPushButton(layoutWidget);
        btnRutaAB->setObjectName("btnRutaAB");
        btnRutaAB->setStyleSheet(QString::fromUtf8("font: 16px 'Courier New';\n"
"color: white; /* texto blanco */\n"
"background-color: #003366; /* azul IUSH */\n"
"border-radius: 15px; /* bordes redondeados */\n"
"padding: 10px 20px;\n"
"border: none;"));

        verticalLayout->addWidget(btnRutaAB);

        btnBuscar = new QPushButton(layoutWidget);
        btnBuscar->setObjectName("btnBuscar");
        btnBuscar->setStyleSheet(QString::fromUtf8("font: 16px 'Courier New';\n"
"color: white;\n"
"background-color: #7B1FA2;   /* morado base diferente */\n"
"border-radius: 15px;\n"
"padding: 10px 20px;\n"
"border: none;"));

        verticalLayout->addWidget(btnBuscar);

        btnLugarBloque = new QPushButton(layoutWidget);
        btnLugarBloque->setObjectName("btnLugarBloque");
        btnLugarBloque->setStyleSheet(QString::fromUtf8("font: 16px 'Courier New';\n"
"color: white;\n"
"background-color: #4B0082;   /* morado oscuro */\n"
"border-radius: 15px;\n"
"padding: 10px 20px;\n"
"border: none;"));

        verticalLayout->addWidget(btnLugarBloque);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QString());
        label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:24pt; font-weight:700; color:#55007f;\">Tejiendo Datos</span></p></body></html>", nullptr));
        saludoMenuPrincipal->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt;\">\302\241Bienvenido(a) a Tejiendo Datos! <br/></span></p><p align=\"center\"><span style=\" font-size:10pt;\">Explora y navega por el campus de manera sencilla, </span></p><p align=\"center\"><span style=\" font-size:10pt;\">encuentra tus destinos favoritos y recorre cada bloque con facilidad. <br/></span></p><p align=\"center\"><span style=\" font-size:10pt;\">\302\241Disfruta tu experiencia!</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; font-weight:700; color:#00007f;\">Selecciona tu acci\303\263n</span></p></body></html>", nullptr));
        btnRutaAB->setText(QCoreApplication::translate("MainWindow", "Consultar Ruta", nullptr));
        btnBuscar->setText(QCoreApplication::translate("MainWindow", "Buscar Lugar", nullptr));
        btnLugarBloque->setText(QCoreApplication::translate("MainWindow", "Ver Lugares Por Bloque", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
