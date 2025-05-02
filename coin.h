#ifndef COIN_H
#define COIN_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Coin : QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Coin(QGraphicsItem *parent = nullptr);
};

#endif // COIN_H
