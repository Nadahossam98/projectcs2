#include "enemy1.h"
#include <QGraphicsScene>
#include <QDebug>

Enemy1::Enemy1(QGraphicsItem *parent)
    : QObject(), QGraphicsPixmapItem(parent),
    is_reversed(false),
    is_on_platform(false),
    moving_left(true),
    isAlive(true),
    pendingDeletion(false)
{
    setPixmap(QPixmap(":/imgs/enemy1.png"));

    moveTimer = new QTimer(this);
    connect(moveTimer, &QTimer::timeout, this, &Enemy1::update_movement);
    moveTimer->start(50);
}

Enemy1::~Enemy1() {
    if (moveTimer && moveTimer->isActive())
        moveTimer->stop();
    qDebug() << "[ENEMY] Destructor called at x:" << x() << ", y:" << y();
}

void Enemy1::update_movement() {
    if (!isAlive || !scene()) return;

    if (moving_left) {
        move_left(3);
    } else {
        move_right(3);
    }
}

void Enemy1::move_left(int dx) {
    if (!scene()) return;

    if (x() <= 0) {
        moving_left = false;
        return;
    }

    if (!is_reversed) {
        setPixmap(QPixmap(":/imgs/reversed-enemy1.png"));
        is_reversed = true;
    }

    setX(x() - dx);
}

void Enemy1::move_right(int dx) {
    if (!scene()) return;

    if (x() + boundingRect().width() >= scene()->width()) {
        moving_left = true;
        return;
    }

    if (is_reversed) {
        setPixmap(QPixmap(":/imgs/enemy1.png"));
        is_reversed = false;
    }

    setX(x() + dx);
}

void Enemy1::destroy() {
    if (!isAlive) return;
    isAlive = false;
    pendingDeletion = true;

    if (moveTimer) moveTimer->stop();
    disconnect();  // Disconnect all signals
    hide();        // Hide from view immediately

    qDebug() << "[ENEMY] Marked for deletion at x:" << x() << ", y:" << y();
}

void Enemy1::markForDeletion() {
    if (!scene()) return;

    scene()->removeItem(this);
    deleteLater();  // Actual safe deletion
    qDebug() << "[ENEMY] Deleted at end of frame";
}

bool Enemy1::isDead() const {
    return !isAlive;
}

bool Enemy1::shouldDelete() const {
    return pendingDeletion;
}
