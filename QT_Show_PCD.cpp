#include "QT_Show_PCD.h"

//�����������루qt���ڱ��⣩
#if _MSC_VER >= 1600  
#pragma execution_character_set("utf-8")  
#endif 

//���ߺ���ת��rs�еĵ��Ƶ�pcl�еĵ���
pcl::PointCloud<pcl::PointXYZ>::Ptr points_to_pcl(const rs2::points& points)
{
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);

	auto sp = points.get_profile().as<rs2::video_stream_profile>();
	cloud->width = sp.width();
	cloud->height = sp.height();
	cloud->is_dense = false;
	cloud->points.resize(points.size());
	auto ptr = points.get_vertices();
	for (auto& p : cloud->points)
	{
		p.x = ptr->x;
		p.y = - ptr->y;
		p.z = - ptr->z;
		ptr++;
	}

	return cloud;
}

//���캯��
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
	//�������ϵ
	connect(ui.onAddCoordinateSystem, SIGNAL(clicked()), this, SLOT(onAddCoordinateSystem()));
	//���㷨�߲���ʾ
	connect(ui.onNormal, SIGNAL(clicked()), this, SLOT(onNormal()));
	//�����Ƴ�
	connect(ui.removeNormals, SIGNAL(clicked()), this, SLOT(onRemoveNormals()));
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
	
	//���Ʊ���
	connect(ui.saveAsPCD, SIGNAL(clicked()), this, SLOT(onSave()));
	//��ʾ�ָ�ǰ����
	connect(ui.showOriginalPointCloud, SIGNAL(clicked()), this, SLOT(showOriginalPointCloud()));
	connect(ui.showOriginalPointCloud2, SIGNAL(clicked()), this, SLOT(showOriginalPointCloud()));
	//�ָ�õ�ƽ����Ʋ���ʾ
	connect(ui.getPlane, SIGNAL(clicked()), this, SLOT(getPlane()));
	//�ָ�ȥ��ƽ����Ʋ���ʾ
	connect(ui.removePlane, SIGNAL(clicked()), this, SLOT(removePlane()));
	//�ָ�õ�������Ʋ���ʾ
	connect(ui.getCylinder, SIGNAL(clicked()), this, SLOT(getCylinder()));
	//�ָ�ȥ��������Ʋ���ʾ
	connect(ui.removeCylinder, SIGNAL(clicked()), this, SLOT(removeCylinder()));
	//����ƽ��ָ�������������ָ�
	connect(ui.loadPointCloudAfterPlane, SIGNAL(clicked()), this, SLOT(loadPointCloudAfterPlane()));
	//���Ӳ���ʾ�µ���
	connect(ui.addNewPointCloud, SIGNAL(clicked()), this, SLOT(addNewPointCloud()));
	//����ɼ�����
	connect(ui.realSenceShowCloud, SIGNAL(clicked()), this, SLOT(realSenceShowCloud()));
	//��ȡһ֡��ɫ����
	connect(ui.getPointCloudOneFrame, SIGNAL(clicked()), this, SLOT(getPointCloudOneFrame()));
	//��̬ѧ�˲�
	connect(ui.morphologicalFilter, SIGNAL(clicked()), this, SLOT(morphologicalFilter()));
}

