all: example.x example.py

example.x: example.c
	gcc $^ -o $@ `pkg-config --cflags --libs gtk+-3.0`


.PHONY: clean test test2

clean:
	rm -rf example.x

test: example.x
	./$<

test2: example.py
	./$<
