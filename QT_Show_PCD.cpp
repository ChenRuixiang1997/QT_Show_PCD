#include "QT_Show_PCD.h"

//处理中文乱码（qt窗口标题）
#if _MSC_VER >= 1600  
#pragma execution_character_set("utf-8")  
#endif 

//构造函数
QT_Show_PCD::QT_Show_PCD(QWidget *parent)
	: QMainWindow(parent)
{
	//ui初始化
	ui.setupUi(this);
	this->setWindowTitle("毕业设计-点云数据采集");
	initialVtkWidget();
	//建立键槽连接关系
	//打开文件并可视化
	connect(ui.actionOpen, SIGNAL(triggered()), this, SLOT(onOpen()));
	//添加坐标系
	connect(ui.onAddCoordinateSystem, SIGNAL(clicked()), this, SLOT(onAddCoordinateSystem()));
	//计算法线并显示
	connect(ui.onNormal, SIGNAL(clicked()), this, SLOT(onNormal()));
	//法线移除
	connect(ui.removeNormals, SIGNAL(clicked()), this, SLOT(onRemoveNormals()));
	//下采样
	connect(ui.voxelGridButton_2, SIGNAL(clicked()), this, SLOT(onVelx()));
	//直通滤波设置参数
	connect(ui.setPathThroughX, SIGNAL(clicked()), this, SLOT(setAxisX()));
	connect(ui.setPathThroughY, SIGNAL(clicked()), this, SLOT(setAxisY()));
	connect(ui.setPathThroughZ, SIGNAL(clicked()), this, SLOT(setAxisZ()));
	connect(ui.checkFilterLimitsNegative, SIGNAL(clicked()), this, SLOT(setFilterNegative()));
	//直通滤波实现槽函数
	connect(ui.passThroughButton, SIGNAL(clicked()), this, SLOT(onPassThrough()));
	//统计滤波
	connect(ui.statisticalOutlierRemovalButton, SIGNAL(clicked()), this, SLOT(onStatisticalOutlierRemoval()));
	
	//点云保存
	connect(ui.saveAsPCD, SIGNAL(clicked()), this, SLOT(onSave()));
	//显示分割前点云
	connect(ui.showOriginalPointCloud, SIGNAL(clicked()), this, SLOT(showOriginalPointCloud()));
	connect(ui.showOriginalPointCloud2, SIGNAL(clicked()), this, SLOT(showOriginalPointCloud()));
	//分割得到平面点云并显示
	connect(ui.getPlane, SIGNAL(clicked()), this, SLOT(getPlane()));
	//分割去除平面点云并显示
	connect(ui.removePlane, SIGNAL(clicked()), this, SLOT(removePlane()));
	//分割得到柱面点云并显示
	connect(ui.getCylinder, SIGNAL(clicked()), this, SLOT(getCylinder()));
	//分割去除柱面点云并显示
	connect(ui.removeCylinder, SIGNAL(clicked()), this, SLOT(removeCylinder()));
	//载入平面分割后点云用于柱面分割
	connect(ui.loadPointCloudAfterPlane, SIGNAL(clicked()), this, SLOT(loadPointCloudAfterPlane()));
}

