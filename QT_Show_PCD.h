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
#include <pcl/io/ply_io.h>
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
#include <pcl/segmentation/region_growing.h>//�����������Ʒָ��㷨
#include <QMessageBox>//QT��Ϣ����
#include <QProcess>//QT����

#include <librealsense2/rs.hpp>
#include <algorithm>            // std::min, std::max



class QT_Show_PCD : public QMainWindow
{
	Q_OBJECT

public:
	QT_Show_PCD(QWidget *parent = Q_NULLPTR);
private:
	Ui::QT_Show_PCDClass ui;

	//������������
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud;//���ڿ��ӻ��ĵ���
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloudA;//���ڿ��ӻ��ĵ���A
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloudB;//���ڿ��ӻ��ĵ���B
	pcl::PCDWriter writer;//д������
	boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer;//���ӻ�
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_save_ptr;//���ڱ������
	pcl::NormalEstimation<pcl::PointXYZ, pcl::Normal> ne;//��̬����
	pcl::PointCloud<pcl::Normal>::Ptr cloud_normals;//������ʾ
	pcl::SACSegmentationFromNormals<pcl::PointXYZ, pcl::Normal> seg;//���Ʒָ����
	pcl::ModelCoefficients::Ptr coefficients_plane;//ƽ��ָ�õ���ƽ��ϵ��
	pcl::PointIndices::Ptr inliers_plane;//ƽ��ָ�õ���ƽ������
	pcl::ExtractIndices<pcl::PointXYZ> extract;//��ȡָ��
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_plane;//ƽ�����
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_without_plane;//ȥ��ƽ��õ��ĵ���
	pcl::ModelCoefficients::Ptr coefficients_cylinder;//ƽ��ָ�õ�������ϵ��
	pcl::PointIndices::Ptr inliers_cylinder;//ƽ��ָ�õ�����������
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_cylinder;//�������
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_without_cylinder;//ȥ��ƽ��õ��ĵ���


	//===========================================================================================
	// Declare pointcloud object, for calculating pointclouds and texture mappings
	// ����pointcloud�������ڼ���pointclouds������ӳ��
	rs2::pointcloud pc;
	// We want the points object to be persistent so we can display the last cloud when a frame drops��
	// ����ϣ��points�����ǳ־õģ��Ա���֡�½�ʱ��ʾ���һ����
	rs2::points points;

	// Declare RealSense pipeline, encapsulating the actual device and sensors
	// ����RealSense�ܵ�����װʵ���豸�ʹ�����
	rs2::pipeline pipe;

	//===========================================================================================
	
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
	//ͳ���˲��ٽ�����
	QString nearPointNum;//����ֵ
	float near_point_num;//ת������ֵ
	 //ͳ���˲���Ⱥ����ֵ
	QString filterThreshold;//����ֵ
	float filter_threshold;//ת������ֵ
	int numberBeforeFilter;//���������������
	int numberAfterFilter;
	std::string numberBeforeFilterStr;
	std::string numberAfterFilterStr;
	QString qstr;
	QString saveFileName;//�����������
	std::string saveFileNameStr;
	bool coordinateSystemFlag;//����ϵ���/�Ƴ�(true/false)��־
	QString normalLevel;//�������ɼ��
	int normal_level;
	QString normalScale;//�������ɳ���
	float normal_scale;
	QString kSearch;//���������ٽ�������
	int k_search;//���㷨��ʱkd���㷨��������㷶Χ
	QString QCoordinateSystemScale;//����ϵ��С
	float coordinateSystemScale;
	QString QCoordinateSystemX;//����ϵԭ��X��λ��
	float coordinateSystemX;
	QString QCoordinateSystemY;//����ϵԭ��Y��λ��
	float coordinateSystemY;
	QString QCoordinateSystemZ;//����ϵԭ��Z��λ��
	float coordinateSystemZ;
	QString QCoordinateSystemViewPort;//����ϵ�ӵ�
	int coordinateSystemViewPort;
	QString QNormalDistanceWeight;//ƽ��ָ��з��߾���Ȩ��
	double normalDistanceWeight;
	QString QMaxIterations;//ƽ��ָ�����������
	int maxIterations;
	QString QDistanceThreshold;//������ֵ
	double distanceThreshold;
	QString QMinRadius;//����ָ���С�뾶
	double minRadius;
	QString QMaxRadius;//����ָ����뾶
	double maxRadius;
	//RGB��ɫ��Ϣ����
	QString RPercent;//��ɫ��Ϣ����
	double rPercent;
	QString GPercent;//��ɫ��Ϣ����
	double gPercent;
	QString BPercent;//��ɫ��Ϣ����
	double bPercent;

	//�����ۺ���
private slots:
	void onOpen();//���ļ�	
	void onVelx();//�²�����������
	//ֱͨ�˲���������	
	void setAxisX();//�����˲�����X	
	void setAxisY();//�����˲�����Y	
	void setAxisZ();//�����˲�����Z	
	void setFilterNegative();//���÷���	
	void onPassThrough();//�˲�ʵ��	
	void onStatisticalOutlierRemoval();//ͳ���˲���������	
	void onSave();//����PCD��ʽ��������	
	void onAddCoordinateSystem();//�������ϵ
	void onNormal();//��ǰ���Ƽ��㷨�߲���ʾ
	void onRemoveNormals();//�Ƴ�����
	void showOriginalPointCloud();//��ʾ�ָ�ǰ����
	void getPlane();//�ָ�õ�ƽ�沢��ʾ
	void removePlane();//�ָ�õ�ƽ�沢��ʾ
	void getCylinder();//�ָ�õ����沢��ʾ
	void removeCylinder();//�Ƴ����沢��ʾ
	void loadPointCloudAfterPlane();//����ƽ��ָ�����
	void addNewPointCloud();//�����µ���
	void realSenceShowCloud();//��ʾrealsence SR300�ɼ�����
	void morphologicalFilter();//��̬ѧ�˲���ȡ����
	void getPointCloudOneFrame();//��ȡ��֡��ɫ����
};
