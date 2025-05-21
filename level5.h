#ifndef LEVEL5_H
#define LEVEL5_H

#include "levelclass.h"
#include "spikes.h"
#include "coinspack.h"
#include "bookspack.h"
#include "platform.h"
#include "enemy1.h"
#include "checkpoint.h"

class Level5 : public LevelClass
{
public:
    Level5(QGraphicsScene *scene, QGraphicsPixmapItem *groundp, QGraphicsPixmapItem *cloudsp,
           QGraphicsPixmapItem *cloudsp2, QGraphicsPixmapItem *cloudsp3);

    void update_scene() override;
    void remove_items() override;
    void move(int dx) override;

    // Platforms
    Platform *platform1, *platform2, *platform3, *platform4, *platform5, *platform6, *platform7;

    // Spikes
    Spikes *spikes1, *spikes2, *spikes3, *spikes4, *spikes5, *spikes6, *spikes7, *spikes8;

    // Coins
    CoinsPack *coinpack1, *coinpack2, *coinpack3, *coinpack4, *coinpack5, *coinpack6, *coinpack7;

    // Enemies
    Enemy1 *enemy1, *enemy2, *enemy3, *enemy4, *enemy5;

    // Books Packs
    BooksPack *bpack1, *bpack2, *bpack3, *bpack4, *bpack5;

    // Checkpoint
    CheckPoint *checkpoint;
};

#endif // LEVEL5_H
