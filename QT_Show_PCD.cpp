#include "QT_Show_PCD.h"

//�����������루qt���ڱ��⣩
#if _MSC_VER >= 1600  
#pragma execution_character_set("utf-8")  
#endif 


QT_Show_PCD::QT_Show_PCD(QWidget *parent)
	: QMainWindow(parent)
{
	//ui��ʼ��
	ui.setupUi(this);
	this->setWindowTitle("��ҵ���-�������ݲɼ�");
	initialVtkWidget();
	//�����������ӹ�ϵ
	//���ļ������ӻ�
	connect(ui.actionOpen, SIGNAL(triggered()), this, SLOT(onOpen()));
	//�²���
	connect(ui.voxelGridButton_2, SIGNAL(clicked()), this, SLOT(onVelx()));
	//ֱͨ�˲����ò���
	connect(ui.setPathThroughX, SIGNAL(clicked()), this, SLOT(setAxisX()));
	connect(ui.setPathThroughY, SIGNAL(clicked()), this, SLOT(setAxisY()));
	connect(ui.setPathThroughZ, SIGNAL(clicked()), this, SLOT(setAxisZ()));
	connect(ui.checkFilterLimitsNegative, SIGNAL(clicked()), this, SLOT(setFilterNegative()));
	//ֱͨ�˲�ʵ�ֲۺ���
	connect(ui.passThroughButton, SIGNAL(clicked()), this, SLOT(onPassThrough()));
	//ͳ���˲�
	connect(ui.statisticalOutlierRemovalButton, SIGNAL(clicked()), this, SLOT(onStatisticalOutlierRemoval()));
	//connect(ui.statisticalOutlierRemovalButton, SIGNAL(clicked()), this, SLOT(cylinder_segmentation()));
}

//��ʼ��VtkWidget
void QT_Show_PCD::initialVtkWidget()
{
	//�趨��������������
	QDoubleValidator *doubleValidator = new QDoubleValidator(-9999, 9999, 6, this);
	doubleValidator->setNotation(QDoubleValidator::StandardNotation);
	ui.editLimitMin->setValidator(doubleValidator);
	ui.editLimitMax->setValidator(doubleValidator);
	//��ʼ������
	cloud.reset(new pcl::PointCloud<pcl::PointXYZ>);
	//����Ĭ���˲���ʽΪ����
	setPassThoughNagative = false;
	//��ʼ��ֱͨ�˲�����
	limitMin.clear();
	limit_min = 0.0;
	//��ʼ��ֱͨ�˲�����
	limitMax.clear();
	limit_max = 0.0;
	//��ʼ�����ӻ�����
	viewer.reset(new pcl::visualization::PCLVisualizer("viewer", false));
	viewer->addPointCloud(cloud, "cloud");
	ui.qvtkWidget->SetRenderWindow(viewer->getRenderWindow());
	viewer->setupInteractor(ui.qvtkWidget->GetInteractor(), ui.qvtkWidget->GetRenderWindow());
	ui.qvtkWidget->update();
}

//�򿪲���ʾ�����ļ�
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
		//����PCD��ȡ����
		pcl::PCDReader rd;
		//��ȡPCDͷ��Ϣ
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

