#include "algo.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <float.h>
#include <time.h>

//fonction comme le test_algo mais avec 20 itérations$
//et compteur d'horloge pour étudier l'efficacité de nos fonctions
int main(int argc, char* argv[])
{
  //initialisation des elements
  int depart,arrivee,cout,compteur,count,choix,res=0;
  FILE* f;
  double cl,moyenne_temps;
  int indice,nbsommet, nbarcs,numero,noeud_dep, noeud_arriv,nb_space;
  double val;
  double lat,longi ;
  char** line;
  char** name;
  char mot[512] ;
  graph_t g;
  int nbtests = -1;
  while(nbtests <1){printf("Entrez le nombre d'essais à réaliser :");scanf("%d",&nbtests);}
  //ouverture fichier et allocation tableaux char
  f=fopen(argv[1],"r");
  if (f==NULL) { printf("Impossible d’ouvrir le fichier\n"); exit(EXIT_FAILURE);}
  fscanf(f,"%d %d ",&nbsommet,&nbarcs);
  fclose(f);
  printf("Moyenne des %d plus courts chemins (%d essais) :\n ",nbsommet,nbtests);

  for(compteur=1;compteur<nbtests+1;compteur++)
  {
    cl = clock();
    f=fopen(argv[1],"r");
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
    res = Astar(rand() % nbsommet,rand() % nbsommet,g);
    //if(res==1){printf("Chemin le plus court : ");print_chemin(depart,arrivee,g);}
    g = graph_delete(g);
    free(*line);free(line);free(*name);free(name);
    //mesure & affichage du temps pour une recherche
    cl = clock()-cl;
    printf("\n temps essai numero %d : %lf",compteur,cl/(double)CLOCKS_PER_SEC);
    moyenne_temps +=cl;
      fclose(f);
  }
  //affichage temps moyen
  printf("\n\n  ->temps total : %lf<-  ",moyenne_temps/(double)CLOCKS_PER_SEC);
  if(nbtests!=1){moyenne_temps = moyenne_temps/(nbtests-1);}
  printf("\n  ->temps moyen : %lf<-  \n",moyenne_temps/(double)CLOCKS_PER_SEC);
  puts("*fin*");
}
