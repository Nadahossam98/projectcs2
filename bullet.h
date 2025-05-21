#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>

class Bullet : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Bullet(bool facingLeft, QGraphicsItem *parent = nullptr);

public slots:
    void move();

private:
    int speed;
    bool facingLeft;
};

#endif // BULLET_H