//�����²���
void QT_Show_PCD::onVelx()
{
	QString fileName = QFileDialog::getOpenFileName(this, "Choose The PointCloud TO VoxelGridFilter", ".", "Open PCD files(*.pcd)");
	if (!fileName.isEmpty())
	{
		//���ļ�����ȡ�ļ���
		std::string file_name = fileName.toStdString();

		// ���塡���ƶ���ָ��
		pcl::PCLPointCloud2::Ptr cloud2_ptr(new pcl::PCLPointCloud2());//�˲�ǰ���ƶ���ָ��
		pcl::PCLPointCloud2::Ptr cloud2_filtered_ptr(new pcl::PCLPointCloud2());//�˲�����ƶ���ָ��

		//pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered_ptr(new pcl::PointCloud<pcl::PointXYZ>);//��֪����ɶ��

		// ��ȡ�����ļ��������ƶ���
		pcl::PCDReader reader;
		reader.read(file_name, *cloud2_ptr);
		if (cloud2_ptr == NULL) {
			QMessageBox::warning(this, "error", "open file failure!");
			return;
		}

		// �����˲�������Create the filtering object
		pcl::VoxelGrid<pcl::PCLPointCloud2> vg;
		// pcl::ApproximateVoxelGrid<pcl::PointXYZ> avg;
		vg.setInputCloud(cloud2_ptr);//�����������
		vg.setLeafSize(0.01f, 0.01f, 0.01f);//�����ؿ��С����cm
		vg.filter(*cloud2_filtered_ptr);//���������ָ��*cloud2_filtered_ptr
		// д���ڴ�
		pcl::PCDWriter writer;
		file_name.insert(file_name.find("."), "_VoxelGridFilter");
		
		writer.write(file_name, *cloud2_filtered_ptr,
			Eigen::Vector4f::Zero(), Eigen::Quaternionf::Identity(), false);
		//----------------------------------�����²������-----------------------------------

		//�����µĵ��ƶ���������ʾ
		pcl::PCLPointCloud2 cloud2;
		Eigen::Vector4f origin;
		Eigen::Quaternionf orientation;
		int pcd_version;
		int data_type;
		unsigned int data_idx;
		int offset = 0;
		//����PCD��ȡ����
		pcl::PCDReader rd;
		//��ȡPCDͷ��Ϣ
		rd.readHeader(file_name, cloud2, origin, orientation, pcd_version, data_type, data_idx);
		//����˵��:data_type�������ͣ�0 = ASCII��1 =�����ƣ�2 =������ѹ����
		if (data_type == 0)
		{
			pcl::io::loadPCDFile(file_name , *cloud);
		}
		else if (data_type == 2)
		{
			pcl::PCDReader reader1;
			reader1.read<pcl::PointXYZ>(file_name , *cloud);
		}
		//ˢ����ʾ
		viewer->updatePointCloud(cloud, "cloud");
		viewer->resetCamera();
		ui.qvtkWidget->update();
		// ����˲���ĵ�����Ϣ
		int numberBeforeFilter = cloud2_ptr->width * cloud2_ptr->height;
		int numberAfterFilter = cloud2_filtered_ptr->width * cloud2_filtered_ptr->height;
		if (numberAfterFilter != 0) 
		{
			std::string numberAfterFilterStr = std::to_string(numberAfterFilter);
			std::string numberBeforeFilterStr = std::to_string(numberBeforeFilter);
			std::string information = "�²����˲�ǰ����:"+ numberBeforeFilterStr +".\n�²����˲�������:" + numberAfterFilterStr+".";
			QString qstr = QString::fromStdString(information);
			QMessageBox::information(this, "�˲�ǰ������:", qstr);
			return;
		}
	}
}

