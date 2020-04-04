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
#include <pcl/visualization/pcl_visualizer.h>//可视化
#include <pcl/filters/voxel_grid.h>//体素格滤波器VoxelGrid
#include <pcl/filters/passthrough.h>//直通滤波器 PassThrough
#include <pcl/filters/statistical_outlier_removal.h>//统计滤波器 
#include <pcl/filters/extract_indices.h>//提取指数
#include <pcl/features/normal_3d.h>//特征相关库
#include <pcl/ModelCoefficients.h>//模型系数库
#include <pcl/sample_consensus/method_types.h>//样本一致性/方法类型
#include <pcl/sample_consensus/model_types.h>//样本一致性/模型类型
#include <pcl/segmentation/sac_segmentation.h>//sac_分割
#include <QMessageBox>//QT消息盒子


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

	//声明槽函数
	private slots:
	void onOpen();
	//下采样函数声明
	void onVelx();
	//直通滤波函数声明
	void onPassThrough();
	//统计滤波函数声明
	void onStatisticalOutlierRemoval();
	//分割程序声明
	void cylinder_segmentation();
};
