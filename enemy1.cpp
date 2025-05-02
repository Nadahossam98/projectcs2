#include <QGraphicsScene>
#include <QKeyEvent>
#include <QTimer>
#include "enemy1.h"
#include <QDebug>

Enemy1::Enemy1(QGraphicsItem *parent)
    : QObject(), QGraphicsPixmapItem(parent),
    is_reversed(false),
    is_on_platform(false),
    moving_left(true) // Start by moving left
{
    setPixmap(QPixmap(":/imgs/enemy1.png"));

    // Create and start the internal movement timer
    moveTimer = new QTimer(this);
    connect(moveTimer, &QTimer::timeout, this, &Enemy1::update_movement);
    moveTimer->start(50); // Call update_movement every 50 ms
}

void Enemy1::update_movement() {
    if (moving_left) {
        move_left(3); // Move 5 pixels to the left
    } else {
        move_right(3); // Move 5 pixels to the right
    }
}

void Enemy1::move_left(int dx) {
    if (x() <= 0) {
        // Reverse direction to move right when at the left edge
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
    if (x() + boundingRect().width() >= scene()->width()) {
        // Reverse direction to move left when at the right edge
        moving_left = true;
        return;
    }

    if (is_reversed) {
        setPixmap(QPixmap(":/imgs/enemy1.png"));
        is_reversed = false;
    }

    setX(x() + dx);
}
