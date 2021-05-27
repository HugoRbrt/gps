#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "graph.h"

//pas de fuite memoire

int main(int argc, char** argv)
{
  vertex_t e1 = vertex_new(0,"n",0.0,0.0,"nom n");
  vertex_t e2 = vertex_new(1,"num0",-1.0,3.0,"nom num0");
  vertex_t e3 = vertex_new(2,"num1",0.0,-7.0,"nom num1");
  graph_t g = graph_new(3,0);

  puts("affichage vertex e1 :");
  vertex_print(e2);puts("");

  puts("affichage graph initialise:");
  graph_print(g);puts("");

  g.data[0]=e1;
  g.data[1]=e2;
  g.data[2]=e3;
  puts("affichage graph rempli:");
  graph_print(g);puts("");

  printf("numero de sommet de nom n (devrait afficher 0) : %d",graph_recherche("n",g));
  puts("");
  printf("numero de sommet de nom n0 (devrait afficher -1 qui signifie qu'il n'y en a pas) : %d",graph_recherche("n0",g));
  puts("");
  puts("suppression graph...");
  g = graph_delete(g);

  puts("*fin*");
}
