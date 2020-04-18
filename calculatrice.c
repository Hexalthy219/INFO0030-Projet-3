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

Donnees *constructeur_Donnees()
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

void addition(GtkWidget *pButton, gpointer data)
{
    int n1, n2;
    const char *str_n1, *str_n2;
    char texte[100];

    Donnees *recuperation_data = (Donnees *)data;

    //récupération des valeurs à addition, entrées par l'utilisateur dans pEntry1 et pEntry2
    str_n1 = gtk_entry_get_text(GTK_ENTRY(recuperation_data->pEntry1));
    str_n2 = gtk_entry_get_text(GTK_ENTRY(recuperation_data->pEntry2));
    n1 = atoi(str_n1);
    n2 = atoi(str_n2);

    sprintf(texte, "La somme vaut: %d", n1 + n2);

    gtk_label_set_text(GTK_LABEL(recuperation_data->pLabel), texte);
}