//����ֱͨ�˲�����
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
//���ñ����㻹�ǹ��˵�
void QT_Show_PCD::setFilterNegative()
{
	setPassThoughNagative = !setPassThoughNagative;
}
//ֱͨ�˲�
void QT_Show_PCD::onPassThrough()
{
	//�趨�˲�������
	if (passThoughAxis.empty())
	{
		QMessageBox::warning(this, "����:", "�����ù���������!");
		return;
	}
	//��ȡ�˲���Χ
	limitMin = ui.editLimitMin->text();
	limitMax = ui.editLimitMax->text();
	if (limitMin.isEmpty()||limitMax.isEmpty()) 
	{
		QMessageBox::warning(this, "����:", "������ֱͨ�˲���Χ!");
		return;
	}
	else
	{
		limit_min = limitMin.toFloat();
		limit_max = limitMax.toFloat();
		if (limit_min>= limit_max)
		{
			QMessageBox::warning(this, "����:", "��������ȷ��ֱͨ�˲���Χ!");
			return;
		}
	}
	//���ļ�����ȡ�ļ���
	QString fileName = QFileDialog::getOpenFileName(this, "Choose The PointCloud TO VoxelGridFilter", ".", "Open PCD files(*.pcd)");
	if (!fileName.isEmpty())
	{
		std::string file_name = fileName.toStdString();

		// ���塡���ƶ���ָ��
		pcl::PointCloud<pcl::PointXYZ>::Ptr cloud2_ptr(new pcl::PointCloud<pcl::PointXYZ>);//�˲�ǰ���ƶ���ָ��
		pcl::PointCloud<pcl::PointXYZ>::Ptr cloud2_filtered_ptr(new pcl::PointCloud<pcl::PointXYZ>);//�˲�����ƶ���ָ��

		// ��ȡ�����ļ��������ƶ���
		pcl::PCDReader reader;
		reader.read(file_name, *cloud2_ptr);
		if (cloud2_ptr == NULL) {
			QMessageBox::warning(this, "error", "open file failure!");
			return;
		}

		// �����˲�������Create the filtering object
		pcl::PassThrough<pcl::PointXYZ> pass;
		pass.setInputCloud(cloud2_ptr);//�����������
		pass.setFilterFieldName(passThoughAxis);// ������
		pass.setFilterLimits(limit_min, limit_max);//����Χ
		 // pass.setKeepOrganized(true); // ���� ������ƽṹ===============
		pass.setFilterLimitsNegative(setPassThoughNagative);//��־Ϊfalseʱ������Χ�ڵĵ�
		pass.filter(*cloud2_filtered_ptr); //�������
		if (cloud2_filtered_ptr == NULL)
		{
			QMessageBox::information(this, "����:", "�������Ϊ��!");
			return;
		}
		// д���ڴ�
		pcl::PCDWriter writer;
		file_name.insert(file_name.find("."), "_PassThroughFilter");

		writer.write(file_name, *cloud2_filtered_ptr, false);
		//----------------------------------ֱͨ�˲����-----------------------------------

		//ˢ����ʾ
		viewer->updatePointCloud(cloud2_filtered_ptr, "cloud");
		viewer->resetCamera();
		ui.qvtkWidget->update();
		// ����˲���ĵ�����Ϣ
		int numberBeforeFilter = cloud2_ptr->width * cloud2_ptr->height;
		int numberAfterFilter = cloud2_filtered_ptr->width * cloud2_filtered_ptr->height;
		if (numberAfterFilter != 0)
		{
			std::string numberAfterFilterStr = std::to_string(numberAfterFilter);
			std::string numberBeforeFilterStr = std::to_string(numberBeforeFilter);
			std::string information = "ֱͨ�˲�ǰ����:" + numberBeforeFilterStr + ".\nֱͨ�˲�������:" + numberAfterFilterStr + ".";
			QString qstr = QString::fromStdString(information);
			QMessageBox::information(this, "�˲�ǰ������:", qstr);
			return;
		}
	}
}
	
