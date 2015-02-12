/********************************************************************************
** Form generated from reading UI file 'protoserver.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROTOSERVER_H
#define UI_PROTOSERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_protoserverClass
{
public:

    void setupUi(QWidget *protoserverClass)
    {
        if (protoserverClass->objectName().isEmpty())
            protoserverClass->setObjectName(QStringLiteral("protoserverClass"));
        protoserverClass->resize(600, 400);

        retranslateUi(protoserverClass);

        QMetaObject::connectSlotsByName(protoserverClass);
    } // setupUi

    void retranslateUi(QWidget *protoserverClass)
    {
        protoserverClass->setWindowTitle(QApplication::translate("protoserverClass", "protoserver", 0));
    } // retranslateUi

};

namespace Ui {
    class protoserverClass: public Ui_protoserverClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROTOSERVER_H
