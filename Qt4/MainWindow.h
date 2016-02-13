#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

// class definition
namespace Ui {
    class MainWindow;
    }

class my_window : public QMainWindow{
        Q_OBJECT
    public:
        explicit my_window(QWidget *parent = 0);
        ~my_window();

    public slots:
        void my_show();

    private:
        Ui::MainWindow *ui;
    };

#endif
