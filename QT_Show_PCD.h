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
#include <pcl/visualization/pcl_visualizer.h>//���ӻ�
#include <pcl/filters/voxel_grid.h>//���ظ��˲���VoxelGrid
#include <pcl/filters/passthrough.h>//ֱͨ�˲��� PassThrough
#include <pcl/filters/statistical_outlier_removal.h>//ͳ���˲��� 
#include <pcl/filters/extract_indices.h>//��ȡָ��
#include <pcl/features/normal_3d.h>//������ؿ�
#include <pcl/ModelCoefficients.h>//ģ��ϵ����
#include <pcl/sample_consensus/method_types.h>//����һ����/��������
#include <pcl/sample_consensus/model_types.h>//����һ����/ģ������
#include <pcl/segmentation/sac_segmentation.h>//sac_�ָ�
#include <QMessageBox>//QT��Ϣ����


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

	//�����ۺ���
	private slots:
	void onOpen();
	//�²�����������
	void onVelx();
	//ֱͨ�˲���������
	void onPassThrough();
	//ͳ���˲���������
	void onStatisticalOutlierRemoval();
	//�ָ��������
	void cylinder_segmentation();
};
