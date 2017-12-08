#include "helloworld.h"
#include "qhttpserver.h"
#include "qhttprequest.h"
#include "qhttpresponse.h"
#include "qhttpserverfwd.h"
#include <QDebug>

/// HelloWorld

HelloWorld::HelloWorld()
{
    QHttpServer *server = new QHttpServer(this);
    connect(server, SIGNAL(newRequest(QHttpRequest*, QHttpResponse*)),
            this, SLOT(handleRequest(QHttpRequest*, QHttpResponse*)));

    server->listen(QHostAddress::Any, 80);
    qDebug() << "listen port 80";
}

void HelloWorld::handleRequest(QHttpRequest *req, QHttpResponse *resp)
{
    Q_UNUSED(req);

    QString path = req->path();
    qDebug() << "path: " << path;
    QByteArray body;
    if (path == "/data/unknownSources")
        body = "{\"status\":\"0\",\"message\":\"ok\"}";
    else
        body = "HelloWorld";
    resp->setHeader("Content-Length", QString::number(body.size()));
    resp->writeHead(200);
    resp->end(body);
}
