#include "algo.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <float.h>
#include <time.h>

int main(int argc, char* argv[])
{
  //initialisation des elements
  unsigned int compteur=1,compteur2=1,res=0,test_metro=0,nbtests = 0;
  int choix=-1,nb_espace;
  unsigned long cl;
  FILE* f;
  double moyenne_temps;
  graph_t g;
  /* pour des pbm d'optimisation, il est necessaire de refaire le graph lorsque qu'on change de ligne
    (donc pour le fichier metroetu), on verifie donc ici si on doit traiter le cas special de metroetu ou non
    PBM d'optimisation : dans le fichier metroetu il y a des lignes, pour les correspondance on estime que commencer
    ou arriver à la même gare sur des lignes différentes n'a pas d'importance, cependant cela met des arcs à 0,
    il faut donc annuler cela soit en optimisant plus le programme (nous n'avons pas eu le temps), soit en refesant la copntruction du graph)*/
  if(strcmp(argv[1],"text/metroetu.txt")==0){test_metro=1;printf("CAS special : test metroetu");}
  //choix de type de mesure et de nombre d'e
  while(nbtests <1){printf("Entrez le nombre d'essais à réaliser :");scanf("%d",&nbtests);}
  while (choix<1 || choix >3){printf("Entrez type de mesure à réaliser :\n1/construction du graph\n2/recherche par Dijkstra\n3/recherche par A*\n");scanf("%d",&choix);}

  while(compteur<nbtests+1)
  {
//construction graph
      if(choix==1){cl = clock();}//ouverture fichier et allocation tableaux char
    f=fopen(argv[1],"r");
      if (f==NULL) { printf("Impossible d’ouvrir le fichier\n"); exit(EXIT_FAILURE);}
    g = creation_graph_sans_table(f,&nb_espace);
    if(choix==1)
    {
      cl = clock()-cl;
      printf("\nconstruction graphe n°%d : %lf",compteur,cl/(double)CLOCKS_PER_SEC);
      moyenne_temps += cl;
    }//mesure & affichage du temps pour une recherche

//test algo dijkstra ou A*
    if(choix==2)
    {
      compteur2=1;
      while(compteur2<nbtests+1)
      {
        cl = clock();
        res = Dijkstra(random() * g.size_vertices/RAND_MAX,random() * g.size_vertices/RAND_MAX,g);
        cl = clock()- cl;
        //mesure & affichage du temps pour une recherche
        printf("\nrecherche Dijkstra n°%d : %lf",compteur2,cl/(double)CLOCKS_PER_SEC);
        moyenne_temps += cl;
        if(test_metro==1){compteur2=nbtests+1;}   //car dans le cas de metro_etu il faut refaire le graph pour refaire une recherche
        compteur2++;
      }
    }
    if(choix==3)
    {
      compteur2=1;
      while(compteur2<nbtests+1)
      {
        cl = clock();
        res = Astar(random() * g.size_vertices/RAND_MAX,random() * g.size_vertices/RAND_MAX,g);
        cl = clock()- cl;
        //mesure & affichage du temps pour une recherche
        printf("\nrecherche A* n°%d : %lf",compteur2,cl/(double)CLOCKS_PER_SEC);
        moyenne_temps += cl;
        if(test_metro==1){compteur2=nbtests+1;} //car dans le cas de metro_etu il faut refaire le graph pour refaire une recherche
        compteur2++;
      }
    }

    g = graph_delete(g);
    fclose(f);
    if(test_metro==1 || choix==1){compteur++;}//si test metroetu avec chgmt de ligne OU
                                              //si on doit mesure le temps de construction d'un graph : on doit reconstruire systematiquement
    else{compteur=nbtests+1;}
  }


  //affichage temps moyen
  printf("\n\n  ->temps total (%d essais) : %lf<-  ",nbtests,moyenne_temps/(double)CLOCKS_PER_SEC);
  if(nbtests!=1){moyenne_temps = moyenne_temps/(nbtests);}
  printf("\n  ->temps moyen : %lf<-  \n",moyenne_temps/(double)CLOCKS_PER_SEC);
  puts("*fin*");
  fclose(f);
}