//��ʼ��VtkWidget
void QT_Show_PCD::initialVtkWidget()
{
	//ָ�����������Ϊdouble��������
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


	ui.r_percent->setValidator(doubleValidator);
	ui.g_percent->setValidator(doubleValidator);
	ui.b_percent->setValidator(doubleValidator);

	ui.nearPointNum->setValidator(new QRegExpValidator(QRegExp("[0-9]+$")));//ָ���������������
	ui.normalLevel->setValidator(new QRegExpValidator(QRegExp("[0-9]+$")));
	ui.kSearch->setValidator(new QRegExpValidator(QRegExp("[0-9]+$")));
	ui.coordinateSystemViewPort->setValidator(new QRegExpValidator(QRegExp("[0-9]+$")));
	ui.coordinateSystemScale->setValidator(new QRegExpValidator(QRegExp("[0-9]+$")));
	ui.maxIterations->setValidator(new QRegExpValidator(QRegExp("[0-9]+$")));
	//��ʼ������
	cloud.reset(new pcl::PointCloud<pcl::PointXYZ>);//��ʼ����
	cloudA.reset(new pcl::PointCloud<pcl::PointXYZ>);//��ʼ����A
	cloudB.reset(new pcl::PointCloud<pcl::PointXYZ>);//��ʼ����B
	cloud_normals.reset(new pcl::PointCloud<pcl::Normal>);//����
	coefficients_plane.reset(new pcl::ModelCoefficients);//ƽ��ϵ��
	inliers_plane.reset(new pcl::PointIndices);//ƽ������
	cloud_plane.reset(new pcl::PointCloud<pcl::PointXYZ>());//ƽ�����
	cloud_without_plane.reset(new pcl::PointCloud<pcl::PointXYZ>());//ȥ��ƽ��ĵ���
	coefficients_cylinder.reset(new pcl::ModelCoefficients);//����ϵ��
	inliers_cylinder.reset(new pcl::PointIndices);//��������
	cloud_cylinder.reset(new pcl::PointCloud<pcl::PointXYZ>());//�������
	cloud_without_cylinder.reset(new pcl::PointCloud<pcl::PointXYZ>());//ȥ��ƽ��ĵ���

	//����Ĭ���˲���ʽΪ����
	setPassThoughNagative = false;
	//Ĭ��δ������ϵ
	coordinateSystemFlag = true;
	//����ϵ��ʼ������
	coordinateSystemScale = 1.0;
	coordinateSystemX = 0.0;
	coordinateSystemY = 0.0;
	coordinateSystemZ = 0.0;
	coordinateSystemViewPort = 0;
	//��ʼ��ֱͨ�˲�����
	limitMin.clear();
	limit_min = 0.0;
	//��ʼ��ֱͨ�˲�����
	limitMax.clear();
	limit_max = 0.0;
	//��ʼ����������ʱ����
	normal_level = 10;
	normal_scale = 0.05;//���߳���0.05��
	k_search = 50;//ָ���������������Ϊ50
	//ƽ��ָ������ʼ��
	normalDistanceWeight = 0.1;//���߾���Ȩ��
	maxIterations = 100;//����������
	distanceThreshold = 0.03;//������ֵ
	//����ָ�뾶��Χ��ʼ��
	minRadius = 0;
	maxRadius = 0.1;
	//��ʼ��RGBƽ�����
	rPercent = 1.0;
	gPercent = 1.0;
	bPercent = 1.0;

	//��ʼ�����ӻ�����
	viewer.reset(new pcl::visualization::PCLVisualizer("viewer", false));
	viewer->addPointCloud(cloud, "cloud");
	viewer->addPointCloud(cloudA, "cloudA");
	viewer->addPointCloud(cloudB, "cloudB");
	ui.qvtkWidget->SetRenderWindow(viewer->getRenderWindow());
	viewer->setupInteractor(ui.qvtkWidget->GetInteractor(), ui.qvtkWidget->GetRenderWindow());
	ui.qvtkWidget->update();
}

//����ϵ
void QT_Show_PCD::onAddCoordinateSystem()
{
	QCoordinateSystemScale = ui.coordinateSystemScale->text();
	QCoordinateSystemX = ui.coordinateSystemX->text();
	QCoordinateSystemY = ui.coordinateSystemY->text();
	QCoordinateSystemZ = ui.coordinateSystemZ->text();
	QCoordinateSystemViewPort = ui.coordinateSystemViewPort->text();
	//��������
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
	// ���塡���ƶ���ָ��
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud2_ptr(new pcl::PointCloud<pcl::PointXYZ>);//�˲�ǰ���ƶ���ָ��
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud2_filtered_ptr(new pcl::PointCloud<pcl::PointXYZ>);//�˲�����ƶ���ָ��
	cloud2_ptr = cloud;
	if (cloud2_ptr->width * cloud2_ptr->height == 0) {
		QMessageBox::warning(this, "����:", "��ǰ���ƴ�СΪ��!");
		return;
	}
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
	
	// �����˲�������
	pcl::PassThrough<pcl::PointXYZ> pass;
	pass.setInputCloud(cloud2_ptr);//�����������
	pass.setFilterFieldName(passThoughAxis);// ������
	pass.setFilterLimits(limit_min, limit_max);//����Χ
	pass.setFilterLimitsNegative(setPassThoughNagative);//��־Ϊfalseʱ������Χ�ڵĵ�
	pass.filter(*cloud2_filtered_ptr); //�������
	if (cloud2_filtered_ptr == NULL)
	{
		QMessageBox::warning(this, "����:", "�������Ϊ��!");
		return;
	}
	// ����˲���ĵ�����Ϣ
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
	//----------------------------------ֱͨ�˲����-----------------------------------
	cloud = cloud2_filtered_ptr;
	//ˢ����ʾ
	viewer->updatePointCloud(cloud, "cloud");
	viewer->resetCamera();
	ui.qvtkWidget->update();
	QMessageBox::information(this, "��Ϣ:", "�˲��ɹ�!");
	cloud_save_ptr = cloud2_filtered_ptr;
}
	
