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
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud;//���ڿ��ӻ��ĵ���					  
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
	//�������ϵ
	void onAddCoordinateSystem();
	//��ǰ���Ƽ��㷨�߲���ʾ
	void onNormal();
	//�Ƴ�����
	void onRemoveNormals();
	//��ʾ�ָ�ǰ����
	void showOriginalPointCloud();
	//�ָ�õ�ƽ�沢��ʾ
	void getPlane();
	//�ָ�õ�ƽ�沢��ʾ
	void removePlane();
	//�ָ�õ����沢��ʾ
	void getCylinder();
	//�Ƴ����沢��ʾ
	void removeCylinder();
};
