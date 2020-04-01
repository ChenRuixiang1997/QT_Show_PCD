/********************************************************************************
** Form generated from reading UI file 'QT_Show_PCD.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QT_SHOW_PCD_H
#define UI_QT_SHOW_PCD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "QVTKWidget.h"

QT_BEGIN_NAMESPACE

class Ui_QT_Show_PCDClass
{
public:
    QAction *actionOpen;
    QWidget *centralWidget;
    QVTKWidget *qvtkWidget;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QT_Show_PCDClass)
    {
        if (QT_Show_PCDClass->objectName().isEmpty())
            QT_Show_PCDClass->setObjectName(QStringLiteral("QT_Show_PCDClass"));
        QT_Show_PCDClass->resize(600, 400);
        actionOpen = new QAction(QT_Show_PCDClass);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        centralWidget = new QWidget(QT_Show_PCDClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        qvtkWidget = new QVTKWidget(centralWidget);
        qvtkWidget->setObjectName(QStringLiteral("qvtkWidget"));
        qvtkWidget->setGeometry(QRect(30, 0, 531, 321));
        QT_Show_PCDClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QT_Show_PCDClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 26));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        QT_Show_PCDClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QT_Show_PCDClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QT_Show_PCDClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QT_Show_PCDClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QT_Show_PCDClass->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(actionOpen);

        retranslateUi(QT_Show_PCDClass);

        QMetaObject::connectSlotsByName(QT_Show_PCDClass);
    } // setupUi

    void retranslateUi(QMainWindow *QT_Show_PCDClass)
    {
        QT_Show_PCDClass->setWindowTitle(QApplication::translate("QT_Show_PCDClass", "QT_Show_PCD", Q_NULLPTR));
        actionOpen->setText(QApplication::translate("QT_Show_PCDClass", "open", Q_NULLPTR));
        menu->setTitle(QApplication::translate("QT_Show_PCDClass", "\346\226\207\344\273\266", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QT_Show_PCDClass: public Ui_QT_Show_PCDClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT_SHOW_PCD_H
