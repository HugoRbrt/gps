#ifndef _ARC_H
#define _ARC_H
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

//On utilise la structure d'arcs chainée triée selon le cout

// Type arc
typedef struct {
int arrivee; // L’indice du sommet d’arriv ́ee de l’arc
double cout; // Le cout (distance) de l’arc
} edge_t;

// Type liste chaînée d’arcs
typedef struct maillon_edge {
edge_t val; // ou edge t* val, suivant votre choix : liste d’arcs ou de pointeurs d’arcs
struct maillon_edge * next;
}* listedge_t;

//Crée 1 arc
edge_t edge_new(int arrivee, double cout);

//Compare 2 arcs retourne 1 si e1>e2, 0 si =, -1 si e1<e2
int edge_compare(edge_t e1, edge_t e2);

//Affiche un arc
void edge_print(edge_t e);

// Crée une liste d'arcs vide
listedge_t listedge_new();

//affiche liste d'arcs avec espace entre element ET/OU parenthese
void listedge_print(listedge_t l);

//retourne 1 si vide, 0 sinon
int listedge_isempty(listedge_t l);

//Ajouter un arc à une liste d'arcs triée
listedge_t listedge_add( edge_t e, listedge_t l );

//retourne le min de la list
edge_t listedge_min(listedge_t l);

//retourne la taille de la liste d'arcs
int listedge_size(listedge_t l);

//supprime et libère le premier maillon de la liste d'arc
//Precondition : liste non vide
listedge_t listedge_delfirst(listedge_t l);

//libère la liste d'arcs
listedge_t listedge_delete(listedge_t l);


#endif
