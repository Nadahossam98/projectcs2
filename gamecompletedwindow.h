#ifndef GAMECOMPLETEDWINDOW_H
#define GAMECOMPLETEDWINDOW_H

#include <QDialog>

namespace Ui {
class GameCompletedWindow;
}

class GameCompletedWindow : public QDialog
{
    Q_OBJECT

public:
    explicit GameCompletedWindow(QWidget *parent = nullptr);
    ~GameCompletedWindow();
protected:
    void closeEvent(QCloseEvent *event) override;
private slots:
    void on_ok_butt_clicked();
private:
    Ui::GameCompletedWindow *ui;
};

#endif // GAMECOMPLETEDWINDOW_H
