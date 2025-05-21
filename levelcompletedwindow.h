#ifndef LEVELCOMPLETEDWINDOW_H
#define LEVELCOMPLETEDWINDOW_H
#include <QDialog>

namespace Ui {
class LevelCompletedWindow;
}

class LevelCompletedWindow : public QDialog
{
    Q_OBJECT
public:
    explicit LevelCompletedWindow(QWidget *parent = nullptr);
    ~LevelCompletedWindow();
signals:
    void wants_to_continue();
protected:
    void closeEvent(QCloseEvent *event) override;
private slots:
    void on_yes_butt_clicked();
    void on_no_butt_clicked();

private:
    Ui::LevelCompletedWindow *ui;
};

#endif // LEVELCOMPLETEDWINDOW_H



