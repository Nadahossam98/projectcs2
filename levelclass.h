#ifndef LEVELCLASS_H
#define LEVELCLASS_H

#include <QGraphicsScene>
#include "checkpoint.h"

class LevelClass
{
public:
    LevelClass(QGraphicsScene *, QGraphicsPixmapItem *, QGraphicsPixmapItem *,
               QGraphicsPixmapItem *, QGraphicsPixmapItem *);
    void move_cloud(QGraphicsPixmapItem *, int);
    void move_clouds(int);
    virtual void update_scene() = 0;
    virtual void remove_items() = 0;
    virtual void move(int) = 0;

    QGraphicsScene *scene;
    QGraphicsPixmapItem *ground;
    QGraphicsPixmapItem *clouds, *clouds2, *clouds3;
    CheckPoint *checkpoint;
};

#endif // LEVELCLASS_H
