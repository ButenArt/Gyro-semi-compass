#ifndef SPRITE_H
#define SPRITE_H

#include <QObject>
#include <QGraphicsItem>
#include <QPixmap>
#include <QPainter>
#include <QSettings>

class Sprite : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Sprite(QObject *parent = 0);
    ~Sprite();

public slots:
    void nextFrame(float YAW);       // Слот для пролистывания изображения в QPixmap
private:
    float yaw = 0;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
    QPixmap *spriteImage;           // В данный объект QPixamp будет помещён спрайт
    qreal left = 130;               // координата начала спрайта по x
    qreal top = 5;                  // координата начала спрайта по y
    qreal width = 690;              // длина спрайта по x
    qreal height = 316;             // ширина спрайта по y
};

#endif // SPRITE_H
