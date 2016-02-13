all: example.x example.py

example.x: example.c
	gcc `pkg-config --cflags gtk+-3.0` $^ -o $@ `pkg-config --libs gtk+-3.0`


.PHONY: clean test test2

clean:
	rm -rf example.x

test: example.x
	./$<

test2: example.py
	./$<
