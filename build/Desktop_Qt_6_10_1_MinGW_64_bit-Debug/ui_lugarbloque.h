/********************************************************************************
** Form generated from reading UI file 'lugarbloque.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LUGARBLOQUE_H
#define UI_LUGARBLOQUE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LugarBloque
{
public:
    QLabel *lblFondo;
    QListWidget *listEspacios;
    QLabel *labelImagenBloque;
    QLabel *label;
    QWidget *widgetBotones;
    QVBoxLayout *verticalLayout_2;
    QPushButton *btnTEC;
    QPushButton *btnACA1;
    QPushButton *btnACA2;
    QPushButton *btnAdmin1;
    QPushButton *btnAdmin2;
    QPushButton *btnAdmin3;
    QLabel *label_2;
    QPushButton *btnRegresar;

    void setupUi(QWidget *LugarBloque)
    {
        if (LugarBloque->objectName().isEmpty())
            LugarBloque->setObjectName("LugarBloque");
        LugarBloque->resize(1280, 720);
        LugarBloque->setMinimumSize(QSize(1280, 720));
        LugarBloque->setMaximumSize(QSize(1280, 720));
        lblFondo = new QLabel(LugarBloque);
        lblFondo->setObjectName("lblFondo");
        lblFondo->setGeometry(QRect(0, 0, 1280, 720));
        lblFondo->setMinimumSize(QSize(1280, 720));
        lblFondo->setMaximumSize(QSize(1280, 720));
        lblFondo->setPixmap(QPixmap(QString::fromUtf8(":/img/img/lugarBloque.png")));
        lblFondo->setScaledContents(true);
        listEspacios = new QListWidget(LugarBloque);
        listEspacios->setObjectName("listEspacios");
        listEspacios->setGeometry(QRect(337, 118, 331, 491));
        listEspacios->setStyleSheet(QString::fromUtf8("QListWidget {\n"
"            background-color: transparent;\n"
"            padding: 5px;\n"
"            font: 14px 'Courier New';\n"
"            font-weight: bold;\n"
"            color: #FFFFFF;\n"
"            outline: 0;\n"
"        }"));
        labelImagenBloque = new QLabel(LugarBloque);
        labelImagenBloque->setObjectName("labelImagenBloque");
        labelImagenBloque->setGeometry(QRect(710, 116, 491, 491));
        labelImagenBloque->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border: 2px solid #D1D0D5;\n"
"border-radius: 15px;\n"
" "));
        labelImagenBloque->setScaledContents(false);
        label = new QLabel(LugarBloque);
        label->setObjectName("label");
        label->setGeometry(QRect(70, 160, 231, 131));
        label->setAutoFillBackground(false);
        label->setStyleSheet(QString::fromUtf8("\n"
"    font: 15px 'Courier New';             /* fuente moderna */\n"
"    border-radius: 15px;                  /* bordes redondeados */\n"
"    padding: 20px;\n"
"	color: rgb(0, 0, 0);\n"
"   background-color: none;\n"
""));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label->setWordWrap(true);
        widgetBotones = new QWidget(LugarBloque);
        widgetBotones->setObjectName("widgetBotones");
        widgetBotones->setGeometry(QRect(80, 300, 211, 301));
        widgetBotones->setStyleSheet(QString::fromUtf8("\n"
"            font: 16px 'Courier New';\n"
"            color: white;\n"
"            background-color: none;\n"
"            border-radius: 15px;\n"
"            padding: 10px 20px;\n"
"				border: 100px;\n"
""));
        verticalLayout_2 = new QVBoxLayout(widgetBotones);
        verticalLayout_2->setObjectName("verticalLayout_2");
        btnTEC = new QPushButton(widgetBotones);
        btnTEC->setObjectName("btnTEC");
        btnTEC->setStyleSheet(QString::fromUtf8("        QPushButton {\n"
"            font: 15px 'Courier New';\n"
"            color: black;\n"
"            background-color: #F2F2F2;\n"
"            border-radius: 8px;\n"
"            padding: 5px 20px;\n"
"            border: none;\n"
"        }"));

        verticalLayout_2->addWidget(btnTEC);

        btnACA1 = new QPushButton(widgetBotones);
        btnACA1->setObjectName("btnACA1");
        btnACA1->setStyleSheet(QString::fromUtf8("        QPushButton {\n"
"            font: 15px 'Courier New';\n"
"            color: black;\n"
"            background-color: #F2F2F2;\n"
"            border-radius: 8px;\n"
"            padding: 5px 20px;\n"
"            border: none;\n"
"        }"));

        verticalLayout_2->addWidget(btnACA1);

        btnACA2 = new QPushButton(widgetBotones);
        btnACA2->setObjectName("btnACA2");
        btnACA2->setStyleSheet(QString::fromUtf8("        QPushButton {\n"
"            font: 15px 'Courier New';\n"
"            color: black;\n"
"            background-color: #F2F2F2;\n"
"            border-radius: 8px;\n"
"            padding: 5px 20px;\n"
"            border: none;\n"
"        }"));

        verticalLayout_2->addWidget(btnACA2);

        btnAdmin1 = new QPushButton(widgetBotones);
        btnAdmin1->setObjectName("btnAdmin1");
        btnAdmin1->setStyleSheet(QString::fromUtf8("        QPushButton {\n"
"            font: 15px 'Courier New';\n"
"            color: black;\n"
"            background-color: #F2F2F2;\n"
"            border-radius: 8px;\n"
"            padding: 5px 20px;\n"
"            border: none;\n"
"        }"));

        verticalLayout_2->addWidget(btnAdmin1);

        btnAdmin2 = new QPushButton(widgetBotones);
        btnAdmin2->setObjectName("btnAdmin2");
        btnAdmin2->setStyleSheet(QString::fromUtf8("        QPushButton {\n"
"            font: 15px 'Courier New';\n"
"            color: black;\n"
"            background-color: #F2F2F2;\n"
"            border-radius: 8px;\n"
"            padding: 5px 20px;\n"
"            border: none;\n"
"        }"));

        verticalLayout_2->addWidget(btnAdmin2);

        btnAdmin3 = new QPushButton(widgetBotones);
        btnAdmin3->setObjectName("btnAdmin3");
        btnAdmin3->setStyleSheet(QString::fromUtf8("        QPushButton {\n"
"            font: 15px 'Courier New';\n"
"            color: black;\n"
"            background-color: #F2F2F2;\n"
"            border-radius: 8px;\n"
"            padding: 5px 20px;\n"
"            border: none;\n"
"        }"));

        verticalLayout_2->addWidget(btnAdmin3);

        label_2 = new QLabel(widgetBotones);
        label_2->setObjectName("label_2");

        verticalLayout_2->addWidget(label_2);

        btnRegresar = new QPushButton(widgetBotones);
        btnRegresar->setObjectName("btnRegresar");
        btnRegresar->setStyleSheet(QString::fromUtf8("        QPushButton {\n"
"            font: 15px 'Courier New';\n"
"            color: white;\n"
"            background-color: #1A356A;\n"
"            border-radius: 15px;\n"
"            padding: 10px 10px;\n"
"            border: none;\n"
"        }"));

        verticalLayout_2->addWidget(btnRegresar);


        retranslateUi(LugarBloque);

        QMetaObject::connectSlotsByName(LugarBloque);
    } // setupUi

    void retranslateUi(QWidget *LugarBloque)
    {
        LugarBloque->setWindowTitle(QCoreApplication::translate("LugarBloque", "Form", nullptr));
        lblFondo->setText(QString());
        labelImagenBloque->setText(QString());
        label->setText(QCoreApplication::translate("LugarBloque", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; color:#000000;\">Por favor, seleccione un bloque para visualizar su informaci\303\263n.</span></p></body></html>", nullptr));
        btnTEC->setText(QCoreApplication::translate("LugarBloque", "Tecnologico", nullptr));
        btnACA1->setText(QCoreApplication::translate("LugarBloque", "Academico 01", nullptr));
        btnACA2->setText(QCoreApplication::translate("LugarBloque", "Academico 02", nullptr));
        btnAdmin1->setText(QCoreApplication::translate("LugarBloque", "Administrativo 01", nullptr));
        btnAdmin2->setText(QCoreApplication::translate("LugarBloque", "Administrativo 02", nullptr));
        btnAdmin3->setText(QCoreApplication::translate("LugarBloque", "Administrativo 03", nullptr));
        label_2->setText(QCoreApplication::translate("LugarBloque", "TextLabel", nullptr));
        btnRegresar->setText(QCoreApplication::translate("LugarBloque", "<- Regresar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LugarBloque: public Ui_LugarBloque {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LUGARBLOQUE_H
