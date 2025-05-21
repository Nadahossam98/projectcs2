#include "level5.h"
#include "coin.h"

Level5::Level5(QGraphicsScene *gscene, QGraphicsPixmapItem *groundp, QGraphicsPixmapItem *cloudsp,
               QGraphicsPixmapItem *cloudsp2, QGraphicsPixmapItem *cloudsp3):
    LevelClass(gscene, groundp, cloudsp, cloudsp2, cloudsp3)
{
}

void Level5::update_scene()
{
    int ground_level = this->scene->height() - ground->boundingRect().height();
    int coin_height = Coin().boundingRect().height();

    // Platforms
    platform1 = new Platform(Platform::SHORT);
    platform1->setPos(200, ground_level - platform1->boundingRect().height() - 60);
    scene->addItem(platform1);

    platform2 = new Platform(Platform::LONG);
    platform2->setPos(platform1->x() + 300, platform1->y() - 100);
    scene->addItem(platform2);

    platform3 = new Platform(Platform::SHORT);
    platform3->setPos(platform2->x() + 400, platform2->y() - 150);
    scene->addItem(platform3);

    platform4 = new Platform(Platform::SHORT);
    platform4->setPos(platform3->x() + 250, platform3->y() + 50);
    scene->addItem(platform4);

    platform5 = new Platform(Platform::SHORT);
    platform5->setPos(platform4->x() + 250, platform4->y() - 50);
    scene->addItem(platform5);

    platform6 = new Platform(Platform::SHORT);
    platform6->setPos(platform5->x() + 250, platform5->y() + 50);
    scene->addItem(platform6);

    platform7 = new Platform(Platform::LONG);
    platform7->setPos(platform6->x() + 300, ground_level - platform7->boundingRect().height() - 100);
    scene->addItem(platform7);

    // Spikes
    spikes1 = new Spikes();
    spikes1->setPos(platform1->x() + 100, ground_level - spikes1->boundingRect().height() + 5);
    scene->addItem(spikes1);

    spikes2 = new Spikes();
    spikes2->setPos(platform2->x() + 100, platform2->y() - spikes2->boundingRect().height() + 5);
    scene->addItem(spikes2);

    spikes3 = new Spikes();
    spikes3->setPos(platform3->x() + 30, platform3->y() - spikes3->boundingRect().height() + 5);
    scene->addItem(spikes3);

    spikes4 = new Spikes();
    spikes4->setPos(platform4->x() + 40, platform4->y() - spikes4->boundingRect().height() + 5);
    scene->addItem(spikes4);

    spikes5 = new Spikes();
    spikes5->setPos(platform5->x() + 40, platform5->y() - spikes5->boundingRect().height() + 5);
    scene->addItem(spikes5);

    spikes6 = new Spikes();
    spikes6->setPos(platform6->x() + 40, platform6->y() - spikes6->boundingRect().height() + 5);
    scene->addItem(spikes6);

    spikes7 = new Spikes();
    spikes7->setPos(platform7->x() + 50, platform7->y() - spikes7->boundingRect().height() + 5);
    scene->addItem(spikes7);

    spikes8 = new Spikes();
    spikes8->setPos(platform7->x() + 100, platform7->y() - spikes8->boundingRect().height() + 5);
    scene->addItem(spikes8);

    // Coins Packs
    coinpack1 = new CoinsPack(3);
    coinpack1->setPos(platform1->x() + 30, platform1->y() - coin_height - 3);
    scene->addItem(coinpack1);

    coinpack2 = new CoinsPack(5);
    coinpack2->setPos(platform2->x() + 220, platform2->y() - coin_height - 3);
    scene->addItem(coinpack2);

    coinpack3 = new CoinsPack(4);
    coinpack3->setPos(platform3->x() + 120, platform3->y() - coin_height - 3);
    scene->addItem(coinpack3);

    coinpack4 = new CoinsPack(3);
    coinpack4->setPos(platform4->x() + 120, platform4->y() - coin_height - 3);
    scene->addItem(coinpack4);

    coinpack5 = new CoinsPack(3);
    coinpack5->setPos(platform5->x() + 120, platform5->y() - coin_height - 3);
    scene->addItem(coinpack5);

    coinpack6 = new CoinsPack(3);
    coinpack6->setPos(platform6->x() + 120, platform6->y() - coin_height - 3);
    scene->addItem(coinpack6);

    coinpack7 = new CoinsPack(10);
    coinpack7->setPos(platform7->x() + 200, platform7->y() - coin_height - 3);
    scene->addItem(coinpack7);

    // Enemies on the ground, spaced further apart
    enemy1 = new Enemy1();
    enemy1->setPos(300, ground_level - enemy1->boundingRect().height());
    scene->addItem(enemy1);

    enemy2 = new Enemy1();
    enemy2->setPos(650, ground_level - enemy2->boundingRect().height());  // +350 from enemy1
    scene->addItem(enemy2);

    enemy3 = new Enemy1();
    enemy3->setPos(1000, ground_level - enemy3->boundingRect().height());  // +350 from enemy2
    scene->addItem(enemy3);

    enemy4 = new Enemy1();
    enemy4->setPos(1350, ground_level - enemy4->boundingRect().height());  // +350 from enemy3
    scene->addItem(enemy4);

    enemy5 = new Enemy1();
    enemy5->setPos(1700, ground_level - enemy5->boundingRect().height());  // +350 from enemy4
    scene->addItem(enemy5);


    // Books packs near enemies
    bpack1 = new BooksPack(4);
    bpack1->setPos(enemy1->x() + 50, ground_level - bpack1->boundingRect().height());
    scene->addItem(bpack1);

    bpack2 = new BooksPack(3);
    bpack2->setPos(enemy2->x() + 50, ground_level - bpack2->boundingRect().height());
    scene->addItem(bpack2);

    bpack3 = new BooksPack(5);
    bpack3->setPos(enemy3->x() + 50, ground_level - bpack3->boundingRect().height());
    scene->addItem(bpack3);

    bpack4 = new BooksPack(3);
    bpack4->setPos(enemy4->x() + 50, ground_level - bpack4->boundingRect().height());
    scene->addItem(bpack4);

    bpack5 = new BooksPack(4);
    bpack5->setPos(enemy5->x() + 50, ground_level - bpack5->boundingRect().height());
    scene->addItem(bpack5);

    // Checkpoint
    checkpoint = new CheckPoint();
    checkpoint->setPos(2500, ground_level - checkpoint->boundingRect().height() + 5);
    this->scene->addItem(checkpoint);
}

