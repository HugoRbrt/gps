#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "arc.h"
#include "graph.h"


int main(int argc, char** argv)
{
  FILE* f;
  int indice,nbsommet, nbarcs,numero,noeud_dep, noeud_arriv, val;
  double lat,longi ;
  char line[128] ;
  char mot[512] ;
  graph_t g;
  f=fopen("text/graphe1.txt","r");
  if (f==NULL) { printf("Impossible d’ouvrir le fichier\n"); exit(EXIT_FAILURE);}
  fscanf(f,"%d %d ",&nbsommet,&nbarcs);
  fgets(mot,511,f);
  g = graph_new(nbsommet,nbarcs);
  for(indice=0;indice<g.size_vertices;indice++)
  {
    fscanf(f,"%d %lf %lf %s", &numero, &lat, &longi, line);
    fgets(mot,511,f);
    if (mot[strlen(mot)-1]<32) mot[strlen(mot)-1]=0;
    g.data[indice] = vertex_new(numero, line, longi, lat);
  }

  fgets(mot,511,f);
  for(indice=0;indice<g.size_egdes;indice++)
  {
    fscanf(f,"%d %d %d ",&noeud_dep,&noeud_arriv,&val);
    g.data[noeud_dep].edges = listedge_add(edge_new(noeud_arriv,(double)val),g.data[noeud_dep].edges );
  }
  printf("affichage du graph : ");
  graph_print(g);
  puts("");printf("affichage de la liste des voisin de 4 : ");
  listedge_print(g.data[4].edges);
  puts("");

  puts("suppression graph et liste...");
  g = graph_delete(g);

  puts("*fin*");

  fclose(f);
}
