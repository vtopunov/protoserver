#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>

class Server : public QTcpServer
{
    Q_OBJECT

public:
    Server(QObject* parent = 0);
    ~Server();

protected:
    void incomingConnection(qintptr socketDescriptor) Q_DECL_OVERRIDE;
};

#endif // SERVER_H