//初始化VtkWidget
void QT_Show_PCD::initialVtkWidget()
{
	//指定输入框输入为double类型数据
	QDoubleValidator *doubleValidator = new QDoubleValidator(-999999999, 999999999, 9, this);
	doubleValidator->setNotation(QDoubleValidator::StandardNotation);
	ui.editLimitMin->setValidator(doubleValidator);
	ui.editLimitMax->setValidator(doubleValidator);
	ui.leafLength->setValidator(doubleValidator);
	ui.leafWidth->setValidator(doubleValidator);
	ui.leafHeight->setValidator(doubleValidator);
	ui.filterThreshold->setValidator(doubleValidator);
	ui.normalScale->setValidator(doubleValidator);
	ui.coordinateSystemX->setValidator(doubleValidator);
	ui.coordinateSystemY->setValidator(doubleValidator);
	ui.coordinateSystemZ->setValidator(doubleValidator);
	ui.normalDistanceWeight->setValidator(doubleValidator);
	ui.distanceThreshold->setValidator(doubleValidator);
	ui.minRadius->setValidator(doubleValidator);
	ui.maxRadius->setValidator(doubleValidator);

	ui.nearPointNum->setValidator(new QRegExpValidator(QRegExp("[0-9]+$")));//指定输入框输入整数
	ui.normalLevel->setValidator(new QRegExpValidator(QRegExp("[0-9]+$")));
	ui.kSearch->setValidator(new QRegExpValidator(QRegExp("[0-9]+$")));
	ui.coordinateSystemViewPort->setValidator(new QRegExpValidator(QRegExp("[0-9]+$")));
	ui.coordinateSystemScale->setValidator(new QRegExpValidator(QRegExp("[0-9]+$")));
	ui.maxIterations->setValidator(new QRegExpValidator(QRegExp("[0-9]+$")));
	//初始化点云
	cloud.reset(new pcl::PointCloud<pcl::PointXYZ>);//初始点云
	cloud_normals.reset(new pcl::PointCloud<pcl::Normal>);//法线
	coefficients_plane.reset(new pcl::ModelCoefficients);//平面系数
	inliers_plane.reset(new pcl::PointIndices);//平面内联
	cloud_plane.reset(new pcl::PointCloud<pcl::PointXYZ>());//平面点云
	cloud_without_plane.reset(new pcl::PointCloud<pcl::PointXYZ>());//去除平面的点云
	coefficients_cylinder.reset(new pcl::ModelCoefficients);//柱面系数
	inliers_cylinder.reset(new pcl::PointIndices);//柱面内联
	cloud_cylinder.reset(new pcl::PointCloud<pcl::PointXYZ>());//柱面点云
	cloud_without_cylinder.reset(new pcl::PointCloud<pcl::PointXYZ>());//去除平面的点云
	//设置默认滤波方式为保留
	setPassThoughNagative = false;
	//默认未打开坐标系
	coordinateSystemFlag = true;
	//坐标系初始化参数
	coordinateSystemScale = 1.0;
	coordinateSystemX = 0.0;
	coordinateSystemY = 0.0;
	coordinateSystemZ = 0.0;
	coordinateSystemViewPort = 0;
	//初始化直通滤波上限
	limitMin.clear();
	limit_min = 0.0;
	//初始化直通滤波下限
	limitMax.clear();
	limit_max = 0.0;
	//初始化法线生成时参数
	normal_level = 10;
	normal_scale = 0.05;//法线长度0.05米
	k_search = 50;//指定附近邻域点数量为50
	//平面分割参数初始化
	normalDistanceWeight = 0.1;//法线距离权重
	maxIterations = 100;//最大迭代次数
	distanceThreshold = 0.03;//距离阈值
	//柱面分割半径范围初始化
	minRadius = 0;
	maxRadius = 0.1;
	//初始化可视化窗口
	viewer.reset(new pcl::visualization::PCLVisualizer("viewer", false));
	viewer->addPointCloud(cloud, "cloud");
	ui.qvtkWidget->SetRenderWindow(viewer->getRenderWindow());
	viewer->setupInteractor(ui.qvtkWidget->GetInteractor(), ui.qvtkWidget->GetRenderWindow());
	ui.qvtkWidget->update();
}

