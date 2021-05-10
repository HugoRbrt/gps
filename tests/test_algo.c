#include "algo.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <float.h>

int main(int argc, char** argv)
{
  //initialisation des elements
  int depart,arrivee,count,choix,res=0;
  FILE* f;
  int indice,nbsommet, nbarcs,numero,noeud_dep, noeud_arriv,nb_space;
  double val;
  double lat,longi ;
  char** line;
  char** name;
  char mot[512] ;
  graph_t g;
  //ouverture fichier et allocation tableaux char
  f=fopen("text/graphe1.txt","r");
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
  for(indice=0;indice<nbsommet;indice++)                 //Boucle pour rensigner les sommets dans le graph
  {
    fscanf(f,"%d %lf %lf %s", &numero, &lat, &longi, line[indice]);
    fgets(name[indice],128,f);
    if (mot[strlen(mot)-1]<32) mot[strlen(mot)-1]=0;
    g.data[indice] = vertex_new(numero, line[indice], longi, lat,name[indice]);
  }
  fgets(mot,511,f);
  for(indice=0;indice<g.size_egdes;indice++)                  //Boucle pour rensigner les arcs dans le graph
  {
    fscanf(f,"%d %d %lf ",&noeud_dep,&noeud_arriv,&val);
    g.data[noeud_dep].edges = listedge_add(edge_new(noeud_arriv,(double)val),g.data[noeud_dep].edges );
  }
  for(count=0;count<g.size_vertices;count++)                //renseigne la longueur des listes
  {
    g.data[count].sizeedges = listedge_size(g.data[count].edges);
  }
  //choix algorithme est execution de l'algorithme
  int cout = choix_int_algo(g);
  g = graph_delete(g);
  free(*line);free(line);free(*name);free(name);
  puts("*fin*");
  fclose(f);
}
