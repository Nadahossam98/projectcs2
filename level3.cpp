#include "level3.h"
#include "coin.h"
#include <cstdlib>

Level3::Level3(QGraphicsScene *gscene, QGraphicsPixmapItem *groundp, QGraphicsPixmapItem *cloudsp,
               QGraphicsPixmapItem *cloudsp2, QGraphicsPixmapItem *cloudsp3):
    LevelClass(gscene, groundp, cloudsp, cloudsp2, cloudsp3)
{
}

void Level3::update_scene(){
    int ground_level = this->scene->height() - ground->boundingRect().height();
    int coin_height = Coin().boundingRect().height();

    platform1 = new Platform(Platform::SHORT);
    platform1->setPos(200, ground_level - platform1->boundingRect().height() - 80);
    this->scene->addItem(platform1);

    cpack1 = new CoinsPack(5);
    cpack1->setPos(platform1->x() + 20, platform1->y() - coin_height - 10);
    this->scene->addItem(cpack1);

    platform2 = new Platform(Platform::LONG);
    platform2->setPos(600, ground_level - platform2->boundingRect().height() - 120);
    this->scene->addItem(platform2);

    spikes1 = new Spikes();
    spikes1->setPos(platform2->x() + 50, platform2->y() - spikes1->boundingRect().height() + 10);
    this->scene->addItem(spikes1);

    cpack2 = new CoinsPack(3);
    cpack2->setPos(platform2->x() + 200, platform2->y() - coin_height - 10);
    this->scene->addItem(cpack2);

    platform3 = new Platform(Platform::SHORT);
    platform3->setPos(1100, ground_level - platform3->boundingRect().height() - 80);
    this->scene->addItem(platform3);

    spikes2 = new Spikes();
    spikes2->setPos(platform3->x() + 15, platform3->y() - spikes2->boundingRect().height());
    this->scene->addItem(spikes2);

    cpack3 = new CoinsPack(8);
    cpack3->setPos(spikes2->x() + spikes2->boundingRect().width() + 10, platform3->y() - coin_height - 10);
    this->scene->addItem(cpack3);

    platform4 = new Platform(Platform::LONG);
    platform4->setPos(1600, ground_level - platform4->boundingRect().height() - 100);
    this->scene->addItem(platform4);

    cpack4 = new CoinsPack(4);
    cpack4->setPos(platform4->x() + 50, platform4->y() - coin_height - 10);
    this->scene->addItem(cpack4);

    spikes3 = new Spikes();
    spikes3->setPos(platform4->x() + 150, platform4->y() - spikes3->boundingRect().height());
    this->scene->addItem(spikes3);

    // Add books packs
    bpack1 = new BooksPack(6);
    bpack1->setPos(900, ground_level - coin_height - 10);
    this->scene->addItem(bpack1);

    bpack2 = new BooksPack(9);
    bpack2->setPos(1300, ground_level - platform3->boundingRect().height() - 120);
    this->scene->addItem(bpack2);

    // Add enemies
    enemy1 = new Enemy1();
    enemy1->setPos(500, ground_level - enemy1->boundingRect().height() + 5);
    this->scene->addItem(enemy1);

    enemy2 = new Enemy1();
    enemy2->setPos(1250, ground_level - enemy2->boundingRect().height() + 5);
    this->scene->addItem(enemy2);

    enemy3 = new Enemy1();
    enemy3->setPos(1700, ground_level - enemy3->boundingRect().height() + 5);
    this->scene->addItem(enemy3);

    checkpoint = new CheckPoint();
    checkpoint->setPos(2100, ground_level - checkpoint->boundingRect().height());
    this->scene->addItem(checkpoint);
}

void Level3::move(int dx){
    if (ground->x() + dx > 0 || ground->x() + ground->boundingRect().width() + dx < this->scene->width())
        return;

    move_clouds(dx);

    ground->setX(ground->x() + dx);
    cpack1->setX(cpack1->x() + dx);
    platform1->setX(platform1->x() + dx);
    cpack2->setX(cpack2->x() + dx);
    platform2->setX(platform2->x() + dx);
    spikes1->setX(spikes1->x() + dx);
    cpack3->setX(cpack3->x() + dx);
    platform3->setX(platform3->x() + dx);
    spikes2->setX(spikes2->x() + dx);
    cpack4->setX(cpack4->x() + dx);
    platform4->setX(platform4->x() + dx);
    spikes3->setX(spikes3->x() + dx);

    // Move books packs
    bpack1->setX(bpack1->x() + dx);
    bpack2->setX(bpack2->x() + dx);

    // Move enemies
    enemy1->setX(enemy1->x() + dx);
    enemy2->setX(enemy2->x() + dx);
    enemy3->setX(enemy3->x() + dx);

    checkpoint->setX(checkpoint->x() + dx);
}

void Level3::remove_items(){
    scene->removeItem(cpack1);
    delete cpack1;
    scene->removeItem(platform1);
    delete platform1;
    scene->removeItem(cpack2);
    delete cpack2;
    scene->removeItem(platform2);
    delete platform2;
    scene->removeItem(spikes1);
    delete spikes1;
    scene->removeItem(cpack3);
    delete cpack3;
    scene->removeItem(platform3);
    delete platform3;
    scene->removeItem(spikes2);
    delete spikes2;
    scene->removeItem(cpack4);
    delete cpack4;
    scene->removeItem(platform4);
    delete platform4;
    scene->removeItem(spikes3);
    delete spikes3;

    // Remove books packs
    scene->removeItem(bpack1);
    delete bpack1;
    scene->removeItem(bpack2);
    delete bpack2;

    // Remove enemies
    scene->removeItem(enemy1);
    delete enemy1;
    scene->removeItem(enemy2);
    delete enemy2;
    scene->removeItem(enemy3);
    delete enemy3;

    scene->removeItem(checkpoint);
    delete checkpoint;
}
