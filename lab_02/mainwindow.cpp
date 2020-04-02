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
    param_t p;
    // data_t data;
    // graphics_t graphics;

    getData(p);

    //countAll(data, p);

    //formGraphics(graphics, data);

    //drawAll(graphics);
}


void MainWindow::getData(param_t &p)
{
    p.Ck = ui->Ck_dataWidget->value();
    p.I0 = ui->Io_dataWidget->value();
    p.Lk = ui->Lk_dataWidget->value();
    p.Rk = ui->Rk_dataWidget->value();
    p.Uc0 = ui->Uco_dataWidget->value();
}


void MainWindow::draw(QCustomPlot *canvas, const graphic_t &graph1, const graphic_t &graph2)
{
    // чистим от старых графиков
    clearCanvas(canvas);

    // добавляем новые графики на холст
    addToCanvas(canvas, graph1);
    addToCanvas(canvas, graph2);

    // отрисовываем графики
    updateCanvas(canvas);
}


void MainWindow::addToCanvas(QCustomPlot *canvas, const graphic_t &graph)
{
    canvas->addGraph();
    canvas->graph(graph.number)->setData(graph.X, graph.Y);
    canvas->graph(graph.number)->setPen(graph.color);

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

