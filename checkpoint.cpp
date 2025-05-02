#include "checkpoint.h"

CheckPoint::CheckPoint(QGraphicsItem *parent):
    QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/imgs/checkpoint.png"));
}
