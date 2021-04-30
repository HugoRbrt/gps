#include "element.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

<<<<<<< HEAD
void element_print (element_t e) {
  printf("%s : %d; ", e.key,e.value);
}

void element_init (element_t* e) {
  e->value=0; e->key=NULL;
}

element_t element_empty() {
  element_t e;
  element_init(&e);
  return e;
}

int element_is_empty(element_t e) {
  element_t vide=element_empty();
  return element_equal(&e,&vide);
}

int element_equal(element_t* e1, element_t* e2) {
  return key_equal(e1->key,e2->key) && value_equal(e1->value,e1->value);
}

int value_equal(value_t v1, value_t v2) {
  return v1==v2;
}

int key_equal(keys_t k1, keys_t k2) {
  return strcasecmp(k1,k2)==0;
}

element_t element_clone(element_t e) {
  element_t clone;
  clone.value=e.value;
  clone.key = strdup(e.key);
  return clone;
}

element_t element_new(keys_t key, value_t value) {
  element_t e;
  e.key=strdup(key);
  e.value=value;
  return e;
}

element_t element_delete(element_t e) {
  if (e.key) free(e.key);
  e.key=NULL;
  e.key=0;
  return e;
}

void element_fprint (FILE* fd, element_t e) {
  fprintf(fd,"%s : %d ; ", e.key,e.value);
}
=======
typedef char* keys_t; 

typedef int value_t;

typedef struct {
  keys_t key;
  value_t value;
} element_t;

// Retourne un nouvel element initialisé avec les valeurs cle et valeur.
// L'espace mémoire pour stocker la clé est allouée dynamiquement.
element_t element_new(keys_t key, value_t value);

// Libère l'espace mémoire alloué pour l'element et retourne une élément vide (empty)
element_t element_delete(element_t e);

// Retourne un clone (meme cle, meme valeur)
element_t element_clone(element_t e);


// Affiche la cle (mot) et la valeur (nombre d'occurrences)
void element_print (element_t e);


// Initialise un couple cle, valeur avec le couple NULL,0
void element_init (element_t* e);

// Retourne un couple cle, valeur avec les valeurs NULL,0
element_t element_empty();

// Teste si le couple cle, valeur est NULL,0
int element_is_empty(element_t e);


// Teste si 2 clés (chaînes de char) sont egales, sans se préoccuper des majuscules et minuscules
int key_equal(keys_t, keys_t);

// Teste si 2 clés (chaînes de char) sont egales, sans se préoccuper des majuscules et minuscules
int value_equal(value_t, value_t);

// Teste si 2 couples sont égaux (meme cle, meme valeur)
int element_equal(element_t*, element_t*);

// Ecrit dans un fichier la cle (mot) et la valeur (nombre d'occurrences)
void element_fprint (FILE* fd, element_t e) ;
>>>>>>> 81e8b17ae78d01717d3612cc9c82f6a3d82a71dc
