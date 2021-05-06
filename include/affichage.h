#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL_phelma.h>

//permet de conserver les max des coordonnes
void max_x_y(double*max_x,double*max_y,double*min_x,double*min_y,double x,double y);

// permet de calculer et tracer les arcs
void trace_arc(SDL_PHWindow* f1,double x1,double y1,double x2,double y2,double max_x,double max_y,double min_x, double min_y,int color);
