#include "algo.h"

int Dijkstra(int depart, int arrivee, graph_t g)
{
  list_t Atraiter = list_new();   //ligne 1
  list_t Atteint = list_new();
  listedge_t l;
  int indice,k;
  double DistTemp;
  vertex_t * u=NULL;
  vertex_t * v=NULL;
  if((depart<0)||(depart>g.size_vertices)||(arrivee<0)||(arrivee>g.size_vertices)){return 0;}//si la station n'existe pas

  for(indice=0;indice<g.size_vertices;indice++) //ligne 2
  {
    g.data[indice].pcc = DBL_MAX;
    g.data[indice].cout = DBL_MAX;
  }
  g.data[depart].pcc = 0; //ligne 3
  g.data[depart].cout = 0;
  Atraiter = list_addsort( &g.data[depart], Atraiter);//ligne 4

  while(!list_isempty(Atraiter))//ligne 5
  {
    u = Atraiter->v;    //ligne 6
    Atraiter = list_delfirst(Atraiter);
    if(u->numero == arrivee)//ligne 7
    {
      return 1;//ligne 8
    }
    else//ligne9
    {//ligne10 de commentaire
      Atteint = list_addfirst(u,Atteint);//ligne11
      l = u->edges;//ligne12
      for(indice=0;indice<u->sizeedges;indice++)
      {
        DistTemp = u->pcc + l->val.cout;//ligne13
        v = &g.data[l->val.arrivee];
        if((NULL==list_findnum(v->numero,Atteint))&&(DistTemp<v->pcc))//ligne14
        {//ligne15 de commentaire
          v->cout = DistTemp;//ligne16
          v->pcc=DistTemp;//ligne17
          v->pere = u->numero;//trouver chemin
          Atraiter = list_addsort(v,Atraiter);//ligne18
        }//ligne19 de commentaire
        l = l->next;
      }//ligne20 de commentaire
    }//ligne21 de commentaire
  }//ligne22 de commentaire
  if(g.data[arrivee].cout<DBL_MAX)//ligne23
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int Astar(int depart, int arrivee, graph_t g)
{
  list_t Atraiter = list_new();   //ligne 1
  list_t Atteint = list_new();
  listedge_t l;
  int indice,k;
  double DistTemp;
  vertex_t * u=NULL;
  vertex_t * v=NULL;
  if((depart<0)||(depart>g.size_vertices)||(arrivee<0)||(arrivee>g.size_vertices)){return 0;}//si la station n'existe pas
  for(indice=0;indice<g.size_vertices;indice++) //ligne 2
  {
    g.data[indice].pcc = DBL_MAX;
    g.data[indice].cout = DBL_MAX;
  }
  g.data[depart].pcc = 0; //ligne 3
  g.data[depart].cout = 0;
  Atraiter = list_addsort( &g.data[depart], Atraiter);//ligne 4
  while(!list_isempty(Atraiter))//ligne 5
  {
    u = Atraiter->v;    //ligne 6
    Atraiter = list_delfirst(Atraiter);
    if(u->numero == arrivee)//ligne 7
    {
      return 1;//ligne 8
    }
    else//ligne9
    {//ligne10 de commentaire
      Atteint = list_addfirst(u,Atteint);//ligne11
      l = u->edges;//ligne12
      for(indice=0;indice<u->sizeedges;indice++)
      {
        DistTemp = u->pcc + l->val.cout;//ligne13
        v = &g.data[l->val.arrivee];
        if((NULL==list_findnum(v->numero,Atteint))&&(DistTemp<v->pcc))//ligne14
        {//ligne15 de commentaire
          v->cout = DistTemp+heuristique(*v,g.data[arrivee]);//ligne16
          v->pcc=DistTemp;//ligne17
          v->pere = u->numero;//trouver chemin
          Atraiter = list_addsort(v,Atraiter);//ligne18
        }//ligne19 de commentaire
        l = l->next;
      }//ligne20 de commentaire
    }//ligne21 de commentaire
  }//ligne22 de commentaire
  if(g.data[arrivee].cout<DBL_MAX)//ligne23
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

double heuristique(vertex_t v, vertex_t a)
{
  return (fabs(v.x - a.x) + fabs(v.y - a.y ))/2 ;
}

void print_chemin(int depart, int arrivee, graph_t g)
{
  printf("Chemin pour aller de %d a %d :",depart, arrivee);puts("");
  int indice = arrivee;
  while(indice != depart)
  {
    printf("%d <- ",indice);
    indice = g.data[indice].pere;
  }
  printf("%d",indice);puts("");
}
