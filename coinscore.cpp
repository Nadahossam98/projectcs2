#include "coinscore.h"
#include <QFont>
#include <QColor>

CoinScore::CoinScore(QGraphicsItem *parent)
    : QGraphicsItemGroup(parent), current_score(0)
{
    score_text = new QGraphicsTextItem("×0");
    score_text->setDefaultTextColor(QColor(255, 165, 0));
    score_text->setFont(QFont("Verdana", 22));
    addToGroup(score_text);

    coin_icon = new QGraphicsPixmapItem(QPixmap(":/imgs/coin.png"));
    coin_icon->setPos(0, 4);
    addToGroup(coin_icon);

    score_text->setPos(coin_icon->boundingRect().width() + 4, -2);
}

void CoinScore::increase_score() {
    ++current_score;
    QString updated_score = QString("×") + QString::number(current_score);
    score_text->setPlainText(updated_score);
}

int CoinScore::get_current_score() {
    return current_score;
}
