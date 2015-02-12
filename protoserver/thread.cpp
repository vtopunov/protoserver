#include "thread.h"

thread::thread(int socket, QObject* parent) :
    QThread(parent),
    socket_(socket)
{
}

thread::~thread()
{

}

void thread::run()
{
    QTcpSocket socket;

    if (!socket.setSocketDescriptor(socket_)) {
        //emit error(socket.error());
        return;
    }

    socket.write("HTTP/1.1 200 OK\n"\
                 "Content-Type: text/plain; charset=utf-8\n"
                 "Content-Length: 4\n\n"
                 "test");

    socket.disconnectFromHost();
    socket.waitForDisconnected();
}

