#include "widget.h"
#include "ui_widget.h"
#include "birditem.h"
#include <QGraphicsPixmapItem>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    scene = new Scene(this);
    scene->setSceneRect(-250,-300,500,600);
    QGraphicsPixmapItem * pixItem = new QGraphicsPixmapItem(QPixmap(":/images/sky.png"));
    scene->addItem(pixItem);
    pixItem->setPos(QPointF(0,0) - QPointF(pixItem->boundingRect().width()/2,
                                           pixItem->boundingRect().height()/2));

    PillarItem* pillar = new PillarItem();
    scene->addItem(pillar);

    scene->addLine(-400,0,400,0,QPen(Qt::blue));
    scene->addLine(0,-400,0,400,QPen(Qt::blue));

    BirdItem * birdItem = new BirdItem(QPixmap(":/images/bird_blue_up.png"));
    scene->addItem(birdItem);

    ui->graphicsView->setScene(scene);
}

Widget::~Widget()
{
    delete ui;
}

