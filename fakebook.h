#ifndef FAKEBOOK_H
#define FAKEBOOK_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
class FakeBook : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    FakeBook(QGraphicsItem *parent = nullptr);
};

#endif // FAKEBOOK_H
