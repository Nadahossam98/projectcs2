#include "fakebook.h"

FakeBook::FakeBook(QGraphicsItem *parent):
    QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/imgs/fakebook.png"));
}
