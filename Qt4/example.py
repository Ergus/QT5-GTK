#!/usr/bin/env python3

#
# This file is part of the QT4-GTK project Copyright (c) 2015 Jimmy Aguilar
# Mena.
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, version 3.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
# General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program. If not, see <http://www.gnu.org/licenses/>.
#

import sys
from PyQt5 import QtCore, QtGui, QtWidgets
from Interface import Ui_MainWindow

class MyInterface(Ui_MainWindow):
    def __init__(self, dialog):
        Ui_MainWindow.__init__(self)
        self.setupUi(dialog)

        #Connect
        self.pushButton.clicked.connect(self.my_show)
        self.lineEdit.returnPressed.connect(self.my_show)

    def my_show(self):
        txt = self.lineEdit.text()
        self.label.setText(txt)


if __name__ == '__main__':
    app = QtWidgets.QApplication(sys.argv)
    MainWindow = QtWidgets.QMainWindow()

    prog = MyInterface(MainWindow)

    MainWindow.show()
    sys.exit(app.exec_())
