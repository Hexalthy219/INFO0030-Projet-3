#include <stdlib.h>
#include <gtk/gtk.h>
#include <stdio.h>

typedef struct{
    GtkWidget *pEntry1;
    GtkWidget *pEntry2;
    GtkWidget *pLabel;
}Donnees;

void addition(GtkWidget *pButton, gpointer data){
    int n1, n2;
    const char *sn1, *sn2;
    char texte[100];

    Donnees *test = (Donnees*) data;

    sn1 = gtk_entry_get_text(GTK_ENTRY(test->pEntry1));
    sn2 = gtk_entry_get_text(GTK_ENTRY(test->pEntry2));
    n1 = atoi(sn1);
    n2 = atoi(sn2);
    printf("%d", n1);

    sprintf(texte, "La somme vaut: %d", n1+n2);

    gtk_label_set_text(GTK_LABEL(test->pLabel), texte);
}


int main(int argc, char **argv){
    Donnees *donnees = malloc(sizeof(Donnees));
    if(donnees==NULL)
        return -1;

    gtk_init(&argc, &argv);


    GtkWidget *pFenetre = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(pFenetre), "Addition");
    gtk_window_set_default_size(GTK_WINDOW(pFenetre), 800, 300);
    
    GtkWidget *pLabel_Nombre1 = gtk_label_new("Nombre 1 : ");
    GtkWidget *pLabel_Nombre2 = gtk_label_new("Nombre 2 : ");
    GtkWidget *pLabel_somme = gtk_label_new(NULL);
    GtkWidget *pEntry_nbr1 = gtk_entry_new();
    GtkWidget *pEntry_nbr2 = gtk_entry_new();
    donnees->pEntry1 = pEntry_nbr1;
    donnees->pEntry2 = pEntry_nbr2;
    donnees->pLabel = pLabel_somme;

    GtkWidget *pButton_addition = gtk_button_new_with_label("Addition");


    GtkWidget *pVBox = gtk_vbox_new(TRUE, 0);
    GtkWidget *pHBox = gtk_hbox_new(TRUE, 0);
    GtkWidget *pHBox2 = gtk_hbox_new(TRUE, 0);
    GtkWidget *pHBox3 = gtk_hbox_new(TRUE, 0);

    gtk_box_pack_start(GTK_BOX(pVBox), pHBox, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(pHBox), pLabel_Nombre1, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(pHBox), pEntry_nbr1, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(pVBox), pHBox2, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(pHBox2), pLabel_Nombre2, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(pHBox2), pEntry_nbr2, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(pVBox), pHBox3, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(pHBox3), pButton_addition, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(pHBox3), pLabel_somme, TRUE, TRUE, 0);

    gtk_container_add(GTK_CONTAINER(pFenetre), pVBox);
    g_signal_connect(G_OBJECT(pButton_addition), "clicked", G_CALLBACK(addition), (gpointer)donnees);
    g_signal_connect(G_OBJECT(pFenetre), "destroy", G_CALLBACK(gtk_main_quit), NULL);


    gtk_widget_show_all(pFenetre);
    gtk_main(); 
    free(donnees);
    return EXIT_SUCCESS;
}