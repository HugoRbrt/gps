#ifndef _LIST_H
#define _LIST_H
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "graph.h"

//On utilise la structure d'arcs chainée triée selon le cout

// Type liste chaînée d’arcs
typedef struct maillon {
vertex_t * v;
struct maillon  *next;
}* list_t;

// Crée une liste vide
list_t list_new() ;

// Retourne VRAI si l est une liste vide
int list_isempty(list_t l);

// Ajoute l'élément e en tête de la liste et retourne la nouvelle liste
list_t list_addfirst( vertex_t * v, list_t l );

// Ajoute l'élément ordre triee par cout croissant
list_t list_addsort( vertex_t * v, list_t l );

// Affiche la liste
void list_print(list_t l);

// Retourne le nombre d'éléments (ou de maillons) de la liste
int list_length(list_t l);

// Retourne un pointeur sur le premier maillon contenant le numero num,
// ou NULL si num n'est pas dans la liste
list_t list_findnum(int num, list_t l);

// Supprime le maillon en tête de liste et retourne la nouvelle liste
// PRECONDITION : liste non vide
list_t list_delfirst(list_t l);

//suprime la liste
list_t list_delete(list_t l);


#endif
