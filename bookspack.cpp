#include "bookspack.h"

BooksPack::BooksPack(int numCoins, QGraphicsItem *parent)
    : QGraphicsPixmapItem(parent) {
    for (int i = 0; i < numCoins; ++i) {
        Book *book = new Book(this);
        int sep = book->boundingRect().width() - 17;
        book->setPos(i * sep, 0);
    }
}
