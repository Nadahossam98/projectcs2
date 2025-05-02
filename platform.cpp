#include "platform.h"

const QString Platform::LONG = "long";
const QString Platform::SHORT = "short";
Platform::Platform(const QString &platform_type, QGraphicsItem *parent):
    QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/imgs/" + platform_type + "-platform-stone.png"));
}
