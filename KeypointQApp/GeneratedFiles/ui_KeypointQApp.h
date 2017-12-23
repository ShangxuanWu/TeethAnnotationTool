/********************************************************************************
** Form generated from reading UI file 'KeypointQApp.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KEYPOINTQAPP_H
#define UI_KEYPOINTQAPP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_KeypointQAppClass
{
public:

    void setupUi(QDialog *KeypointQAppClass)
    {
        if (KeypointQAppClass->objectName().isEmpty())
            KeypointQAppClass->setObjectName(QStringLiteral("KeypointQAppClass"));
        KeypointQAppClass->resize(600, 400);

        retranslateUi(KeypointQAppClass);

        QMetaObject::connectSlotsByName(KeypointQAppClass);
    } // setupUi

    void retranslateUi(QDialog *KeypointQAppClass)
    {
        KeypointQAppClass->setWindowTitle(QApplication::translate("KeypointQAppClass", "KeypointQApp", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class KeypointQAppClass: public Ui_KeypointQAppClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KEYPOINTQAPP_H