//�����²���
void QT_Show_PCD::onVelx()
{
	// ���塡���ƶ���ָ��
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud2_ptr(new pcl::PointCloud<pcl::PointXYZ>);//�˲�ǰ���ƶ���ָ��
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud2_filtered_ptr(new pcl::PointCloud<pcl::PointXYZ>);//�˲�����ƶ���ָ��
	cloud2_ptr = cloud;
	if (cloud2_ptr->width * cloud2_ptr->height == 0) {
		QMessageBox::warning(this, "����:", "��ǰ���ƴ�СΪ��!");
		return;
	}
	//�����˲����ش�С
	leafLength = ui.leafLength->text();
	leafWidth = ui.leafWidth->text();
	leafHeight = ui.leafHeight->text();
	if (leafLength.isEmpty() || leafWidth.isEmpty() || leafHeight.isEmpty())
	{
		QMessageBox::warning(this, "����:", "�����ù������ش�С!");
		return;
	}
	leaf_length = leafLength.toFloat();
	leaf_width = leafWidth.toFloat();
	leaf_height = leafHeight.toFloat();
	// �����˲�������
	pcl::VoxelGrid<pcl::PointXYZ> vg;
	// pcl::ApproximateVoxelGrid<pcl::PointXYZ> avg;
	vg.setInputCloud(cloud2_ptr);//�����������
	vg.setLeafSize(leaf_length, leaf_width, leaf_height);//�����ؿ��С����cm
	vg.filter(*cloud2_filtered_ptr);//���������ָ��*cloud2_filtered_ptr
	if (cloud2_filtered_ptr == NULL)
	{
		QMessageBox::warning(this, "����:", "�������Ϊ��!");
		return;
	}
	// ����˲���ĵ�����Ϣ
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
	//----------------------------------�²������-----------------------------------
	cloud = cloud2_filtered_ptr;
	//ˢ����ʾ
	viewer->updatePointCloud(cloud, "cloud");
	viewer->resetCamera();
	ui.qvtkWidget->update();
	QMessageBox::information(this, "��Ϣ:", "�˲��ɹ�!");
	cloud_save_ptr = cloud2_filtered_ptr;
}

