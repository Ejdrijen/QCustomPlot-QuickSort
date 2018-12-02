#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "magic.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Magic m;
    QVector<double> x,y;

    y=m.GenerateAndSort(1000,1000,100);

    x=m.getXAxisValues(1000,1000,100);

    //set up graph
    ui->widget->addGraph();
    ui->widget->graph(0)->setData(x,y);

    ui->widget->xAxis->setLabel("pocet prvkov pola");
    ui->widget->yAxis->setLabel("cas potrebny na utriedenie [mikrosekundy]");

    ui->widget->xAxis->setRange(1000,2000);
    ui->widget->yAxis->setRange(0,20000);
    ui->widget->setInteraction(QCP::iRangeDrag, true);// tahanie osi
    ui->widget->setInteraction(QCP::iRangeZoom, true);// zoomovanie

    ui->widget->replot();
}

MainWindow::~MainWindow()
{
    delete ui;
}