//坐标系
void QT_Show_PCD::onAddCoordinateSystem()
{
	QCoordinateSystemScale = ui.coordinateSystemScale->text();
	QCoordinateSystemX = ui.coordinateSystemX->text();
	QCoordinateSystemY = ui.coordinateSystemY->text();
	QCoordinateSystemZ = ui.coordinateSystemZ->text();
	QCoordinateSystemViewPort = ui.coordinateSystemViewPort->text();
	//参数传入
	if (!QCoordinateSystemScale.isEmpty()) {
		coordinateSystemScale = QCoordinateSystemScale.toFloat();
	}
	if (!QCoordinateSystemX.isEmpty()) {
		coordinateSystemX = QCoordinateSystemX.toFloat();
	}
	if (!QCoordinateSystemY.isEmpty()) {
		coordinateSystemY = QCoordinateSystemY.toFloat();
	}
	if (!QCoordinateSystemZ.isEmpty()) {
		coordinateSystemZ = QCoordinateSystemZ.toFloat();
	}
	if (!QCoordinateSystemViewPort.isEmpty()) {
		coordinateSystemViewPort = QCoordinateSystemViewPort.toInt();
	}
	if (coordinateSystemFlag)
	{
		viewer->addCoordinateSystem(coordinateSystemScale, coordinateSystemX, coordinateSystemY, coordinateSystemZ, "global" , coordinateSystemViewPort);
		coordinateSystemFlag = !coordinateSystemFlag;
	}
	else
	{
		viewer->removeCoordinateSystem( "global");
		coordinateSystemFlag = !coordinateSystemFlag;
	}
	viewer->resetCamera();
	ui.qvtkWidget->update();
	
}
//打开并显示点云文件
void QT_Show_PCD::onOpen()
{
	QString fileName = QFileDialog::getOpenFileName(this, "Open PointCloud", ".", "Open PCD files(*.pcd)");
	if (!fileName.isEmpty())
	{
		std::string file_name = fileName.toStdString();

		//sensor_msgs::PointCloud2 cloud2;

		pcl::PCLPointCloud2 cloud2;

		//pcl::PointCloud<Eigen::MatrixXf> cloud2;

		Eigen::Vector4f origin;
		Eigen::Quaternionf orientation;
		int pcd_version;
		int data_type;
		unsigned int data_idx;
		int offset = 0;
		//创建PCD读取对象
		pcl::PCDReader rd;
		//读取PCD头信息
		rd.readHeader(file_name, cloud2, origin, orientation, pcd_version, data_type, data_idx);
		if (data_type == 0 || data_type == 1)

		{
			pcl::io::loadPCDFile(fileName.toStdString(), *cloud);
		}

		else if (data_type == 2 )
		{
			pcl::PCDReader reader;
			reader.read<pcl::PointXYZ>(fileName.toStdString(), *cloud);
		}
		viewer->updatePointCloud(cloud, "cloud");
		viewer->resetCamera();
		ui.qvtkWidget->update();
	}
}

//点云保存
void QT_Show_PCD::onSave()
{
	if (cloud_save_ptr == NULL)
	{
		QMessageBox::warning(this, "错误:", "输出数据为空!");
		return;
	}
	QString saveFileName = QFileDialog::getSaveFileName(this, "保存点云", ".", "点云文件(*.pcd)");
	if (!saveFileName.isEmpty())
	{
		saveFileNameStr = saveFileName.toStdString();
		writer.write(saveFileNameStr, *cloud_save_ptr, false);
		QMessageBox::information(this, "信息:", "保存成功!");
		return;
	}

}

