#include "graph.h"
#include "list.h"
#include "arc.h"
#include "tadhash.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <float.h>

//Algorithme Dijkstra retourne 1 si chemin trouve, 0 sinon
int Dijkstra(int depart, int arrivee, graph_t g);

//Algorithme Astar retourne 1 si chemin trouve, 0 sinon
int Astar(int depart, int arrivee, graph_t g);

// retourne la distance euclidienne entre 2 vertex_t
double heuristique(vertex_t v, vertex_t a);

//Affichage du chemin(uniquement si Astar ou Dijkstra a trouver le chemin (donc retourner 1) ! (sinon boucle infinie)
void print_chemin(int depart, int arrivee, graph_t g);

//retourne le graph d'un fichier texte mais aussi une table de hash des numero avec le  nom des sommets
graph_t creation_graph(FILE* f, hashtable_t * h);

//realise le calcule du PCC et dit le pcc et prend le graphe construit avec la fonction precedent avec numero station
int choix_int_algo(graph_t g);

//realise le calcule du PCC et dit le pcc et prend le graphe construit avec la fonction precedent avec nom station
int choix_char_algo(graph_t g,hashtable_t* tab_station);

//mise a zero des couts dont l'arrivee d'un arc partant de numero possède le meme nom que numero
graph_t same_name(graph_t g, int numero);
