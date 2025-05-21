#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
#include "health.h"
#include "coinscore.h"
#include "bookscore.h"
#include "levelclass.h"
#include "levelcompletedwindow.h"
#include "gamecompletedwindow.h"
#include "bullet.h"

class Player : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    explicit Player(QGraphicsItem *parent = nullptr);

    void walkLeft(int);
    void walkRight(int);
    void shoot();
    void keyPressEvent(QKeyEvent *event) override;

    void setHealth(Health *);
    void setCoinScore(CoinScore *);
    void setBookScore(BookScore *);
    void setLevel(LevelClass *);
    void setLevelCompleteUI(LevelCompletedWindow *);
    void setGameCompleteUI(GameCompletedWindow *);

private:
    bool facingLeft;
    bool poweredUp;
    bool inJump;
    bool onSurface;
    int velocityY;

    QTimer* fallTimer;
    QTimer* boostTimer;

    Health* playerHealth;
    CoinScore* coinCounter;
    BookScore* bookCounter;
    LevelClass* levelRef;
    LevelCompletedWindow* levelUI;
    GameCompletedWindow* finalUI;

    void detectEnemyCollision();
    void detectSpikesCollision();
    void detectFakeBookCollision();
    void detectCoinPickup();
    void detectBookPickup();
    void detectCheckpointTrigger();
    void detectPlatformLanding();
    void detectAllCollisions();
    void activateBoost();

public slots:
    void applyFall();
    void deactivateBoost();
};

#endif // PLAYER_H
