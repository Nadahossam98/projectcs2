#ifndef ENEMY1_H
#define ENEMY1_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>

class Enemy1 : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    explicit Enemy1(QGraphicsItem *parent = nullptr);
    ~Enemy1();

    void move_left(int dx);
    void move_right(int dx);

    void destroy();              // Called when enemy is hit
    void markForDeletion();      // Actually remove and delete the enemy
    bool isDead() const;         // True if enemy is not active
    bool shouldDelete() const;   // True if enemy is flagged for deletion

private slots:
    void update_movement();

private:
    QTimer *moveTimer;
    bool is_reversed;
    bool is_on_platform;
    bool moving_left;
    bool isAlive;
    bool pendingDeletion;
};

#endif // ENEMY1_H
