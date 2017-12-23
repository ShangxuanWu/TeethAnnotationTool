#include "KeypointQApp.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	KeypointQApp w;
	w.show();
	return a.exec();
}
