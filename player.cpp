#include "player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QDebug>
#include "enemy1.h"
#include "spikes.h"
#include "fakebook.h"
#include "coin.h"
#include "book.h"
#include "checkpoint.h"
#include "platform.h"
#include <QApplication>

Player::Player(QGraphicsItem *parent)
    : QGraphicsPixmapItem(parent),
    facingLeft(false),
    poweredUp(false),
    inJump(false),
    onSurface(false),
    velocityY(0),
    fallTimer(new QTimer(this))
{
    setPixmap(QPixmap(":/imgs/player1.png"));
    connect(fallTimer, &QTimer::timeout, this, &Player::applyFall);
    fallTimer->start(30);
}

void Player::setHealth(Health *hp) {
    playerHealth = hp;
}
void Player::setCoinScore(CoinScore *score) {
    coinCounter = score;
}
void Player::setBookScore(BookScore *score) {
    bookCounter = score;
}
void Player::setLevel(LevelClass *lvl) {
    levelRef = lvl;
}

void Player::detectEnemyCollision() {
    for (QGraphicsItem* obj : collidingItems()) {
        auto* foe = dynamic_cast<Enemy1*>(obj);
        if (foe) {
            int offset = foe->boundingRect().width() + boundingRect().width() + 1;
            if (poweredUp) {
                walkRight(offset);
                return;
            }
            playerHealth->decrease_health();
            facingLeft ? walkLeft(offset) : walkRight(offset);
            return;
        }
    }
}

void Player::detectSpikesCollision() {
    for (QGraphicsItem* obj : collidingItems()) {
        auto* trap = dynamic_cast<Spikes*>(obj);
        if (trap) {
            int offset = trap->boundingRect().width() + boundingRect().width() + 1;
            if (poweredUp) {
                walkRight(offset);
                return;
            }
            playerHealth->decrease_health();
            facingLeft ? walkLeft(offset) : walkRight(offset);
            return;
        }
    }
}

void Player::detectFakeBookCollision() {
    for (QGraphicsItem* obj : collidingItems()) {
        auto* bait = dynamic_cast<FakeBook*>(obj);
        if (bait) {
            int offset = bait->boundingRect().width() + boundingRect().width() + 1;
            if (!poweredUp) {
                playerHealth->decrease_health();
            }
            scene()->removeItem(bait);
            delete bait;
            facingLeft ? walkLeft(offset) : walkRight(offset);
            return;
        }
    }
}

void Player::detectCoinPickup() {
    for (QGraphicsItem* obj : collidingItems()) {
        auto* coin = dynamic_cast<Coin*>(obj);
        if (coin) {
            coinCounter->increase_score();
            scene()->removeItem(coin);
            delete coin;
        }
    }
}

void Player::detectBookPickup() {
    for (QGraphicsItem* obj : collidingItems()) {
        auto* book = dynamic_cast<Book*>(obj);
        if (book) {
            bookCounter->increase_score();
            scene()->removeItem(book);
            delete book;
        }
    }
}

void Player::detectCheckpointTrigger() {
    for (QGraphicsItem* obj : collidingItems()) {
        auto* checkpoint = dynamic_cast<CheckPoint*>(obj);
        if (checkpoint) {
            QApplication::quit();
        }
    }
}

void Player::detectPlatformLanding() {
    for (QGraphicsItem* obj : collidingItems()) {
        auto* platform = dynamic_cast<Platform*>(obj);
        if (platform && y() + boundingRect().height() >= platform->y() + 5 && velocityY > 0) {
            velocityY = 0;
            inJump = false;
            onSurface = true;
            setY(platform->y() - boundingRect().height());
            return;
        }
    }
    onSurface = false;
}

void Player::detectAllCollisions() {
    detectEnemyCollision();
    detectSpikesCollision();
    detectFakeBookCollision();
    detectCoinPickup();
    detectBookPickup();
    detectCheckpointTrigger();
    detectPlatformLanding();
}

void Player::walkLeft(int step) {
    if (x() <= 0) return;
    if (!poweredUp && !facingLeft) {
        setPixmap(QPixmap(":/imgs/reversed-player1.png"));
        facingLeft = true;
    }

    if (x() + boundingRect().width() < scene()->width() / 2 || levelRef->ground->x() == 0)
        setX(x() - step);
    else
        levelRef->move(step);

    if (!inJump && !onSurface)
        setY(y() - 2);
}

void Player::walkRight(int step) {
    if (x() + boundingRect().width() >= scene()->width()) return;
    if (!poweredUp && facingLeft) {
        setPixmap(QPixmap(":/imgs/player1.png"));
        facingLeft = false;
    }

    if (x() + boundingRect().width() < scene()->width() / 2)
        setX(x() + step);
    else
        levelRef->move(-step);

    if (!inJump && !onSurface)
        setY(y() - 2);
}

void Player::keyPressEvent(QKeyEvent *event) {
    int moveStep = 20;
    if (event->key() == Qt::Key_Left) {
        walkLeft(moveStep);
        detectAllCollisions();
    } else if (event->key() == Qt::Key_Right) {
        walkRight(moveStep);
        detectAllCollisions();
    } else if (event->key() == Qt::Key_Up && !inJump) {
        velocityY = -20;
        inJump = true;
        detectPlatformLanding();
    }
}

void Player::applyFall() {
    if (onSurface) {
        velocityY = 0;
        return;
    }

    velocityY += 1;
    int newY = y() + velocityY;
    int groundY = 590 - boundingRect().height() + 5;

    if (newY >= groundY) {
        newY = groundY;
        velocityY = 0;
        inJump = false;
    }

    setPos(x(), newY);
    detectAllCollisions();
}
