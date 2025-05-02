#ifndef SPIKES_H
#define SPIKES_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
class Spikes : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Spikes(QGraphicsItem *parent = nullptr);
};

#endif // SPIKES_H
