#include "log.h"
#include "thread.h"

thread::thread(qintptr hsocket, QObject* parent) :
    QThread(parent),
	hsocket_(hsocket),
	socket_(new QTcpSocket(this))
{
	if (!socket_->setSocketDescriptor(hsocket)) {
		LOG(q_c_str(socket_->errorString()+"\n"));
		emit error(socket_->error());
	}

	connect(socket_, SIGNAL(disconnected()), this, SLOT(disconnected()));
}

thread::~thread() {
}

void thread::run()
{
	LOG("starting thread %d\n", (int)currentThreadId());
	QTcpSocket socket;
	if (!socket.setSocketDescriptor(hsocket_)) {
		LOG(q_c_str(socket.errorString() + "\n"));
		emit error(socket.error());
		return;
	}

	LOG("SQL> SELECT ololo FROM ololos\n");

	QThread::msleep(1000); // sql test

	LOG("write request to %s\n", q_c_str(socket.peerAddress().toString() + ":" + QString::number(socket.peerPort()) ) );
	socket.write(QByteArray(100000000, '$'));

	LOG("disconect...\n");
	socket.disconnectFromHost();
	socket.waitForDisconnected();
	LOG("disconect ok\n");
}

void thread::disconnected() {
	LOG("disconect ok\n");
}