//ͳ���˲���
void QT_Show_PCD::onStatisticalOutlierRemoval() {
	QString fileName = QFileDialog::getOpenFileName(this, "Choose The PointCloud TO VoxelGridFilter", ".", "Open PCD files(*.pcd)");
	if (!fileName.isEmpty())
	{
		//���ļ�����ȡ�ļ���
		std::string file_name = fileName.toStdString();

		// ���塡���ƶ���ָ��
		pcl::PointCloud<pcl::PointXYZ>::Ptr cloud2_ptr(new pcl::PointCloud<pcl::PointXYZ>);//�˲�ǰ���ƶ���ָ��
		pcl::PointCloud<pcl::PointXYZ>::Ptr cloud2_filtered_ptr(new pcl::PointCloud<pcl::PointXYZ>);//�˲�����ƶ���ָ��

																									// ��ȡ�����ļ��������ƶ���
		pcl::PCDReader reader;
		reader.read(file_name, *cloud2_ptr);
		if (cloud2_ptr == NULL) {
			QMessageBox::warning(this, "error", "open file failure!");
			return;
		}
		
		// �����˲�������ÿ����������ٽ���ĸ�������Ϊ50 ��������׼��ı�������Ϊ1  ����ζ�����һ
		// ����ľ��볬����ƽ������һ����׼�����ϣ���õ㱻���Ϊ��Ⱥ�㣬�������Ƴ����洢����
		pcl::StatisticalOutlierRemoval<pcl::PointXYZ> sta;//�����˲�������
		sta.setInputCloud(cloud2_ptr);		    //���ô��˲��ĵ���
		sta.setMeanK(50);	     			    //�����ڽ���ͳ��ʱ���ǲ�ѯ���ٽ�����
		sta.setStddevMulThresh(1.0);	   		    //�����ж��Ƿ�Ϊ��Ⱥ��ķ�ֵ
		sta.filter(*cloud2_filtered_ptr); 		    //�洢�ڵ�

		pcl::PCDWriter writer;//д������
		file_name.insert(file_name.find("."), "_StatisticalOutlierRemoval");

		writer.write(file_name, *cloud2_filtered_ptr, false);
		//----------------------------------ͳ���˲����-----------------------------------

		//ˢ����ʾ
		viewer->updatePointCloud(cloud2_filtered_ptr, "cloud");
		viewer->resetCamera();
		ui.qvtkWidget->update();
		// ����˲���ĵ�����Ϣ
		int numberBeforeFilter = cloud2_ptr->width * cloud2_ptr->height;
		int numberAfterFilter = cloud2_filtered_ptr->width * cloud2_filtered_ptr->height;
		if (numberAfterFilter != 0)
		{
			std::string numberAfterFilterStr = std::to_string(numberAfterFilter);
			std::string numberBeforeFilterStr = std::to_string(numberBeforeFilter);
			std::string information = "ͳ���˲�ǰ����:" + numberBeforeFilterStr + ".\nͳ���˲�������:" + numberAfterFilterStr + ".";
			QString qstr = QString::fromStdString(information);
			QMessageBox::information(this, "�˲�ǰ������:", qstr);
			return;
		}
	}
}