//设置直通滤波轴向
void QT_Show_PCD::setAxisX() 
{
	passThoughAxis = "x";
}
void QT_Show_PCD::setAxisY() 
{
	passThoughAxis = "y";
}
void QT_Show_PCD::setAxisZ() 
{
	passThoughAxis = "z";
}
//设置保留点还是过滤点
void QT_Show_PCD::setFilterNegative()
{
	setPassThoughNagative = !setPassThoughNagative;
}
//直通滤波
void QT_Show_PCD::onPassThrough()
{
	// 定义　点云对象　指针
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud2_ptr(new pcl::PointCloud<pcl::PointXYZ>);//滤波前点云对象指针
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud2_filtered_ptr(new pcl::PointCloud<pcl::PointXYZ>);//滤波后点云对象指针
	cloud2_ptr = cloud;
	if (cloud2_ptr->width * cloud2_ptr->height == 0) {
		QMessageBox::warning(this, "错误:", "当前点云大小为零!");
		return;
	}
	//设定滤波坐标轴
	if (passThoughAxis.empty())
	{
		QMessageBox::warning(this, "错误:", "请设置过滤坐标轴!");
		return;
	}
	//获取滤波范围
	limitMin = ui.editLimitMin->text();
	limitMax = ui.editLimitMax->text();
	if (limitMin.isEmpty()||limitMax.isEmpty()) 
	{
		QMessageBox::warning(this, "错误:", "请设置直通滤波范围!");
		return;
	}
	else
	{
		limit_min = limitMin.toFloat();
		limit_max = limitMax.toFloat();
		if (limit_min>= limit_max)
		{
			QMessageBox::warning(this, "错误:", "请设置正确的直通滤波范围!");
			return;
		}
	}
	
	// 创建滤波器对象
	pcl::PassThrough<pcl::PointXYZ> pass;
	pass.setInputCloud(cloud2_ptr);//设置输入点云
	pass.setFilterFieldName(passThoughAxis);// 定义轴
	pass.setFilterLimits(limit_min, limit_max);//　范围
	pass.setFilterLimitsNegative(setPassThoughNagative);//标志为false时保留范围内的点
	pass.filter(*cloud2_filtered_ptr); //输出点云
	if (cloud2_filtered_ptr == NULL)
	{
		QMessageBox::warning(this, "错误:", "输出数据为空!");
		return;
	}
	// 输出滤波后的点云信息
	numberBeforeFilter = cloud2_ptr->width * cloud2_ptr->height;
	numberAfterFilter = cloud2_filtered_ptr->width * cloud2_filtered_ptr->height;
	if (numberAfterFilter != 0)
	{
		numberBeforeFilterStr = std::to_string(numberBeforeFilter);
		numberAfterFilterStr = std::to_string(numberAfterFilter);
		qstr = QString::fromStdString(numberBeforeFilterStr);
		ui.pointNumBefore->setText(qstr);
		qstr = QString::fromStdString(numberAfterFilterStr);
		ui.pointNumAfter->setText(qstr);
	}
	//----------------------------------直通滤波完成-----------------------------------
	cloud = cloud2_filtered_ptr;
	//刷新显示
	viewer->updatePointCloud(cloud, "cloud");
	viewer->resetCamera();
	ui.qvtkWidget->update();
	QMessageBox::information(this, "信息:", "滤波成功!");
	cloud_save_ptr = cloud2_filtered_ptr;
}
	
//点云下采样
void QT_Show_PCD::onVelx()
{
	// 定义　点云对象　指针
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud2_ptr(new pcl::PointCloud<pcl::PointXYZ>);//滤波前点云对象指针
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud2_filtered_ptr(new pcl::PointCloud<pcl::PointXYZ>);//滤波后点云对象指针
	cloud2_ptr = cloud;
	if (cloud2_ptr->width * cloud2_ptr->height == 0) {
		QMessageBox::warning(this, "错误:", "当前点云大小为零!");
		return;
	}
	//设置滤波体素大小
	leafLength = ui.leafLength->text();
	leafWidth = ui.leafWidth->text();
	leafHeight = ui.leafHeight->text();
	if (leafLength.isEmpty() || leafWidth.isEmpty() || leafHeight.isEmpty())
	{
		QMessageBox::warning(this, "错误:", "请设置过滤体素大小!");
		return;
	}
	leaf_length = leafLength.toFloat();
	leaf_width = leafWidth.toFloat();
	leaf_height = leafHeight.toFloat();
	// 创建滤波器对象
	pcl::VoxelGrid<pcl::PointXYZ> vg;
	// pcl::ApproximateVoxelGrid<pcl::PointXYZ> avg;
	vg.setInputCloud(cloud2_ptr);//设置输入点云
	vg.setLeafSize(leaf_length, leaf_width, leaf_height);//　体素块大小　１cm
	vg.filter(*cloud2_filtered_ptr);//点云输出到指针*cloud2_filtered_ptr
	if (cloud2_filtered_ptr == NULL)
	{
		QMessageBox::warning(this, "错误:", "输出数据为空!");
		return;
	}
	// 输出滤波后的点云信息
	numberBeforeFilter = cloud2_ptr->width * cloud2_ptr->height;
	numberAfterFilter = cloud2_filtered_ptr->width * cloud2_filtered_ptr->height;
	if (numberAfterFilter != 0)
	{
		numberBeforeFilterStr = std::to_string(numberBeforeFilter);
		numberAfterFilterStr = std::to_string(numberAfterFilter);
		qstr = QString::fromStdString(numberBeforeFilterStr);
		ui.pointNumBefore->setText(qstr);
		qstr = QString::fromStdString(numberAfterFilterStr);
		ui.pointNumAfter->setText(qstr);
	}
	//----------------------------------下采样完成-----------------------------------
	cloud = cloud2_filtered_ptr;
	//刷新显示
	viewer->updatePointCloud(cloud, "cloud");
	viewer->resetCamera();
	ui.qvtkWidget->update();
	QMessageBox::information(this, "信息:", "滤波成功!");
	cloud_save_ptr = cloud2_filtered_ptr;
}

