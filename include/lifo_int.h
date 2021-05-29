#ifndef _LIFO_INT_H
#define _LIFO_INT_H
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "graph.h"


// 1. Définition des types maillon (link_t) et liste (list_t)
typedef struct _link {
  int val; /* un int de la liste*/
  struct _link *next; /* l'adresse du maillon suivant */
} link_t, *lifo_int_t;


// Crée et retourne un pile vide ou NULL en cas d'erreur
lifo_int_t lifo_new();

// Supprime le premier element de la pile
lifo_int_t lifo_del_first(lifo_int_t p);

// Détruit la pile et retourne une pile vide
lifo_int_t lifo_delete(lifo_int_t stack);

// Retourne 1 si la pile  stack   est vide, 0 sinon
int lifo_is_empty(lifo_int_t stack);

// Ajoute l'élément e à la pile  stack  et retourne la nouvelle pile
lifo_int_t lifo_push(int e, lifo_int_t stack);

// Retourne l'élément en tête de pile (sans l'enlever de la pile)
// PRECONDITION : la pile  stack  ne doit pas être vide
int lifo_peek(lifo_int_t stack);

// Enlève l'élément en tête de la pile, et retourne cet élément
// PRECONDITION : la pile pointée par  p_stack  ne doit pas être vide
int lifo_pop(lifo_int_t * p_stack);

lifo_int_t lifo_delete(lifo_int_t stack);

void lifo_print(lifo_int_t stack, graph_t g);
#endif
