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
double cout;   //cout du sommet
int pere; //pere de la station numero (-1 si il y en a pas)
} vertex_t;

// Type graphe :
typedef struct {
int size_vertices;    // nombre de sommets
int size_egdes; // nombre d’arcs
vertex_t* data; // tableau des sommets, alloue dynamiquement
} graph_t;


//retourne le numero du sommet ayant le meme nom que l (-1 si n'existe pas)
int graph_recherche(char* l, graph_t g);

//creer et retourne un nouveau graph de la bonne taille
graph_t graph_new(int nbsommet, int nbarcs);

//creer un nouvel ligne
vertex_t vertex_new(int num, char* line, double longi, double lat);

//affiche une ligne de tableau
void vertex_print(vertex_t v);

//affiche le tableau
void graph_print(graph_t g);

//supprime graph
graph_t graph_delete(graph_t g);



#endif
