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
	connect(ui.actionOpen, SIGNAL(triggered()), this, SLOT(onOpen()));
	connect(ui.voxelGridButton_2, SIGNAL(clicked()), this, SLOT(onVelx()));
	connect(ui.passThroughButton, SIGNAL(clicked()), this, SLOT(onPassThrough()));
	connect(ui.statisticalOutlierRemovalButton, SIGNAL(clicked()), this, SLOT(onStatisticalOutlierRemoval()));
}

//��ʼ��VtkWidget
void QT_Show_PCD::initialVtkWidget()
{
	//��ʼ������
	cloud.reset(new pcl::PointCloud<pcl::PointXYZ>);
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

//ֱͨ�˲�
void QT_Show_PCD::onPassThrough()
{
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

		// �����˲�������Create the filtering object
		pcl::PassThrough<pcl::PointXYZ> pass;
		pass.setInputCloud(cloud2_ptr);//�����������
		pass.setFilterFieldName("z");// ������
		pass.setFilterLimits(0.0, 0.5);//����Χ
		 // pass.setKeepOrganized(true); // ���� ������ƽṹ===============
		pass.setFilterLimitsNegative(true);//��־Ϊfalseʱ������Χ�ڵĵ�
		pass.filter(*cloud2_filtered_ptr); //�������
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