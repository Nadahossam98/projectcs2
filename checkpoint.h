#ifndef CHECKPOINT_H
#define CHECKPOINT_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class CheckPoint : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    CheckPoint(QGraphicsItem *parent = nullptr);
};

#endif // CHECKPOINT_H
