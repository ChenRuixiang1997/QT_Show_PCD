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
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "QVTKWidget.h"

QT_BEGIN_NAMESPACE

class Ui_QT_Show_PCDClass
{
public:
    QAction *actionOpen;
    QAction *voxelGridButton;
    QAction *actionTest;
    QWidget *centralWidget;
    QVTKWidget *qvtkWidget;
    QFrame *line;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QVBoxLayout *verticalLayout;
    QPushButton *voxelGridButton_2;
    QSpacerItem *verticalSpacer_2;
    QPushButton *passThroughButton;
    QSpacerItem *verticalSpacer;
    QPushButton *statisticalOutlierRemovalButton;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QT_Show_PCDClass)
    {
        if (QT_Show_PCDClass->objectName().isEmpty())
            QT_Show_PCDClass->setObjectName(QStringLiteral("QT_Show_PCDClass"));
        QT_Show_PCDClass->resize(902, 583);
        actionOpen = new QAction(QT_Show_PCDClass);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        voxelGridButton = new QAction(QT_Show_PCDClass);
        voxelGridButton->setObjectName(QStringLiteral("voxelGridButton"));
        actionTest = new QAction(QT_Show_PCDClass);
        actionTest->setObjectName(QStringLiteral("actionTest"));
        centralWidget = new QWidget(QT_Show_PCDClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        qvtkWidget = new QVTKWidget(centralWidget);
        qvtkWidget->setObjectName(QStringLiteral("qvtkWidget"));
        qvtkWidget->setGeometry(QRect(30, 10, 521, 501));
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(560, 0, 20, 741));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(580, 10, 97, 218));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_2->addWidget(label);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        voxelGridButton_2 = new QPushButton(widget);
        voxelGridButton_2->setObjectName(QStringLiteral("voxelGridButton_2"));

        verticalLayout->addWidget(voxelGridButton_2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        passThroughButton = new QPushButton(widget);
        passThroughButton->setObjectName(QStringLiteral("passThroughButton"));

        verticalLayout->addWidget(passThroughButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        statisticalOutlierRemovalButton = new QPushButton(widget);
        statisticalOutlierRemovalButton->setObjectName(QStringLiteral("statisticalOutlierRemovalButton"));

        verticalLayout->addWidget(statisticalOutlierRemovalButton);


        verticalLayout_2->addLayout(verticalLayout);

        QT_Show_PCDClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QT_Show_PCDClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 902, 26));
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
        voxelGridButton->setText(QApplication::translate("QT_Show_PCDClass", "\344\270\213\351\207\207\346\240\267", Q_NULLPTR));
        actionTest->setText(QApplication::translate("QT_Show_PCDClass", "test", Q_NULLPTR));
        label->setText(QApplication::translate("QT_Show_PCDClass", "\347\202\271\344\272\221\345\244\204\347\220\206:", Q_NULLPTR));
        voxelGridButton_2->setText(QApplication::translate("QT_Show_PCDClass", "\344\270\213\351\207\207\346\240\267\346\273\244\346\263\242", Q_NULLPTR));
        passThroughButton->setText(QApplication::translate("QT_Show_PCDClass", "\347\233\264\351\200\232\346\273\244\346\263\242", Q_NULLPTR));
        statisticalOutlierRemovalButton->setText(QApplication::translate("QT_Show_PCDClass", "\347\273\237\350\256\241\346\273\244\346\263\242", Q_NULLPTR));
        menu->setTitle(QApplication::translate("QT_Show_PCDClass", "\346\226\207\344\273\266", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QT_Show_PCDClass: public Ui_QT_Show_PCDClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT_SHOW_PCD_H
