#ifndef ENEMY1_H
#define ENEMY1_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QTimer>

class Enemy1 : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT

public:
    Enemy1(QGraphicsItem *parent = nullptr);

    void move_left(int dx);
    void move_right(int dx);

private slots:
    void update_movement();

private:
    QTimer *moveTimer;   // Timer for continuous movement
    bool is_reversed;    // Flag to check if the enemy is reversed
    bool is_on_platform; // Flag to check if the enemy is on a platform (you can expand this later)
    bool moving_left;    // Flag to determine the current direction (left or right)
};

#endif // ENEMY1_H
