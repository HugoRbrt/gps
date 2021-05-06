#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL_phelma.h>
#include "affichage.h"

void max_x_y(double*max_x,double*max_y,double*min_x,double*min_y,double x,double y)
{
  if(x > *max_x)
  {
    *max_x = x;
  }
  if(x < *min_x)
  {
    *min_x = x;
  }
  if(y > * max_y)
  {
    *max_y = y;
  }
  if(y < * min_y)
  {
    *min_y = y;
  }
}

void trace_arc(SDL_PHWindow* f1,double x1,double y1,double x2,double y2,double max_x,double max_y,double min_x, double min_y,int color)
{
  //il faut d'abord faire une transofrmation des donnee
  int xf1 = 1+(x1-min_x)*695/(max_x-min_x);
  int yf1 = 1+(-y1+max_y)*695/(max_y-min_y);
  int xf2 = 1+(x2-min_x)*695/(max_x-min_x);
  int yf2 = 1+(-y2+max_y)*695/(max_y-min_y);
  lineColor(f1->rendu, xf1, yf1, xf2, yf2, color);
}
