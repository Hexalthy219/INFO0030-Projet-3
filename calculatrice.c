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

static void fenetre_erreur(int type_erreur);

static void popup_close(GtkWidget *pPopup, gpointer data);

static int verification_entree(const char *pEntry1, const char *pEntry2);

static GtkWidget *charge_image_bouton(void);

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
    //modification des reglages de la fenêtre
    gtk_window_set_title(GTK_WINDOW(pFenetre), "Addition");
    gtk_window_set_default_size(GTK_WINDOW(pFenetre), 800, 200);
    gtk_window_move(GTK_WINDOW(pFenetre), 400, 400);

    //ajout du widget à la fenêtre
    gtk_container_add(GTK_CONTAINER(pFenetre), pVBox);

    /*structure des boxs, va créer une interface comprenant une box verticale
    reprenant 3 boxs horizontales séparées en 2 cases égales*/

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

    pButton +=0; //inutile, mais sinon warning "unused variable à la compilation"

    Donnees *recuperation_data = (Donnees *)data;

    //récupération des valeurs à addition, entrées par l'utilisateur dans pEntry1 et pEntry2
    str_n1 = gtk_entry_get_text(GTK_ENTRY(recuperation_data->pEntry1));
    str_n2 = gtk_entry_get_text(GTK_ENTRY(recuperation_data->pEntry2));

    //vérification des entree de l'utilisateur
    if(strlen(str_n2)==0||strlen(str_n1)==0){
        fenetre_erreur(1);
        return;
    }
    if(verification_entree(str_n1, str_n2)==-1){
        fenetre_erreur(2);
        return;
    }

   
    /*récupération des données dans des variables int afin de créer
    le texte à faire apparaitre dans le label somme avec la somme des 2 variables*/
    n1 = atoi(str_n1);
    n2 = atoi(str_n2);

    sprintf(texte, "La somme vaut %d", n1 + n2);

    gtk_label_set_text(GTK_LABEL(recuperation_data->pLabel), texte);
}//fin addition

static int verification_entree(const char *pEntry1, const char *pEntry2)
{
    assert(pEntry1!=NULL && pEntry2!=NULL);
    for (unsigned int i = 0; i < strlen(pEntry1); i++)
    {
        if (pEntry1[i] < '0' || pEntry1[i] > '9')
            return -1;
    }//fin for
    for (unsigned int i = 0; i < strlen(pEntry2); i++)
    {
        if (pEntry2[i] < '0' || pEntry2[i] > '9')
            return -1;
    }//fin for
    return 0;
}//fin verification_entree

static void fenetre_erreur(int type_erreur)
{
    GtkWidget *pPopup = gtk_window_new(GTK_WINDOW_POPUP);
    GtkWidget *pVBox = gtk_vbox_new(TRUE, 0);
    GtkWidget *pHBox = gtk_hbox_new(TRUE, 0);
    GtkWidget *pLabel_erreur_champ_vide = gtk_label_new("Un ou plusieurs champs sont vides");
    GtkWidget *pLabel_erreur_mauvaise_entree = gtk_label_new("Veuillez entrer des valeurs entières");
    GtkWidget *pButton_ok = charge_image_bouton();
    //si échec du chargement de l'image bouton_ok alors création
    //d'un bouton standard avec label "ok"
    if (pButton_ok==NULL)
        pButton_ok = gtk_button_new_with_label("ok");

    gtk_window_set_default_size(GTK_WINDOW(pPopup), 500, 150);
    gtk_window_move(GTK_WINDOW(pPopup), 550, 420);
    if(type_erreur==1)
        gtk_box_pack_start(GTK_BOX(pVBox), pLabel_erreur_champ_vide, TRUE, TRUE, 0);
    else
        gtk_box_pack_start(GTK_BOX(pVBox), pLabel_erreur_mauvaise_entree, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(pVBox), pHBox, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(pHBox), pButton_ok, TRUE, FALSE, 0);

    gtk_container_add(GTK_CONTAINER(pPopup), pVBox);

    g_signal_connect(G_OBJECT(pButton_ok), "clicked", G_CALLBACK(popup_close), (gpointer)pPopup);

    gtk_widget_show_all(pPopup);
}//fin fenetre_erreur

static GtkWidget *charge_image_bouton(void)
{
    GtkWidget *pBouton;
    GdkPixbuf *pb_temp, *pb;
    GtkWidget *image;
    
    // 1. Charger l’image et la redimensionner (100*100 pixels)
    pb_temp = gdk_pixbuf_new_from_file("logo-ok-png-6.png", NULL);
    if(pb_temp == NULL)
    {
        printf(" Erreur de chargement de l’image logo-ok-png-6.png!\n");
        return NULL;
    }
    pb = gdk_pixbuf_scale_simple(pb_temp, 100, 100, GDK_INTERP_NEAREST);
    
    // 2. Créer le bouton
    pBouton = gtk_button_new();
    // 3. Placer l’image
    image = gtk_image_new_from_pixbuf(pb);
    gtk_button_set_image(GTK_BUTTON(pBouton), image);
    
    return pBouton;
} // fin charge_image_bouton()

static void popup_close(GtkWidget *pButton, gpointer data){
    GtkWidget *recup_data = data;
    pButton = pButton;//inutile, mais sinon warning "unused variable à la compilation"
    gtk_widget_destroy(recup_data);
}//fin popup_close
