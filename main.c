#include <stdlib.h>
#include <gtk/gtk.h>
#include <stdio.h>


int main(int argc, char **argv){

    gtk_init(&argc, &argv);


    GtkWidget *pFenetre = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(pFenetre), "Addition");
    gtk_window_set_default_size(GTK_WINDOW(pFenetre), 800, 300);
    
    GtkWidget *pLabel_Nombre1 = gtk_label_new("Nombre 1 : ");
    GtkWidget *pLabel_Nombre2 = gtk_label_new("Nombre 2 : ");
    GtkWidget *pLabel_Nombre4 = gtk_label_new("bite");

    GtkWidget *pButton_addition = gtk_button_new_with_label("Addition");


    GtkWidget *pVBox = gtk_vbox_new(TRUE, 0);
    GtkWidget *pHBox = gtk_hbox_new(TRUE, 0);
    GtkWidget *pHBox2 = gtk_hbox_new(TRUE, 0);
    GtkWidget *pHBox3 = gtk_hbox_new(TRUE, 0);

    gtk_box_pack_start(GTK_BOX(pVBox), pHBox, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(pHBox), pLabel_Nombre1, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(pVBox), pHBox2, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(pHBox2), pLabel_Nombre2, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(pHBox2), pLabel_Nombre4, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(pVBox), pHBox3, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(pHBox3), pButton_addition, TRUE, TRUE, 0);

    gtk_container_add(GTK_CONTAINER(pFenetre), pVBox);
   
    g_signal_connect(G_OBJECT(pFenetre), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_widget_show_all(pFenetre);
    gtk_main(); 
    return EXIT_SUCCESS;
}