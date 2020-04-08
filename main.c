#include <gtk/gtk.h>
#include <stdio.h>

void detruire_fenetre(GtkWidget *pF, gpointer data){
    gtk_main_quit();
}

int main(int argc, char **argv){
    gtk_init(&argc, &argv);
    
    

    GtkWidget *fenetre = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(fenetre, "Addition");
    gtk_window_set_default_size(fenetre, 800, 400);
    

    
    GtkWidget *pLabel_nombre1 = gtk_label_new("Nombre 1 :");
    gtk_container_add(GTK_CONTAINER(fenetre), pLabel_nombre1);
    GtkWidget *pLabel_nombre2 = gtk_label_new("Nombre 2: ");


    
    gtk_container_add(GTK_CONTAINER(fenetre), pLabel_nombre2);
    gtk_widget_show_all(fenetre);




    g_signal_connect(G_OBJECT(fenetre), "destroy", G_CALLBACK(detruire_fenetre), NULL);

    gtk_main(); 
    return EXIT_SUCCESS;
}