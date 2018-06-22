/*
 * This file is part of the QT4-GTK project Copyright (c) 2015 Jimmy Aguilar
 * Mena.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

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

void my_window::my_show()
{
	QString tmp = ui->lineEdit->text();
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
