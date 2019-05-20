/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *layout;
    QLineEdit *line_step;
    QPushButton *button;
    QComboBox *comboBox;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *line_interval_left_x;
    QLineEdit *line_interval_right_x;
    QLineEdit *line_interval_down_y;
    QLineEdit *line_interval_up_y;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(999, 565);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 711, 491));
        layout = new QVBoxLayout(verticalLayoutWidget);
        layout->setSpacing(6);
        layout->setContentsMargins(11, 11, 11, 11);
        layout->setObjectName(QString::fromUtf8("layout"));
        layout->setContentsMargins(0, 0, 0, 0);
        line_step = new QLineEdit(centralWidget);
        line_step->setObjectName(QString::fromUtf8("line_step"));
        line_step->setGeometry(QRect(810, 134, 113, 31));
        button = new QPushButton(centralWidget);
        button->setObjectName(QString::fromUtf8("button"));
        button->setGeometry(QRect(820, 400, 89, 25));
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(810, 80, 111, 31));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(770, 140, 41, 17));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(770, 90, 41, 16));
        line_interval_left_x = new QLineEdit(centralWidget);
        line_interval_left_x->setObjectName(QString::fromUtf8("line_interval_left_x"));
        line_interval_left_x->setGeometry(QRect(750, 230, 91, 31));
        line_interval_right_x = new QLineEdit(centralWidget);
        line_interval_right_x->setObjectName(QString::fromUtf8("line_interval_right_x"));
        line_interval_right_x->setGeometry(QRect(880, 230, 91, 31));
        line_interval_down_y = new QLineEdit(centralWidget);
        line_interval_down_y->setObjectName(QString::fromUtf8("line_interval_down_y"));
        line_interval_down_y->setGeometry(QRect(750, 320, 91, 31));
        line_interval_up_y = new QLineEdit(centralWidget);
        line_interval_up_y->setObjectName(QString::fromUtf8("line_interval_up_y"));
        line_interval_up_y->setGeometry(QRect(880, 320, 91, 31));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(820, 190, 101, 31));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(820, 280, 101, 31));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(730, 230, 21, 31));
        QFont font;
        font.setPointSize(20);
        label_5->setFont(font);
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(730, 320, 21, 31));
        label_6->setFont(font);
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(980, 320, 21, 31));
        label_7->setFont(font);
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(980, 230, 21, 31));
        label_8->setFont(font);
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(860, 230, 21, 31));
        label_9->setFont(font);
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(860, 320, 21, 31));
        label_10->setFont(font);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 999, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        button->setText(QApplication::translate("MainWindow", "Draw", nullptr));
        label->setText(QApplication::translate("MainWindow", "Step", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "f(x) = ", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Interval X", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Interval Y", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "[", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "[", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "]", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "]", nullptr));
        label_9->setText(QApplication::translate("MainWindow", ";", nullptr));
        label_10->setText(QApplication::translate("MainWindow", ";", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
