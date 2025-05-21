#include "bullet.h"
#include "enemy1.h"
#include <QGraphicsScene>
#include <QTimer>

Bullet::Bullet(bool facingLeft, QGraphicsItem *parent)
    : QObject(), QGraphicsPixmapItem(parent), facingLeft(facingLeft), speed(15)
{
    if (facingLeft) {
        setPixmap(QPixmap(":/imgs/reversed-bullet.png").scaled(20, 10));
    } else {
        setPixmap(QPixmap(":/imgs/bullet.png").scaled(20, 10));
    }

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Bullet::move);
    timer->start(30);
}

void Bullet::move() {
    if (facingLeft) {
        setX(x() - speed);
    } else {
        setX(x() + speed);
    }

    if (!scene()) return;

    // Remove bullet if out of scene bounds
    if (x() < 0 || x() > scene()->width()) {
        scene()->removeItem(this);
        delete this;
        return;
    }

    // Check for collision with enemy
    QList<QGraphicsItem*> colliding = collidingItems();
    for (QGraphicsItem* item : colliding) {
        Enemy1* enemy = dynamic_cast<Enemy1*>(item);
        if (enemy && !enemy->isDead()) {
            enemy->destroy();  // ✅ Safely kill enemy
            scene()->removeItem(this);
            delete this;
            return;
        }
    }
}
