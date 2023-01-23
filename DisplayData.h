#ifndef DISPLAYDATA_H
#define DISPLAYDATA_H

#include <QtGlobal>

// Заголовок пакета
struct DisplayTCPHeader
{
    quint32 Mark;
    quint32 PacketType;
    quint32 DataSize;
};

// Данные пакета
struct DisplayDataPacket
{
    bool PacketReady = 0;
    float yaw = 0;                 // Курс
    bool SwitchGPK = false;        // Тумблер включения
};

#endif // DISPLAYDATA_H
