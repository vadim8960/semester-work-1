#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    simulation = new OpenglWidget;
    ui->layout->addWidget(simulation);
    ui->comboBox->addItem("sin x");
    ui->comboBox->addItem("cos x");
    ui->comboBox->addItem("tan x");
    ui->comboBox->addItem("ln x");
    ui->comboBox->currentIndex();

    connect(this, &MainWindow::signal_set_params_openglwidget,
            simulation, &OpenglWidget::set_painter);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_button_clicked() {
    int func = ui->comboBox->currentIndex();
    double step = ui->lineEdit->text().toDouble();
    emit signal_set_params_openglwidget(func + 1, step);
}
