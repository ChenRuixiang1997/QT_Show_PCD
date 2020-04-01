#include "QT_Show_PCD.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QT_Show_PCD w;
	w.show();
	return a.exec();
}