//ͳ���˲���
void QT_Show_PCD::onStatisticalOutlierRemoval()
{
	// ���塡���ƶ���ָ��
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud2_ptr(new pcl::PointCloud<pcl::PointXYZ>);//�˲�ǰ���ƶ���ָ��
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud2_filtered_ptr(new pcl::PointCloud<pcl::PointXYZ>);//�˲�����ƶ���ָ��
	cloud2_ptr = cloud;
	if (cloud2_ptr->width * cloud2_ptr->height == 0) {
		QMessageBox::warning(this, "����:", "��ǰ���ƴ�СΪ��!");
		return;
	}
	//�����˲������������ֵ
	nearPointNum = ui.nearPointNum->text();
	filterThreshold = ui.filterThreshold->text();
	if (nearPointNum.isEmpty() || filterThreshold.isEmpty())
	{
		QMessageBox::warning(this, "����:", "�������˲������������ֵ!");
		return;
	}
	near_point_num = nearPointNum.toInt();
	filter_threshold = filterThreshold.toFloat();
	
	// �����˲�������ÿ����������ٽ���ĸ�������Ϊ50 ��������׼��ı�������Ϊ1  ����ζ�����һ
	// ����ľ��볬����ƽ������һ����׼�����ϣ���õ㱻���Ϊ��Ⱥ�㣬�������Ƴ����洢����
	pcl::StatisticalOutlierRemoval<pcl::PointXYZ> sta;//�����˲�������
	sta.setInputCloud(cloud2_ptr);		    //���ô��˲��ĵ���
	sta.setMeanK(near_point_num);	     			    //�����ڽ���ͳ��ʱ���ǲ�ѯ���ٽ�����
	sta.setStddevMulThresh(filter_threshold);	   		    //�����ж��Ƿ�Ϊ��Ⱥ��ķ�ֵ
	sta.filter(*cloud2_filtered_ptr); 		    //�洢�ڵ�
	if (cloud2_filtered_ptr == NULL)
	{
		QMessageBox::warning(this, "����:", "�������Ϊ��!");
		return;
	}
	// ����˲���ĵ�����Ϣ
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
	//----------------------------------ͳ���˲����-----------------------------------
	cloud = cloud2_filtered_ptr;
	//ˢ����ʾ
	viewer->updatePointCloud(cloud, "cloud");
	viewer->resetCamera();
	ui.qvtkWidget->update();
	QMessageBox::information(this, "��Ϣ:", "�˲��ɹ�!");
	cloud_save_ptr = cloud2_filtered_ptr;
}

//������ʾ
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
	//pcl::PointCloud<pcl::Normal>::Ptr cloud_normals(new pcl::PointCloud<pcl::Normal>);//���߼���
	pcl::search::KdTree<pcl::PointXYZ>::Ptr tree(new pcl::search::KdTree<pcl::PointXYZ>());//kd��
	// ����㷨��
	ne.setSearchMethod(tree);//���ý��������㷨 
	ne.setInputCloud(cloud);//�����������
	ne.setKSearch(k_search);//ָ���ٽ�������
	ne.compute(*cloud_normals);
	//pcl::concatenateFields(*cloud, *cloud_normals, *cloud_with_normals);
	
	//ˢ����ʾ
	viewer->addPointCloudNormals<pcl::PointXYZ, pcl::Normal>(cloud, cloud_normals, normal_level, normal_scale, "normals");
	//viewer->removePointCloud("normals");
	viewer->resetCamera();
	ui.qvtkWidget->update();
}

//��������
void QT_Show_PCD::onRemoveNormals()
{
	viewer->removePointCloud("normals");
	viewer->resetCamera();
	ui.qvtkWidget->update();
}

//��ʾ�ָ�ǰ����
void QT_Show_PCD::showOriginalPointCloud()
{
	if (cloud->width * cloud->height == 0 ) {
		QMessageBox::warning(this, "����!", "���ƴ�СΪ�㣡");
		return;
	}
	viewer->removeAllPointClouds();
	viewer->addPointCloud(cloud, "cloud");
	viewer->resetCamera();
	ui.qvtkWidget->update();
	cloud_save_ptr = cloud;
}

//�ָ�õ�ƽ�沢��ʾ
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
		QMessageBox::warning(this, "����!", "�������ɷ���!");
		return;
	}
	// Ϊƽ��ģ�ʹ����ָ�����������в���
	seg.setOptimizeCoefficients(true);//�����Ż�ϵ��
	seg.setModelType(pcl::SACMODEL_NORMAL_PLANE);//���÷ָ�ģ�����:ƽ��ָ�
	seg.setNormalDistanceWeight(normalDistanceWeight);//���÷��߾���Ȩ��
	seg.setMethodType(pcl::SAC_RANSAC);//�������ĸ�����������Ʒ���
	seg.setMaxIterations(maxIterations);//��������������
	seg.setDistanceThreshold(distanceThreshold);//���þ�����ֵ
	seg.setInputCloud(cloud);//�����������
	seg.setInputNormals(cloud_normals);//�������뷨��
	// �ָ�õ�ƽ��������ϵ��
	seg.segment(*inliers_plane, *coefficients_plane);//ǰ�� ƽ������ �� ���� ƽ��ϵ��

	// ��ֱͨ�˲��������Ϊ������ȡƽ��������
	extract.setInputCloud(cloud);//�����������
	extract.setIndices(inliers_plane);//��������
	extract.setNegative(false);//�����Ƿ�ӦӦ�õ���˵ĳ���������ת�������������negative:false = �����Ĺ�������Ϊ��Ĭ�ϣ���true = �������Ϊ��

	// ��ƽ������д�����
	extract.filter(*cloud_plane);

	//��ʾ����
	if (cloud_plane->width * cloud_plane->height == 0) {
		QMessageBox::warning(this, "����!", "���ɵ��ƴ�СΪ�㣡");
		return;
	}
	viewer->removeAllPointClouds();
	viewer->addPointCloud(cloud_plane, "cloud_plane");
	viewer->resetCamera();
	ui.qvtkWidget->update();
	cloud_save_ptr = cloud_plane;
}

