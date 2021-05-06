#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL_phelma.h>
#include "graph.h"
#include "tadhash.h"
#include "algo.h"

int main()
{
  //declaration de variables
  FILE* f = fopen("text/metroetu.txt","r");
  if (f==NULL) { printf("Impossible d’ouvrir le fichier\n"); exit(EXIT_FAILURE);}
  hashtable_t tab_station = hashtable_new(30);
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
  g = creation_graph_affichage(f ,&tab_station, &nb_space,f1);
  SDL_PH_FlushWindow(f1);

  puts("Taper une touche pour continuer") ;
  getchar() ;
/* libere la memoire */
  SDL_PH_DestroyWindow(f1);
  SDL_Quit();
  puts("*fin*");
  fclose(f);
return EXIT_SUCCESS;
}
