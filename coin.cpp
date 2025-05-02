#include "coin.h"

Coin::Coin(QGraphicsItem *parent):
    QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/imgs/coin.png"));
}
