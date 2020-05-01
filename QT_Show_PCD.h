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
#include <pcl/segmentation/region_growing.h>//区域增长点云分割算法
#include <QMessageBox>//QT消息盒子
#include <QProcess>//QT进程

#include <librealsense2/rs.hpp>
#include <algorithm>            // std::min, std::max



class QT_Show_PCD : public QMainWindow
{
	Q_OBJECT

public:
	QT_Show_PCD(QWidget *parent = Q_NULLPTR);
private:
	Ui::QT_Show_PCDClass ui;

	//创建公共对象
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud;//用于可视化的点云
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloudA;//用于可视化的点云A
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloudB;//用于可视化的点云B
	pcl::PCDWriter writer;//写出点云
	boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer;//可视化
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_save_ptr;//用于保存点云
	pcl::NormalEstimation<pcl::PointXYZ, pcl::Normal> ne;//正态估计
	pcl::PointCloud<pcl::Normal>::Ptr cloud_normals;//法线显示
	pcl::SACSegmentationFromNormals<pcl::PointXYZ, pcl::Normal> seg;//点云分割对象
	pcl::ModelCoefficients::Ptr coefficients_plane;//平面分割得到的平面系数
	pcl::PointIndices::Ptr inliers_plane;//平面分割得到的平面内联
	pcl::ExtractIndices<pcl::PointXYZ> extract;//萃取指数
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_plane;//平面点云
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_without_plane;//去除平面得到的点云
	pcl::ModelCoefficients::Ptr coefficients_cylinder;//平面分割得到的柱面系数
	pcl::PointIndices::Ptr inliers_cylinder;//平面分割得到的柱面内联
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_cylinder;//柱面点云
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_without_cylinder;//去除平面得到的点云


	//===========================================================================================
	// Declare pointcloud object, for calculating pointclouds and texture mappings
	// 声明pointcloud对象，用于计算pointclouds和纹理映射
	rs2::pointcloud pc;
	// We want the points object to be persistent so we can display the last cloud when a frame drops、
	// 我们希望points对象是持久的，以便在帧下降时显示最后一个云
	rs2::points points;

	// Declare RealSense pipeline, encapsulating the actual device and sensors
	// 声明RealSense管道，封装实际设备和传感器
	rs2::pipeline pipe;

	//===========================================================================================
	
	//初始化组件
	void initialVtkWidget();
protected:
	std::string passThoughAxis;
	//默认保留范围内点
	bool setPassThoughNagative;
	//直通滤波下限
	QString limitMin;//接收值
	float limit_min;//转换运算值
	//直通滤波上限
	QString limitMax;//接收值
	float limit_max;//转换运算值
	//下采样体素长度
	QString leafLength;//接收值
	float leaf_length;//转换运算值
	 //下采样体素宽度
	QString leafWidth;//接收值
	float leaf_width;//转换运算值
	 //下采样体素高度
	QString leafHeight;//接收值
	float leaf_height;//转换运算值
	//统计滤波临近点数
	QString nearPointNum;//接收值
	float near_point_num;//转换运算值
	 //统计滤波离群点阈值
	QString filterThreshold;//接收值
	float filter_threshold;//转换运算值
	int numberBeforeFilter;//输出点云数量所需
	int numberAfterFilter;
	std::string numberBeforeFilterStr;
	std::string numberAfterFilterStr;
	QString qstr;
	QString saveFileName;//保存点云所需
	std::string saveFileNameStr;
	bool coordinateSystemFlag;//坐标系添加/移除(true/false)标志
	QString normalLevel;//法线生成间隔
	int normal_level;
	QString normalScale;//法线生成长度
	float normal_scale;
	QString kSearch;//法线生成临近点数量
	int k_search;//计算法线时kd树算法搜索邻域点范围
	QString QCoordinateSystemScale;//坐标系大小
	float coordinateSystemScale;
	QString QCoordinateSystemX;//坐标系原点X轴位置
	float coordinateSystemX;
	QString QCoordinateSystemY;//坐标系原点Y轴位置
	float coordinateSystemY;
	QString QCoordinateSystemZ;//坐标系原点Z轴位置
	float coordinateSystemZ;
	QString QCoordinateSystemViewPort;//坐标系视点
	int coordinateSystemViewPort;
	QString QNormalDistanceWeight;//平面分割中法线距离权重
	double normalDistanceWeight;
	QString QMaxIterations;//平面分割最大迭代次数
	int maxIterations;
	QString QDistanceThreshold;//距离阈值
	double distanceThreshold;
	QString QMinRadius;//柱面分割最小半径
	double minRadius;
	QString QMaxRadius;//柱面分割最大半径
	double maxRadius;
	//RGB彩色信息调节
	QString RPercent;//红色信息比率
	double rPercent;
	QString GPercent;//蓝色信息比率
	double gPercent;
	QString BPercent;//绿色信息比率
	double bPercent;

	//声明槽函数
private slots:
	void onOpen();//打开文件	
	void onVelx();//下采样函数声明
	//直通滤波函数声明	
	void setAxisX();//设置滤波轴向X	
	void setAxisY();//设置滤波轴向Y	
	void setAxisZ();//设置滤波轴向Z	
	void setFilterNegative();//设置反向	
	void onPassThrough();//滤波实现	
	void onStatisticalOutlierRemoval();//统计滤波函数声明	
	void onSave();//保存PCD格式点云声明	
	void onAddCoordinateSystem();//添加坐标系
	void onNormal();//当前点云计算法线并显示
	void onRemoveNormals();//移除法线
	void showOriginalPointCloud();//显示分割前点云
	void getPlane();//分割得到平面并显示
	void removePlane();//分割得到平面并显示
	void getCylinder();//分割得到柱面并显示
	void removeCylinder();//移除柱面并显示
	void loadPointCloudAfterPlane();//载入平面分割后点云
	void addNewPointCloud();//加入新点云
	void realSenceShowCloud();//显示realsence SR300采集点云
	void morphologicalFilter();//形态学滤波提取地面
	void getPointCloudOneFrame();//获取单帧彩色点云
};
