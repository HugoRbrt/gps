#include "arc.h"


edge_t edge_new(int a, double c)
{
  edge_t e;
  e.arrivee = a;
  e.cout = c;
  return e;
}

void edge_print(edge_t e)
{
  printf("%d,%lf",e.arrivee,e.cout);
}

int edge_compare(edge_t e1, edge_t e2)
{
  if(e1.cout>e2.cout){return 1;}
  if(e2.cout>e1.cout){return -1;}
  return 0;
}

listedge_t listedge_new()
{
  return NULL;
}

void listedge_print(listedge_t l)
{
  listedge_t p =l;
  if (l!=NULL)    //si la liste n'est pas vide
  {
    printf("( ");
    edge_print(p->val);
    printf(" ");
    while(p->next != NULL)
    {
      p = p->next;
      edge_print(p->val);
      printf(" ");
    }
    printf(")");
  }
}

listedge_t listedge_addfirst(edge_t e, listedge_t l)
{
  listedge_t p = calloc( 1, sizeof( *p ) );
  if ( NULL == p ) {
    fprintf( stderr, "Fatal: Unable to allocate new listedge link.\n" );
    return l;
  }
  p->val  = e;
  p->next = l;
  return p;
}

// Precondition : liste non vide
listedge_t listedge_delfirst( listedge_t l ) {
  assert(!listedge_isempty(l));
  listedge_t p = l->next;
  free( l );
  return p;
}

listedge_t listedge_delete(listedge_t l)
{
  listedge_t p = l;
  while(!listedge_isempty(p))
  {
    p = listedge_delfirst(p);
  }
  return NULL;
}



listedge_t listedge_add( edge_t e, listedge_t l ) {
  if ( listedge_isempty( l ) || edge_compare( e, l->val ) <= 0 ) {
    /* C'est une insertion en tête car
       soit l est vide
       soit e est plus petit que la tête de liste */
    return listedge_addfirst( e,l);
  }
  else {
    listedge_t pred, c;
    /* c : le pointeur courant, pred : celui qui précéde c */
    pred = l;
    c = l->next;
    while ( ! listedge_isempty( c ) && (edge_compare( e, c->val )==1) ) {
      pred = c;
      c = c->next;
    }
    /* On réutilise la fonction list_add_first
       car on ajoute un maillon
       en tête de la liste commençant par c
       (le premier élément plus grand que e)
       et cette nouvelle liste devient
       la suite de l'élément qui précède e */
    pred->next = listedge_addfirst( e, c );
    return l;
  }
}

int listedge_isempty(listedge_t l)
{
  return NULL==l;
}

edge_t listedge_min(listedge_t l)
{
  return l->val;
}

int listedge_size(listedge_t l)
{
  listedge_t p = l;
  int indice =1;
  if(listedge_isempty(l)){return 0;}
  while(p->next !=NULL )
  {
    indice++;
    p=p->next;
  }
  return indice;
}
