#include "game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QBrush>
#include <QGraphicsPixmapItem>
#include <QImage>
#include "level1.h"
#include <QApplication>

Game::Game(QWidget *parent):
    QGraphicsView(parent), current_level(1)
{
    const int SCREEN_WIDTH = 1000;
    const int SCREEN_HEIGHT = 650;
    game_scene = new QGraphicsScene();
    game_scene->setSceneRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    setBackgroundBrush(QBrush(QImage(":/imgs/background1.jpg")));

    setScene(game_scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(SCREEN_WIDTH, SCREEN_HEIGHT);

    background_ground = new QGraphicsPixmapItem(QPixmap(":/imgs/full-ground-stone.png"));
    background_ground->setPos(0, SCREEN_HEIGHT - background_ground->boundingRect().height());
    game_scene->addItem(background_ground);

    cloud_1 = new QGraphicsPixmapItem(QPixmap(":/imgs/clouds.png"));
    cloud_1->setPos(130, 50);
    game_scene->addItem(cloud_1);

    cloud_2 = new QGraphicsPixmapItem(QPixmap(":/imgs/clouds2.png"));
    cloud_2->setPos(200, 0);
    game_scene->addItem(cloud_2);

    cloud_3 = new QGraphicsPixmapItem(QPixmap(":/imgs/clouds3.png"));
    cloud_3->setPos(600, 150);
    game_scene->addItem(cloud_3);

    int ground_position = background_ground->y();

    main_player = new Player();
    main_player->setPos(0, ground_position - main_player->boundingRect().height() + 5);
    main_player->setFlag(QGraphicsItem::ItemIsFocusable);
    main_player->setFocus();
    game_scene->addItem(main_player);

    player_health = new Health(5);
    player_health->setPos(10, 10);
    game_scene->addItem(player_health);
    main_player->setHealth(player_health);

    player_coin_score = new CoinScore();
    game_scene->addItem(player_coin_score);
    player_coin_score->setPos(5, player_health->y() + player_health->boundingRect().height() + 10);
    main_player->setCoinScore(player_coin_score);

    player_book_score = new BookScore();
    game_scene->addItem(player_book_score);
    player_book_score->setPos(5, player_coin_score->y() + player_coin_score->boundingRect().height() + 10);
    main_player->setBookScore(player_book_score);

    level_display = new QGraphicsTextItem("Level: 1");
    level_display->setFont(QFont("Calibri", 24));
    level_display->setPos(10, player_book_score->y() + player_book_score->boundingRect().height() + 20);
    game_scene->addItem(level_display);

    current_level_instance = new Level1(game_scene, background_ground, cloud_1, cloud_2, cloud_3);
    current_level_instance->update_scene();
    main_player->setLevel(current_level_instance);
}

void Game::on_level_advanced() {
    ++current_level;
    level_display->setPlainText("Level: " + QString::number(current_level));

    // Remove level items
    current_level_instance->remove_items();
    const int SCREEN_HEIGHT = 650;

    background_ground->setPos(0, SCREEN_HEIGHT - background_ground->boundingRect().height());
    cloud_1->setPos(130, 50);
    cloud_2->setPos(200, 0);
    cloud_3->setPos(600, 150);
    main_player->setPos(0, background_ground->y() - main_player->boundingRect().height() + 5);
    main_player->setFocus();

    // Close the game immediately after Level 1 finishes
    QApplication::quit();  // This will close the game
}
