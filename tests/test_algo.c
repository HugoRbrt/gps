#include "algo.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <float.h>


int main(int argc, char** argv)
{
  int depart,arrivee,count,choix,res=0;
  FILE* f;
  int indice,nbsommet, nbarcs,numero,noeud_dep, noeud_arriv, val;
  double lat,longi ;
  char line[128] ;
  char mot[512] ;
  graph_t g;

  f=fopen("text/grapheUSAOuest.txt","r");



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

  for(count=0;count<g.size_vertices;count++)
  {
    g.data[count].sizeedges = listedge_size(g.data[count].edges);
  }
  printf("Choisissez l'algorithme a utiliser :\n1 : Dijkstra\n2 : A*\n");
  scanf("%d",&choix);
  if(choix==1)
  {
    puts("DEBUT DIJKSTRA");
    printf("Choisissez le numero de la station depart : ");
    scanf("%d",&depart);
    printf("Choisissez le numero de la station arrivee : ");
    scanf("%d",&arrivee);puts("");
    res = Dijkstra(depart,arrivee,g);
    printf("resultat : %d",res);puts("");
  }
  else if(choix==2)
  {
    puts("DEBUT A*");printf("Choisissez le numero de la station depart : ");
    scanf("%d",&depart);puts("");
    printf("Choisissez le numero de la station arrivee : ");
    scanf("%d",&arrivee);puts("");
    res = Astar(depart,arrivee,g);
    printf("resultat : %d",res);puts("");

  }
  else{printf("Error : wrong input");exit(0);}
  if(res==1){print_chemin(depart,arrivee,g);}
  puts("*fin*");
  fclose(f);
}
