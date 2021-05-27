#include "algo.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <float.h>

//pas de fuite memoire

int main(int argc, char* argv[])
{
  //initialisation des elements
  int depart,arrivee,choix,res=0;
  FILE* f;
  int nb_space;

  graph_t g;
  //ouverture fichier et allocation tableaux char
  f=fopen(argv[1],"r");
  if (f==NULL) { printf("Impossible d’ouvrir le fichier\n"); exit(EXIT_FAILURE);}

  g = creation_graph_sans_table(f,&nb_space);
  //choix algorithme est execution de l'algorithme
  int cout = choix_int_algo(g);
  g = graph_delete(g);
  puts("*fin*");
  fclose(f);
}
