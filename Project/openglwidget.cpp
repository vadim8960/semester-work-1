#include "openglwidget.h"

OpenglWidget::OpenglWidget() {
    cur_step = 0.01;
    status = 0;
    interval_left_x = -1;
    interval_right_x = 1;
    interval_down_y = -1;
    interval_up_y = 1;
}

void OpenglWidget::initializeGL() {
    glClearColor(1, 1, 1, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(interval_left_x, interval_right_x, interval_down_y, interval_up_y);
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
    case 4:
        ln_x();
    break;
    }
}

void OpenglWidget::draw_grid() {
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(interval_left_x, interval_right_x, interval_down_y, interval_up_y);
    glLineWidth(2);
    glBegin(GL_LINES);
        glColor3d(0, 0, 0);
        glVertex2d(interval_left_x, 0);
        glVertex2d(interval_right_x, 0);
        glVertex2d(0, interval_down_y);
        glVertex2d(0, interval_up_y);
    glEnd();

}

void OpenglWidget::set_painter(int func,
                               double step,
                               int interval_left_x,
                               int interval_right_x,
                               int interval_up_y,
                               int interval_down_y) {
    this->interval_left_x  = interval_left_x;
    this->interval_right_x = interval_right_x;
    this->interval_down_y  = interval_down_y;
    this->interval_up_y    = interval_up_y;
    status = func;
    cur_step = step;
    update();
}

void OpenglWidget::sin_x() {
    draw_grid();
    glLineWidth(2.5);
    glBegin(GL_LINES);
        glColor3d(0, 1, 0);
        for (double x = 0; x < interval_right_x; x += cur_step) {
            glVertex2d(x, qSin(x));
            glVertex2d(x + cur_step, qSin(x + cur_step));
        }
        for (double x = 0; x > interval_left_x; x -= cur_step) {
            glVertex2d(x, qSin(x));
            glVertex2d(x - cur_step, qSin(x - cur_step));
        }
    glEnd();
    update();
}

void OpenglWidget::cos_x() {
    draw_grid();
    glLineWidth(2.5);
    glBegin(GL_LINES);
        glColor3d(0, 1, 0);
        for (double x = 0; x < interval_right_x; x += cur_step) {
            glVertex2d(x, qCos(x));
            glVertex2d(x + cur_step, qCos(x + cur_step));
        }
        for (double x = 0; x > interval_left_x; x -= cur_step) {
            glVertex2d(x, qCos(x));
            glVertex2d(x - cur_step, qCos(x - cur_step));
        }
    glEnd();
    update();
}

void OpenglWidget::tan_x() {
    draw_grid();
    glLineWidth(2.5);
    glBegin(GL_LINES);
        glColor3d(0, 1, 0);
        for (double x = 0; x < interval_right_x; x += cur_step) {
            glVertex2d(x, qTan(x));
            glVertex2d(x + cur_step, qTan(x + cur_step));
        }
        for (double x = 0; x > interval_left_x; x -= cur_step) {
            glVertex2d(x, qTan(x));
            glVertex2d(x - cur_step, qTan(x - cur_step));
        }
    glEnd();
    update();
}

void OpenglWidget::ln_x() {
    draw_grid();
    glLineWidth(2.5);
    glBegin(GL_LINES);
        glColor3d(0, 1, 0);
        for (double x = 0; x < interval_right_x; x += cur_step) {
            glVertex2d(x, qLn(x));
            glVertex2d(x + cur_step, qLn(x + cur_step));
        }
        for (double x = 0; x > interval_left_x; x -= cur_step) {
            glVertex2d(x, qLn(x));
            glVertex2d(x - cur_step, qLn(x - cur_step));
        }
    glEnd();
    update();
}
