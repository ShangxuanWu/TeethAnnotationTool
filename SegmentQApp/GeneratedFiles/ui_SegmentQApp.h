/********************************************************************************
** Form generated from reading UI file 'SegmentQApp.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEGMENTQAPP_H
#define UI_SEGMENTQAPP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SegmentQAppClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SegmentQAppClass)
    {
        if (SegmentQAppClass->objectName().isEmpty())
            SegmentQAppClass->setObjectName(QStringLiteral("SegmentQAppClass"));
        SegmentQAppClass->resize(600, 400);
        menuBar = new QMenuBar(SegmentQAppClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        SegmentQAppClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SegmentQAppClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        SegmentQAppClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(SegmentQAppClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        SegmentQAppClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(SegmentQAppClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        SegmentQAppClass->setStatusBar(statusBar);

        retranslateUi(SegmentQAppClass);

        QMetaObject::connectSlotsByName(SegmentQAppClass);
    } // setupUi

    void retranslateUi(QMainWindow *SegmentQAppClass)
    {
        SegmentQAppClass->setWindowTitle(QApplication::translate("SegmentQAppClass", "SegmentQApp", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SegmentQAppClass: public Ui_SegmentQAppClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEGMENTQAPP_H
