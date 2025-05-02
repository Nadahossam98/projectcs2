#include "coinspack.h"

CoinsPack::CoinsPack(int numCoins, QGraphicsItem *parent)
    : QGraphicsPixmapItem(parent) {
    for (int i = 0; i < numCoins; ++i) {
        Coin *coin = new Coin(this);
        int sep = coin->boundingRect().width() - 17;
        coin->setPos(i * sep, 0);
    }
}
