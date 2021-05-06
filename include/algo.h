#include "graph.h"
#include "list.h"
#include "arc.h"
#include "tadhash.h"
#include "affichage.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <float.h>
#include <SDL2/SDL_phelma.h>

//Algorithme Dijkstra retourne 1 si chemin trouve, 0 sinon
int Dijkstra(int depart, int arrivee, graph_t g);

//Algorithme Astar retourne 1 si chemin trouve, 0 sinon
int Astar(int depart, int arrivee, graph_t g);

// retourne la distance euclidienne entre 2 vertex_t
double heuristique(vertex_t v, vertex_t a);

//Affichage du chemin(uniquement si Astar ou Dijkstra a trouver le chemin (donc retourner 1) ! (sinon boucle infinie)
void print_chemin(int depart, int arrivee, graph_t g);

//pareil mais avec une fenetre graphique
void affichage_chemin(int depart, int arrivee,double max_x,double max_y,double min_x,double min_y, graph_t g,SDL_PHWindow* f1);

//retourne le graph d'un fichier texte mais aussi une table de hash des numero avec le  nom des sommets
graph_t creation_graph(FILE* f, hashtable_t * h, int* nb_espace);

//retourne le graph d'un fichier texte mais aussi une table de hash des numero avec le  nom des sommets
graph_t creation_graph_affichage(FILE* f,double* max_x,double* max_y,double* min_x,double* min_y,hashtable_t* tab_station, int* nb_espace,SDL_PHWindow* f1);

//pareil mais l'affiche dans une fenetre graphique
int choix_char_algo_affichage(graph_t g,double max_x,double max_y,double min_x,double min_y,hashtable_t* tab_station,SDL_PHWindow* f1);

//realise le calcule du PCC et dit le pcc et prend le graphe construit avec la fonction precedent avec numero station
int choix_int_algo(graph_t g);

//realise le calcule du PCC et dit le pcc et prend le graphe construit avec la fonction precedent avec nom station
int choix_char_algo(graph_t g,hashtable_t* tab_station);

//mise a zero des couts dont l'arrivee d'un arc partant de numero possède le meme nom que numero
graph_t same_name(graph_t g, int numero);
