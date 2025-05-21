#include <QApplication>
#include <QCloseEvent>
#include "gamecompletedwindow.h"
#include "ui_gamecompletedwindow.h"

GameCompletedWindow::GameCompletedWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameCompletedWindow)
{
    ui->setupUi(this);
}

void GameCompletedWindow::on_ok_butt_clicked()
{
    qApp->exit(0);
}

void GameCompletedWindow::closeEvent(QCloseEvent *event)
{
    qApp->exit(0);
    event->accept();
}

GameCompletedWindow::~GameCompletedWindow()
{
    delete ui;
}
