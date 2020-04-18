/**
 * \file calculatrice.c
 * \brief Ce fichier contient les définitions de types et les fonctions pour la gestion
 * de l'interface graphique de la calculatrice addition.
 * 
 * \author: Russe Cyril s170220
 * \date: 18-04-2020
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <gtk/gtk.h>

#include "calculatrice.h"

/**
 * \struct Donnees_t
 * \brief Définition du type opaque Donnees_t
 */
struct Donnees_t{
    GtkWidget *pEntry1;
    GtkWidget *pEntry2;
    GtkWidget *pLabel;
};

Donnees *constructeur_Donnees(void)
{
    Donnees *nouvelles_donnnees = malloc(sizeof(Donnees));

    return nouvelles_donnnees;
}

void destructeur_Donnees(Donnees *donnees)
{
    if (donnees != NULL){
        free(donnees);
        donnees = NULL;
    }
}

void set_Donnees_entry1(Donnees *donnees, GtkWidget *pEntry)
{
    assert(donnees!=NULL);

    donnees->pEntry1 = pEntry;
}

void set_Donnees_entry2(Donnees *donnees, GtkWidget *pEntry)
{
    assert(donnees!=NULL);

    donnees->pEntry2 = pEntry;
}

void set_Donnees_label(Donnees *donnees, GtkWidget *pLabel)
{
    assert(donnees!=NULL);

    donnees->pLabel = pLabel;
}

void gestion_widget_fenetre(GtkWidget *pFenetre, GtkWidget *pVBox, 
                            GtkWidget *pHBox, GtkWidget *pHBox2, GtkWidget *pHBox3, 
                            GtkWidget *pLabel_Nombre1, GtkWidget *pLabel_Nombre2, 
                            GtkWidget *pEntry_nbr1, GtkWidget *pEntry_nbr2, 
                            GtkWidget *pButton_addition, GtkWidget *pLabel_somme)
{
    gtk_window_set_title(GTK_WINDOW(pFenetre), "Addition");
    gtk_window_set_default_size(GTK_WINDOW(pFenetre), 600, 200);

    gtk_container_add(GTK_CONTAINER(pFenetre), pVBox);

    gtk_box_pack_start(GTK_BOX(pVBox), pHBox, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(pHBox), pLabel_Nombre1, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(pHBox), pEntry_nbr1, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(pVBox), pHBox2, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(pHBox2), pLabel_Nombre2, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(pHBox2), pEntry_nbr2, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(pVBox), pHBox3, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(pHBox3), pButton_addition, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(pHBox3), pLabel_somme, TRUE, TRUE, 0);

    gtk_widget_show_all(pFenetre);
}

void addition(GtkWidget *pButton, gpointer data)
{
    int n1, n2;
    const char *str_n1, *str_n2;
    char texte[100];

    Donnees *recuperation_data = (Donnees *)data;

    //récupération des valeurs à addition, entrées par l'utilisateur dans pEntry1 et pEntry2
    str_n1 = gtk_entry_get_text(GTK_ENTRY(recuperation_data->pEntry1));
    str_n2 = gtk_entry_get_text(GTK_ENTRY(recuperation_data->pEntry2));

    if(strlen(str_n2)==0||strlen(str_n1)==0){
        GtkWidget *pPopup = gtk_window_new(GTK_WINDOW_POPUP);
        GtkWidget *pLabel_erreur = gtk_label_new("Un ou plusieurs champs sont vides");
        gtk_container_add(GTK_CONTAINER(pPopup), pLabel_erreur);

        return;
    }

    for(unsigned int i=0; i<strlen(str_n1); i++){
        if(str_n1[i]<'0'||str_n1[i]>'9')
            return;
    }
    for (unsigned int i = 0; i < strlen(str_n2); i++)
    {
        if (str_n2[i] < '0' || str_n2[i] > '9')
            return;
    }

    n1 = atoi(str_n1);
    n2 = atoi(str_n2);

    sprintf(texte, "La somme vaut: %d", n1 + n2);

    gtk_label_set_text(GTK_LABEL(recuperation_data->pLabel), texte);
}