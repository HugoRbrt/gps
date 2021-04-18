#include "list.h"

list_t list_new() {
  return NULL;
}

int list_isempty( list_t l ) {
  return NULL == l;
}

list_t list_addfirst( vertex_t * vert, list_t l ) {
  list_t p = calloc( 1, sizeof( *p ) );
  if ( NULL == p ) {
    fprintf( stderr, "Fatal: Unable to allocate new list link.\n" );
    return l;
  }
  p->v = vert;
  p->next = l;
  return p;
}

list_t list_addsort( vertex_t * vert,  list_t l ){
  if ( list_isempty( l )) {return list_addfirst( vert,l);}
  if ((vert->cout) < (l->v->cout)) {return list_addfirst( vert,l);}
  else {
    list_t pred, c;
    /* c : le pointeur courant, pred : celui qui précéde c */
    pred = l;
    c = l->next;
    while ( ! list_isempty( c ) && (vert->cout > c->v->cout) ) {
      pred = c;
      c = c->next;
    }
    /* On réutilise la fonction list_add_first
       car on ajoute un maillon
       en tête de la liste commençant par c
       (le premier élément plus grand que e)
       et cette nouvelle liste devient
       la suite de l'élément qui précède e */
    pred->next = list_addfirst(vert,c );
    return l;
  }
}

// Precondition : liste non vide
list_t list_delfirst( list_t l ) {
  assert(!list_isempty(l));
  list_t p = l->next;
  free( l );
  return p;
}

void list_print(list_t l) {
  if(!list_isempty(l))
  {
    list_t p;
    printf("( ");
    for ( p=l; ! list_isempty(p); p = p->next) {
      vertex_print(*(p->v));
      if(p->next!=NULL){printf( " ; " );}
    }
    printf(")\n");
  }
}

int list_length(list_t l) {
  int len = 0;
  list_t p;
  for( p=l; ! list_isempty(p) ; p=p->next ) {
    len ++;
  }
  return len;
}

list_t list_findnum(int num, list_t l) {
  list_t p;
  for( p=l; ! list_isempty(p) ; p=p->next ) {
    if( num == p->v->numero ) {
      return p;
    }
  }
  return NULL;
}

list_t list_delete(list_t l)
{
  list_t p = l;
  while(!list_isempty(p))
  {
    p = list_delfirst(p);
  }
  return NULL;
}
