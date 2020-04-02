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

void MainWindow::on_pushButton_clicked()
{
    init(data);
    init(graphics);

    getData(p);

    count_all(data, p);

    form_graphs(graphics, data);

    drawAll(graphics);

    release(data);
    release(graphics);
}


void MainWindow::getData(param_t &p)
{
    p.Ck = ui->Ck_dataWidget->value();
    p.I0 = ui->Io_dataWidget->value();
    p.Lk = ui->Lk_dataWidget->value();
    p.Rk = ui->Rk_dataWidget->value();
    p.Uc0 = ui->Uco_dataWidget->value();
}


void MainWindow::drawAll(draw_data_t &graphics)
{
    draw(ui->GraphWidget_1, *graphics.fourth_approx->I, *graphics.second_approx->I);
    draw(ui->GraphWidget_2, *graphics.fourth_approx->U, *graphics.second_approx->U);
    draw(ui->GraphWidget_3, *graphics.fourth_approx->Ucp, *graphics.second_approx->Ucp);
    draw(ui->GraphWidget_4, *graphics.fourth_approx->T0, *graphics.second_approx->T0);
    draw(ui->GraphWidget_5, *graphics.fourth_approx->Rp, *graphics.second_approx->Rp);
}


void MainWindow::draw(QCustomPlot *canvas, graphic_t &graph1, graphic_t &graph2)
{
    // чистим от старых графиков
    clearCanvas(canvas);

    // добавляем новые графики на холст
    addToCanvas(canvas, graph1, 0);
    addToCanvas(canvas, graph2, 1);

    // отрисовываем графики
    updateCanvas(canvas);
}


void MainWindow::addToCanvas(QCustomPlot *canvas, const graphic_t &graph, int no)
{
    canvas->addGraph();
    canvas->graph(no)->setData(graph.X, graph.Y);
    canvas->graph(no)->setPen(color[no]);

    setAxis(canvas->xAxis, graph.X, graph.xAxis);
    setAxis(canvas->yAxis, graph.Y, graph.yAxis);
}


void MainWindow::setAxis(QCPAxis *canvas, const QVector<double> &axis, const QString &name)
{
    // название оси
    canvas->setLabel(name);

    // границы отображения
    auto limits = std::minmax_element(axis.begin(), axis.end());
    canvas->setRange(*limits.first, *limits.second);
}


void MainWindow::clearCanvas(QCustomPlot *canvas)
{
    canvas->clearGraphs();
}


void MainWindow::updateCanvas(QCustomPlot *canvas)
{
    canvas->replot();
}

