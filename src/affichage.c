#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL_phelma.h>
#include "affichage.h"

void max_x_y(double*max_x,double*max_y,double x,double y)
{
  if(x > *max_x)
  {
    *max_x = x;
  }
  if(y > * max_y)
  {
    *max_y = y;
  }
}

void trace_arc(SDL_PHWindow* f1,double x1,double y1,double x2,double y2,double max_x,double max_y)
{
  //il faut d'abord faire une transofrmation des donnee
  int xf1 = x1*700/max_x;
  int yf1 = y1*700/max_y;
  int xf2 = x2*700/max_x;
  int yf2 = y2*700/max_y;
  lineColor(f1->rendu, xf1, yf1, xf2, yf1, SDL_PH_BLACK);

}
