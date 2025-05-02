#include "health.h"
#include "gameoverwindow.h"
#include <QGraphicsScene>

Health::Health(int max_hearts, QGraphicsItem* parent)
    : QGraphicsItemGroup(parent), current_health(max_hearts) {
    for (int i = 0; i < max_hearts; ++i) {
        QGraphicsPixmapItem* heart = new QGraphicsPixmapItem(QPixmap(":/imgs/heart.png"));
        heart->setPos(i * 40, 0);
        addToGroup(heart);
        hearts.append(heart);
    }
}

void Health::decrease_health() {
    if (current_health > 0) {
        --current_health;
        hearts[current_health]->setVisible(false);
    }
    if (current_health == 0) {
        GameOverWindow *game_over = new GameOverWindow();
        game_over->exec();
    }
}

int Health::get_current_health(){
    return current_health;
}