//�ָ�ȥ��ƽ�沢��ʾ
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
		QMessageBox::warning(this, "����!", "�������ɷ���!");
		return;
	}
	// Ϊƽ��ģ�ʹ����ָ�����������в���
	seg.setOptimizeCoefficients(true);//�����Ż�ϵ��
	seg.setModelType(pcl::SACMODEL_NORMAL_PLANE);//���÷ָ�ģ�����:ƽ��ָ�
	seg.setNormalDistanceWeight(normalDistanceWeight);//���÷��߾���Ȩ��
	seg.setMethodType(pcl::SAC_RANSAC);//�������ĸ�����������Ʒ���
	seg.setMaxIterations(maxIterations);//��������������
	seg.setDistanceThreshold(distanceThreshold);//���þ�����ֵ
	seg.setInputCloud(cloud);//�����������
	seg.setInputNormals(cloud_normals);//�������뷨��
	 // �ָ�õ�ƽ��������ϵ��
	seg.segment(*inliers_plane, *coefficients_plane);//ǰ�� ƽ������ �� ���� ƽ��ϵ��

	 // ��ֱͨ�˲��������Ϊ������ȡƽ��������
	extract.setInputCloud(cloud);//�����������
	extract.setIndices(inliers_plane);//��������
	extract.setNegative(true);//�����Ƿ�ӦӦ�õ���˵ĳ���������ת�������������negative:false = �����Ĺ�������Ϊ��Ĭ�ϣ���true = �������Ϊ��

	// ��ƽ������д�����
	//pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_without_plane(new pcl::PointCloud<pcl::PointXYZ>());
	extract.filter(*cloud_without_plane);

	//��ʾ����
	if (cloud_without_plane->width * cloud_without_plane->height == 0) {
		QMessageBox::warning(this, "����!", "���ɵ��ƴ�СΪ�㣡");
		return;
	}
	viewer->removeAllPointClouds();
	viewer->addPointCloud(cloud_without_plane, "cloud_without_plane");
	viewer->resetCamera();
	ui.qvtkWidget->update();
	cloud_save_ptr = cloud_without_plane;
}

//�ָ�õ�����
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
		QMessageBox::warning(this,"����!","�������ɷ���!");
		return;
	}
	// ����Բ����ָ�ķָ�����������в���
	seg.setOptimizeCoefficients(true);
	seg.setModelType(pcl::SACMODEL_CYLINDER);
	seg.setMethodType(pcl::SAC_RANSAC);
	seg.setNormalDistanceWeight(0.1);
	seg.setMaxIterations(10000);
	seg.setDistanceThreshold(0.05);
	seg.setRadiusLimits(minRadius, maxRadius);//���ð뾶����
	seg.setInputCloud(cloud);
	seg.setInputNormals(cloud_normals);
	// ���Բ����ǻ��ϵ��
	seg.segment(*inliers_cylinder, *coefficients_cylinder);
	// ����������д�����
	extract.setInputCloud(cloud);
	extract.setIndices(inliers_cylinder);
	extract.setNegative(false);
	extract.filter(*cloud_cylinder);

	//��ʾ����
	if (cloud_cylinder->width * cloud_cylinder->height == 0) {
		QMessageBox::warning(this, "����!", "���ɵ��ƴ�СΪ�㣡");
		return;
	}
	viewer->removeAllPointClouds();
	viewer->addPointCloud(cloud_cylinder, "cloud_cylinder");
	viewer->resetCamera();
	ui.qvtkWidget->update();
	cloud_save_ptr = cloud_cylinder;
}

