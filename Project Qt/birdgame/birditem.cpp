#include "birditem.h"
#include <QTimer>

BirdItem::BirdItem(QPixmap pixmap):
    wingPosition(WingPosition::Up),
    wingDirection(0)
{
    setPixmap(pixmap);

    QTimer * birdWingsTimer = new QTimer(this);
    connect(birdWingsTimer,&QTimer::timeout,[=](){
        updatePixmap();
    });

    birdWingsTimer->start(80);

    groundPosition = scenePos ().y() + 200;

    //init new Aimation
    yAnimation = new QPropertyAnimation (this, "y", this);
    //set start value - begining animation
    yAnimation->setStartValue(scenePos().y());
    //set end value - where animation going to end
    yAnimation->setEndValue(groundPosition);
    //set animation direction
    yAnimation->setEasingCurve(QEasingCurve::InQuad);
    //set duration - how many times animation will be execute
    yAnimation->setDuration(1000);
    //run animation
    yAnimation->start();

    rotationAnimation = new QPropertyAnimation(this, "rotation",this);
    rotateTo(90,1200,QEasingCurve::InQuad);
}



void BirdItem::updatePixmap()
{
    if (wingPosition == WingPosition::Middle){

        if(wingDirection){
            setPixmap(QPixmap(":/images/bird_blue_up.png"));
            wingPosition = WingPosition::Up;
            wingDirection = 0;
        }else{
            setPixmap(QPixmap(":/images/bird_blue_down.png"));
            wingPosition = WingPosition::Down;
            wingDirection = 1;
        }
    }else{
        setPixmap(QPixmap(":/images/bird_blue_middle.png"));
        wingPosition = WingPosition::Middle;
    }
}

qreal BirdItem::rotation() const
{
    return m_rotation;
}

qreal BirdItem::y() const
{

    return m_y;
}

void BirdItem::setRotation(qreal newRotation)
{
    m_rotation = newRotation;
    QPointF c = boundingRect () .center () ;
    QTransform t;
    t.translate(c.x(), c.y());
    t.rotate(newRotation);
    t.translate(-c.x(), -c.y());
    setTransform(t);
}

void BirdItem::setY(qreal newY)
{
    moveBy(0,newY-m_y);
    m_y = newY;
}

void BirdItem::rotateTo(const qreal &end, const int &duration, const QEasingCurve &curve)
{
    rotationAnimation->setStartValue(rotation());
    rotationAnimation->setEndValue(end);
    rotationAnimation->setEasingCurve(curve);
    rotationAnimation->setDuration(duration);

    rotationAnimation->start();
}

void BirdItem::shootUp()
{
    yAnimation->stop();
    rotationAnimation->stop();

    double curPosy = getY();
    yAnimation->setStartValue(curPosy);
    yAnimation->setEndValue(curPosy - scene() -> sceneRect().height()/8);
    yAnimation->setEasingCurve(QEasingCurve::OutQuad);
    yAnimation->setDuration(285);
    yAnimation->start();

    rotateTo(-20, 200, QEasingCurve::OutCubic);

}
