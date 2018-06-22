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

import gi
gi.require_version('Gtk', '3.0')
from gi.repository import Gtk

class Objects:
    def __init__(self):
        self.builder, self.window, self.label, self.edit, self.button=0,0,0,0,0

def my_show(button, oin):
    # Esta es la funcion que hace el trabajo.
    str=oin.edit.get_text()
    oin.label.set_text(str)

def wrapper(edit,event,oin):
    # Comprueba que la tecla fue enter
    if (event.keyval == 65293):
        my_show(oin.button,oin)  #Llama a la otra funcion
    return False

def main(args):

    # Esta clase sera el contenedor de las otras formas para hacerlo absequible
    obj=Objects()

    # Construye el builder y asociarlo con la interface
    obj.builder=Gtk.Builder()
    obj.builder.add_from_file("Interface.glade")

    # Asociar punteros con los objetos de la interface
    obj.window = obj.builder.get_object("window")
    obj.button = obj.builder.get_object("button")
    obj.label  = obj.builder.get_object("label")
    obj.edit   = obj.builder.get_object("entry")

    obj.button.connect("clicked", my_show, obj)
    obj.edit.connect("key-press-event",wrapper, obj)
    obj.window.connect("delete-event", Gtk.main_quit)
    
    obj.window.show_all()
    Gtk.main()
    
    return 0

if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))

