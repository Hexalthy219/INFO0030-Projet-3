/**
 * \file calculatrice.h
 * \brief Ce fichier contient les déclarations de types et les prototypes des fonctions pour la gestion
 * de l'interface graphique de la calculatrice addition.
 * 
 * \author: Russe Cyril s170220
 * \date: 18-04-2020
 * 
 */

#ifndef __CALCULATRICE__
#define __CALCULATRICE__

/**
 * \struct typedef struct Donnees_t Donnees
 * \brief Déclaration du type opaque Donnees
 *
 */
typedef struct Donnees_t Donnees;

Donnees *constructeur_Donnees();

void destructeur_Donnees(Donnees *donnees);

void set_Donnees_entry1(Donnees *donnees, GtkWidget *pEntry);

void set_Donnees_entry2(Donnees *donnees, GtkWidget *pEntry);

void set_Donnees_label(Donnees *donnees, GtkWidget *pLabel);

// void creaction_fenetre()

/**
 * \fn addition(GtkWidget *pButton, gpointer data)
 * \brief Additionne les valeurs données par l'utilisateur et vérifie que celles-ci 
 * corresepondent à ce qui est attendu, sinon affiche une fenêtre caractérisant 
 * l'erreur à l'utilisateur
 * 
 * \param pButton un pointeur GtkWidget, le bouton ayant été activé pour 
 * accéder à cette fonction
 * \param data un gpointer les données transmises lors de la connection du bouton
 * 
 * \pre 
 * \post label de l'addition modifié si arguments corrects sinon affichage fenêtre pop-up
 * spécifiant l'erreur
 *
 */
    void addition(GtkWidget *pButton, gpointer data);

#endif