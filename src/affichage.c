#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL_phelma.h>
#include "affichage.h"

int window_creation()
{
  /* Variable permettant de manipuler une fenetre */
  SDL_PHWindow* f1=NULL ;
  /* Creation d’une fenetre de dimension 300x100,
  Couleurs sur 32 bits, Fond de couleur blanche
  CRTL-C possible pour tuer le programme */
  f1=SDL_PH_CreateWindow(300,100);
  /* Verification de l’ouverture de la fenetre ;
  if (f1==NULL) {
  sinon, arret du programme */
  puts("impossible d’ouvrir une fenetre graphique") ;
  exit(EXIT_FAILURE) ; }
  SDL_PH_ClearWindow(f1); /* efface la fenetre graphique */
/* Affichage : dessiner sur la fenetre f1
une ligne noire entre les points (x=10,y=0) et (x=300,y=50)
Attention, la ligne n’est pas encore visible a l’ecran */
  lineColor(f1->rendu, 10, 0, 300, 50, SDL_PH_BLACK);
/* Met l’ecran a jour : la ligne apparait */
  SDL_PH_FlushWindow(f1);
/* un getchar pour attendre, sinon le programme se termine
et la fenetre disparait aussitot */
  puts("Taper une touche pour continuer") ;
  getchar() ;
/* libere la memoire */
  SDL_PH_DestroyWindow(f1); SDL_Quit();
return EXIT_SUCCESS; }
