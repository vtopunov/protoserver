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

public slots:
	void listen();
	void tcpclose();

private:
	Ui::protoserverClass ui;
	Server server;
};

#endif // PROTOSERVER_H
