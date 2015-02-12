#ifndef THREAD_H
#define THREAD_H

#include <QtNetwork>
#include <QThread>

class thread : public QThread
{
    Q_OBJECT

public:
    thread(int socket, QObject* parent = 0);
    ~thread();

protected:
    void run() Q_DECL_OVERRIDE;

signals:
    void error(QTcpSocket::SocketError socketError);

 private:
    int socket_;
};

#endif // THREAD_H
