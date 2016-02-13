#!/usr/bin/env python

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
