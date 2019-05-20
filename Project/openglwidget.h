#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H

#include <QOpenGLWidget>
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
    void set_painter(int func, double step);

private:
    double cur_step;
    int status;

    void sin_x();
    void cos_x();
    void tan_x();
    void ln_x();

    void draw_grid();

    double my_map(double x, double in_min, double in_max, double out_min, double out_max);
};

#endif // OPENGLWIDGET_H
