#include "graph.h"

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
