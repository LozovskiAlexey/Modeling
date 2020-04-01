#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "qcustomplot.h"
#include "funcs.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);  
    ~MainWindow();

private:
    void draw(QCustomPlot *canvas, const draw_t &graph);

private slots:
    void on_execButton_clicked();
    
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
