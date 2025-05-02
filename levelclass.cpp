#include "levelclass.h"

LevelClass::LevelClass(QGraphicsScene *gscene, QGraphicsPixmapItem *groundp, QGraphicsPixmapItem *cloudsp,
                       QGraphicsPixmapItem *cloudsp2, QGraphicsPixmapItem *cloudsp3):
    scene(gscene), ground(groundp), clouds(cloudsp), clouds2(cloudsp2), clouds3(cloudsp3)
{
}

void LevelClass::move_cloud(QGraphicsPixmapItem *clouds_img, int dx){
    clouds_img->setX(clouds_img->x() + dx);
    if (clouds_img->x() + clouds_img->boundingRect().width() < 0)
        clouds_img->setPos(scene->width(), rand() % 200);
    else if (clouds_img->x() > scene->width())
        clouds_img->setPos(-clouds_img->boundingRect().width(), rand() % 200);
}

void LevelClass::move_clouds(int dx){
    move_cloud(clouds, dx * 0.5);
    move_cloud(clouds2, dx);
    move_cloud(clouds3, dx * 1.2);
}
