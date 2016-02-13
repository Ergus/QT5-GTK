all: example.x example.py Interface.py

example.x: Makefile2
	make -f Makefile2

Makefile2: Test.pro
	qmake -o $@

%.py: %.ui
	pyuic5 -x $< -o $@


.PHONY: clean test test2

clean:
	rm -rf Makefile2 example.x moc_*.cpp ui_*.h __pycache__ Interface.py *.o

test: example.x
	./$<

test2: example.py Interface.py
	./$<
