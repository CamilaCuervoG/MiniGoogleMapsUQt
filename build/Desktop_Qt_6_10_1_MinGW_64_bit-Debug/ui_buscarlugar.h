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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BuscarLugar
{
public:
    QPushButton *pushButton;

    void setupUi(QWidget *BuscarLugar)
    {
        if (BuscarLugar->objectName().isEmpty())
            BuscarLugar->setObjectName("BuscarLugar");
        BuscarLugar->resize(400, 300);
        pushButton = new QPushButton(BuscarLugar);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(120, 140, 56, 18));

        retranslateUi(BuscarLugar);

        QMetaObject::connectSlotsByName(BuscarLugar);
    } // setupUi

    void retranslateUi(QWidget *BuscarLugar)
    {
        BuscarLugar->setWindowTitle(QCoreApplication::translate("BuscarLugar", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("BuscarLugar", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BuscarLugar: public Ui_BuscarLugar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUSCARLUGAR_H
