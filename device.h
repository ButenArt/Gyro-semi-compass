#ifndef DEVICE_H
#define DEVICE_H

#include <QObject>
#include "gpk.h"
#include "tcp_server.h"

class Device: public QObject
{
    Q_OBJECT

public:
    explicit Device(QObject *parent = nullptr);
    ~Device();
    DisplayDataPacket *planeParams;

private:
    GPK *gpk;
    TCP_server *server;
    //QTimer timer;
};

#endif // DEVICE_H
