#ifndef BIRDITEM_H
#define BIRDITEM_H

#include <QObject>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QPropertyAnimation>

class BirdItem : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    Q_PROPERTY (double rotation READ rotation WRITE setRotation)
    Q_PROPERTY (double y READ y WRITE setY )
public:

    explicit BirdItem(QPixmap pixmap);

    qreal rotation() const;
    void setRotation(qreal newRotation);

    qreal y() const;
    void setY(qreal newY);
    void rotateTo (const qreal &end, const int& duration, const QEasingCurve& curve);
    void shootUp();
    double getY();
signals:
private:
    enum WingPosition{Up, Middle, Down};
    void updatePixmap();

    WingPosition wingPosition;
    bool wingDirection; // 0:down , 1:up позиция крыльев
    qreal m_rotation;
    qreal m_y;
    QPropertyAnimation * yAnimation;
    QPropertyAnimation * rotationAnimation;
    qreal groundPosition;

};

#endif // BIRDITEM_H
