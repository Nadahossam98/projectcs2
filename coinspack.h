#ifndef COINSPACK_H
#define COINSPACK_H

#include <QGraphicsPixmapItem>
#include "coin.h"

class CoinsPack : public QGraphicsPixmapItem {
public:
    explicit CoinsPack(int numCoins, QGraphicsItem *parent = nullptr);
};

#endif // COINSPACK_H
