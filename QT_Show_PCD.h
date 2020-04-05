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

	//������������
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud;//���ڿ��ӻ�					  
	pcl::PCDWriter writer;//д������
	boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer;
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_save_ptr;//���ڱ������
	//��ʼ�����
	void initialVtkWidget();
protected:
	std::string passThoughAxis;
	//Ĭ�ϱ�����Χ�ڵ�
	bool setPassThoughNagative;
	//ֱͨ�˲�����
	QString limitMin;//����ֵ
	float limit_min;//ת������ֵ
	//ֱͨ�˲�����
	QString limitMax;//����ֵ
	float limit_max;//ת������ֵ
	//�²������س���
	QString leafLength;//����ֵ
	float leaf_length;//ת������ֵ
	 //�²������ؿ��
	QString leafWidth;//����ֵ
	float leaf_width;//ת������ֵ
	 //�²������ظ߶�
	QString leafHeight;//����ֵ
	float leaf_height;//ת������ֵ
	//���������������
	int numberBeforeFilter;
	int numberAfterFilter;
	std::string numberBeforeFilterStr;
	std::string numberAfterFilterStr;
	QString qstr;
	//�����������
	QString saveFileName;
	std::string saveFileNameStr;
	//�����ۺ���
private slots:
	//���ļ�
	void onOpen();
	//�²�����������
	void onVelx();
	//ֱͨ�˲���������
	//�����˲�����X
	void setAxisX();
	//�����˲�����Y
	void setAxisY();
	//�����˲�����Z
	void setAxisZ();
	//���÷���
	void setFilterNegative();
	//�˲�ʵ��
	void onPassThrough();
	//ͳ���˲���������
	void onStatisticalOutlierRemoval();
	//�ָ��������
	void cylinder_segmentation();
	//����PCD��ʽ��������
	void onSave();
};
