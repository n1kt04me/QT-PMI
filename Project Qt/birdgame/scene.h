#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include "pillaritem.h"
#include <QTimer>

class Scene : public QGraphicsScene
{
    Q_OBJECT
public:
    Scene(QObject* parent = nullptr);

private:
    void setUpPillarTimer();
    QTimer*pillarTimer;

signals:

public slots:
};

#endif // SCENE_H
