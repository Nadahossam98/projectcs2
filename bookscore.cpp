#include "bookscore.h"
#include <QFont>
#include <QColor>

BookScore::BookScore(QGraphicsItem *parent)
    : QGraphicsItemGroup(parent), current_score(0)
{
    score_text = new QGraphicsTextItem("×0");
    score_text->setDefaultTextColor(QColor(0, 255, 255));
    score_text->setFont(QFont("Verdana", 22));
    addToGroup(score_text);

    book_icon = new QGraphicsPixmapItem(QPixmap(":/imgs/book.png"));
    book_icon->setPos(0, 4);
    addToGroup(book_icon);

    score_text->setPos(book_icon->boundingRect().width() + 4, -2);
}

void BookScore::increase_score() {
    ++current_score;
    QString updated_score = QString("×") + QString::number(current_score);
    score_text->setPlainText(updated_score);
}

int BookScore::get_current_score() {
    return current_score;
}
