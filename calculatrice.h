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

/**
 * \fn constructeur_Donnees(void)
 * \brief alloue de la mémoire pour une sruct Donnees
 *
 * \return 
 *      pointeur sur Donnees 
 */
Donnees *constructeur_Donnees(void);

/**
 * \fn destructeur_Donnees(Donnees *donnees)
 * \brief libère un pointeur sur donnees
 * 
 * \param donnees un pointeur sur Donnees
 * 
 * \pre donnees!=NULL
 * \post donnees=NULL
 * 
 */
void destructeur_Donnees(Donnees *donnees);

/**
 * \fn set_Donnees_entry1(Donnees *donnees, GtkWidget *pEntry)
 * \brief Attribue une nouvelle valeur pEntry au champ 
 * pEntry1 de donnees
 * 
 * \pre donnees!=NULL
 * \post donnees->pEntry1 = pEntry
 *
 */
void set_Donnees_entry1(Donnees *donnees, GtkWidget *pEntry);

/**
 * \fn set_Donnees_entry2(Donnees *donnees, GtkWidget *pEntry)
 * \brief Attribue une nouvelle valeur pEntry au champ 
 * pEntry2 de donnees
 * 
 * \pre donnees!=NULL
 * \post donnees->pEntry2 = pEntry
 *
 */
void set_Donnees_entry2(Donnees *donnees, GtkWidget *pEntry);

/**
 * \fn set_Donnees_label(Donnees *donnees, GtkWidget *pLabel)
 * \brief Attribue une nouvelle valeur pLabel au champ 
 * pLabel de donnees
 * 
 * \pre donnees!=NULL
 * \post donnees->pLabel = pLabel
 *
 */
void set_Donnees_label(Donnees *donnees, GtkWidget *pLabel);

/**
 * \fn gestion_widget_fenetre(GtkWidget *pFenetre, GtkWidget *pVBox, GtkWidget *pHBox, GtkWidget *pHBox2, GtkWidget *pHBox3, GtkWidget *pLabel_Nombre1, GtkWidget *pLabel_Nombre2, GtkWidget *pEntry_nbr1, GtkWidget *pEntry_nbr2, GtkWidget *pButton_addition, GtkWidget *pLabel_somme)
 * 
 * \brief Gère les box contenue dans pFenetre + modifie taille et 
 * titre de la fenêtre et affiche les widgets dans la fenêtre
 * 
 */
void gestion_widget_fenetre(GtkWidget *pFenetre, GtkWidget *pVBox,
                            GtkWidget *pHBox, GtkWidget *pHBox2, GtkWidget *pHBox3,
                            GtkWidget *pLabel_Nombre1, GtkWidget *pLabel_Nombre2,
                            GtkWidget *pEntry_nbr1, GtkWidget *pEntry_nbr2,
                            GtkWidget *pButton_addition, GtkWidget *pLabel_somme);

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
 * \post label de l'addition modifié si arguments corrects sinon affichage fenêtre pop-up
 * spécifiant l'erreur
 *
 */
void addition(GtkWidget *pButton, gpointer data);

#endif