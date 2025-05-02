#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
#include "health.h"
#include "coinscore.h"
#include "bookscore.h"
#include "levelclass.h"

class Player : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    explicit Player(QGraphicsItem *parent = nullptr);

    void walkLeft(int);
    void walkRight(int);
    void keyPressEvent(QKeyEvent *event) override;

    void setHealth(Health *);
    void setCoinScore(CoinScore *);
    void setBookScore(BookScore *);
    void setLevel(LevelClass *);

private:
    bool facingLeft;
    bool poweredUp;
    bool inJump;
    bool onSurface;
    int velocityY;

    QTimer* fallTimer;

    Health* playerHealth;
    CoinScore* coinCounter;
    BookScore* bookCounter;
    LevelClass* levelRef;

    void detectEnemyCollision();
    void detectSpikesCollision();
    void detectFakeBookCollision();
    void detectCoinPickup();
    void detectBookPickup();
    void detectCheckpointTrigger();
    void detectPlatformLanding();
    void detectAllCollisions();

public slots:
    void applyFall();
};

#endif // PLAYER_H
