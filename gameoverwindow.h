#ifndef GAMEOVERWINDOW_H
#define GAMEOVERWINDOW_H

#include <QDialog>

namespace Ui {
class GameOverWindow;
}

class GameOverWindow : public QDialog
{
    Q_OBJECT

public:
    explicit GameOverWindow(QWidget *parent = nullptr);
    ~GameOverWindow();
protected:
    void closeEvent(QCloseEvent *event) override;
private slots:
    void on_yes_butt_clicked();
    void on_no_butt_clicked();

private:
    Ui::GameOverWindow *ui;
};

#endif // GAMEOVERWINDOW_H