//统计滤波器
void QT_Show_PCD::onStatisticalOutlierRemoval()
{
	// 定义　点云对象　指针
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud2_ptr(new pcl::PointCloud<pcl::PointXYZ>);//滤波前点云对象指针
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud2_filtered_ptr(new pcl::PointCloud<pcl::PointXYZ>);//滤波后点云对象指针
	cloud2_ptr = cloud;
	if (cloud2_ptr->width * cloud2_ptr->height == 0) {
		QMessageBox::warning(this, "错误:", "当前点云大小为零!");
		return;
	}
	//设置滤波邻域点数和阈值
	nearPointNum = ui.nearPointNum->text();
	filterThreshold = ui.filterThreshold->text();
	if (nearPointNum.isEmpty() || filterThreshold.isEmpty())
	{
		QMessageBox::warning(this, "错误:", "请设置滤波邻域点数和阈值!");
		return;
	}
	near_point_num = nearPointNum.toInt();
	filter_threshold = filterThreshold.toFloat();
	
	// 创建滤波器，对每个点分析的临近点的个数设置为50 ，并将标准差的倍数设置为1  这意味着如果一
	// 个点的距离超出了平均距离一个标准差以上，则该点被标记为离群点，并将它移除，存储起来
	pcl::StatisticalOutlierRemoval<pcl::PointXYZ> sta;//创建滤波器对象
	sta.setInputCloud(cloud2_ptr);		    //设置待滤波的点云
	sta.setMeanK(near_point_num);	     			    //设置在进行统计时考虑查询点临近点数
	sta.setStddevMulThresh(filter_threshold);	   		    //设置判断是否为离群点的阀值
	sta.filter(*cloud2_filtered_ptr); 		    //存储内点
	if (cloud2_filtered_ptr == NULL)
	{
		QMessageBox::warning(this, "错误:", "输出数据为空!");
		return;
	}
	// 输出滤波后的点云信息
	numberBeforeFilter = cloud2_ptr->width * cloud2_ptr->height;
	numberAfterFilter = cloud2_filtered_ptr->width * cloud2_filtered_ptr->height;
	if (numberAfterFilter != 0)
	{
		numberBeforeFilterStr = std::to_string(numberBeforeFilter);
		numberAfterFilterStr = std::to_string(numberAfterFilter);
		qstr = QString::fromStdString(numberBeforeFilterStr);
		ui.pointNumBefore->setText(qstr);
		qstr = QString::fromStdString(numberAfterFilterStr);
		ui.pointNumAfter->setText(qstr);
	}
	//----------------------------------统计滤波完成-----------------------------------
	cloud = cloud2_filtered_ptr;
	//刷新显示
	viewer->updatePointCloud(cloud, "cloud");
	viewer->resetCamera();
	ui.qvtkWidget->update();
	QMessageBox::information(this, "信息:", "滤波成功!");
	cloud_save_ptr = cloud2_filtered_ptr;
}

