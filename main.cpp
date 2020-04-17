#include "QT_Show_PCD.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])try
{
	QApplication a(argc, argv);
	QT_Show_PCD w;
	w.show();
	return a.exec();
}
catch (const rs2::error & e)
{
	std::cerr << "RealSense error calling " << e.get_failed_function() << "(" << e.get_failed_args() << "):\n    " << e.what() << std::endl;
	return EXIT_FAILURE;
}
catch (const std::exception & e)
{
	std::cerr << e.what() << std::endl;
	return EXIT_FAILURE;
}
