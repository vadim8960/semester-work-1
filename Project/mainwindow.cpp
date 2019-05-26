#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("GraphViewer");
    simulation = new OpenglWidget;
    ui->layout->addWidget(simulation);
    ui->comboBox->addItem("sin x");
    ui->comboBox->addItem("cos x");
    ui->comboBox->addItem("tan x");
    ui->comboBox->addItem("ln x");
    ui->comboBox->addItem("1 / x");
    ui->comboBox->currentIndex();

    connect(this, &MainWindow::signal_set_params_openglwidget,
            simulation, &OpenglWidget::set_painter);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_button_clicked() {
    int func             = ui->comboBox->currentIndex();
    double step          = ui->line_step->text().toDouble();
    int interval_left_x  = ui->line_interval_left_x->text().toInt();
    int interval_right_x = ui->line_interval_right_x->text().toInt();
    int interval_up_y    = ui->line_interval_up_y->text().toInt();
    int interval_down_y  = ui->line_interval_down_y->text().toInt();
    emit signal_set_params_openglwidget(func + 1,
                                        step,
                                        interval_left_x,
                                        interval_right_x,
                                        interval_up_y,
                                        interval_down_y);
}
