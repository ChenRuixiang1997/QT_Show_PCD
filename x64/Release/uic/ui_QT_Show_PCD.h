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
    QFrame *line_4;
    QFrame *line_2;
    QFrame *line_3;
    QFrame *line_5;
    QFrame *line_6;
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
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_4;
    QLineEdit *pointNumBefore;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLineEdit *pointNumAfter;
    QPushButton *saveAsPCD;
    QFrame *line_7;
    QGroupBox *groupBox;
    QWidget *widget;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_6;
    QLineEdit *leafLength;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_8;
    QLineEdit *leafWidth;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_7;
    QLineEdit *leafHeight;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QT_Show_PCDClass)
    {
        if (QT_Show_PCDClass->objectName().isEmpty())
            QT_Show_PCDClass->setObjectName(QStringLiteral("QT_Show_PCDClass"));
        QT_Show_PCDClass->resize(864, 588);
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
        line->setGeometry(QRect(560, 0, 20, 521));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(582, 10, 68, 16));
        voxelGridButton_2 = new QPushButton(centralWidget);
        voxelGridButton_2->setObjectName(QStringLiteral("voxelGridButton_2"));
        voxelGridButton_2->setGeometry(QRect(590, 240, 41, 101));
        statisticalOutlierRemovalButton = new QPushButton(centralWidget);
        statisticalOutlierRemovalButton->setObjectName(QStringLiteral("statisticalOutlierRemovalButton"));
        statisticalOutlierRemovalButton->setGeometry(QRect(580, 370, 93, 28));
        line_4 = new QFrame(centralWidget);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setGeometry(QRect(0, 510, 571, 20));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(850, 0, 20, 521));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(centralWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(570, 220, 291, 20));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_5 = new QFrame(centralWidget);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setGeometry(QRect(570, 100, 291, 20));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);
        line_6 = new QFrame(centralWidget);
        line_6->setObjectName(QStringLiteral("line_6"));
        line_6->setGeometry(QRect(570, 510, 291, 20));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(581, 120, 262, 96));
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

        layoutWidget2 = new QWidget(centralWidget);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(582, 42, 261, 55));
        verticalLayout_4 = new QVBoxLayout(layoutWidget2);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_4 = new QLabel(layoutWidget2);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_6->addWidget(label_4);

        pointNumBefore = new QLineEdit(layoutWidget2);
        pointNumBefore->setObjectName(QStringLiteral("pointNumBefore"));

        horizontalLayout_6->addWidget(pointNumBefore);


        verticalLayout_4->addLayout(horizontalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_5 = new QLabel(layoutWidget2);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_5->addWidget(label_5);

        pointNumAfter = new QLineEdit(layoutWidget2);
        pointNumAfter->setObjectName(QStringLiteral("pointNumAfter"));

        horizontalLayout_5->addWidget(pointNumAfter);


        verticalLayout_4->addLayout(horizontalLayout_5);

        saveAsPCD = new QPushButton(centralWidget);
        saveAsPCD->setObjectName(QStringLiteral("saveAsPCD"));
        saveAsPCD->setGeometry(QRect(690, 10, 151, 21));
        line_7 = new QFrame(centralWidget);
        line_7->setObjectName(QStringLiteral("line_7"));
        line_7->setGeometry(QRect(570, 340, 291, 20));
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(640, 240, 201, 101));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(660, 260, 171, 71));
        verticalLayout_5 = new QVBoxLayout(widget);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_6 = new QLabel(widget);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_7->addWidget(label_6);

        leafLength = new QLineEdit(widget);
        leafLength->setObjectName(QStringLiteral("leafLength"));

        horizontalLayout_7->addWidget(leafLength);


        verticalLayout_5->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_8 = new QLabel(widget);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_8->addWidget(label_8);

        leafWidth = new QLineEdit(widget);
        leafWidth->setObjectName(QStringLiteral("leafWidth"));

        horizontalLayout_8->addWidget(leafWidth);


        verticalLayout_5->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_7 = new QLabel(widget);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_9->addWidget(label_7);

        leafHeight = new QLineEdit(widget);
        leafHeight->setObjectName(QStringLiteral("leafHeight"));

        horizontalLayout_9->addWidget(leafHeight);


        verticalLayout_5->addLayout(horizontalLayout_9);

        QT_Show_PCDClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QT_Show_PCDClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 864, 26));
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
        voxelGridButton_2->setText(QApplication::translate("QT_Show_PCDClass", "\344\270\213\n"
"\351\207\207\n"
"\346\240\267\n"
"\346\273\244\n"
"\346\263\242", Q_NULLPTR));
        statisticalOutlierRemovalButton->setText(QApplication::translate("QT_Show_PCDClass", "\347\273\237\350\256\241\346\273\244\346\263\242", Q_NULLPTR));
        radioGroupBox->setTitle(QApplication::translate("QT_Show_PCDClass", "\350\275\264\345\220\221", Q_NULLPTR));
        setPathThroughX->setText(QApplication::translate("QT_Show_PCDClass", "X", Q_NULLPTR));
        setPathThroughY->setText(QApplication::translate("QT_Show_PCDClass", "Y", Q_NULLPTR));
        setPathThroughZ->setText(QApplication::translate("QT_Show_PCDClass", "Z", Q_NULLPTR));
        label_2->setText(QApplication::translate("QT_Show_PCDClass", "\350\256\276\347\275\256\344\270\213\351\231\220", Q_NULLPTR));
        label_3->setText(QApplication::translate("QT_Show_PCDClass", "\350\256\276\347\275\256\344\270\212\351\231\220", Q_NULLPTR));
        passThroughButton->setText(QApplication::translate("QT_Show_PCDClass", "\347\233\264\351\200\232\346\273\244\346\263\242", Q_NULLPTR));
        checkFilterLimitsNegative->setText(QApplication::translate("QT_Show_PCDClass", "\350\277\207\346\273\244/\344\277\235\347\225\231", Q_NULLPTR));
        label_4->setText(QApplication::translate("QT_Show_PCDClass", "\345\244\204\347\220\206\345\211\215\346\225\260\346\215\256\351\207\217:", Q_NULLPTR));
        label_5->setText(QApplication::translate("QT_Show_PCDClass", "\345\244\204\347\220\206\345\220\216\346\225\260\346\215\256\351\207\217:", Q_NULLPTR));
        saveAsPCD->setText(QApplication::translate("QT_Show_PCDClass", "\344\277\235\345\255\230\344\270\272PCD", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("QT_Show_PCDClass", "\344\275\223\347\264\240\345\235\227\345\244\247\345\260\217", Q_NULLPTR));
        label_6->setText(QApplication::translate("QT_Show_PCDClass", "\351\225\277\345\272\246:", Q_NULLPTR));
        label_8->setText(QApplication::translate("QT_Show_PCDClass", "\345\256\275\345\272\246:", Q_NULLPTR));
        label_7->setText(QApplication::translate("QT_Show_PCDClass", "\351\253\230\345\272\246:", Q_NULLPTR));
        menu->setTitle(QApplication::translate("QT_Show_PCDClass", "\346\226\207\344\273\266", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QT_Show_PCDClass: public Ui_QT_Show_PCDClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT_SHOW_PCD_H