void Level5::move(int dx)
{
    if (ground->x() + dx > 0 || ground->x() + ground->boundingRect().width() + dx < scene->width())
        return;

    move_clouds(dx);

    ground->setX(ground->x() + dx);

    platform1->setX(platform1->x() + dx);
    platform2->setX(platform2->x() + dx);
    platform3->setX(platform3->x() + dx);
    platform4->setX(platform4->x() + dx);
    platform5->setX(platform5->x() + dx);
    platform6->setX(platform6->x() + dx);
    platform7->setX(platform7->x() + dx);

    spikes1->setX(spikes1->x() + dx);
    spikes2->setX(spikes2->x() + dx);
    spikes3->setX(spikes3->x() + dx);
    spikes4->setX(spikes4->x() + dx);
    spikes5->setX(spikes5->x() + dx);
    spikes6->setX(spikes6->x() + dx);
    spikes7->setX(spikes7->x() + dx);
    spikes8->setX(spikes8->x() + dx);

    coinpack1->setX(coinpack1->x() + dx);
    coinpack2->setX(coinpack2->x() + dx);
    coinpack3->setX(coinpack3->x() + dx);
    coinpack4->setX(coinpack4->x() + dx);
    coinpack5->setX(coinpack5->x() + dx);
    coinpack6->setX(coinpack6->x() + dx);
    coinpack7->setX(coinpack7->x() + dx);

    enemy1->setX(enemy1->x() + dx);
    enemy2->setX(enemy2->x() + dx);
    enemy3->setX(enemy3->x() + dx);
    enemy4->setX(enemy4->x() + dx);
    enemy5->setX(enemy5->x() + dx);

    bpack1->setX(bpack1->x() + dx);
    bpack2->setX(bpack2->x() + dx);
    bpack3->setX(bpack3->x() + dx);
    bpack4->setX(bpack4->x() + dx);
    bpack5->setX(bpack5->x() + dx);

    checkpoint->setX(checkpoint->x() + dx);
}

void Level5::remove_items()
{
    // Remove platforms
    scene->removeItem(platform1);
    delete platform1;
    scene->removeItem(platform2);
    delete platform2;
    scene->removeItem(platform3);
    delete platform3;
    scene->removeItem(platform4);
    delete platform4;
    scene->removeItem(platform5);
    delete platform5;
    scene->removeItem(platform6);
    delete platform6;
    scene->removeItem(platform7);
    delete platform7;

    // Remove spikes
    scene->removeItem(spikes1);
    delete spikes1;
    scene->removeItem(spikes2);
    delete spikes2;
    scene->removeItem(spikes3);
    delete spikes3;
    scene->removeItem(spikes4);
    delete spikes4;
    scene->removeItem(spikes5);
    delete spikes5;
    scene->removeItem(spikes6);
    delete spikes6;
    scene->removeItem(spikes7);
    delete spikes7;
    scene->removeItem(spikes8);
    delete spikes8;

    // Remove coin packs
    scene->removeItem(coinpack1);
    delete coinpack1;
    scene->removeItem(coinpack2);
    delete coinpack2;
    scene->removeItem(coinpack3);
    delete coinpack3;
    scene->removeItem(coinpack4);
    delete coinpack4;
    scene->removeItem(coinpack5);
    delete coinpack5;
    scene->removeItem(coinpack6);
    delete coinpack6;
    scene->removeItem(coinpack7);
    delete coinpack7;

    // Remove enemies
    scene->removeItem(enemy1);
    delete enemy1;
    scene->removeItem(enemy2);
    delete enemy2;
    scene->removeItem(enemy3);
    delete enemy3;
    scene->removeItem(enemy4);
    delete enemy4;
    scene->removeItem(enemy5);
    delete enemy5;

    // Remove books packs
    scene->removeItem(bpack1);
    delete bpack1;
    scene->removeItem(bpack2);
    delete bpack2;
    scene->removeItem(bpack3);
    delete bpack3;
    scene->removeItem(bpack4);
    delete bpack4;
    scene->removeItem(bpack5);
    delete bpack5;

    // Remove checkpoint
    scene->removeItem(checkpoint);
    delete checkpoint;
}
