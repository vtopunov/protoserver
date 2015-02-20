#include "log.h"
#include "server.h"
#include "thread.h"

Server::Server(QObject* parent) : QTcpServer(parent)
{
}

Server::~Server()
{


}

void Server::incomingConnection(qintptr socket)
{
    auto *t = new ::thread(socket, this);
    connect(t, SIGNAL(finished()), t, SLOT(deleteLater()));
    t->start();
}

void Server::acceptErrorSlot(QAbstractSocket::SocketError socketError) {
	LOG("QTcpServer: accept error %d\n", socketError);
}

