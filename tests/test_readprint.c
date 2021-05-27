#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "arc.h"
#include "graph.h"

//pas de fuite memoire

int main(int argc, char** argv)
{
  //initialisation des elements
  FILE* f=NULL;
  int indice,nbsommet, nbarcs,numero,noeud_dep, noeud_arriv, val;
  double lat,longi ;
  char** line=NULL ;
  char** name=NULL ;
  char mot[512] ;
  graph_t g;
//ouverture fichier et allocation tableau de char
  f=fopen("text/graphe2.txt","r");
  if (f==NULL) { printf("Impossible d’ouvrir le fichier\n"); exit(EXIT_FAILURE);}
  fscanf(f,"%d %d ",&nbsommet,&nbarcs);
  fgets(mot,511,f);
  line =  calloc(nbsommet,sizeof(*line));
  if (line==NULL) { printf("erreur alloaction tableau de char line\n"); exit(EXIT_FAILURE);}
  *line = calloc(nbsommet*128,sizeof(**line));
  if (*line==NULL) { printf("erreur alloaction tableau de char *name\n");free(line); exit(EXIT_FAILURE);}
  name =  calloc(nbsommet,sizeof(*name));
  if (name==NULL) { printf("erreur alloaction tableau de char name\n"); exit(EXIT_FAILURE);}
  *name = calloc(nbsommet*128,sizeof(**name));
  if (*name==NULL) { printf("erreur alloaction tableau de char *name\n");free(name); exit(EXIT_FAILURE);}
  g = graph_new(nbsommet,nbarcs);
  for(indice=1;indice<nbsommet;indice++)
  {
    name[indice]=name[indice-1]+128;
    line[indice]=line[indice-1]+128;
  }


  for(indice=0;indice<g.size_vertices;indice++)
  {
    fscanf(f,"%d %lf %lf %s", &numero, &lat, &longi, line[indice]);
    fgets(name[indice],128,f);
    if (mot[strlen(mot)-1]<32) mot[strlen(mot)-1]=0;
    g.data[indice] = vertex_new(numero, line[indice], longi, lat, name[indice]);
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
  free(line);free(name);
  fclose(f);
}
