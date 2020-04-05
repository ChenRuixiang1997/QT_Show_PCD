#include "QT_Show_PCD.h"

//处理中文乱码（qt窗口标题）
#if _MSC_VER >= 1600  
#pragma execution_character_set("utf-8")  
#endif 


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
	//connect(ui.statisticalOutlierRemovalButton, SIGNAL(clicked()), this, SLOT(cylinder_segmentation()));
	//点云保存
	connect(ui.saveAsPCD, SIGNAL(clicked()), this, SLOT(onSave()));
}

//初始化VtkWidget
void QT_Show_PCD::initialVtkWidget()
{
	//设定上下限输入类型
	QDoubleValidator *doubleValidator = new QDoubleValidator(-9999, 9999, 6, this);
	doubleValidator->setNotation(QDoubleValidator::StandardNotation);
	ui.editLimitMin->setValidator(doubleValidator);
	ui.editLimitMax->setValidator(doubleValidator);
	ui.leafLength->setValidator(doubleValidator);
	ui.leafWidth->setValidator(doubleValidator);
	ui.leafHeight->setValidator(doubleValidator);
	ui.filterThreshold->setValidator(doubleValidator);
	
	ui.nearPointNum->setValidator(new QRegExpValidator(QRegExp("[0-9]+$")));
	//初始化点云
	cloud.reset(new pcl::PointCloud<pcl::PointXYZ>);
	//设置默认滤波方式为保留
	setPassThoughNagative = false;
	//初始化直通滤波上限
	limitMin.clear();
	limit_min = 0.0;
	//初始化直通滤波下限
	limitMax.clear();
	limit_max = 0.0;
	//初始化可视化窗口
	viewer.reset(new pcl::visualization::PCLVisualizer("viewer", false));
	viewer->addPointCloud(cloud, "cloud");
	ui.qvtkWidget->SetRenderWindow(viewer->getRenderWindow());
	viewer->setupInteractor(ui.qvtkWidget->GetInteractor(), ui.qvtkWidget->GetRenderWindow());
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
		if (data_type == 0)

		{
			pcl::io::loadPCDFile(fileName.toStdString(), *cloud);
		}

		else if (data_type == 2)
		{
			pcl::PCDReader reader;
			reader.read<pcl::PointXYZ>(fileName.toStdString(), *cloud);
		}
		viewer->updatePointCloud(cloud, "cloud");
		viewer->resetCamera();
		ui.qvtkWidget->update();
	}
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
	if (leafLength.isEmpty()||leafWidth.isEmpty()||leafHeight.isEmpty()) 
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
	cloud_save_ptr = cloud2_filtered_ptr;
	//刷新显示
	viewer->updatePointCloud(cloud, "cloud");
	viewer->resetCamera();
	ui.qvtkWidget->update();
	QMessageBox::information(this, "信息:", "滤波成功!");
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
	cloud_save_ptr = cloud2_filtered_ptr;
	//刷新显示
	viewer->updatePointCloud(cloud, "cloud");
	viewer->resetCamera();
	ui.qvtkWidget->update();
	QMessageBox::information(this, "信息:", "滤波成功!");
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
	cloud_save_ptr = cloud2_filtered_ptr;
	//刷新显示
	viewer->updatePointCloud(cloud, "cloud");
	viewer->resetCamera();
	ui.qvtkWidget->update();
	QMessageBox::information(this, "信息:", "滤波成功!");
}

