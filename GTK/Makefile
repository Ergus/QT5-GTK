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
