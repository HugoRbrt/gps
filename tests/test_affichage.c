#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL_phelma.h>

int main()
{

  SDL_PHWindow* f1=NULL ;

  f1=SDL_PH_CreateWindow(700,700);

  if (f1==NULL)
   {
  puts("impossible d’ouvrir une fenetre graphique") ;
  exit(EXIT_FAILURE) ;
    }
  SDL_PH_ClearWindow(f1);

  lineColor(f1->rendu, 10, 0, 300, 50, SDL_PH_BLACK);

  SDL_PH_FlushWindow(f1);

  puts("Taper une touche pour continuer") ;
  getchar() ;
/* libere la memoire */
  SDL_PH_DestroyWindow(f1);
  SDL_Quit();
return EXIT_SUCCESS;
}
