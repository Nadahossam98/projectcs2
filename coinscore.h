#ifndef COINSCORE_H
#define COINSCORE_H

#include <QGraphicsTextItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

class CoinScore : public QGraphicsItemGroup  {
public:
    CoinScore(QGraphicsItem *parent = nullptr);
    void increase_score();
    int get_current_score();
private:
    int current_score;
    QGraphicsPixmapItem *coin_icon;
    QGraphicsTextItem *score_text;
};

#endif // COINSCORE_H