//法线显示
void QT_Show_PCD::onNormal()
{
	normalLevel = ui.normalLevel->text();
	normalScale = ui.normalScale->text();
	kSearch = ui.kSearch->text();
	if (!normalLevel.isEmpty())
	{
		normal_level = normalLevel.toInt();
	}
	if (!normalScale.isEmpty())
	{
		normal_scale = normalScale.toFloat();
	}
	if (!kSearch.isEmpty())
	{
		k_search = kSearch.toInt();
	}
	//pcl::PointCloud<pcl::Normal>::Ptr cloud_normals(new pcl::PointCloud<pcl::Normal>);//法线计算
	pcl::search::KdTree<pcl::PointXYZ>::Ptr tree(new pcl::search::KdTree<pcl::PointXYZ>());//kd树
	// 计算点法线
	ne.setSearchMethod(tree);//设置近邻搜索算法 
	ne.setInputCloud(cloud);//设置输入点云
	ne.setKSearch(k_search);//指定临近点数量
	ne.compute(*cloud_normals);
	//pcl::concatenateFields(*cloud, *cloud_normals, *cloud_with_normals);
	
	//刷新显示
	viewer->addPointCloudNormals<pcl::PointXYZ, pcl::Normal>(cloud, cloud_normals, normal_level, normal_scale, "normals");
	//viewer->removePointCloud("normals");
	viewer->resetCamera();
	ui.qvtkWidget->update();
}

//法线隐藏
void QT_Show_PCD::onRemoveNormals()
{
	viewer->removePointCloud("normals");
	viewer->resetCamera();
	ui.qvtkWidget->update();
}

//显示分割前点云
void QT_Show_PCD::showOriginalPointCloud()
{
	if (cloud->width * cloud->height == 0 ) {
		QMessageBox::warning(this, "警告!", "点云大小为零！");
		return;
	}
	viewer->removeAllPointClouds();
	viewer->addPointCloud(cloud, "cloud");
	viewer->resetCamera();
	ui.qvtkWidget->update();
	cloud_save_ptr = cloud;
}

//分割得到平面并显示
void QT_Show_PCD::getPlane()
{
	if (!QNormalDistanceWeight.isEmpty())
	{
		normalDistanceWeight = QNormalDistanceWeight.toDouble();
	}
	if (!QMaxIterations.isEmpty())
	{
		maxIterations = QMaxIterations.toInt();
	}
	if (!QDistanceThreshold.isEmpty())
	{
		distanceThreshold = QDistanceThreshold.toDouble();
	}
	if (cloud_normals->points.empty())
	{
		QMessageBox::warning(this, "警告!", "请先生成法线!");
		return;
	}
	// 为平面模型创建分割对象并设置所有参数
	seg.setOptimizeCoefficients(true);//设置优化系数
	seg.setModelType(pcl::SACMODEL_NORMAL_PLANE);//设置分割模型类别:平面分割
	seg.setNormalDistanceWeight(normalDistanceWeight);//设置法线距离权重
	seg.setMethodType(pcl::SAC_RANSAC);//设置用哪个随机参数估计方法
	seg.setMaxIterations(maxIterations);//设置最大迭代次数
	seg.setDistanceThreshold(distanceThreshold);//设置距离阈值
	seg.setInputCloud(cloud);//设置输入点云
	seg.setInputNormals(cloud_normals);//设置输入法线
									   // 分割得到平面内联和系数
	seg.segment(*inliers_plane, *coefficients_plane);//前者 平面内联 ， 后者 平面系数

													 // 将直通滤波后点云作为输入提取平面内联线
	extract.setInputCloud(cloud);//设置输入点云
	extract.setIndices(inliers_plane);//设置索引
	extract.setNegative(false);//设置是否应应用点过滤的常规条件或倒转条件。输入参数negative:false = 正常的过滤器行为（默认），true = 反向的行为。

							   // 将平面内联写入磁盘
							   //pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_plane(new pcl::PointCloud<pcl::PointXYZ>());
	extract.filter(*cloud_plane);

	//显示点云
	if (cloud_plane->width * cloud_plane->height == 0) {
		QMessageBox::warning(this, "警告!", "生成点云大小为零！");
		return;
	}
	viewer->removeAllPointClouds();
	viewer->addPointCloud(cloud_plane, "cloud_plane");
	viewer->resetCamera();
	ui.qvtkWidget->update();
	cloud_save_ptr = cloud_plane;
}

