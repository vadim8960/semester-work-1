#include "openglwidget.h"

OpenglWidget::OpenglWidget() {

}

void OpenglWidget::initializeGL() {
    glClearColor(1, 1, 1, 1);
    glEnable(GL_SMOOTH);
}

void OpenglWidget::paintGL() {
    draw_grid();
    cos_x();
}

void OpenglWidget::draw_grid() {
    glLineWidth(2);
    glBegin(GL_LINES);
        glColor3d(0, 0, 0);
        glVertex2d(-1, 0);
        glVertex2d(1, 0);
        glVertex2d(0, -1);
        glVertex2d(0, 1);
    glEnd();
}

void OpenglWidget::set_painter(QString func, double step) {
    cur_func = func;
    cur_step = step;
}

double OpenglWidget::my_map(double x, double in_min, double in_max, double out_min, double out_max) {
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void OpenglWidget::sin_x() {
    double min_graph = -1,
           max_graph = 1,
           min_f     = -M_PI,
           max_f     = M_PI;
    double step = my_map(0.7, min_f, max_f, min_graph, max_graph);;
    glLineWidth(2.5);
    glBegin(GL_LINES);
        glColor3d(0, 1, 0);
        for (double x = 0; x < max_graph; x += step) {
            glVertex2d(x, qSin(my_map(x, min_graph, max_graph, min_f, max_f)));
            glVertex2d(x + step, qSin(my_map(x + step, min_graph, max_graph, min_f, max_f)));
        }
        for (double x = 0; x > min_graph; x -= step) {
            glVertex2d(x, qSin(my_map(x, min_graph, max_graph, min_f, max_f)));
            glVertex2d(x - step, qSin(my_map(x - step, min_graph, max_graph, min_f, max_f)));
        }
    glEnd();
}

void OpenglWidget::cos_x() {
    double min_graph = -1,
           max_graph = 1,
           min_f     = -M_PI,
           max_f     = M_PI;
    double step = my_map(0.2, min_f, max_f, min_graph, max_graph);;
    glLineWidth(2.5);
    glBegin(GL_LINES);
        glColor3d(0, 1, 0);
        for (double x = 0; x < max_graph; x += step) {
            glVertex2d(x, qCos(my_map(x, min_graph, max_graph, min_f, max_f)));
            glVertex2d(x + step, qCos(my_map(x + step, min_graph, max_graph, min_f, max_f)));
        }
        for (double x = 0; x > min_graph; x -= step) {
            glVertex2d(x, qCos(my_map(x, min_graph, max_graph, min_f, max_f)));
            glVertex2d(x - step, qCos(my_map(x - step, min_graph, max_graph, min_f, max_f)));
        }
    glEnd();
}
