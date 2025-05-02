#include <QApplication>
#include <QProcess>
#include <QCloseEvent>
#include "gameoverwindow.h"
#include "ui_gameoverwindow.h"

GameOverWindow::GameOverWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameOverWindow)
{
    ui->setupUi(this);
    ui->label->setStyleSheet("color: red;");
}

GameOverWindow::~GameOverWindow()
{
    delete ui;
}

void GameOverWindow::on_yes_butt_clicked()
{
    qApp->quit();
    QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
}

void GameOverWindow::on_no_butt_clicked()
{
    qApp->exit(0);
}
void GameOverWindow::closeEvent(QCloseEvent *event)
{
    qApp->exit(0);
    event->accept();
}
