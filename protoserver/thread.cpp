#include "thread.h"

thread::thread(qintptr hsocket, QObject* parent) :
    QThread(parent),
	hsocket_(hsocket)
{
}

thread::~thread() {
}

void thread::run()
{
	qDebug() << "starting thread " << (int)currentThreadId();

	QTcpSocket socket_;

	if (!socket_.setSocketDescriptor(hsocket_)) {
		qWarning() << socket_.errorString();
		emit error(socket_.error());
	}

	connect(&socket_, SIGNAL(disconnected()), this, SLOT(disconnected()), Qt::QueuedConnection);

	
	qDebug() << "SQL> SELECT ololo FROM ololos\n";

	QThread::msleep(1000); // sql test

	qDebug() << "write request to " 
		<< socket_.peerAddress().toString() 
		+ ":" + QString::number(socket_.peerPort());

	socket_.write(QByteArray(100000000, '$'));

	qDebug() << "disconect";
	socket_.disconnectFromHost();
	socket_.waitForDisconnected();
	qDebug() << "disconect ok";
}

void thread::disconnected() {
	qDebug() << "disconect slot";
}
