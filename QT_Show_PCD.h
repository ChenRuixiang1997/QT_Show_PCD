#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QT_Show_PCD.h"


#ifndef INITIAL_OPENGL
#define INITIAL_OPENGL
#include <vtkAutoInit.h>
VTK_MODULE_INIT(vtkRenderingOpenGL)
VTK_MODULE_INIT(vtkInteractionStyle)
#endif

#include <QFileDialog>

#include <QtWidgets/QWidget>
#include <vtkRenderWindow.h>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/visualization/pcl_visualizer.h>


class QT_Show_PCD : public QMainWindow
{
	Q_OBJECT
		
public:
	QT_Show_PCD(QWidget *parent = Q_NULLPTR);

private:
	Ui::QT_Show_PCDClass ui;

	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud;
	boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer;
	void initialVtkWidget();

private slots:
	void onOpen();
};
