#ifndef GPK_H
#define GPK_H

#include <QWidget>
#include <QGraphicsScene>
//#include <QMessageBox>
#include "sprite.h"
#include "DisplayData.h"
#include "sprite.h"

QT_BEGIN_NAMESPACE
namespace Ui { class GPK; }
QT_END_NAMESPACE

class GPK : public QWidget
{
    Q_OBJECT

public:
    explicit GPK(QWidget *parent = nullptr);
    ~GPK();

    const Sprite* GetSprite()const{return sprite;}

public slots:
    void Switch(bool SWITCHGPK);       // Слот для черной шторки
private:
    bool switchgpk = false;
    int control = 0;

    Ui::GPK *ui;
    Sprite *sprite;
    void read_config();
    QGraphicsScene *scene;              // Объявляем графическую сцену
    int wWindow;                        //Расстояние от расположения окна в 0 точке по ширине
    int hWindow;                        //Расстояние от расположения окна в 0 точке по высоте
    QSettings *ini;
};
#endif // GPK_H
