#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H

#include <QOpenGLWidget>
#include <GL/glu.h>
#include <QtMath>
#include <QDebug>

class OpenglWidget : public QOpenGLWidget
{
    Q_OBJECT
public:
    OpenglWidget();

    void initializeGL() override;
    void paintGL() override;

public slots:
    void set_painter(int func,
                     double step,
                     int interval_left_x,
                     int interval_right_x,
                     int interval_up_y,
                     int interval_down_y);

private:
    double cur_step;
    int status;
    int interval_left_x;
    int interval_right_x;
    int interval_up_y;
    int interval_down_y;

    void sin_x();
    void cos_x();
    void tan_x();
    void ln_x();
    void x_negative_1();

    void draw_grid();
};

#endif // OPENGLWIDGET_H
