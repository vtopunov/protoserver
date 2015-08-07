#include "protoserver.h"

protoserver::protoserver(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	auto server = new Server(this);

	const auto enabledClose = [this](bool isEnabled) {
		this->ui.listen->setEnabled(!isEnabled);
		this->ui.close->setEnabled(isEnabled);
		this->ui.port->setEnabled(!isEnabled);
	};

	const auto listen = [this, server, enabledClose]() {
		if (server->isListening()) {
			this->ui.port->setValue(server->serverPort());
		}
		else {
			server->listen(QHostAddress::Any, this->ui.port->value());
			qDebug() << "start listen on *:" << ui.port->value();
		}

		enabledClose(true);
	};

	const auto close = [server, enabledClose]() {
		qDebug() << "close";
		server->close();
		enabledClose(false);
	};

	QObject::connect(ui.listen, &QPushButton::clicked, listen);

	QObject::connect(ui.close, &QPushButton::clicked, close);

	listen();
}

protoserver::~protoserver()
{

} 


