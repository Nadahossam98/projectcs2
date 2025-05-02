#include "level1.h"
#include "coin.h"
#include "book.h"
#include <cstdlib>

Level1::Level1(QGraphicsScene *gscene, QGraphicsPixmapItem *groundp, QGraphicsPixmapItem *cloudsp,
                                       QGraphicsPixmapItem *cloudsp2, QGraphicsPixmapItem *cloudsp3):
    LevelClass(gscene, groundp, cloudsp, cloudsp2, cloudsp3)
{
}

void Level1::update_scene(){
    int ground_level = this->scene->height() - ground->boundingRect().height();
    int coin_height = Coin().boundingRect().height();
    int book_height = Book().boundingRect().height();

    cpack1 = new CoinsPack(3);
    this->scene->addItem(cpack1);
    cpack1->setPos(100, ground_level - coin_height - 3);

    bpack1 = new BooksPack(3);
    this->scene->addItem(bpack1);
    bpack1->setPos(250, ground_level - book_height - 3);

    platform1 = new Platform(Platform::SHORT);
    platform1->setPos(250, ground_level - platform1->boundingRect().height() - 70);
    this->scene->addItem(platform1);

    cpack2 = new CoinsPack(10);
    cpack2->setPos(platform1->x() + 30, platform1->y() - coin_height - 3);
    this->scene->addItem(cpack2);

    spikes1 = new Spikes();
    spikes1->setPos(750, ground_level - spikes1->boundingRect().height() + 2);
    this->scene->addItem(spikes1);

    fakebook1 = new FakeBook();
    fakebook1->setPos(350, ground_level - fakebook1->boundingRect().height() + 2);
    this->scene->addItem(fakebook1);

    enemy1 = new Enemy1();
    enemy1->setPos(450, ground_level - enemy1->boundingRect().height() + 2);
    this->scene->addItem(enemy1);

    cpack3 = new CoinsPack(3);
    cpack3->setPos(spikes1->x() + 5, spikes1->y() - coin_height - 120);
    this->scene->addItem(cpack3);

    platform2 = new Platform(Platform::LONG);
    platform2->setPos(1100, ground_level - platform2->boundingRect().height() - 70);
    this->scene->addItem(platform2);

    cpack4 = new CoinsPack(3);
    cpack4->setPos(platform2->x() + 30, platform2->y() - coin_height - 3);
    this->scene->addItem(cpack4);

    spikes2 = new Spikes();
    spikes2->setPos(platform2->x() + (platform2->boundingRect().width() - spikes2->boundingRect().width()) / 2,
                    platform2->y() - spikes2->boundingRect().height() + 2);
    this->scene->addItem(spikes2);

    cpack5 = new CoinsPack(3);
    cpack5->setPos(platform2->x() + platform2->boundingRect().width() - 100, platform2->y() - coin_height - 3);
    this->scene->addItem(cpack5);

    platform3 = new Platform(Platform::SHORT);
    platform3->setPos(platform2->x() + 500, platform2->y() - platform3->boundingRect().height() - 70);
    this->scene->addItem(platform3);

    cpack6 = new CoinsPack(10);
    cpack6->setPos(platform3->x() + 30, platform3->y() - coin_height - 3);
    this->scene->addItem(cpack6);

    spikes3 = new Spikes();
    spikes3->setPos(platform3->x() + 500, spikes1->y());
    this->scene->addItem(spikes3);

    cpack7 = new CoinsPack(3);
    cpack7->setPos(spikes3->x() + 5, cpack3->y());
    this->scene->addItem(cpack7);

    cpack8 = new CoinsPack(15);
    this->scene->addItem(cpack8);
    cpack8->setPos(2400, cpack1->y());

    this->checkpoint = new CheckPoint();
    int checkpoint_x = 3000;
    int checkpoint_y = ground_level - this->checkpoint->boundingRect().height() + 5;
    this->checkpoint->setPos(checkpoint_x, checkpoint_y);
    this->scene->addItem(this->checkpoint);
}

void Level1::move(int dx){
    if (ground->x() + dx > 0 || ground->x() + ground->boundingRect().width() + dx < this->scene->width())
        return;

    move_clouds(dx);

    ground->setX(ground->x() + dx);
    enemy1->setX(enemy1->x() + dx);
    cpack1->setX(cpack1->x() + dx);
    bpack1->setX(bpack1->x() + dx);
    platform1->setX(platform1->x() + dx);
    cpack2->setX(cpack2->x() + dx);
    spikes1->setX(spikes1->x() + dx);
    fakebook1->setX(fakebook1->x() + dx);
    cpack3->setX(cpack3->x() + dx);
    platform2->setX(platform2->x() + dx);
    cpack4->setX(cpack4->x() + dx);
    spikes2->setX(spikes2->x() + dx);
    cpack5->setX(cpack5->x() + dx);
    platform3->setX(platform3->x() + dx);
    cpack6->setX(cpack6->x() + dx);
    spikes3->setX(spikes3->x() + dx);
    cpack7->setX(cpack7->x() + dx);
    cpack8->setX(cpack8->x() + dx);
    checkpoint->setX(checkpoint->x() + dx);
}

void Level1::remove_items(){
    scene->removeItem(cpack1);
    delete cpack1;
    scene->removeItem(bpack1);
    delete bpack1;
    scene->removeItem(platform1);
    delete platform1;
    scene->removeItem(cpack2);
    delete cpack2;
    scene->removeItem(spikes1);
    delete spikes1;
    //scene->removeItem(fakebook1); // this causes crash since its already deleted on collision in player since its a single not a pack
    //delete fakebook1;
    scene->removeItem(enemy1); // this enemy moves with the screen by accident he keeps following you so its a cool feature (not killable)
    delete enemy1;
    scene->removeItem(cpack3);
    delete cpack3;
    scene->removeItem(platform2);
    delete platform2;
    scene->removeItem(cpack4);
    delete cpack4;
    scene->removeItem(spikes2);
    delete spikes2;
    scene->removeItem(cpack5);
    delete cpack5;
    scene->removeItem(platform3);
    delete platform3;
    scene->removeItem(cpack6);
    delete cpack6;
    scene->removeItem(spikes3);
    delete spikes3;
    scene->removeItem(cpack7);
    delete cpack7;
    scene->removeItem(cpack8);
    delete cpack8;
    scene->removeItem(checkpoint);
    delete checkpoint;
}
