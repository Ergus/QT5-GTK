all: example.x example.py Interface.py

example.x: ui_Interface.h

example.x: example.cc moc_MainWindow.cpp
	c++ -fPIC $^ -o $@  `pkg-config  --cflags --libs Qt5Core` \
			    `pkg-config  --cflags --libs Qt5Gui`  \
			    `pkg-config  --cflags --libs Qt5Widgets`

ui_%.h: %.ui
	uic $< -o $@

moc_%.cpp: %.h
	moc $< -o $@

#== This are the rules to build with qmake and a .pro ===
# I substituted them for eassier rules more "make like"

#example.x: Makefile2
#	make -f Makefile2

#Makefile2: Test.pro
#	qmake -o $@

#=======================================================

%.py: %.ui
	pyuic5 -x $< -o $@

.PHONY: clean test test2

clean:
	rm -rf Makefile2 example.x moc_*.cpp ui_*.h __pycache__ Interface.py *.o

test: example.x
	./$<

test2: example.py Interface.py
	./$<
