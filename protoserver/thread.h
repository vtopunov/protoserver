#ifndef THREAD_H
#define THREAD_H

#include <QtNetwork>
#include <QThread>

class thread : public QThread
{
    Q_OBJECT

public:
	thread(qintptr hsocket, QObject* parent = 0);
    ~thread();

protected:
    void run() Q_DECL_OVERRIDE;

signals:
    void error(QTcpSocket::SocketError socketError);

private slots:
	void disconnected();

 private:
	 qintptr hsocket_;
	 QTcpSocket* socket_;
};

#endif // THREAD_H