//分割去除平面并显示
void QT_Show_PCD::removePlane()
{
	if (!QNormalDistanceWeight.isEmpty())
	{
		normalDistanceWeight = QNormalDistanceWeight.toDouble();
	}
	if (!QMaxIterations.isEmpty())
	{
		maxIterations = QMaxIterations.toInt();
	}
	if (!QDistanceThreshold.isEmpty())
	{
		distanceThreshold = QDistanceThreshold.toDouble();
	}
	if (cloud_normals->points.empty())
	{
		QMessageBox::warning(this, "警告!", "请先生成法线!");
		return;
	}
	// 为平面模型创建分割对象并设置所有参数
	seg.setOptimizeCoefficients(true);//设置优化系数
	seg.setModelType(pcl::SACMODEL_NORMAL_PLANE);//设置分割模型类别:平面分割
	seg.setNormalDistanceWeight(normalDistanceWeight);//设置法线距离权重
	seg.setMethodType(pcl::SAC_RANSAC);//设置用哪个随机参数估计方法
	seg.setMaxIterations(maxIterations);//设置最大迭代次数
	seg.setDistanceThreshold(distanceThreshold);//设置距离阈值
	seg.setInputCloud(cloud);//设置输入点云
	seg.setInputNormals(cloud_normals);//设置输入法线
	 // 分割得到平面内联和系数
	seg.segment(*inliers_plane, *coefficients_plane);//前者 平面内联 ， 后者 平面系数

	 // 将直通滤波后点云作为输入提取平面内联线
	extract.setInputCloud(cloud);//设置输入点云
	extract.setIndices(inliers_plane);//设置索引
	extract.setNegative(true);//设置是否应应用点过滤的常规条件或倒转条件。输入参数negative:false = 正常的过滤器行为（默认），true = 反向的行为。

	// 将平面内联写入磁盘
	//pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_without_plane(new pcl::PointCloud<pcl::PointXYZ>());
	extract.filter(*cloud_without_plane);

	//显示点云
	if (cloud_without_plane->width * cloud_without_plane->height == 0) {
		QMessageBox::warning(this, "警告!", "生成点云大小为零！");
		return;
	}
	viewer->removeAllPointClouds();
	viewer->addPointCloud(cloud_without_plane, "cloud_without_plane");
	viewer->resetCamera();
	ui.qvtkWidget->update();
	cloud_save_ptr = cloud_without_plane;
}

