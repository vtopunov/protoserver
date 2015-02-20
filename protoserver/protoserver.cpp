#include "log.h"
#include "protoserver.h"

protoserver::protoserver(QWidget *parent)
	: QWidget(parent), server()
{
	ui.setupUi(this);
	
	listen();
}

protoserver::~protoserver()
{

}

void protoserver::listen() {
	if (server.isListening()) {
		ui.port->setValue(server.serverPort());
	}
	else {
		server.listen(QHostAddress::Any, ui.port->value());
	}

	ui.listen->setEnabled(false);
	ui.close->setEnabled(true);
	ui.port->setEnabled(false);

	LOG("start listen on *:%d\n", ui.port->value());
}

void protoserver::tcpclose() {
	LOG("close\n");

	server.close();

	ui.listen->setEnabled(true);
	ui.close->setEnabled(false);
	ui.port->setEnabled(true);
}