//�ָ��Ƴ�����
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
		QMessageBox::warning(this, "����!", "�������ɷ���!");
		return;
	}
	// ����Բ����ָ�ķָ�����������в���
	seg.setOptimizeCoefficients(true);
	seg.setModelType(pcl::SACMODEL_CYLINDER);
	seg.setMethodType(pcl::SAC_RANSAC);
	seg.setNormalDistanceWeight(0.1);
	seg.setMaxIterations(10000);
	seg.setDistanceThreshold(0.05);
	seg.setRadiusLimits(minRadius, maxRadius);//���ð뾶����
	seg.setInputCloud(cloud);
	seg.setInputNormals(cloud_normals);
	// ���Բ����ǻ��ϵ��
	seg.segment(*inliers_cylinder, *coefficients_cylinder);
	// ����������д�����
	extract.setInputCloud(cloud);
	extract.setIndices(inliers_cylinder);
	extract.setNegative(true);
	extract.filter(*cloud_without_cylinder);

	//��ʾ����
	if (cloud_without_cylinder->width * cloud_without_cylinder->height == 0) {
		QMessageBox::warning(this, "����!", "���ɵ��ƴ�СΪ�㣡");
		return;
	}
	viewer->removeAllPointClouds();
	viewer->addPointCloud(cloud_without_cylinder, "cloud_cylinder");
	viewer->resetCamera();
	ui.qvtkWidget->update();
	cloud_save_ptr = cloud_without_cylinder;
}

//����ƽ��ָ�������������ָ�
void QT_Show_PCD::loadPointCloudAfterPlane() 
{
	if (cloud_without_plane->width * cloud_without_plane->height == 0) 
	{
		QMessageBox::warning(this,"����!","δ�ҵ�ȥ��ƽ������!");
		return;
	}
	cloud = cloud_without_plane;
	QMessageBox::information(this, "��ʾ!", "ȥ��ƽ����������ɹ�!");
}

//�����뷨�߷ָ�
void QT_Show_PCD::morphologicalFilter()
{
	if (cloud_normals->empty())
	{
		QMessageBox::warning(this, "����!", "�������ɷ��ߣ�");
		return;
	}
	//���������ķ�ʽ����˵�ǽṹ��kd��������
	pcl::search::Search<pcl::PointXYZ>::Ptr tree = boost::shared_ptr<pcl::search::Search<pcl::PointXYZ> >(new pcl::search::KdTree<pcl::PointXYZ>);
	//������������ָ����<�㣬����>
	pcl::RegionGrowing<pcl::PointXYZ, pcl::Normal> reg;
	reg.setMinClusterSize(50);     //��С�ľ���ĵ���
	reg.setMaxClusterSize(1000000);//���ľ���ĵ���
	reg.setSearchMethod(tree);     //������ʽ
	reg.setNumberOfNeighbours(30); //���������������ĸ���
	reg.setInputCloud(cloud);      //�����
								   //reg.setIndices (indices);
	reg.setInputNormals(cloud_normals);  //����ķ���
	reg.setSmoothnessThreshold(3.0 / 180.0 * M_PI);//����ƽ���� ���߲�ֵ��ֵ
	reg.setCurvatureThreshold(1.0);                //�������ʵķ�ֵ

	std::vector <pcl::PointIndices> clusters;
	reg.extract(clusters);//��ȡ�������

	pcl::PointCloud <pcl::PointXYZRGB>::Ptr colored_cloud = reg.getColoredCloud();



	pcl::visualization::PointCloudColorHandlerRGBField<pcl::PointXYZRGB> rgb(colored_cloud);

	viewer->addPointCloud<pcl::PointXYZRGB>(colored_cloud, "sample cloud");
	viewer->removePointCloud("cloud");
	viewer->resetCamera();
	ui.qvtkWidget->update();
}

