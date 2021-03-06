#include "tadhash.h"
// Pour plus de propreté des concepts,
// on définit l'identifier NIL (signifiant "fin de liste")
// plutôt que d'utiliser directement NULL (signifiant "pointeur nul")
#define NIL NULL

list_hash_t list_hash_new() {
  return NIL;
}

int list_hash_is_empty( list_hash_t l ) {
  return NIL == l;
}

// Precondition : liste non vide
element_hash_t list_hash_first(list_hash_t l){
  assert(!list_hash_is_empty(l));
  return l->val;
}

list_hash_t list_hash_add_first( element_hash_t e, list_hash_t l ) {
  list_hash_t p = calloc( 1, sizeof( *p ) );
  if ( NULL == p ) {
    fprintf( stderr, "Fatal: Unable to allocate new list link.\n" );
    return l;
  }
  p->val  = e;
  p->next = l;
  return p;
}

// Precondition : liste non vide
list_hash_t list_hash_del_first( list_hash_t l ) {
  assert(!list_hash_is_empty(l));

  element_delete(l->val);
  list_hash_t p = l->next;
  free( l );
  return p;
}

void list_hash_print(list_hash_t l) {
  list_hash_t p;
  printf("( ");
  for ( p=l; ! list_hash_is_empty(p); p = p->next) {
    element_print( p->val );
    printf( " " );
  }
  printf(") ");
}

int list_hash_length(list_hash_t l) {
  int len = 0;
  list_hash_t p;
  for( p=l; ! list_hash_is_empty(p) ; p=p->next ) {
    len ++;
  }
  return len;
}

list_hash_t list_hash_find(element_hash_t e, list_hash_t l) {
  list_hash_t p;
  for( p=l; ! list_hash_is_empty(p) ; p=p->next ) {
    if( element_equal(&(p->val), &e) ) {
      return p;
    }
  }
  return NULL;
}


list_hash_t list_hash_delete(list_hash_t l) {
  list_hash_t p = l;
  while ( ! list_hash_is_empty(p) ) {
    p=list_hash_del_first(p);
  }
  return NULL;
}


list_hash_t list_hash_find_key(keys_t k, list_hash_t l){
  list_hash_t p;
  for( p=l; ! list_hash_is_empty(p) ; p=p->next ) {
    if( key_equal(p->val.key, k) ) {
      return p;
    }
  }
  return NULL;
}


list_hash_t list_hash_delete_key(keys_t k, list_hash_t l) { list_hash_t p=NULL, ppred=NULL;
  for (p=ppred=l; !list_hash_is_empty(p) && strcasecmp(p->val.key,k)!=0 ; p=p->next) ppred=p;
  if (list_hash_is_empty(p)) return l;
  else
    if (p==ppred) return list_hash_del_first(l);
    else {
      ppred->next=list_hash_del_first(p);
      return l;
    }
}

list_hash_t list_hash_add_last(element_hash_t e, list_hash_t l) {list_hash_t p=NIL, c=NIL;;
  if ( (p=calloc( 1, sizeof (*p)))!=NULL)  { p->val=e; }
  if (list_hash_is_empty(l)) return p;
  else {
    c=l;
    while (!list_hash_is_empty(c->next)) c=c->next ;
    c->next=p;
    return l;
  }
}

list_hash_t list_hash_concat(list_hash_t l1, list_hash_t l2) { list_hash_t c;
  if (list_hash_is_empty(l1)) return l2;
  else { for (c=l1; !list_hash_is_empty(c->next); c=c->next);
    c->next=l2;
    return l1;
  }
}

list_hash_t list_hash_copy(list_hash_t l) { list_hash_t c,copy;
  copy=list_hash_new();
  for (c=l; !list_hash_is_empty(c); c=c->next)
    copy=list_hash_add_last(element_clone(c->val),copy);
  return copy;
}

list_hash_t list_hash_inverse_copy(list_hash_t l) { list_hash_t c,copy;
  copy=list_hash_new();
  for (c=l; !list_hash_is_empty(c); c=c->next)
    copy=list_hash_add_first(element_clone(c->val),copy);
  return copy;
}

list_hash_t list_hash_fusion(list_hash_t l1, list_hash_t l2) {
  // l est la liste resultant, p un pointeur pour la construire
  // p1 parcourt l1, p2 parcourt l2 en fonction du plus grand element
  list_hash_t p=list_hash_new();
  list_hash_t l=list_hash_new();
  list_hash_t p1=l1;
  list_hash_t p2=l2;

  // Initialisation de l avec le plus grand element de l1 et l2
  // Cas triviaux si l1 ou l2 est vide
  if (list_hash_is_empty(p1)) return p2;
  else if (list_hash_is_empty(p2)) return p1;
  else if (p1->val.value > p2->val.value) { l=p=p1; p1=p1->next; }
  else { l=p=p2; p2=p2->next; }

  // Parcours de l1 ou l2 et modification des chainages en fonction
  // du plus grand element
  // Arret rapide quand un des 2 listes est vide
  while (!list_hash_is_empty(p1) || !list_hash_is_empty(p2)) {
    if (!list_hash_is_empty(p1))
      if (!list_hash_is_empty(p2))
        if (p1->val.value > p2->val.value) { p->next=p1; p1=p1->next; }
        else {p->next=p2; p2=p2->next; }
      else { p->next=p1; return l; }
    else {p->next=p2; return l; }
    p=p->next;
  }
  return l;
}

list_hash_t list_hash_sort_value(list_hash_t l ) {
  list_hash_t l1,l2,p,p1,p2;
  l1=l2=p=p1=p2=list_hash_new();
  // Si la liste est vide ou de taille 1, elle est triee
  if (list_hash_is_empty(l) || list_hash_is_empty(l->next)) return l;

  // maillons pairs dans l1, maillons impairs dans l2
  p1=l1=l;
  p=p2=l2=l->next;
  while (!list_hash_is_empty(p)) {
    p1->next=p->next;
    p1=p1->next;
    p=p->next;
    if (!list_hash_is_empty(p)) {
      p2->next=p->next;
      p2=p2->next;
      p=p->next;
    }
  }
  if (p2) p2->next=NULL;
  if (p1) p1->next=NULL;

  // tri recursif de l1
  l1=list_hash_sort_value(l1);
  // tri recursif de l2
  l2=list_hash_sort_value(l2);
  // Fusion des listes triees
  return list_hash_fusion(l1,l2);
}

int list_hash_fprint(list_hash_t l, char* filename) {
  FILE* fd;
  list_hash_t p;
  int i=1;

  if ( (fd=fopen(filename,"w"))==NULL) return 0;
  for ( p=l; ! list_hash_is_empty(p); i++,p = p->next) {
    fprintf(fd, "%d\t",i );
    element_fprint(fd,p->val );
    fprintf(fd, "\n");
  }
  fclose(fd);
  return 1;
}

// Duplique les n premiers maillons
list_hash_t list_hash_dup_n(list_hash_t l, int n) { int i=0;
  list_hash_t c,copy;
    copy=list_hash_new();
    for (c=l; !list_hash_is_empty(c) && i<n; i++,c=c->next)
      copy=list_hash_add_last(element_clone(c->val),copy);
    return copy;
}