//点云分割
void QT_Show_PCD::cylinder_segmentation() 
{
	// 所有需要的对象
	pcl::PCDReader reader;//读取点云
	pcl::PassThrough<pcl::PointXYZ> pass;//直通滤波
	pcl::NormalEstimation<pcl::PointXYZ, pcl::Normal> ne;//正态估计
	pcl::SACSegmentationFromNormals<pcl::PointXYZ, pcl::Normal> seg;//点云分割
	pcl::PCDWriter writer;//点云写出
	pcl::ExtractIndices<pcl::PointXYZ> extract;//萃取指数
	pcl::ExtractIndices<pcl::Normal> extract_normals;//萃取指数
	pcl::search::KdTree<pcl::PointXYZ>::Ptr tree(new pcl::search::KdTree<pcl::PointXYZ>());//kd树

	// 数据集
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);//原始点云
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered(new pcl::PointCloud<pcl::PointXYZ>);//点云过滤
	pcl::PointCloud<pcl::Normal>::Ptr cloud_normals(new pcl::PointCloud<pcl::Normal>);
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered2(new pcl::PointCloud<pcl::PointXYZ>);//点云过滤
	pcl::PointCloud<pcl::Normal>::Ptr cloud_normals2(new pcl::PointCloud<pcl::Normal>);
	pcl::ModelCoefficients::Ptr coefficients_plane(new pcl::ModelCoefficients), coefficients_cylinder(new pcl::ModelCoefficients);
	pcl::PointIndices::Ptr inliers_plane(new pcl::PointIndices), inliers_cylinder(new pcl::PointIndices);

	QString fileName = QFileDialog::getOpenFileName(this, "Choose The PointCloud TO VoxelGridFilter", ".", "Open PCD files(*.pcd)");

	if (!fileName.isEmpty())
	{
		std::string file_name = fileName.toStdString();
		// 读取点云数据
		reader.read(file_name, *cloud);
		
		//-----cloud->points.size()此时点云数据量
		// << "PointCloud has: " << cloud->points.size() << " data points." << std::endl;

		// 直通滤波去除杂散nan点(z轴，去除1.5米外的点)
		pass.setInputCloud(cloud);
		pass.setFilterFieldName("z");
		pass.setFilterLimits(0, 1.5);
		pass.filter(*cloud_filtered);

		//-----cloud_filtered->points.size()直通滤波后点云数据量
		//std::cerr << "PointCloud after filtering has: " << cloud_filtered->points.size() << " data points." << std::endl;

		// 估计点法线
		ne.setSearchMethod(tree);
		ne.setInputCloud(cloud_filtered);
		ne.setKSearch(50);
		ne.compute(*cloud_normals);

		// 为平面模型创建分割对象并设置所有参数
		seg.setOptimizeCoefficients(true);
		seg.setModelType(pcl::SACMODEL_NORMAL_PLANE);
		seg.setNormalDistanceWeight(0.1);
		seg.setMethodType(pcl::SAC_RANSAC);
		seg.setMaxIterations(100);
		seg.setDistanceThreshold(0.03);
		seg.setInputCloud(cloud_filtered);
		seg.setInputNormals(cloud_normals);
		// 得到平面内线和系数
		seg.segment(*inliers_plane, *coefficients_plane);
		std::cerr << "Plane coefficients: " << *coefficients_plane << std::endl;

		// 将直通滤波后点云作为输入提取平面内联线
		extract.setInputCloud(cloud_filtered);
		extract.setIndices(inliers_plane);//设置索引
		extract.setNegative(false);//设置是否应应用点过滤的常规条件或倒转条件。输入参数negative:false = 正常的过滤器行为（默认），true = 反向的行为。

		// 将平面内联写入磁盘
		pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_plane(new pcl::PointCloud<pcl::PointXYZ>());
		extract.filter(*cloud_plane);
		
		//提示一些信息
		//std::cerr << "PointCloud representing the planar component: " << cloud_plane->points.size() << " data points." << std::endl;_plane
		file_name.insert(file_name.find("."), "_plane");
		writer.write(file_name, *cloud_plane, false);

		// 移除平面内联，取出其余部分
		extract.setNegative(true);
		extract.filter(*cloud_filtered2);
		extract_normals.setNegative(true);
		extract_normals.setInputCloud(cloud_normals);
		extract_normals.setIndices(inliers_plane);
		extract_normals.filter(*cloud_normals2);

		// 创建圆柱体分割的分割对象并设置所有参数
		seg.setOptimizeCoefficients(true);
		seg.setModelType(pcl::SACMODEL_CYLINDER);
		seg.setMethodType(pcl::SAC_RANSAC);
		seg.setNormalDistanceWeight(0.1);
		seg.setMaxIterations(10000);
		seg.setDistanceThreshold(0.05);
		seg.setRadiusLimits(0, 0.1);
		seg.setInputCloud(cloud_filtered2);
		seg.setInputNormals(cloud_normals2);

		// 获得圆柱内腔和系数
		seg.segment(*inliers_cylinder, *coefficients_cylinder);
		//std::cerr << "Cylinder coefficients: " << *coefficients_cylinder << std::endl;

		// 将柱面内联写入磁盘
		extract.setInputCloud(cloud_filtered2);
		extract.setIndices(inliers_cylinder);
		extract.setNegative(false);
		pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_cylinder(new pcl::PointCloud<pcl::PointXYZ>());
		extract.filter(*cloud_cylinder);
		if (cloud_cylinder->points.empty())
		{
			//std::cerr << "Can't find the cylindrical component." << std::endl;
			QMessageBox::warning(this, "错误:", "找不到圆柱形组件");
		}	
		else
		{
			file_name.erase(file_name.find(".") - 6);
			file_name.append("_cylinder.pcd");
			writer.write(file_name, *cloud_cylinder, false);
		}
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
