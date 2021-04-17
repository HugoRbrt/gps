#ifndef _GRAPH_H
#define _GRAPH_H
#include "arc.h"

// Type sommet
typedef struct {
int numero; // indice du sommet
char* nom; // nom donne au sommet
char* ligne; // nom de la ligne, utile uniquement pour le metro
double x,y; // coordonnees latitude et longitude du sommet
int sizeedges; //nombre d'arcs qui partent de ce sommet
listedge_t edges; // liste des arcs qui partent de ce sommet
double pcc; // valeur du "plus court chemin" entre le sommet de d ́epart et ce sommet.
} vertex_t;

// Type graphe :
typedef struct {
int size_vertices;    // nombre de sommets
int size_egdes; // nombre d’arcs
vertex_t* data; // tableau des sommets, alloue dynamiquement
} graph_t;


//retourne le numero du sommet ayant le meme nom que l (-1 si n'existe pas)
int graph_recherche(char* l, graph_t g);














#endif
