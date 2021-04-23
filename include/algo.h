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

//algorithme avec choix entre Astar et Dijkstra
int algorithme();
