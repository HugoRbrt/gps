#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL_phelma.h>
#include "graph.h"
#include "tadhash.h"
#include "algo.h"

int main(int argc, char* argv[])
{
  //declaration de variables
  double max_x = 0;
  double max_y = 0;
  double min_x = DBL_MAX;
  double min_y = DBL_MAX;
  FILE* f = fopen(argv[1],"r");
  if (f==NULL) { printf("Impossible d’ouvrir le fichier\n"); exit(EXIT_FAILURE);}
  hashtable_t tab_station = hashtable_new(700);
  int nb_space;
  graph_t g;
  //creation de la fenetre,
  SDL_PHWindow* f1=NULL ;
  f1=SDL_PH_CreateWindow(700,700);

  if (f1==NULL)
   {
  puts("impossible d’ouvrir une fenetre graphique") ;
  exit(EXIT_FAILURE) ;
    }
  SDL_PH_ClearWindow(f1);
  //on creer le graphe
  g = creation_graph_affichage(f,&max_x,&max_y,&min_x,&min_y,&tab_station, &nb_space,f1);
  SDL_PH_FlushWindow(f1);
int cout = choix_char_algo_affichage(g,max_x,max_y,min_x,min_y,&tab_station,f1);
/* libere la memoire */
  SDL_PH_DestroyWindow(f1);
  SDL_Quit();
  puts("*fin*");
  fclose(f);
return EXIT_SUCCESS;
}
