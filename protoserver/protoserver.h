#ifndef PROTOSERVER_H
#define PROTOSERVER_H

#include <QtWidgets/QWidget>
#include "ui_protoserver.h"
#include "server.h"

class protoserver : public QWidget
{
	Q_OBJECT

public:
	protoserver(QWidget *parent = 0);
	~protoserver();

private:
	Ui::protoserverClass ui;
};

#endif // PROTOSERVER_H
