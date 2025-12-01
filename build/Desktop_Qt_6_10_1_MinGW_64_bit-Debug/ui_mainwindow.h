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
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *btnDFS;
    QPushButton *btnDijkstra;
    QComboBox *comboInicio;
    QTextEdit *textResultado;
    QComboBox *comboDestino;
    QMenuBar *menubar;
    QMenu *menuMapa;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(481, 250);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        btnDFS = new QPushButton(centralwidget);
        btnDFS->setObjectName("btnDFS");
        btnDFS->setGeometry(QRect(250, 20, 211, 18));
        btnDijkstra = new QPushButton(centralwidget);
        btnDijkstra->setObjectName("btnDijkstra");
        btnDijkstra->setGeometry(QRect(20, 20, 211, 18));
        comboInicio = new QComboBox(centralwidget);
        comboInicio->setObjectName("comboInicio");
        comboInicio->setGeometry(QRect(20, 50, 211, 21));
        textResultado = new QTextEdit(centralwidget);
        textResultado->setObjectName("textResultado");
        textResultado->setGeometry(QRect(20, 80, 441, 131));
        comboDestino = new QComboBox(centralwidget);
        comboDestino->setObjectName("comboDestino");
        comboDestino->setGeometry(QRect(250, 50, 211, 21));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 481, 17));
        menuMapa = new QMenu(menubar);
        menuMapa->setObjectName("menuMapa");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuMapa->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        btnDFS->setText(QCoreApplication::translate("MainWindow", "Recorrido Mapa", nullptr));
        btnDijkstra->setText(QCoreApplication::translate("MainWindow", "Ruta m\303\241s corta", nullptr));
        menuMapa->setTitle(QCoreApplication::translate("MainWindow", "Mapa", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
