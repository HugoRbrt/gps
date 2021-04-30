#include "algo.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <float.h>


int main(int argc, char** argv)
{
  hashtable_t tab_station;
  tab_station = hashtable_new(26); //reste a definir m; ~le nombre de station differente pour le metro
  FILE* f;
  graph_t g = creation_graph(f,&tab_station);
  int cout = choix_char_algo(g,&tab_station);
  fclose(f);
}
