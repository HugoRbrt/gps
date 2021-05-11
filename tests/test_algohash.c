#include "algo.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <float.h>

//pas de fuite memoire

int main(int argc, char** argv)
{
  FILE* f;
  int nb_space;
  graph_t g;
  hashtable_t tab_station = hashtable_new(30); //(choix de 30 arbitraire)
  f=fopen("text/metroetu.txt","r");
  if (f==NULL) { printf("Impossible d’ouvrir le fichier\n"); exit(EXIT_FAILURE);}

  //creation du graph :
  g = creation_graph(f,&tab_station,&nb_space);

  //choix algorithme est execution de l'algorithme
  int cout = choix_char_algo(g,&tab_station);
  tab_station = hashtable_delete(tab_station);
  g = graph_delete(g);
  puts("*fin*");
  fclose(f);
}
