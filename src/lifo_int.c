#include "lifo_int.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//-- le type de pile est definie par le type list donc on peut reutiliser les fonctions

lifo_int_t lifo_new(void) {	return NULL; }

int lifo_is_empty(lifo_int_t p) {return NULL ==p; }

// pas de cdt sur la liste vide
lifo_int_t lifo_push (int e,lifo_int_t p){
  lifo_int_t q = calloc(1,sizeof(*q));
  if(NULL == q) {
    fprintf( stderr, "Fatal: Unable to allocate new list link.\n" );
    return p;
  }
  q->val = e;
  q->next =p;
  return q;
}


lifo_int_t lifo_del_first(lifo_int_t p) {
  assert(!lifo_is_empty(p));
  lifo_int_t q = p->next;
  free(p);
  return q;
}

// la pile n'est pas modifiée
int lifo_peek(lifo_int_t p){
  assert(!lifo_is_empty(p));
  int e = p->val;
  return e;
}

// attention: la pile est modifiee
int lifo_pop(lifo_int_t* ap)	{
  assert(*ap != NULL);
  int elem;
  elem = lifo_peek(*ap);
  *ap =lifo_del_first(*ap);
  return elem;
}


void lifo_print(lifo_int_t p, graph_t g) {
  lifo_int_t q;
  printf("( ");
  for(q=p; !lifo_is_empty(q); q = q->next) {
    printf("%d",q->val);
    printf(" ");

//affichage des correspondance du metro an cas de changement de ligne
    if((!lifo_is_empty(q->next))&&(strcmp(g.data[q->val].ligne,g.data[q->next->val].ligne)!=0)) {printf("(Changement de ligne vers %s) ",g.data[q->next->val].ligne);}
  }
  printf(")\n");
}

lifo_int_t lifo_delete(lifo_int_t p)
{
  while( ! lifo_is_empty(p))
  {
    p = lifo_del_first(p);
  }
  return p;
}
