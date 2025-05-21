#include "level2.h"
#include "coin.h"
#include <cstdlib>

Level2::Level2(QGraphicsScene *gscene, QGraphicsPixmapItem *groundp, QGraphicsPixmapItem *cloudsp,
               QGraphicsPixmapItem *cloudsp2, QGraphicsPixmapItem *cloudsp3):
    LevelClass(gscene, groundp, cloudsp, cloudsp2, cloudsp3)
{
}

void Level2::update_scene(){
    int ground_level = this->scene->height() - ground->boundingRect().height();
    int coin_height = Coin().boundingRect().height();

    // Spikes and coins as before
    spikes1 = new Spikes();
    spikes1->setPos(300, ground_level - spikes1->boundingRect().height() + 2);
    this->scene->addItem(spikes1);

    cpack1 = new CoinsPack(3);
    cpack1->setPos(spikes1->x() + 5, spikes1->y() - coin_height - 120);
    this->scene->addItem(cpack1);

    spikes2 = new Spikes();
    spikes2->setPos(550, ground_level - spikes2->boundingRect().height() + 2);
    this->scene->addItem(spikes2);

    cpack2 = new CoinsPack(3);
    cpack2->setPos(spikes2->x() + 5, spikes2->y() - coin_height - 120);
    this->scene->addItem(cpack2);

    spikes3 = new Spikes();
    spikes3->setPos(800, ground_level - spikes3->boundingRect().height() + 2);
    this->scene->addItem(spikes3);

    cpack3 = new CoinsPack(3);
    cpack3->setPos(spikes3->x() + 5, spikes3->y() - coin_height - 120);
    this->scene->addItem(cpack3);

    spikes4 = new Spikes();
    spikes4->setPos(1050, ground_level - spikes4->boundingRect().height() + 2);
    this->scene->addItem(spikes4);

    cpack4 = new CoinsPack(3);
    cpack4->setPos(spikes4->x() + 5, spikes4->y() - coin_height - 120);
    this->scene->addItem(cpack4);

    cpack5 = new CoinsPack(10);
    cpack5->setPos(1400, ground_level - coin_height - 3);
    this->scene->addItem(cpack5);

    platform1 = new Platform(Platform::LONG);
    platform1->setPos(2000, ground_level - platform1->boundingRect().height() - 100);
    this->scene->addItem(platform1);

    cpack6 = new CoinsPack(20);
    cpack6->setPos(platform1->x() + 30, platform1->y() - coin_height - 3);
    this->scene->addItem(cpack6);

    spikes5 = new Spikes();
    spikes5->setPos(2800, ground_level - spikes5->boundingRect().height() + 2);
    this->scene->addItem(spikes5);

    cpack7 = new CoinsPack(3);
    cpack7->setPos(spikes5->x() + 5, spikes5->y() - coin_height - 120);
    this->scene->addItem(cpack7);

    cpack8 = new CoinsPack(5);
    cpack8->setPos(3200, ground_level - coin_height - 3);
    this->scene->addItem(cpack8);

    // New BooksPacks added
    bpack1 = new BooksPack(5);  // assuming constructor param similar to CoinsPack
    bpack1->setPos(1600, ground_level - coin_height - 3);
    this->scene->addItem(bpack1);

    bpack2 = new BooksPack(7);
    bpack2->setPos(2300, ground_level - platform1->boundingRect().height() - 150);
    this->scene->addItem(bpack2);

    // New enemies added
    enemy1 = new Enemy1();
    enemy1->setPos(1200, ground_level - enemy1->boundingRect().height() + 5);
    this->scene->addItem(enemy1);

    enemy2 = new Enemy1();
    enemy2->setPos(2500, ground_level - enemy2->boundingRect().height() + 5);
    this->scene->addItem(enemy2);

    this->checkpoint = new CheckPoint();
    int checkpoint_x = 3500;
    int checkpoint_y = ground_level - this->checkpoint->boundingRect().height() + 5;
    this->checkpoint->setPos(checkpoint_x, checkpoint_y);
    this->scene->addItem(this->checkpoint);
}

void Level2::move(int dx){
    if (ground->x() + dx > 0 || ground->x() + ground->boundingRect().width() + dx < this->scene->width())
        return;

    move_clouds(dx);

    ground->setX(ground->x() + dx);

    // Move all items by dx
    cpack1->setX(cpack1->x() + dx);
    platform1->setX(platform1->x() + dx);
    cpack2->setX(cpack2->x() + dx);
    spikes1->setX(spikes1->x() + dx);
    cpack3->setX(cpack3->x() + dx);
    cpack4->setX(cpack4->x() + dx);
    spikes2->setX(spikes2->x() + dx);
    cpack5->setX(cpack5->x() + dx);
    cpack6->setX(cpack6->x() + dx);
    spikes3->setX(spikes3->x() + dx);
    spikes4->setX(spikes4->x() + dx);
    spikes5->setX(spikes5->x() + dx);
    cpack7->setX(cpack7->x() + dx);
    cpack8->setX(cpack8->x() + dx);

    bpack1->setX(bpack1->x() + dx);
    bpack2->setX(bpack2->x() + dx);

    enemy1->setX(enemy1->x() + dx);
    enemy2->setX(enemy2->x() + dx);

    checkpoint->setX(checkpoint->x() + dx);
}

void Level2::remove_items(){
    scene->removeItem(cpack1);
    delete cpack1;
    scene->removeItem(platform1);
    delete platform1;
    scene->removeItem(cpack2);
    delete cpack2;
    scene->removeItem(spikes1);
    delete spikes1;
    scene->removeItem(cpack3);
    delete cpack3;
    scene->removeItem(spikes4);
    delete spikes4;
    scene->removeItem(cpack4);
    delete cpack4;
    scene->removeItem(spikes2);
    delete spikes2;
    scene->removeItem(cpack5);
    delete cpack5;
    scene->removeItem(spikes5);
    delete spikes5;
    scene->removeItem(cpack6);
    delete cpack6;
    scene->removeItem(spikes3);
    delete spikes3;
    scene->removeItem(cpack7);
    delete cpack7;
    scene->removeItem(cpack8);
    delete cpack8;

    scene->removeItem(bpack1);
    delete bpack1;

    scene->removeItem(bpack2);
    delete bpack2;

    scene->removeItem(enemy1);
    delete enemy1;

    scene->removeItem(enemy2);
    delete enemy2;

    scene->removeItem(checkpoint);
    delete checkpoint;
}
