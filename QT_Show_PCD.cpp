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
	connect(ui.actionOpen, SIGNAL(triggered()), this, SLOT(onOpen()));
	connect(ui.voxelGridButton_2, SIGNAL(clicked()), this, SLOT(onVelx()));
	connect(ui.passThroughButton, SIGNAL(clicked()), this, SLOT(onPassThrough()));
	connect(ui.statisticalOutlierRemovalButton, SIGNAL(clicked()), this, SLOT(onStatisticalOutlierRemoval()));
}

//初始化VtkWidget
void QT_Show_PCD::initialVtkWidget()
{
	//初始化点云
	cloud.reset(new pcl::PointCloud<pcl::PointXYZ>);
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
	QString fileName = QFileDialog::getOpenFileName(this, "Choose The PointCloud TO VoxelGridFilter", ".", "Open PCD files(*.pcd)");
	if (!fileName.isEmpty())
	{
		//打开文件，获取文件名
		std::string file_name = fileName.toStdString();

		// 定义　点云对象　指针
		pcl::PCLPointCloud2::Ptr cloud2_ptr(new pcl::PCLPointCloud2());//滤波前点云对象指针
		pcl::PCLPointCloud2::Ptr cloud2_filtered_ptr(new pcl::PCLPointCloud2());//滤波后点云对象指针

		//pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered_ptr(new pcl::PointCloud<pcl::PointXYZ>);//不知道干啥的

		// 读取点云文件　填充点云对象
		pcl::PCDReader reader;
		reader.read(file_name, *cloud2_ptr);
		if (cloud2_ptr == NULL) {
			QMessageBox::warning(this, "error", "open file failure!");
			return;
		}

		// 创建滤波器对象　Create the filtering object
		pcl::VoxelGrid<pcl::PCLPointCloud2> vg;
		// pcl::ApproximateVoxelGrid<pcl::PointXYZ> avg;
		vg.setInputCloud(cloud2_ptr);//设置输入点云
		vg.setLeafSize(0.01f, 0.01f, 0.01f);//　体素块大小　１cm
		vg.filter(*cloud2_filtered_ptr);//点云输出到指针*cloud2_filtered_ptr
		// 写入内存
		pcl::PCDWriter writer;
		file_name.insert(file_name.find("."), "_VoxelGridFilter");
		
		writer.write(file_name, *cloud2_filtered_ptr,
			Eigen::Vector4f::Zero(), Eigen::Quaternionf::Identity(), false);
		//----------------------------------点云下采样完成-----------------------------------

		//创建新的点云对象用于显示
		pcl::PCLPointCloud2 cloud2;
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
		//参数说明:data_type数据类型（0 = ASCII，1 =二进制，2 =二进制压缩）
		if (data_type == 0)
		{
			pcl::io::loadPCDFile(file_name , *cloud);
		}
		else if (data_type == 2)
		{
			pcl::PCDReader reader1;
			reader1.read<pcl::PointXYZ>(file_name , *cloud);
		}
		//刷新显示
		viewer->updatePointCloud(cloud, "cloud");
		viewer->resetCamera();
		ui.qvtkWidget->update();
		// 输出滤波后的点云信息
		int numberBeforeFilter = cloud2_ptr->width * cloud2_ptr->height;
		int numberAfterFilter = cloud2_filtered_ptr->width * cloud2_filtered_ptr->height;
		if (numberAfterFilter != 0) 
		{
			std::string numberAfterFilterStr = std::to_string(numberAfterFilter);
			std::string numberBeforeFilterStr = std::to_string(numberBeforeFilter);
			std::string information = "下采样滤波前数量:"+ numberBeforeFilterStr +".\n下采样滤波后数量:" + numberAfterFilterStr+".";
			QString qstr = QString::fromStdString(information);
			QMessageBox::information(this, "滤波前后数量:", qstr);
			return;
		}
	}
}

