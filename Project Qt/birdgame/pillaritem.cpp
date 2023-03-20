#include "pillaritem.h"
#include <QDebug>
#include <QGraphicsScene>
#include <QRandomGenerator>

PillarItem::PillarItem():

    TopPillar(new QGraphicsPixmapItem(QPixmap(":/images/pillar.png"))),
    BottomPillar(new QGraphicsPixmapItem(QPixmap(":/images/pillar.png")))

{
    TopPillar->setPos(QPointF(0,0) - QPointF(TopPillar->boundingRect().width()/2,
                                             TopPillar->boundingRect().height()+90));

    BottomPillar->setPos(QPointF(0,0) - QPointF(BottomPillar->boundingRect().width()/2,
                                                0));
    addToGroup(TopPillar);
    addToGroup(BottomPillar);

    yPos = QRandomGenerator::global()->bounded(150);
    int xRandomizer = QRandomGenerator::global()->bounded(200);
    setPos(QPoint(0,0) + QPoint(260 + xRandomizer,yPos));

    xAnimation = new QPropertyAnimation(this,"x",this);
    xAnimation->setStartValue(260 + xRandomizer);
    xAnimation->setEndValue(-260);
    xAnimation->setEasingCurve(QEasingCurve::Linear);
    xAnimation->setDuration(1500);
    xAnimation->start();

    connect (xAnimation,&QPropertyAnimation::finished,[=](){
        qDebug() << "Animation finished";
        scene()->removeItem (this) ;
        delete this;});


}

PillarItem::~PillarItem()
{
    qDebug() << "Deleting PiallarItem";
}

double PillarItem::x() const
{
    return m_x;
}

void PillarItem::setX(double newX)
{
    m_x = newX;
    setPos(QPointF(0,0) + QPointF(newX, yPos));
    qDebug()<<"PillarItem instance position: "<<m_x;
}
