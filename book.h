#ifndef BOOK_H
#define BOOK_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Book : QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Book(QGraphicsItem *parent = nullptr);
};

#endif // BOOK_H
