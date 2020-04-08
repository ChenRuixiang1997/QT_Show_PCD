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
#include <QtWidgets/QTabWidget>
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
    QFrame *line_4;
    QPushButton *saveAsPCD;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_12;
    QPushButton *statisticalOutlierRemovalButton;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_9;
    QLineEdit *nearPointNum;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_10;
    QLineEdit *filterThreshold;
    QPushButton *voxelGridButton_2;
    QGroupBox *groupBox;
    QWidget *layoutWidget1;
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
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_4;
    QGroupBox *radioGroupBox;
    QWidget *layoutWidget3;
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
    QWidget *layoutWidget4;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_4;
    QLineEdit *pointNumBefore;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLineEdit *pointNumAfter;
    QFrame *line_2;
    QFrame *line_3;
    QFrame *line_5;
    QLabel *label_11;
    QWidget *tab_2;
    QWidget *layoutWidget5;
    QVBoxLayout *verticalLayout_12;
    QVBoxLayout *verticalLayout_10;
    QVBoxLayout *verticalLayout_9;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_12;
    QLineEdit *normalLevel;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_13;
    QLineEdit *normalScale;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_14;
    QLineEdit *kSearch;
    QPushButton *onNormal;
    QPushButton *removeNormals;
    QFrame *line_6;
    QVBoxLayout *verticalLayout_11;
    QPushButton *onAddCoordinateSystem;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_16;
    QLineEdit *coordinateSystemScale;
    QHBoxLayout *horizontalLayout_18;
    QLabel *label_15;
    QLineEdit *coordinateSystemX;
    QHBoxLayout *horizontalLayout_19;
    QLabel *label_17;
    QLineEdit *coordinateSystemY;
    QHBoxLayout *horizontalLayout_20;
    QLabel *label_18;
    QLineEdit *coordinateSystemZ;
    QHBoxLayout *horizontalLayout_21;
    QLabel *label_19;
    QLineEdit *coordinateSystemViewPort;
    QWidget *tab_3;
    QGroupBox *groupBox_2;
    QWidget *layoutWidget6;
    QVBoxLayout *verticalLayout_13;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_20;
    QLineEdit *normalDistanceWeight;
    QHBoxLayout *horizontalLayout_22;
    QLabel *label_21;
    QLineEdit *distanceThreshold;
    QHBoxLayout *horizontalLayout_23;
    QLabel *label_22;
    QLineEdit *maxIterations;
    QWidget *layoutWidget7;
    QVBoxLayout *verticalLayout_14;
    QPushButton *showOriginalPointCloud;
    QPushButton *getPlane;
    QPushButton *removePlane;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QT_Show_PCDClass)
    {
        if (QT_Show_PCDClass->objectName().isEmpty())
            QT_Show_PCDClass->setObjectName(QStringLiteral("QT_Show_PCDClass"));
        QT_Show_PCDClass->resize(866, 607);
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
        qvtkWidget->setGeometry(QRect(10, 10, 551, 511));
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(560, 0, 20, 531));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(582, 10, 68, 16));
        line_4 = new QFrame(centralWidget);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setGeometry(QRect(0, 520, 571, 20));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        saveAsPCD = new QPushButton(centralWidget);
        saveAsPCD->setObjectName(QStringLiteral("saveAsPCD"));
        saveAsPCD->setGeometry(QRect(750, 10, 111, 21));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(570, 30, 281, 501));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        layoutWidget = new QWidget(tab);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 390, 261, 57));
        horizontalLayout_12 = new QHBoxLayout(layoutWidget);
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        horizontalLayout_12->setContentsMargins(0, 0, 0, 0);
        statisticalOutlierRemovalButton = new QPushButton(layoutWidget);
        statisticalOutlierRemovalButton->setObjectName(QStringLiteral("statisticalOutlierRemovalButton"));

        horizontalLayout_12->addWidget(statisticalOutlierRemovalButton);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_10->addWidget(label_9);

        nearPointNum = new QLineEdit(layoutWidget);
        nearPointNum->setObjectName(QStringLiteral("nearPointNum"));

        horizontalLayout_10->addWidget(nearPointNum);


        verticalLayout_6->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label_10 = new QLabel(layoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_11->addWidget(label_10);

        filterThreshold = new QLineEdit(layoutWidget);
        filterThreshold->setObjectName(QStringLiteral("filterThreshold"));

        horizontalLayout_11->addWidget(filterThreshold);


        verticalLayout_6->addLayout(horizontalLayout_11);


        horizontalLayout_12->addLayout(verticalLayout_6);

        voxelGridButton_2 = new QPushButton(tab);
        voxelGridButton_2->setObjectName(QStringLiteral("voxelGridButton_2"));
        voxelGridButton_2->setGeometry(QRect(10, 240, 41, 111));
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(70, 240, 201, 111));
        layoutWidget1 = new QWidget(groupBox);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 20, 181, 85));
        verticalLayout_5 = new QVBoxLayout(layoutWidget1);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_6 = new QLabel(layoutWidget1);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_7->addWidget(label_6);

        leafLength = new QLineEdit(layoutWidget1);
        leafLength->setObjectName(QStringLiteral("leafLength"));

        horizontalLayout_7->addWidget(leafLength);


        verticalLayout_5->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_8 = new QLabel(layoutWidget1);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_8->addWidget(label_8);

        leafWidth = new QLineEdit(layoutWidget1);
        leafWidth->setObjectName(QStringLiteral("leafWidth"));

        horizontalLayout_8->addWidget(leafWidth);


        verticalLayout_5->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_7 = new QLabel(layoutWidget1);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_9->addWidget(label_7);

        leafHeight = new QLineEdit(layoutWidget1);
        leafHeight->setObjectName(QStringLiteral("leafHeight"));

        horizontalLayout_9->addWidget(leafHeight);


        verticalLayout_5->addLayout(horizontalLayout_9);

        layoutWidget2 = new QWidget(tab);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 110, 262, 96));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        radioGroupBox = new QGroupBox(layoutWidget2);
        radioGroupBox->setObjectName(QStringLiteral("radioGroupBox"));
        layoutWidget3 = new QWidget(radioGroupBox);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(10, 22, 37, 73));
        verticalLayout_3 = new QVBoxLayout(layoutWidget3);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        setPathThroughX = new QRadioButton(layoutWidget3);
        setPathThroughX->setObjectName(QStringLiteral("setPathThroughX"));

        verticalLayout_3->addWidget(setPathThroughX);

        setPathThroughY = new QRadioButton(layoutWidget3);
        setPathThroughY->setObjectName(QStringLiteral("setPathThroughY"));

        verticalLayout_3->addWidget(setPathThroughY);

        setPathThroughZ = new QRadioButton(layoutWidget3);
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
        label_2 = new QLabel(layoutWidget2);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        editLimitMin = new QLineEdit(layoutWidget2);
        editLimitMin->setObjectName(QStringLiteral("editLimitMin"));

        horizontalLayout_2->addWidget(editLimitMin);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_3 = new QLabel(layoutWidget2);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);

        editLimitMax = new QLineEdit(layoutWidget2);
        editLimitMax->setObjectName(QStringLiteral("editLimitMax"));

        horizontalLayout->addWidget(editLimitMax);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        passThroughButton = new QPushButton(layoutWidget2);
        passThroughButton->setObjectName(QStringLiteral("passThroughButton"));

        horizontalLayout_3->addWidget(passThroughButton);

        checkFilterLimitsNegative = new QCheckBox(layoutWidget2);
        checkFilterLimitsNegative->setObjectName(QStringLiteral("checkFilterLimitsNegative"));

        horizontalLayout_3->addWidget(checkFilterLimitsNegative);


        verticalLayout_2->addLayout(horizontalLayout_3);


        horizontalLayout_4->addLayout(verticalLayout_2);

        layoutWidget4 = new QWidget(tab);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(10, 30, 261, 55));
        verticalLayout_4 = new QVBoxLayout(layoutWidget4);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_4 = new QLabel(layoutWidget4);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_6->addWidget(label_4);

        pointNumBefore = new QLineEdit(layoutWidget4);
        pointNumBefore->setObjectName(QStringLiteral("pointNumBefore"));

        horizontalLayout_6->addWidget(pointNumBefore);


        verticalLayout_4->addLayout(horizontalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_5 = new QLabel(layoutWidget4);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_5->addWidget(label_5);

        pointNumAfter = new QLineEdit(layoutWidget4);
        pointNumAfter->setObjectName(QStringLiteral("pointNumAfter"));

        horizontalLayout_5->addWidget(pointNumAfter);


        verticalLayout_4->addLayout(horizontalLayout_5);

        line_2 = new QFrame(tab);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(0, 90, 291, 20));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(tab);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(0, 210, 291, 20));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_5 = new QFrame(tab);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setGeometry(QRect(-10, 360, 301, 20));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);
        label_11 = new QLabel(tab);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(10, 10, 41, 16));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        layoutWidget5 = new QWidget(tab_2);
        layoutWidget5->setObjectName(QStringLiteral("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(10, 11, 251, 332));
        verticalLayout_12 = new QVBoxLayout(layoutWidget5);
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setContentsMargins(11, 11, 11, 11);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        verticalLayout_12->setContentsMargins(0, 0, 0, 0);
        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        label_12 = new QLabel(layoutWidget5);
        label_12->setObjectName(QStringLiteral("label_12"));

        horizontalLayout_13->addWidget(label_12);

        normalLevel = new QLineEdit(layoutWidget5);
        normalLevel->setObjectName(QStringLiteral("normalLevel"));

        horizontalLayout_13->addWidget(normalLevel);


        verticalLayout_7->addLayout(horizontalLayout_13);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        label_13 = new QLabel(layoutWidget5);
        label_13->setObjectName(QStringLiteral("label_13"));

        horizontalLayout_14->addWidget(label_13);

        normalScale = new QLineEdit(layoutWidget5);
        normalScale->setObjectName(QStringLiteral("normalScale"));

        horizontalLayout_14->addWidget(normalScale);


        verticalLayout_7->addLayout(horizontalLayout_14);


        verticalLayout_9->addLayout(verticalLayout_7);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        label_14 = new QLabel(layoutWidget5);
        label_14->setObjectName(QStringLiteral("label_14"));

        horizontalLayout_15->addWidget(label_14);

        kSearch = new QLineEdit(layoutWidget5);
        kSearch->setObjectName(QStringLiteral("kSearch"));

        horizontalLayout_15->addWidget(kSearch);

        onNormal = new QPushButton(layoutWidget5);
        onNormal->setObjectName(QStringLiteral("onNormal"));

        horizontalLayout_15->addWidget(onNormal);


        verticalLayout_9->addLayout(horizontalLayout_15);


        verticalLayout_10->addLayout(verticalLayout_9);

        removeNormals = new QPushButton(layoutWidget5);
        removeNormals->setObjectName(QStringLiteral("removeNormals"));

        verticalLayout_10->addWidget(removeNormals);


        verticalLayout_12->addLayout(verticalLayout_10);

        line_6 = new QFrame(layoutWidget5);
        line_6->setObjectName(QStringLiteral("line_6"));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);

        verticalLayout_12->addWidget(line_6);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        onAddCoordinateSystem = new QPushButton(layoutWidget5);
        onAddCoordinateSystem->setObjectName(QStringLiteral("onAddCoordinateSystem"));

        verticalLayout_11->addWidget(onAddCoordinateSystem);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setSpacing(6);
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        label_16 = new QLabel(layoutWidget5);
        label_16->setObjectName(QStringLiteral("label_16"));

        horizontalLayout_17->addWidget(label_16);

        coordinateSystemScale = new QLineEdit(layoutWidget5);
        coordinateSystemScale->setObjectName(QStringLiteral("coordinateSystemScale"));

        horizontalLayout_17->addWidget(coordinateSystemScale);


        verticalLayout_8->addLayout(horizontalLayout_17);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setSpacing(6);
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        label_15 = new QLabel(layoutWidget5);
        label_15->setObjectName(QStringLiteral("label_15"));

        horizontalLayout_18->addWidget(label_15);

        coordinateSystemX = new QLineEdit(layoutWidget5);
        coordinateSystemX->setObjectName(QStringLiteral("coordinateSystemX"));

        horizontalLayout_18->addWidget(coordinateSystemX);


        verticalLayout_8->addLayout(horizontalLayout_18);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setSpacing(6);
        horizontalLayout_19->setObjectName(QStringLiteral("horizontalLayout_19"));
        label_17 = new QLabel(layoutWidget5);
        label_17->setObjectName(QStringLiteral("label_17"));

        horizontalLayout_19->addWidget(label_17);

        coordinateSystemY = new QLineEdit(layoutWidget5);
        coordinateSystemY->setObjectName(QStringLiteral("coordinateSystemY"));

        horizontalLayout_19->addWidget(coordinateSystemY);


        verticalLayout_8->addLayout(horizontalLayout_19);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setSpacing(6);
        horizontalLayout_20->setObjectName(QStringLiteral("horizontalLayout_20"));
        label_18 = new QLabel(layoutWidget5);
        label_18->setObjectName(QStringLiteral("label_18"));

        horizontalLayout_20->addWidget(label_18);

        coordinateSystemZ = new QLineEdit(layoutWidget5);
        coordinateSystemZ->setObjectName(QStringLiteral("coordinateSystemZ"));

        horizontalLayout_20->addWidget(coordinateSystemZ);


        verticalLayout_8->addLayout(horizontalLayout_20);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setSpacing(6);
        horizontalLayout_21->setObjectName(QStringLiteral("horizontalLayout_21"));
        label_19 = new QLabel(layoutWidget5);
        label_19->setObjectName(QStringLiteral("label_19"));

        horizontalLayout_21->addWidget(label_19);

        coordinateSystemViewPort = new QLineEdit(layoutWidget5);
        coordinateSystemViewPort->setObjectName(QStringLiteral("coordinateSystemViewPort"));

        horizontalLayout_21->addWidget(coordinateSystemViewPort);


        verticalLayout_8->addLayout(horizontalLayout_21);


        verticalLayout_11->addLayout(verticalLayout_8);


        verticalLayout_12->addLayout(verticalLayout_11);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        groupBox_2 = new QGroupBox(tab_3);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 10, 261, 231));
        layoutWidget6 = new QWidget(groupBox_2);
        layoutWidget6->setObjectName(QStringLiteral("layoutWidget6"));
        layoutWidget6->setGeometry(QRect(10, 20, 241, 91));
        verticalLayout_13 = new QVBoxLayout(layoutWidget6);
        verticalLayout_13->setSpacing(6);
        verticalLayout_13->setContentsMargins(11, 11, 11, 11);
        verticalLayout_13->setObjectName(QStringLiteral("verticalLayout_13"));
        verticalLayout_13->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        label_20 = new QLabel(layoutWidget6);
        label_20->setObjectName(QStringLiteral("label_20"));

        horizontalLayout_16->addWidget(label_20);

        normalDistanceWeight = new QLineEdit(layoutWidget6);
        normalDistanceWeight->setObjectName(QStringLiteral("normalDistanceWeight"));

        horizontalLayout_16->addWidget(normalDistanceWeight);


        verticalLayout_13->addLayout(horizontalLayout_16);

        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setSpacing(6);
        horizontalLayout_22->setObjectName(QStringLiteral("horizontalLayout_22"));
        label_21 = new QLabel(layoutWidget6);
        label_21->setObjectName(QStringLiteral("label_21"));

        horizontalLayout_22->addWidget(label_21);

        distanceThreshold = new QLineEdit(layoutWidget6);
        distanceThreshold->setObjectName(QStringLiteral("distanceThreshold"));

        horizontalLayout_22->addWidget(distanceThreshold);


        verticalLayout_13->addLayout(horizontalLayout_22);

        horizontalLayout_23 = new QHBoxLayout();
        horizontalLayout_23->setSpacing(6);
        horizontalLayout_23->setObjectName(QStringLiteral("horizontalLayout_23"));
        label_22 = new QLabel(layoutWidget6);
        label_22->setObjectName(QStringLiteral("label_22"));

        horizontalLayout_23->addWidget(label_22);

        maxIterations = new QLineEdit(layoutWidget6);
        maxIterations->setObjectName(QStringLiteral("maxIterations"));

        horizontalLayout_23->addWidget(maxIterations);


        verticalLayout_13->addLayout(horizontalLayout_23);

        layoutWidget7 = new QWidget(groupBox_2);
        layoutWidget7->setObjectName(QStringLiteral("layoutWidget7"));
        layoutWidget7->setGeometry(QRect(10, 120, 241, 101));
        verticalLayout_14 = new QVBoxLayout(layoutWidget7);
        verticalLayout_14->setSpacing(6);
        verticalLayout_14->setContentsMargins(11, 11, 11, 11);
        verticalLayout_14->setObjectName(QStringLiteral("verticalLayout_14"));
        verticalLayout_14->setContentsMargins(0, 0, 0, 0);
        showOriginalPointCloud = new QPushButton(layoutWidget7);
        showOriginalPointCloud->setObjectName(QStringLiteral("showOriginalPointCloud"));

        verticalLayout_14->addWidget(showOriginalPointCloud);

        getPlane = new QPushButton(layoutWidget7);
        getPlane->setObjectName(QStringLiteral("getPlane"));

        verticalLayout_14->addWidget(getPlane);

        removePlane = new QPushButton(layoutWidget7);
        removePlane->setObjectName(QStringLiteral("removePlane"));

        verticalLayout_14->addWidget(removePlane);

        tabWidget->addTab(tab_3, QString());
        QT_Show_PCDClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QT_Show_PCDClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 866, 26));
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

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(QT_Show_PCDClass);
    } // setupUi

    void retranslateUi(QMainWindow *QT_Show_PCDClass)
    {
        QT_Show_PCDClass->setWindowTitle(QApplication::translate("QT_Show_PCDClass", "QT_Show_PCD", Q_NULLPTR));
        actionOpen->setText(QApplication::translate("QT_Show_PCDClass", "open", Q_NULLPTR));
        voxelGridButton->setText(QApplication::translate("QT_Show_PCDClass", "\344\270\213\351\207\207\346\240\267", Q_NULLPTR));
        actionTest->setText(QApplication::translate("QT_Show_PCDClass", "test", Q_NULLPTR));
        label->setText(QApplication::translate("QT_Show_PCDClass", "\347\202\271\344\272\221\345\244\204\347\220\206:", Q_NULLPTR));
        saveAsPCD->setText(QApplication::translate("QT_Show_PCDClass", "\344\277\235\345\255\230\344\270\272PCD", Q_NULLPTR));
        statisticalOutlierRemovalButton->setText(QApplication::translate("QT_Show_PCDClass", "\347\273\237\350\256\241\n"
"\346\273\244\346\263\242", Q_NULLPTR));
        label_9->setText(QApplication::translate("QT_Show_PCDClass", "\351\202\273\345\237\237\347\202\271\346\225\260:", Q_NULLPTR));
        label_10->setText(QApplication::translate("QT_Show_PCDClass", "\346\273\244\346\263\242\351\230\210\345\200\274:", Q_NULLPTR));
        voxelGridButton_2->setText(QApplication::translate("QT_Show_PCDClass", "\344\270\213\n"
"\351\207\207\n"
"\346\240\267\n"
"\346\273\244\n"
"\346\263\242", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("QT_Show_PCDClass", "\344\275\223\347\264\240\345\235\227\345\244\247\345\260\217", Q_NULLPTR));
        label_6->setText(QApplication::translate("QT_Show_PCDClass", "\351\225\277\345\272\246:", Q_NULLPTR));
        label_8->setText(QApplication::translate("QT_Show_PCDClass", "\345\256\275\345\272\246:", Q_NULLPTR));
        label_7->setText(QApplication::translate("QT_Show_PCDClass", "\351\253\230\345\272\246:", Q_NULLPTR));
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
        label_11->setText(QApplication::translate("QT_Show_PCDClass", "\344\277\241\346\201\257:", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("QT_Show_PCDClass", "\346\273\244\346\263\242", Q_NULLPTR));
        label_12->setText(QApplication::translate("QT_Show_PCDClass", "\351\234\200\346\230\276\347\244\272\346\263\225\345\220\221\347\232\204\347\202\271\344\272\221\351\227\264\351\232\224:", Q_NULLPTR));
        label_13->setText(QApplication::translate("QT_Show_PCDClass", "\351\234\200\346\230\276\347\244\272\346\263\225\345\220\221\347\232\204\347\202\271\344\272\221\351\225\277\345\272\246:", Q_NULLPTR));
        label_14->setText(QApplication::translate("QT_Show_PCDClass", "\344\270\264\350\277\221\347\202\271\346\225\260\351\207\217:", Q_NULLPTR));
        onNormal->setText(QApplication::translate("QT_Show_PCDClass", "\347\224\237\346\210\220\346\263\225\347\272\277", Q_NULLPTR));
        removeNormals->setText(QApplication::translate("QT_Show_PCDClass", "\351\232\220\350\227\217\346\263\225\347\272\277", Q_NULLPTR));
        onAddCoordinateSystem->setText(QApplication::translate("QT_Show_PCDClass", "\347\224\237\346\210\220/\351\232\220\350\227\217\345\235\220\346\240\207\347\263\273", Q_NULLPTR));
        label_16->setText(QApplication::translate("QT_Show_PCDClass", "\345\235\220\346\240\207\347\263\273\345\244\247\345\260\217:", Q_NULLPTR));
        label_15->setText(QApplication::translate("QT_Show_PCDClass", "\345\235\220\346\240\207\347\263\273X\344\275\215\347\275\256:", Q_NULLPTR));
        label_17->setText(QApplication::translate("QT_Show_PCDClass", "\345\235\220\346\240\207\347\263\273Y\344\275\215\347\275\256:", Q_NULLPTR));
        label_18->setText(QApplication::translate("QT_Show_PCDClass", "\345\235\220\346\240\207\347\263\273Z\344\275\215\347\275\256:", Q_NULLPTR));
        label_19->setText(QApplication::translate("QT_Show_PCDClass", "\345\235\220\346\240\207\347\263\273\350\247\206\347\202\271:", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("QT_Show_PCDClass", "\346\263\225\347\272\277\344\270\216\345\235\220\346\240\207\347\263\273", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("QT_Show_PCDClass", "\345\271\263\351\235\242\345\210\206\345\211\262", Q_NULLPTR));
        label_20->setText(QApplication::translate("QT_Show_PCDClass", "\346\263\225\347\272\277\350\267\235\347\246\273\346\235\203\351\207\215:", Q_NULLPTR));
        label_21->setText(QApplication::translate("QT_Show_PCDClass", "\345\210\206\345\211\262\350\267\235\347\246\273\351\230\210\345\200\274:", Q_NULLPTR));
        label_22->setText(QApplication::translate("QT_Show_PCDClass", "\346\234\200\345\244\247\350\277\255\344\273\243\346\254\241\346\225\260:", Q_NULLPTR));
        showOriginalPointCloud->setText(QApplication::translate("QT_Show_PCDClass", "\346\230\276\347\244\272\345\216\237\347\202\271\344\272\221", Q_NULLPTR));
        getPlane->setText(QApplication::translate("QT_Show_PCDClass", "\345\210\206\345\211\262\345\217\226\345\276\227\345\271\263\351\235\242", Q_NULLPTR));
        removePlane->setText(QApplication::translate("QT_Show_PCDClass", "\345\210\206\345\211\262\345\216\273\351\231\244\345\271\263\351\235\242", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("QT_Show_PCDClass", "\345\210\206\345\211\262", Q_NULLPTR));
        menu->setTitle(QApplication::translate("QT_Show_PCDClass", "\346\226\207\344\273\266", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QT_Show_PCDClass: public Ui_QT_Show_PCDClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT_SHOW_PCD_H
