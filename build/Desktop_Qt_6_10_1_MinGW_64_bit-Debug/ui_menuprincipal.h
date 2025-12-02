/********************************************************************************
** Form generated from reading UI file 'menuprincipal.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENUPRINCIPAL_H
#define UI_MENUPRINCIPAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MenuPrincipal
{
public:
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *comboInicio;
    QComboBox *comboDestino;
    QTextEdit *textResultado;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnDijkstra;
    QPushButton *btnDFS;
    QPushButton *btnRegresar;
    QLabel *label;

    void setupUi(QWidget *MenuPrincipal)
    {
        if (MenuPrincipal->objectName().isEmpty())
            MenuPrincipal->setObjectName("MenuPrincipal");
        MenuPrincipal->resize(1280, 720);
        MenuPrincipal->setMinimumSize(QSize(1280, 720));
        MenuPrincipal->setMaximumSize(QSize(1280, 720));
        MenuPrincipal->setStyleSheet(QString::fromUtf8(""));
        groupBox = new QGroupBox(MenuPrincipal);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(90, 89, 421, 541));
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
        layoutWidget->setGeometry(QRect(10, 10, 401, 521));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");
        label_2->setStyleSheet(QString::fromUtf8("			  font: 14px 'Courier New';\n"
"            padding: 5px 5px;\n"
"            border: none;"));
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_3->addWidget(label_2);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");
        label_3->setStyleSheet(QString::fromUtf8("			  font: 14px 'Courier New';\n"
"            padding: 5px 5px;\n"
"            border: none;"));
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_3->addWidget(label_3);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        comboInicio = new QComboBox(layoutWidget);
        comboInicio->setObjectName("comboInicio");
        comboInicio->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"            font: 16px 'Courier New';\n"
"            color: white;                              /* texto blanco */\n"
"            background-color: #032263; /*\n"
"            qproperty-alignment: 'AlignCenter';\n"
"            border-radius: 12px;\n"
"            padding: 8px 20px 8px 12px;               /* espacio interno */\n"
"            border: 2px solid rgba(100, 100, 150, 200); /* borde suave */\n"
"            min-width: 150px;\n"
"        }"));

        horizontalLayout_2->addWidget(comboInicio);

        comboDestino = new QComboBox(layoutWidget);
        comboDestino->setObjectName("comboDestino");
        comboDestino->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"            font: 16px 'Courier New';\n"
"            color: white;                              /* texto blanco */\n"
"            background-color: #032263; /*\n"
"            qproperty-alignment: 'AlignCenter';\n"
"            border-radius: 12px;\n"
"            padding: 8px 20px 8px 12px;               /* espacio interno */\n"
"            border: 2px solid rgba(100, 100, 150, 200); /* borde suave */\n"
"            min-width: 150px;\n"
"        }"));

        horizontalLayout_2->addWidget(comboDestino);


        verticalLayout->addLayout(horizontalLayout_2);

        textResultado = new QTextEdit(layoutWidget);
        textResultado->setObjectName("textResultado");
        textResultado->setStyleSheet(QString::fromUtf8("QTextEdit {\n"
"    font: 16px 'Courier New';\n"
"    color: #003366;              /* texto azul IUSH */\n"
"    background-color: rgba(255, 255, 255, 200); /* fondo semi-transparente */\n"
"    border-radius: 15px;\n"
"    padding: 10px;\n"
"    border: 2px solid #7B1FA2;  /* borde morado */\n"
"}"));

        verticalLayout->addWidget(textResultado);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        btnDijkstra = new QPushButton(layoutWidget);
        btnDijkstra->setObjectName("btnDijkstra");
        btnDijkstra->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"            font: 16px 'Courier New';\n"
"            color: white;\n"
"            background-color: #9B1FA2;   /* morado base */\n"
"            border-radius: 15px;\n"
"            padding: 10px 20px;\n"
"            border: none;\n"
"        }"));

        horizontalLayout->addWidget(btnDijkstra);

        btnDFS = new QPushButton(layoutWidget);
        btnDFS->setObjectName("btnDFS");
        btnDFS->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"            font: 16px 'Courier New';\n"
"            color: white;\n"
"            background-color: #7B1FA2;   /* morado base */\n"
"            border-radius: 15px;\n"
"            padding: 10px 20px;\n"
"            border: none;\n"
"        }"));

        horizontalLayout->addWidget(btnDFS);


        verticalLayout->addLayout(horizontalLayout);

        btnRegresar = new QPushButton(layoutWidget);
        btnRegresar->setObjectName("btnRegresar");
        btnRegresar->setStyleSheet(QString::fromUtf8("font: 12px 'Courier New';\n"
"        color: white;\n"
"        background-color: #003366;  \n"
"        border-radius: 15px;\n"
"        padding: 8px 8px;\n"
"        border: none;\n"
"       "));

        verticalLayout->addWidget(btnRegresar);

        label = new QLabel(MenuPrincipal);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 1280, 720));
        label->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    font: 16px 'Courier New';\n"
"    color: white;                  /* texto blanco */\n"
"    background-color: #7B1FA2;     /* morado base IUSH */\n"
"    border-radius: 15px;\n"
"    padding: 8px 15px;\n"
"    border: none;\n"
"    min-width: 150px;\n"
"}"));
        label->setPixmap(QPixmap(QString::fromUtf8(":/img/img/rutaab.png")));
        label->setScaledContents(true);
        label->raise();
        groupBox->raise();
        label_3->raise();
        label_2->raise();

        retranslateUi(MenuPrincipal);

        QMetaObject::connectSlotsByName(MenuPrincipal);
    } // setupUi

    void retranslateUi(QWidget *MenuPrincipal)
    {
        MenuPrincipal->setWindowTitle(QCoreApplication::translate("MenuPrincipal", "Form", nullptr));
        groupBox->setTitle(QString());
        label_2->setText(QCoreApplication::translate("MenuPrincipal", "<html><head/><body><p align=\"center\"><span style=\" font-weight:700; color:#00007f;\">Origen</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("MenuPrincipal", "<html><head/><body><p align=\"center\"><span style=\" font-weight:700; color:#00007f;\">Destino</span></p></body></html>", nullptr));
        btnDijkstra->setText(QCoreApplication::translate("MenuPrincipal", "Ruta m\303\241s corta", nullptr));
        btnDFS->setText(QCoreApplication::translate("MenuPrincipal", "Recorrido Mapa", nullptr));
        btnRegresar->setText(QCoreApplication::translate("MenuPrincipal", "Regresar al men\303\272", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MenuPrincipal: public Ui_MenuPrincipal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUPRINCIPAL_H
