#ifndef BOOKSCORE_H
#define BOOKSCORE_H

#include <QGraphicsTextItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

class BookScore : public QGraphicsItemGroup  {
public:
    BookScore(QGraphicsItem *parent = nullptr);
    void increase_score();
    int get_current_score();
private:
    int current_score;
    QGraphicsPixmapItem *book_icon;
    QGraphicsTextItem *score_text;
};

#endif // BOOKSCORE_H
