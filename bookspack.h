#ifndef BOOKSPACK_H
#define BOOKSPACK_H

#include <QGraphicsPixmapItem>
#include "book.h"

class BooksPack : public QGraphicsPixmapItem {
public:
    explicit BooksPack(int numCoins, QGraphicsItem *parent = nullptr);
};

#endif // BOOKSPACK_H
