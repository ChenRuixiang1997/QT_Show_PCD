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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
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
    QLabel *label;
    QPushButton *voxelGridButton_2;
    QPushButton *statisticalOutlierRemovalButton;
    QFrame *line_2;
    QFrame *line_3;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_4;
    QGroupBox *radioGroupBox;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *setPathThroughX;
    QRadioButton *setPathThroughY;
    QRadioButton *setPathThroughZ;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *editLimitMin;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLineEdit *editLimitMax;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *passThroughButton;
    QCheckBox *checkFilterLimitsNegative;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QT_Show_PCDClass)
    {
        if (QT_Show_PCDClass->objectName().isEmpty())
            QT_Show_PCDClass->setObjectName(QStringLiteral("QT_Show_PCDClass"));
        QT_Show_PCDClass->resize(853, 583);
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
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(581, 11, 68, 16));
        voxelGridButton_2 = new QPushButton(centralWidget);
        voxelGridButton_2->setObjectName(QStringLiteral("voxelGridButton_2"));
        voxelGridButton_2->setGeometry(QRect(580, 240, 93, 28));
        statisticalOutlierRemovalButton = new QPushButton(centralWidget);
        statisticalOutlierRemovalButton->setObjectName(QStringLiteral("statisticalOutlierRemovalButton"));
        statisticalOutlierRemovalButton->setGeometry(QRect(580, 270, 93, 28));
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(570, 150, 311, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(centralWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(570, 30, 301, 16));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(581, 51, 269, 96));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        radioGroupBox = new QGroupBox(layoutWidget);
        radioGroupBox->setObjectName(QStringLiteral("radioGroupBox"));
        layoutWidget1 = new QWidget(radioGroupBox);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 22, 37, 73));
        verticalLayout_3 = new QVBoxLayout(layoutWidget1);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        setPathThroughX = new QRadioButton(layoutWidget1);
        setPathThroughX->setObjectName(QStringLiteral("setPathThroughX"));

        verticalLayout_3->addWidget(setPathThroughX);

        setPathThroughY = new QRadioButton(layoutWidget1);
        setPathThroughY->setObjectName(QStringLiteral("setPathThroughY"));

        verticalLayout_3->addWidget(setPathThroughY);

        setPathThroughZ = new QRadioButton(layoutWidget1);
        setPathThroughZ->setObjectName(QStringLiteral("setPathThroughZ"));

        verticalLayout_3->addWidget(setPathThroughZ);


        horizontalLayout_4->addWidget(radioGroupBox);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        editLimitMin = new QLineEdit(layoutWidget);
        editLimitMin->setObjectName(QStringLiteral("editLimitMin"));

        horizontalLayout_2->addWidget(editLimitMin);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);

        editLimitMax = new QLineEdit(layoutWidget);
        editLimitMax->setObjectName(QStringLiteral("editLimitMax"));

        horizontalLayout->addWidget(editLimitMax);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        passThroughButton = new QPushButton(layoutWidget);
        passThroughButton->setObjectName(QStringLiteral("passThroughButton"));

        horizontalLayout_3->addWidget(passThroughButton);

        checkFilterLimitsNegative = new QCheckBox(layoutWidget);
        checkFilterLimitsNegative->setObjectName(QStringLiteral("checkFilterLimitsNegative"));

        horizontalLayout_3->addWidget(checkFilterLimitsNegative);


        verticalLayout_2->addLayout(horizontalLayout_3);


        horizontalLayout_4->addLayout(verticalLayout_2);

        QT_Show_PCDClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QT_Show_PCDClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 853, 26));
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
        statisticalOutlierRemovalButton->setText(QApplication::translate("QT_Show_PCDClass", "\347\273\237\350\256\241\346\273\244\346\263\242", Q_NULLPTR));
        radioGroupBox->setTitle(QApplication::translate("QT_Show_PCDClass", "\350\275\264\345\220\221", Q_NULLPTR));
        setPathThroughX->setText(QApplication::translate("QT_Show_PCDClass", "X", Q_NULLPTR));
        setPathThroughY->setText(QApplication::translate("QT_Show_PCDClass", "Y", Q_NULLPTR));
        setPathThroughZ->setText(QApplication::translate("QT_Show_PCDClass", "Z", Q_NULLPTR));
        label_2->setText(QApplication::translate("QT_Show_PCDClass", "\350\256\276\347\275\256\344\270\213\351\231\220", Q_NULLPTR));
        label_3->setText(QApplication::translate("QT_Show_PCDClass", "\350\256\276\347\275\256\344\270\212\351\231\220", Q_NULLPTR));
        passThroughButton->setText(QApplication::translate("QT_Show_PCDClass", "\347\233\264\351\200\232\346\273\244\346\263\242", Q_NULLPTR));
        checkFilterLimitsNegative->setText(QApplication::translate("QT_Show_PCDClass", "\350\277\207\346\273\244/\344\277\235\347\225\231", Q_NULLPTR));
        menu->setTitle(QApplication::translate("QT_Show_PCDClass", "\346\226\207\344\273\266", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QT_Show_PCDClass: public Ui_QT_Show_PCDClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT_SHOW_PCD_H
