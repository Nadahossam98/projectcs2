#ifndef PLATFORM_H
#define PLATFORM_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QString>

class Platform : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Platform(const QString &, QGraphicsItem *parent = nullptr);
    static const QString LONG;
    static const QString SHORT;
};

#endif // PLATFORM_H
