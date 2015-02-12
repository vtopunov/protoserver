#include "protoserver.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	protoserver w;
	w.show();
	return a.exec();
}
