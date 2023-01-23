#include <QtDebug>
#include "sprite.h"

Sprite::Sprite(QObject *parent) : QObject(parent), QGraphicsItem()
{
    QPixmap image = QPixmap("YawN_3.png");
    image = image.scaled(6636, 512,Qt::IgnoreAspectRatio,Qt::FastTransformation);
    spriteImage = new QPixmap(image);                                   // Загружаем изображение спрайта в QPixmap
}

Sprite::~Sprite()
{

}

QRectF Sprite::boundingRect() const
{
    return QRectF(left,top,width,height);
}

void Sprite::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    /* Первых два аргумента - это координат X и Y куда помещается QPixmap
     * Третий аргумент - это указатель на QPixmap
     * 4 и 5 аргументы - Координаты в В изображении QPixmap, откуда будет отображаться изображение
     * Задавая координату X мы будем как бы передвигать камеру по спрайту
     * последние два аргумента - это ширина и высота отображаем части изображение, то есть кадра
     * */
    painter->drawPixmap(120,-75, *spriteImage, yaw, 100, 800,2000);
    Q_UNUSED(option);
    Q_UNUSED(widget);
    QPen pen(Qt::white, 5);
    painter->setPen(pen);
    painter->drawLine(490, -20, 490, 360);
}

void Sprite::nextFrame(float YAW)
{

    while (YAW > 359 || YAW < 0){
        if (YAW > 359)
            YAW -= 360;
        if (YAW < 0)
            YAW += 360;
    }
    yaw = YAW * 11.38;                                      //устанавливаем текущее значение курса переведенное в значение пикселя на спрайте
    /* По сигналу от сервера передвигаем на количество
     * пикселей точку отрисовки
     * Если yaw = 4100 то обнуляем его,
     * для цикличности также при 6
     */
    if (yaw >= 4096 ) yaw = 1;
    if (yaw <= 0 ) yaw = 4095;
    this->update(left,top,width,height);                    // и перерисовываем графический объект с новым кадром спрайта
}