//分割得到柱面
void QT_Show_PCD::getCylinder()
{
	if (!QNormalDistanceWeight.isEmpty())
	{
		normalDistanceWeight = QNormalDistanceWeight.toDouble();
	}
	if (!QMaxIterations.isEmpty())
	{
		maxIterations = QMaxIterations.toInt();
	}
	if (!QDistanceThreshold.isEmpty())
	{
		distanceThreshold = QDistanceThreshold.toDouble();
	}
	if (!QMinRadius.isEmpty())
	{
		minRadius = QMinRadius.toDouble();
	}
	if (!QMaxRadius.isEmpty())
	{
		maxRadius = QMaxRadius.toDouble();
	}
	if (cloud_normals->points.empty()) 
	{
		QMessageBox::warning(this,"警告!","请先生成法线!");
		return;
	}
	// 创建圆柱体分割的分割对象并设置所有参数
	seg.setOptimizeCoefficients(true);
	seg.setModelType(pcl::SACMODEL_CYLINDER);
	seg.setMethodType(pcl::SAC_RANSAC);
	seg.setNormalDistanceWeight(0.1);
	seg.setMaxIterations(10000);
	seg.setDistanceThreshold(0.05);
	seg.setRadiusLimits(minRadius, maxRadius);//设置半径限制
	seg.setInputCloud(cloud);
	seg.setInputNormals(cloud_normals);
	// 获得圆柱内腔和系数
	seg.segment(*inliers_cylinder, *coefficients_cylinder);
	// 将柱面内联写入磁盘
	extract.setInputCloud(cloud);
	extract.setIndices(inliers_cylinder);
	extract.setNegative(false);
	extract.filter(*cloud_cylinder);

	//显示点云
	if (cloud_cylinder->width * cloud_cylinder->height == 0) {
		QMessageBox::warning(this, "警告!", "生成点云大小为零！");
		return;
	}
	viewer->removeAllPointClouds();
	viewer->addPointCloud(cloud_cylinder, "cloud_cylinder");
	viewer->resetCamera();
	ui.qvtkWidget->update();
	cloud_save_ptr = cloud_cylinder;
}

//分割移除柱面
void QT_Show_PCD::removeCylinder()
{
	if (!QNormalDistanceWeight.isEmpty())
	{
		normalDistanceWeight = QNormalDistanceWeight.toDouble();
	}
	if (!QMaxIterations.isEmpty())
	{
		maxIterations = QMaxIterations.toInt();
	}
	if (!QDistanceThreshold.isEmpty())
	{
		distanceThreshold = QDistanceThreshold.toDouble();
	}
	if (!QMinRadius.isEmpty())
	{
		minRadius = QMinRadius.toDouble();
	}
	if (!QMaxRadius.isEmpty())
	{
		maxRadius = QMaxRadius.toDouble();
	}
	if (cloud_normals->points.empty())
	{
		QMessageBox::warning(this, "警告!", "请先生成法线!");
		return;
	}
	// 创建圆柱体分割的分割对象并设置所有参数
	seg.setOptimizeCoefficients(true);
	seg.setModelType(pcl::SACMODEL_CYLINDER);
	seg.setMethodType(pcl::SAC_RANSAC);
	seg.setNormalDistanceWeight(0.1);
	seg.setMaxIterations(10000);
	seg.setDistanceThreshold(0.05);
	seg.setRadiusLimits(minRadius, maxRadius);//设置半径限制
	seg.setInputCloud(cloud);
	seg.setInputNormals(cloud_normals);
	// 获得圆柱内腔和系数
	seg.segment(*inliers_cylinder, *coefficients_cylinder);
	// 将柱面内联写入磁盘
	extract.setInputCloud(cloud);
	extract.setIndices(inliers_cylinder);
	extract.setNegative(true);
	extract.filter(*cloud_without_cylinder);

	//显示点云
	if (cloud_without_cylinder->width * cloud_without_cylinder->height == 0) {
		QMessageBox::warning(this, "警告!", "生成点云大小为零！");
		return;
	}
	viewer->removeAllPointClouds();
	viewer->addPointCloud(cloud_without_cylinder, "cloud_cylinder");
	viewer->resetCamera();
	ui.qvtkWidget->update();
	cloud_save_ptr = cloud_without_cylinder;
}

//载入平面分割后点云用于柱面分割
void QT_Show_PCD::loadPointCloudAfterPlane() 
{
	if (cloud_without_plane->width * cloud_without_plane->height == 0) 
	{
		QMessageBox::warning(this,"警告!","未找到去除平面后点云!");
		return;
	}
	cloud = cloud_without_plane;
	QMessageBox::information(this, "提示!", "去除平面后点云载入成功!");
}