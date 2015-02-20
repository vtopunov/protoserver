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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_protoserverClass
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *port;
    QPushButton *listen;
    QPushButton *close;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *protoserverClass)
    {
        if (protoserverClass->objectName().isEmpty())
            protoserverClass->setObjectName(QStringLiteral("protoserverClass"));
        protoserverClass->resize(253, 170);
        verticalLayout = new QVBoxLayout(protoserverClass);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(1);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(protoserverClass);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        port = new QSpinBox(protoserverClass);
        port->setObjectName(QStringLiteral("port"));
        port->setMinimum(1);
        port->setMaximum(65535);
        port->setValue(8080);

        horizontalLayout->addWidget(port);

        listen = new QPushButton(protoserverClass);
        listen->setObjectName(QStringLiteral("listen"));

        horizontalLayout->addWidget(listen);

        close = new QPushButton(protoserverClass);
        close->setObjectName(QStringLiteral("close"));

        horizontalLayout->addWidget(close);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 118, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(protoserverClass);
        QObject::connect(close, SIGNAL(clicked()), protoserverClass, SLOT(tcpclose()));
        QObject::connect(listen, SIGNAL(clicked()), protoserverClass, SLOT(listen()));

        QMetaObject::connectSlotsByName(protoserverClass);
    } // setupUi

    void retranslateUi(QWidget *protoserverClass)
    {
        protoserverClass->setWindowTitle(QApplication::translate("protoserverClass", "protoserver", 0));
        label->setText(QApplication::translate("protoserverClass", "Port", 0));
        listen->setText(QApplication::translate("protoserverClass", "Listen", 0));
        close->setText(QApplication::translate("protoserverClass", "Close", 0));
    } // retranslateUi

};

namespace Ui {
    class protoserverClass: public Ui_protoserverClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROTOSERVER_H
