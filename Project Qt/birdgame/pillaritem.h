#ifndef PILLARITEM_H
#define PILLARITEM_H
#include <QPropertyAnimation>
#include <QGraphicsItemGroup>
#include <QGraphicsPixmapItem>
#include <QRandomGenerator>

class PillarItem :  public QObject, public QGraphicsItemGroup
{
    Q_OBJECT
    Q_PROPERTY(double x READ x WRITE setX)
public:
    PillarItem();
    ~PillarItem();
    double x() const;
    void setX(double newX);

private:
 QGraphicsPixmapItem * TopPillar;
 QGraphicsPixmapItem * BottomPillar;
 QPropertyAnimation* xAnimation;
 int yPos;
 int scene();
 double m_x;
};
#endif // PILLARITEM_H
