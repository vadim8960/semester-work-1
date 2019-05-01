#include "openglwidget.h"

OpenglWidget::OpenglWidget() {
    cur_step = 0.01;
    status = 0;
}

void OpenglWidget::initializeGL() {
    glClearColor(1, 1, 1, 1);
    glEnable(GL_SMOOTH);
}

void OpenglWidget::paintGL() {
    switch (status) {
    case 0:
        draw_grid();
    break;
    case 1:
        sin_x();
    break;
    case 2:
        cos_x();
    break;
    case 3:
        tan_x();
    break;
    }
}

void OpenglWidget::draw_grid() {
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLineWidth(2);
    glBegin(GL_LINES);
        glColor3d(0, 0, 0);
        glVertex2d(-1, 0);
        glVertex2d(1, 0);
        glVertex2d(0, -1);
        glVertex2d(0, 1);
    glEnd();
}

void OpenglWidget::set_painter(int func, double step) {
    status = func;
    cur_step = step;
    update();
}

double OpenglWidget::my_map(double x, double in_min, double in_max, double out_min, double out_max) {
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void OpenglWidget::sin_x() {
    draw_grid();
    double min_graph = -1,
           max_graph = 1,
           min_f     = -M_PI,
           max_f     = M_PI;
    double step = my_map(cur_step, min_f, max_f, min_graph, max_graph);;
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
    draw_grid();
    double min_graph = -1,
           max_graph = 1,
           min_f     = -M_PI,
           max_f     = M_PI;
    double step = my_map(cur_step, min_f, max_f, min_graph, max_graph);;
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
    update();
}

void OpenglWidget::tan_x() {
    draw_grid();
    double min_graph = -1,
           max_graph = 1,
           min_f     = -10,
           max_f     = 10;
    double step = my_map(cur_step, min_f, max_f, min_graph, max_graph);;
    glLineWidth(2.5);
    glBegin(GL_LINES);
        glColor3d(0, 1, 0);
        for (double x = 0; x < max_graph; x += step) {
            glVertex2d(x, qTan(my_map(x, min_graph, max_graph, min_f, max_f)));
            glVertex2d(x + step, qTan(my_map(x + step, min_graph, max_graph, min_f, max_f)));
        }
        for (double x = 0; x > min_graph; x -= step) {
            glVertex2d(x, qTan(my_map(x, min_graph, max_graph, min_f, max_f))/10);
            glVertex2d(x - step, qTan(my_map(x - step, min_graph, max_graph, min_f, max_f)));
        }
    glEnd();
    update();
}