//���Ʊ���
void QT_Show_PCD::onSave()
{
	cloud_save_ptr = cloud;
	if (cloud_save_ptr->points.empty())
	{
		QMessageBox::warning(this, "����:", "�������Ϊ��!");
		return;
	}
	QString saveFileName = QFileDialog::getSaveFileName(this, "�������", ".", "�����ļ�(*.pcd)");
	if (!saveFileName.isEmpty())
	{
		saveFileNameStr = saveFileName.toStdString();
		writer.write(saveFileNameStr, *cloud_save_ptr, false);
		QMessageBox::information(this, "��Ϣ:", "����ɹ�!");
		return;
	}

}

//�򿪲���ʾ�����ļ�
void QT_Show_PCD::onOpen()
{
	QString fileName = QFileDialog::getOpenFileName(this, "Open PointCloud", ".", "Open PCD OR PLY files(*.pcd *.ply)");
	if (!fileName.isEmpty())
	{
		std::string file_name = fileName.toStdString();
		if (file_name.substr(file_name.find("."),file_name.length()) == ".ply")
		{
			pcl::PCLPointCloud2 ply_cloud2;
			pcl::PLYReader plyReader;
			plyReader.read(file_name, ply_cloud2);
			pcl::PointCloud<pcl::PointXYZRGB> ply_point_cloud;
			pcl::fromPCLPointCloud2(ply_cloud2, ply_point_cloud);
			pcl::PCDWriter writer;
			//======================== ���� ===========================
			writer.writeASCII("dataAAA.pcd", ply_point_cloud);
			pcl::PointCloud<pcl::PointXYZRGB>::Ptr ply_ptr(new pcl::PointCloud<pcl::PointXYZRGB>);
			pcl::PCDReader reader;
			reader.read<pcl::PointXYZRGB>("dataAAA.pcd", *ply_ptr);
			viewer->addPointCloud(ply_ptr,"ply_point_cloud");
		}

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
		if (data_type == 0 || data_type == 1)

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
	}
}

//�����µ���
void QT_Show_PCD::addNewPointCloud() 
{
	QString fileName = QFileDialog::getOpenFileName(this, "�򿪵���", ".", "Open PCD files(*.pcd)");
	if (!fileName.isEmpty())
	{
		std::string file_name = fileName.toStdString();

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
		if (cloud->points.empty()) 
		{
			if (data_type == 0 || data_type == 1)
			{
				pcl::io::loadPCDFile(fileName.toStdString(), *cloud);
			}
			else if (data_type == 2)
			{
				pcl::PCDReader reader;
				reader.read<pcl::PointXYZ>(fileName.toStdString(), *cloud);
			}
			viewer->updatePointCloud(cloud,"cloud");
			viewer->resetCamera();
			ui.qvtkWidget->update();
		}
		else if (cloudA->points.empty()) 
		{
			if (data_type == 0 || data_type == 1)
			{
				pcl::io::loadPCDFile(fileName.toStdString(), *cloudA);
			}
			else if (data_type == 2)
			{
				pcl::PCDReader reader;
				reader.read<pcl::PointXYZ>(fileName.toStdString(), *cloudA);
			}
			//viewer->addPointCloud(cloudA, "cloudA");
			viewer->updatePointCloud(cloudA, "cloudA");
			viewer->resetCamera();
			ui.qvtkWidget->update();
		}
		else if (cloudB->points.empty())
		{
			if (data_type == 0 || data_type == 1)
			{
				pcl::io::loadPCDFile(fileName.toStdString(), *cloudB);
			}
			else if (data_type == 2)
			{
				pcl::PCDReader reader;
				reader.read<pcl::PointXYZ>(fileName.toStdString(), *cloudB);
			}
			//viewer->addPointCloud(cloudB, "cloudB");
			viewer->updatePointCloud(cloudB, "cloudB");
			viewer->resetCamera();
			ui.qvtkWidget->update();
		}
		else 
		{
			QMessageBox::warning(this,"����!","���ͬʱ��ʾ��������");
		}
	}
}

