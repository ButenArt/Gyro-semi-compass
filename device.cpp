#include "device.h"

Device::Device(QObject *parent): QObject(parent)
{
    server = new TCP_server();
    planeParams = &(server->displayPacket);

    gpk = new GPK;
    gpk->show();
    connect(server,SIGNAL(readyYaw(float)),gpk->GetSprite(),SLOT(nextFrame(float)));        // Подключаем сигнал от сервера к слоту перелистывания кадров спрайта
    connect(server,SIGNAL(readySwitch(bool)),gpk,SLOT(Switch(bool)));                        // Подключаем сигнал от сервера к слоту занавеса шторки
}

Device::~Device()
{
    delete gpk;
    delete server;
}

