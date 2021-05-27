#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "arc.h"
#include "algo.h"
#include "graph.h"

//pas de fuite memoire

int main(int argc, char** argv)
{
  //initialisation des elements
  FILE* f=NULL;
  int nb_space;
  graph_t g;
//ouverture fichier et allocation tableau de char
  f=fopen(argv[1],"r");
  if (f==NULL) { printf("Impossible d’ouvrir le fichier\n"); exit(EXIT_FAILURE);}

  g = creation_graph_sans_table(f,&nb_space);
  //afffichage graph correspondant au ficbhier
  printf("affichage du graph : ");
  graph_print(g);
  puts("");printf("affichage de la liste des voisin de 2 : ");
  listedge_print(g.data[2].edges);
  puts("");
//fin
  puts("suppression graph et liste...");
  g = graph_delete(g);
  puts("*fin*");
  fclose(f);
}
