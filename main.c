/**
 * \file main.c
 * \brief Ce fichier contient la fonction main() du programme de calculatrice d'addition.
 * \author: Russe Cyril s170220
 * \date: 18-04-2020
 * 
 */

#include <stdlib.h>
#include <stdio.h>
#include <gtk/gtk.h>

#include "calculatrice.h"


int main(int argc, char **argv){
    /*Initialisation struct donnees permettant de transmettre 
    les donnees nécessaires à l'addition lors de l'activation du 
    bouton "addition"*/
    Donnees *donnees = constructeur_Donnees();
    if(donnees==NULL)
        return EXIT_FAILURE;
    /*FIN Initialisation struct donnees*/

    gtk_init(&argc, &argv);

    /*Initialisation des widgets du programme*/

    //fenêtre
    GtkWidget *pFenetre = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    //label
    GtkWidget *pLabel_Nombre1 = gtk_label_new("Nombre 1 : ");
    GtkWidget *pLabel_Nombre2 = gtk_label_new("Nombre 2 : ");
    GtkWidget *pLabel_somme = gtk_label_new(NULL);
    //entry
    GtkWidget *pEntry_nbr1 = gtk_entry_new();
    GtkWidget *pEntry_nbr2 = gtk_entry_new();
    //set la valeur max des entrées à 9 caractères pour éviter overflow lors de l'addition
    //de ces 2 valeurs dans un int
    gtk_entry_set_max_length(GTK_ENTRY(pEntry_nbr1), 9);
    gtk_entry_set_max_length(GTK_ENTRY(pEntry_nbr2), 9);
    //bouton
    GtkWidget *pButton_addition = gtk_button_new_with_label("Addition");
    //box
    GtkWidget *pVBox = gtk_vbox_new(TRUE, 0);
    GtkWidget *pHBox = gtk_hbox_new(TRUE, 0);
    GtkWidget *pHBox2 = gtk_hbox_new(TRUE, 0);
    GtkWidget *pHBox3 = gtk_hbox_new(TRUE, 0);

    /*FIN Initialisation des widgets*/

    /*Gestion de la fenêtre et de l'affichage des boxs*/
    gestion_widget_fenetre(pFenetre, pVBox, pHBox, pHBox2, pHBox3, pLabel_Nombre1, pLabel_Nombre2,
                           pEntry_nbr1, pEntry_nbr2, pButton_addition, pLabel_somme);
    /*FIN Gestion de la fenêtre et de l'affichage des boxs*/

    /*Mise à jour des données dans la struct donnees*/
    set_Donnees_entry1(donnees, pEntry_nbr1);
    set_Donnees_entry2(donnees, pEntry_nbr2);
    set_Donnees_label(donnees, pLabel_somme);
    /*FIN Mise à jour des données dans la struct donnees*/

    /*Connexion des signaux*/
    g_signal_connect(G_OBJECT(pButton_addition), "clicked", G_CALLBACK(addition), (gpointer)donnees);
    g_signal_connect(G_OBJECT(pFenetre), "destroy", G_CALLBACK(gtk_main_quit), NULL);
    /*FIN Connexion des signaux*/

    gtk_main(); 

    destructeur_Donnees(donnees);

    return EXIT_SUCCESS;
}