#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "openglwidget.h"

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_button_clicked();

signals:
    void signal_set_params_openglwidget(int func, double step);

private:
    Ui::MainWindow *ui;
    OpenglWidget *simulation;
};

#endif // MAINWINDOW_H
