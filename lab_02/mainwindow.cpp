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


void MainWindow::draw(QCustomPlot *canvas, const draw_t &graph)
{
    canvas->addGraph();
    canvas->graph(0)->setData(graph.X, graph.Y);

    //Задаем цвет графика
    canvas->graph(0)->setPen(graph.color);

    //Подписываем оси Ox и Oy
    canvas->xAxis->setLabel(graph.xAxis);
    canvas->yAxis->setLabel(graph.yAxis);

    //Установим область, которая будет показываться на графике
    auto limits = std::minmax_element(graph.X.begin(), graph.X.end());
    canvas->xAxis->setRange(*limits.first, *limits.second);

    limits = std::minmax_element(graph.Y.begin(), graph.Y.end());
    canvas->yAxis->setRange(*limits.first, *limits.second);

    //И перерисуем график на нашем widget
    canvas->replot();
}

void MainWindow::on_pushButton_clicked()
{
    QVector<double> X {-0.4, -0.3, -0.2, -0.1, 0.0, 0.1, 0.2, 0.3, 0.4};
    QVector<double> Y {0.16, 0.09, 0.04, 0.01, 0.0, 0.01, 0.04, 0.09, 0.16};
    draw_t gr1 = {X, Y, "x", "y", Qt::red};
    draw(ui->GraphWidget_1, gr1);
}
