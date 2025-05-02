#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsItemGroup>
#include <QGraphicsPixmapItem>
#include <QVector>

class Health : public QGraphicsItemGroup {
public:
    Health(int, QGraphicsItem* parent = nullptr);
    int get_current_health();
    void decrease_health();

private:
    QVector<QGraphicsPixmapItem*> hearts;
    int current_health;
};

#endif // HEALTH_H
