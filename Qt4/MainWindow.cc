#include "MainWindow.h"
#include "ui_Interface.h"

// class functions
my_window::my_window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){
    
    ui->setupUi(this); // this sets up GUI
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(my_show()));
    connect(ui->lineEdit, SIGNAL(returnPressed()),this,SLOT(my_show()));
    
    }

my_window::~my_window(){
    delete ui;
    }

void my_window::my_show(){
    QString tmp=ui->lineEdit->text();
    ui->label->setText(tmp);
    }


#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    my_window w;
    w.show();

    return a.exec();
    }