//���Ʒָ�
void QT_Show_PCD::cylinder_segmentation() 
{
	// ������Ҫ�Ķ���
	pcl::PCDReader reader;//��ȡ����
	pcl::PassThrough<pcl::PointXYZ> pass;//ֱͨ�˲�
	pcl::NormalEstimation<pcl::PointXYZ, pcl::Normal> ne;//��̬����
	pcl::SACSegmentationFromNormals<pcl::PointXYZ, pcl::Normal> seg;//���Ʒָ�
	pcl::PCDWriter writer;//����д��
	pcl::ExtractIndices<pcl::PointXYZ> extract;//��ȡָ��
	pcl::ExtractIndices<pcl::Normal> extract_normals;//��ȡָ��
	pcl::search::KdTree<pcl::PointXYZ>::Ptr tree(new pcl::search::KdTree<pcl::PointXYZ>());//kd��

	// ���ݼ�
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);//ԭʼ����
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered(new pcl::PointCloud<pcl::PointXYZ>);//���ƹ���
	pcl::PointCloud<pcl::Normal>::Ptr cloud_normals(new pcl::PointCloud<pcl::Normal>);
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered2(new pcl::PointCloud<pcl::PointXYZ>);//���ƹ���
	pcl::PointCloud<pcl::Normal>::Ptr cloud_normals2(new pcl::PointCloud<pcl::Normal>);
	pcl::ModelCoefficients::Ptr coefficients_plane(new pcl::ModelCoefficients), coefficients_cylinder(new pcl::ModelCoefficients);
	pcl::PointIndices::Ptr inliers_plane(new pcl::PointIndices), inliers_cylinder(new pcl::PointIndices);

	QString fileName = QFileDialog::getOpenFileName(this, "Choose The PointCloud TO VoxelGridFilter", ".", "Open PCD files(*.pcd)");

	if (!fileName.isEmpty())
	{
		std::string file_name = fileName.toStdString();
		// ��ȡ��������
		reader.read(file_name, *cloud);
		
		//-----cloud->points.size()��ʱ����������
		// << "PointCloud has: " << cloud->points.size() << " data points." << std::endl;

		// ֱͨ�˲�ȥ����ɢnan��(z�ᣬȥ��1.5����ĵ�)
		pass.setInputCloud(cloud);
		pass.setFilterFieldName("z");
		pass.setFilterLimits(0, 1.5);
		pass.filter(*cloud_filtered);

		//-----cloud_filtered->points.size()ֱͨ�˲������������
		//std::cerr << "PointCloud after filtering has: " << cloud_filtered->points.size() << " data points." << std::endl;

		// ���Ƶ㷨��
		ne.setSearchMethod(tree);
		ne.setInputCloud(cloud_filtered);
		ne.setKSearch(50);
		ne.compute(*cloud_normals);

		// Ϊƽ��ģ�ʹ����ָ�����������в���
		seg.setOptimizeCoefficients(true);
		seg.setModelType(pcl::SACMODEL_NORMAL_PLANE);
		seg.setNormalDistanceWeight(0.1);
		seg.setMethodType(pcl::SAC_RANSAC);
		seg.setMaxIterations(100);
		seg.setDistanceThreshold(0.03);
		seg.setInputCloud(cloud_filtered);
		seg.setInputNormals(cloud_normals);
		// �õ�ƽ�����ߺ�ϵ��
		seg.segment(*inliers_plane, *coefficients_plane);
		std::cerr << "Plane coefficients: " << *coefficients_plane << std::endl;

		// ��ֱͨ�˲��������Ϊ������ȡƽ��������
		extract.setInputCloud(cloud_filtered);
		extract.setIndices(inliers_plane);//��������
		extract.setNegative(false);//�����Ƿ�ӦӦ�õ���˵ĳ���������ת�������������negative:false = �����Ĺ�������Ϊ��Ĭ�ϣ���true = �������Ϊ��

		// ��ƽ������д�����
		pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_plane(new pcl::PointCloud<pcl::PointXYZ>());
		extract.filter(*cloud_plane);
		
		//��ʾһЩ��Ϣ
		//std::cerr << "PointCloud representing the planar component: " << cloud_plane->points.size() << " data points." << std::endl;_plane
		file_name.insert(file_name.find("."), "_plane");
		writer.write(file_name, *cloud_plane, false);

		// �Ƴ�ƽ��������ȡ�����ಿ��
		extract.setNegative(true);
		extract.filter(*cloud_filtered2);
		extract_normals.setNegative(true);
		extract_normals.setInputCloud(cloud_normals);
		extract_normals.setIndices(inliers_plane);
		extract_normals.filter(*cloud_normals2);

		// ����Բ����ָ�ķָ�����������в���
		seg.setOptimizeCoefficients(true);
		seg.setModelType(pcl::SACMODEL_CYLINDER);
		seg.setMethodType(pcl::SAC_RANSAC);
		seg.setNormalDistanceWeight(0.1);
		seg.setMaxIterations(10000);
		seg.setDistanceThreshold(0.05);
		seg.setRadiusLimits(0, 0.1);
		seg.setInputCloud(cloud_filtered2);
		seg.setInputNormals(cloud_normals2);

		// ���Բ����ǻ��ϵ��
		seg.segment(*inliers_cylinder, *coefficients_cylinder);
		//std::cerr << "Cylinder coefficients: " << *coefficients_cylinder << std::endl;

		// ����������д�����
		extract.setInputCloud(cloud_filtered2);
		extract.setIndices(inliers_cylinder);
		extract.setNegative(false);
		pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_cylinder(new pcl::PointCloud<pcl::PointXYZ>());
		extract.filter(*cloud_cylinder);
		if (cloud_cylinder->points.empty())
		{
			//std::cerr << "Can't find the cylindrical component." << std::endl;
			QMessageBox::warning(this, "����:", "�Ҳ���Բ�������");
		}	
		else
		{
			//std::cerr << "PointCloud representing the cylindrical component: " << cloud_cylinder->points.size() << " data points." << std::endl;
			//QMessageBox::information(this, "��Ϣ:", "��ʾ��������ĵ��Ƹ���:"+ cloud_cylinder->points.size());
			file_name.erase(file_name.find(".") - 6);
			file_name.append("_cylinder.pcd");
			writer.write(file_name, *cloud_cylinder, false);
		}
	}
}
