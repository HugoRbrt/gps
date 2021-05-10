#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "arc.h"

//pas de fuite memoire

int main(int argc, char** argv)
{
  edge_t e1 = edge_new(3,11);
  edge_t e2 = edge_new(1,1);
  edge_t e3 = edge_new(2,10);
  edge_t e4 = edge_new(2,0);

  puts("affichage arc e1 :");
  edge_print(e1);puts("");
  puts("affichage arc e2 :");
  edge_print(e2);puts("");
  puts("affichage arc e3 :");
  edge_print(e3);puts("");
  puts("affichage arc e4 :");
  edge_print(e4);puts("");
  listedge_t l = listedge_new();

  puts("affichage liste vide :");
  listedge_print(l);puts("");

  puts("affichage list (e1) :");
  l = listedge_add(e1,l);
  listedge_print(l);puts("");

  puts("affichage list triee (e4,e2,e3,e1) :");
  l = listedge_add(e2,l);l = listedge_add(e3,l);l = listedge_add(e4,l);
  listedge_print(l);puts("");

  printf("minimum de la liste :");
  edge_print(listedge_min(l));puts("");

  printf("taille de la liste : %d",listedge_size(l));puts("");

  puts("Liberation de la liste...");
  l = listedge_delete(l);
  printf("taille de la liste : %d",listedge_size(l));puts("");

  puts("*fin*");
}
