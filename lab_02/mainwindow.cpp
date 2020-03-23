#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_execButton_clicked()
{
    // считать данные
    // обработать корректность ввода

    // запустить count_Runge_Kutta(Runge_Kutte_4th, U, I, p);
    // запустить count_Runge_Kutta(Runge_Kutte_2nd, U1, I1, p);
    // отрисовать U I, U1 I1

    // дописать функции для вычисления остальных графиков
    // отрисовать остальные графики
    // функция отрисовки графиков
}
