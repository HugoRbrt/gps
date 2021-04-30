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
  char* line ;
  char* name ;
  char mot[512] ;
  graph_t g;
  f=fopen("text/graphe2.txt","r");
  if (f==NULL) { printf("Impossible d’ouvrir le fichier\n"); exit(EXIT_FAILURE);}
  fscanf(f,"%d %d ",&nbsommet,&nbarcs);
  fgets(mot,511,f);
  line = malloc(129*nbsommet+1);
  name = malloc(129*nbsommet+1);
  g = graph_new(nbsommet,nbarcs);
  for(indice=0;indice<g.size_vertices;indice++)
  {
    fscanf(f,"%d %lf %lf %s", &numero, &lat, &longi, line+(128*indice));
    fgets(name+(128*indice),128,f);
    if (mot[strlen(mot)-1]<32) mot[strlen(mot)-1]=0;
    g.data[indice] = vertex_new(numero, line+(indice*128), longi, lat, name+(128*indice));
  }
  fgets(mot,511,f);
  for(indice=0;indice<g.size_egdes;indice++)
  {
    fscanf(f,"%d %d %d ",&noeud_dep,&noeud_arriv,&val);
    g.data[noeud_dep].edges = listedge_add(edge_new(noeud_arriv,(double)val),g.data[noeud_dep].edges );
  }
  printf("affichage du graph : ");
  graph_print(g);
  puts("");printf("affichage de la liste des voisin de 2 : ");
  listedge_print(g.data[2].edges);
  puts("");

  puts("suppression graph et liste...");
  g = graph_delete(g);

  puts("*fin*");

  fclose(f);
}