//���Ʋɼ���ʾ
//void QT_Show_PCD::realSenceShowCloud() 
//{
//	QString path = "./rs-pointcloud.exe";
//	QProcess *process = new QProcess;
//	process->execute("\"" + path + "\"");
//
//	//viewer->removeAllPointClouds();
//	realSenceFlag = !realSenceFlag;
//	pipe.start();
//	// �ȴ��������һ��֡
//	auto frames = pipe.wait_for_frames();
//
//	auto color = frames.get_color_frame();
//	// ����û��RGB����������������ǽ��ѵ���ӳ�䵽�����������ɫ
//	if (!color)
//	{
//		color = frames.get_infrared_frame();
//	}
//	// ����pointcloud����ӳ�䵽����ɫ���
//	pc.map_to(color);
//
//	auto depth = frames.get_depth_frame();
//	// ���ɵ��ƺ�����ӳ��
//	points = pc.calculate(depth);
//
//	cloud = points_to_pcl(points);
//	
//	pipe.stop();
//
//	viewer->removeAllPointClouds();
//	viewer->addPointCloud(cloud, "cloud");
//	viewer->resetCamera();
//	ui.qvtkWidget->update();
//	cloud_save_ptr = cloud;
//	
//}

void QT_Show_PCD::realSenceShowCloud()
{

	QString path = "./rs-pointcloud.exe";


	QProcess *process = new QProcess;

	process->execute("\"" + path + "\"");
	
}

void QT_Show_PCD::getPointCloudOneFrame()
{
	RPercent = ui.r_percent->text();
	GPercent = ui.b_percent->text();
	BPercent = ui.b_percent->text();
	if (!RPercent.isEmpty())
	{
		rPercent = RPercent.toDouble();
	}
	if (!GPercent.isEmpty())
	{
		gPercent = GPercent.toDouble();
	}
	if (!BPercent.isEmpty())
	{
		bPercent = BPercent.toDouble();
	}
	uint32_t depth_width = 1280;
	uint32_t depth_height = 720;
	uint32_t depth_fps = 30;

	// �����豸����
	rs2::config config;
	config.enable_stream(rs2_stream::RS2_STREAM_DEPTH, depth_width, depth_height, rs2_format::RS2_FORMAT_Z16, depth_fps);

	// ��������
	pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_cam1;

	//����ָ��
	cloud_cam1 = boost::make_shared<pcl::PointCloud<pcl::PointXYZRGB>>();
	cloud_cam1->width = static_cast<uint32_t>(depth_width);
	cloud_cam1->height = static_cast<uint32_t>(depth_height);
	cloud_cam1->points.resize(cloud_cam1->height * cloud_cam1->width);
	cloud_cam1->is_dense = false;

	pipe.start();

	//=======================
	// �ȴ��������һ��֡
	auto frames = pipe.wait_for_frames();
	auto depth = frames.get_depth_frame();
	// ���ɵ��ƺ�����ӳ��
	points = pc.calculate(depth);
	cloud = points_to_pcl(points);

	//	��ȡ��ɫ����
	rs2::align align(RS2_STREAM_DEPTH);
	auto aligned_frames = align.process(frames);
	rs2::video_frame color_frame = aligned_frames.get_color_frame();
	auto p_color_frame = static_cast<uint8_t*>(const_cast<void*>(color_frame.get_data()));
	uint32_t color_width = color_frame.as<rs2::video_frame>().get_width();
	uint32_t color_height = color_frame.as<rs2::video_frame>().get_height();


	//	������
	int j = 0;
	for (int i = 0; i < color_width * color_height; i++) {
		cloud_cam1->points[i].x = cloud->points[i].x;
		cloud_cam1->points[i].y = cloud->points[i].y;
		cloud_cam1->points[i].z = cloud->points[i].z;
		cloud_cam1->points[i].g = p_color_frame[j] * gPercent;
		cloud_cam1->points[i].b = p_color_frame[j + 1] * bPercent;
		cloud_cam1->points[i].r = p_color_frame[j + 2] * rPercent;
		j = j + 3;
	}
	//	��PCL�鿴������ʾ���
	if (!viewer->updatePointCloud(cloud_cam1, "cloud1")) {
		viewer->addPointCloud(cloud_cam1, "cloud1");
	}

	viewer->resetCamera();
	//=======================

	ui.qvtkWidget->update();
	pipe.stop();
}