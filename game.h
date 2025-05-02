#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "player.h"
#include "health.h"
#include "coinscore.h"
#include "bookscore.h"
#include "levelclass.h"

class Game: public QGraphicsView {
public:
    Game(QWidget *parent = nullptr);
private slots:
    void on_level_advanced();
private:
    QGraphicsScene *game_scene;
    QGraphicsPixmapItem *background_ground;
    QGraphicsPixmapItem *cloud_1, *cloud_2, *cloud_3;
    Player *main_player;
    Health *player_health;
    CoinScore *player_coin_score;
    BookScore *player_book_score;
    QGraphicsTextItem *level_display;
    int current_level;
    LevelClass *current_level_instance;
};

#endif // GAME_H
