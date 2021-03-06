#include "graph.h"
#include <string.h>

int graph_recherche(char* l, graph_t g)
{
  int indice =0;
  while(indice < g.size_vertices)
  {
    if(!strcmp(l,g.data[indice].ligne))
    {
      return indice;
    }
    indice++;
  }
  return -1;
}

vertex_t vertex_delete(vertex_t v)
{
  free(v.nom);
  free(v.ligne);
  return v;
}

graph_t graph_new(int nbsommet, int nbarcs)
{
  graph_t g;
  g.size_egdes = nbarcs;
  g.size_vertices = nbsommet;
  g.data =NULL;
  if(g.size_vertices >0)
  {
    g.data = malloc(g.size_vertices * sizeof(vertex_t));
    if(g.data ==NULL)
    {
      printf("Fatal error : Unable to allocate new graph.data\n");
      g.size_egdes = 0;
      g.size_vertices = 0;
    }
  }
  return g;
}

vertex_t vertex_new(int num, char* line, double longi, double lat, char* name)
{
  vertex_t v;
  v.numero = num;
  v.ligne = malloc(128);
  strcpy(v.ligne,line);
  v.nom = malloc(128);
  strcpy(v.nom,name);
  v.x = lat;
  v.y=longi;
  v.edges=NULL;
  v.pere = -1;
  return v;
}

void vertex_print(vertex_t v)
{
  printf("%d %lf %lf %s %s",v.numero, v.x, v.y,v.ligne, v.nom);
}

void graph_print(graph_t g)
{
  int indice;
  puts("[");
  vertex_print(g.data[0]);
  for(indice=1;indice<g.size_vertices;indice++)
  {
    vertex_print(g.data[indice]);
  }
  puts("]");
}

graph_t graph_delete(graph_t g){
  int indice ;
  for(indice=0;indice<g.size_vertices;indice++){
    listedge_delete(g.data[indice].edges);
    vertex_delete(g.data[indice]);
  }
  free(g.data);
  return g;
}
