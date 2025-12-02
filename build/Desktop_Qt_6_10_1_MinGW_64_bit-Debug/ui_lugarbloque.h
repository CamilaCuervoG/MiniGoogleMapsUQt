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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LugarBloque
{
public:
    QPushButton *pushButton;

    void setupUi(QWidget *LugarBloque)
    {
        if (LugarBloque->objectName().isEmpty())
            LugarBloque->setObjectName("LugarBloque");
        LugarBloque->resize(400, 300);
        pushButton = new QPushButton(LugarBloque);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(170, 130, 56, 18));

        retranslateUi(LugarBloque);

        QMetaObject::connectSlotsByName(LugarBloque);
    } // setupUi

    void retranslateUi(QWidget *LugarBloque)
    {
        LugarBloque->setWindowTitle(QCoreApplication::translate("LugarBloque", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("LugarBloque", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LugarBloque: public Ui_LugarBloque {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LUGARBLOQUE_H