//直通滤波
void QT_Show_PCD::onPassThrough()
{
	QString fileName = QFileDialog::getOpenFileName(this, "Choose The PointCloud TO VoxelGridFilter", ".", "Open PCD files(*.pcd)");
	if (!fileName.isEmpty())
	{
		//打开文件，获取文件名
		std::string file_name = fileName.toStdString();

		// 定义　点云对象　指针
		pcl::PointCloud<pcl::PointXYZ>::Ptr cloud2_ptr(new pcl::PointCloud<pcl::PointXYZ>);//滤波前点云对象指针
		pcl::PointCloud<pcl::PointXYZ>::Ptr cloud2_filtered_ptr(new pcl::PointCloud<pcl::PointXYZ>);//滤波后点云对象指针

		// 读取点云文件　填充点云对象
		pcl::PCDReader reader;
		reader.read(file_name, *cloud2_ptr);
		if (cloud2_ptr == NULL) {
			QMessageBox::warning(this, "error", "open file failure!");
			return;
		}

		// 创建滤波器对象　Create the filtering object
		pcl::PassThrough<pcl::PointXYZ> pass;
		pass.setInputCloud(cloud2_ptr);//设置输入点云
		pass.setFilterFieldName("z");// 定义轴
		pass.setFilterLimits(0.0, 0.5);//　范围
		 // pass.setKeepOrganized(true); // 保持 有序点云结构===============
		pass.setFilterLimitsNegative(true);//标志为false时保留范围内的点
		pass.filter(*cloud2_filtered_ptr); //输出点云
		// 写入内存
		pcl::PCDWriter writer;
		file_name.insert(file_name.find("."), "_PassThroughFilter");

		writer.write(file_name, *cloud2_filtered_ptr, false);
		//----------------------------------直通滤波完成-----------------------------------

		//刷新显示
		viewer->updatePointCloud(cloud2_filtered_ptr, "cloud");
		viewer->resetCamera();
		ui.qvtkWidget->update();
		// 输出滤波后的点云信息
		int numberBeforeFilter = cloud2_ptr->width * cloud2_ptr->height;
		int numberAfterFilter = cloud2_filtered_ptr->width * cloud2_filtered_ptr->height;
		if (numberAfterFilter != 0)
		{
			std::string numberAfterFilterStr = std::to_string(numberAfterFilter);
			std::string numberBeforeFilterStr = std::to_string(numberBeforeFilter);
			std::string information = "直通滤波前数量:" + numberBeforeFilterStr + ".\n直通滤波后数量:" + numberAfterFilterStr + ".";
			QString qstr = QString::fromStdString(information);
			QMessageBox::information(this, "滤波前后数量:", qstr);
			return;
		}
	}
}
	
//统计滤波器

void QT_Show_PCD::onStatisticalOutlierRemoval() {
	QString fileName = QFileDialog::getOpenFileName(this, "Choose The PointCloud TO VoxelGridFilter", ".", "Open PCD files(*.pcd)");
	if (!fileName.isEmpty())
	{
		//打开文件，获取文件名
		std::string file_name = fileName.toStdString();

		// 定义　点云对象　指针
		pcl::PointCloud<pcl::PointXYZ>::Ptr cloud2_ptr(new pcl::PointCloud<pcl::PointXYZ>);//滤波前点云对象指针
		pcl::PointCloud<pcl::PointXYZ>::Ptr cloud2_filtered_ptr(new pcl::PointCloud<pcl::PointXYZ>);//滤波后点云对象指针

																									// 读取点云文件　填充点云对象
		pcl::PCDReader reader;
		reader.read(file_name, *cloud2_ptr);
		if (cloud2_ptr == NULL) {
			QMessageBox::warning(this, "error", "open file failure!");
			return;
		}
		
		// 创建滤波器，对每个点分析的临近点的个数设置为50 ，并将标准差的倍数设置为1  这意味着如果一
		// 个点的距离超出了平均距离一个标准差以上，则该点被标记为离群点，并将它移除，存储起来
		pcl::StatisticalOutlierRemoval<pcl::PointXYZ> sta;//创建滤波器对象
		sta.setInputCloud(cloud2_ptr);		    //设置待滤波的点云
		sta.setMeanK(50);	     			    //设置在进行统计时考虑查询点临近点数
		sta.setStddevMulThresh(1.0);	   		    //设置判断是否为离群点的阀值
		sta.filter(*cloud2_filtered_ptr); 		    //存储内点

		pcl::PCDWriter writer;//写出点云
		file_name.insert(file_name.find("."), "_StatisticalOutlierRemoval");

		writer.write(file_name, *cloud2_filtered_ptr, false);
		//----------------------------------统计滤波完成-----------------------------------

		//刷新显示
		viewer->updatePointCloud(cloud2_filtered_ptr, "cloud");
		viewer->resetCamera();
		ui.qvtkWidget->update();
		// 输出滤波后的点云信息
		int numberBeforeFilter = cloud2_ptr->width * cloud2_ptr->height;
		int numberAfterFilter = cloud2_filtered_ptr->width * cloud2_filtered_ptr->height;
		if (numberAfterFilter != 0)
		{
			std::string numberAfterFilterStr = std::to_string(numberAfterFilter);
			std::string numberBeforeFilterStr = std::to_string(numberBeforeFilter);
			std::string information = "统计滤波前数量:" + numberBeforeFilterStr + ".\n统计滤波后数量:" + numberAfterFilterStr + ".";
			QString qstr = QString::fromStdString(information);
			QMessageBox::information(this, "滤波前后数量:", qstr);
			return;
		}
	}
}