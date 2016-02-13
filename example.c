#include <gtk/gtk.h>

typedef struct{
    GtkBuilder *builder;
    GtkWidget *window, *label, *edit, *button;
    } Objects;


void my_show(GtkButton *button, Objects *in){
    // Esta es la funcion que hace el trabajo.
    const char *str;
    str=gtk_entry_get_text((GtkEntry*)in->edit);   // lee el Entry
    gtk_label_set_text((GtkLabel*)in->label, str); // escribe en el label
    }

static gboolean wrapper(GtkWidget *edit, GdkEventKey *event, Objects *in){
    // Comprueba que la tecla fue enter
    if (event->keyval == 65293)     
        my_show((GtkButton*)in->button,in);  //Llama a la otra funcion
    return FALSE; 
    }

int main(int argc, char *argv[]){

    //Esta clase sera el contenedor de las otras formas para hacerlo absequible
    Objects *obj= g_slice_new (Objects);
    
    gtk_init(&argc, &argv);

    //Construye el builder y asociarlo con la interface
    obj->builder = gtk_builder_new();
    gtk_builder_add_from_file (obj->builder, "Interface.glade", NULL);

    // Asociar punteros con los objetos de la interface
    obj->window = GTK_WIDGET(gtk_builder_get_object(obj->builder, "window"));
    obj->button = GTK_WIDGET(gtk_builder_get_object(obj->builder, "button"));
    obj->label  = GTK_WIDGET(gtk_builder_get_object(obj->builder, "label"));
    obj->edit   = GTK_WIDGET(gtk_builder_get_object(obj->builder, "entry"));    

    // Conectar enter y clock con la funcion
    g_signal_connect(G_OBJECT(obj->button),"clicked",G_CALLBACK(my_show), obj);    
    g_signal_connect(G_OBJECT(obj->edit),"key-press-event",G_CALLBACK(wrapper), obj);

    // Cerrar ventana y terminar programa
    g_signal_connect(obj->window, "destroy", G_CALLBACK(gtk_main_quit), NULL);  

    // Conectar todas las funciones
    gtk_builder_connect_signals(obj->builder, NULL);

    // pone el contador a cero; no me queda claro
    g_object_unref(obj->builder);

    gtk_widget_show(obj->window);
    gtk_main();

    return 0;
    }
