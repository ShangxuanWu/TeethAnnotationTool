/********************************************************************************
** Form generated from reading UI file 'TeethAnnotationTool.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEETHANNOTATIONTOOL_H
#define UI_TEETHANNOTATIONTOOL_H

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

class Ui_TeethAnnotationToolClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TeethAnnotationToolClass)
    {
        if (TeethAnnotationToolClass->objectName().isEmpty())
            TeethAnnotationToolClass->setObjectName(QStringLiteral("TeethAnnotationToolClass"));
        TeethAnnotationToolClass->resize(600, 400);
        menuBar = new QMenuBar(TeethAnnotationToolClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        TeethAnnotationToolClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TeethAnnotationToolClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        TeethAnnotationToolClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(TeethAnnotationToolClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        TeethAnnotationToolClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(TeethAnnotationToolClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        TeethAnnotationToolClass->setStatusBar(statusBar);

        retranslateUi(TeethAnnotationToolClass);

        QMetaObject::connectSlotsByName(TeethAnnotationToolClass);
    } // setupUi

    void retranslateUi(QMainWindow *TeethAnnotationToolClass)
    {
        TeethAnnotationToolClass->setWindowTitle(QApplication::translate("TeethAnnotationToolClass", "TeethAnnotationTool", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TeethAnnotationToolClass: public Ui_TeethAnnotationToolClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEETHANNOTATIONTOOL_H
