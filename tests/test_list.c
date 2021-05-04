#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "list.h"
#include "graph.h"


int main(int argc, char** argv)
{
  vertex_t e1 = vertex_new(0,"n",0.0,0.0,"nom_n");
  e1.cout = 1;
  vertex_t e2 = vertex_new(1,"num0",-1.0,3.0,"nom_num0");
  e2.cout =2;
  vertex_t e3 = vertex_new(2,"num1",0.0,-7.0,"nom_num1");
  e3.cout = 3;
  list_t liste = list_new();

  puts("affichage liste initialise:");
  list_print(liste);puts("");

  liste = list_addsort(&e1,liste);
  puts("affichage liste avec e3:");
  list_print(liste);puts("");

  liste = list_addsort(&e3,liste);
  puts("affichage liste avec e3 et e1 triee:");
  list_print(liste);puts("");

  liste = list_addsort(&e2,liste);
puts("affichage liste avec e1, e2 et e3 triee:");
list_print(liste);puts("");

  printf("affichage taille liste (normalement 3): ");
  printf("%d",list_length(liste));puts("");

  printf("affichage du nom de maillon de numero 2 (normalement num1) : %s",list_findnum(2,liste)->v->ligne);
  puts("");

  puts("suppression de la liste");
  liste = list_delete(liste);
  printf("affichage liste supprimé (normalement rien): ");
  list_print(liste);
  puts("");puts("*fin*");
}
