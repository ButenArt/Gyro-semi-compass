#include "gpk.h"
#include "ui_gpk.h"

GPK::GPK(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GPK)
{
    read_config();
    setGeometry(wWindow,hWindow,0,0);
    ui->setupUi(this);
    scene = new QGraphicsScene();           // Инициализируем графическую сцену
    ui->graphicsView->setScene(scene);      // Устанавливаем графическую сцену в graphicsView
    sprite = new Sprite;
    scene->addItem(sprite);                 // Помещаем на сцену новый объект спрайта
}

void GPK::read_config()
{
    ini = new QSettings("gpk_config.ini", QSettings::IniFormat);
    ini->beginGroup("GEOMETRY");
    {
        wWindow = ini->value("wWindow").toInt();
        hWindow = ini->value("hWindow").toInt();
    }
    ini->endGroup();

    delete ini;
}

GPK::~GPK()
{
    delete ui;
    delete sprite;
}

void GPK::Switch(bool Switches)
{
    if (!Switches && control == 0)
    {
        control += 1;
        scene->removeItem(sprite);
        //delete sprite;
        //QMessageBox::information(this, "Tumbler defolt","");
    }
    else if (Switches && control > 0)
    {
        control = 0;
        scene->update();
        scene->addItem(sprite);                 // Помещаем на сцену новый объект спрайта
    }
}


