#include "graph.h"
#include "list.h"
#include "arc.h"
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
graphe_t creation_graph(hashtable_t * h);

//realise le calcule du PCC et dit le pcc et prend le graphe construit avec la fonction precedent
int choix_algo(graphe_t g);
