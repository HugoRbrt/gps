#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "element_hash.h"

// 1. Définition des types maillon (link_hash_t) et liste (list_hash_t)
typedef struct _link {
  element_hash_t val; /* un élément de la liste*/
  struct _link *next; /* l'adresse du maillon suivant */
} link_hash_t, *list_hash_t;

// 2. Protoype des fonctions realisant les opérations essentielles du type abstrait Liste

// Crée une liste vide
list_hash_t list_new() ;

// Retourne VRAI si l est une liste vide
int list_is_empty(list_hash_t l);

// Retourne l'élément en tête de liste
// PRECONDITION : liste non vide
element_hash_t list_first(list_hash_t l);

// Retourne le reste de la liste
// PRECONDITION : liste non vide
list_hash_t list_next(list_hash_t l);

// Ajoute l'élément e en tête de la liste et retourne la nouvelle liste
list_hash_t list_add_first(element_hash_t e, list_hash_t l);

// Supprime le maillon en tête de liste et retourne la nouvelle liste
// PRECONDITION : liste non vide
list_hash_t list_del_first(list_hash_t l);

// Retourne le nombre d'éléments (ou de maillons) de la liste
int list_length(list_hash_t l);

// Retourne un pointeur sur le premier maillon contenant e,
// ou NULL si e n'est pas dans la liste
list_hash_t list_find(element_hash_t e, list_hash_t l);

// Affiche la liste
void list_print(list_hash_t l);

// Trouve une cle dans la list_is_empty
list_hash_t list_find_key(keys_t k, list_hash_t l);

//SUppresion du maillon de cle k
list_hash_t list_delete_key(keys_t k, list_hash_t l);

// Libère toute la liste et retourne une liste vide
list_hash_t list_delete(list_hash_t l);

// Compte le nombre de e dans la liste
int list_count(element_hash_t e, list_hash_t l) ;

// Ajoute en fin de liste
list_hash_t list_add_last(element_hash_t e, list_hash_t l) ;

// Concatene 2 listes
list_hash_t list_concat(list_hash_t l1, list_hash_t l2);

// Clone une liste
list_hash_t list_copy(list_hash_t l);

// Clone une liste a l'envers
list_hash_t list_inverse_copy(list_hash_t l);


// Supprime l'element en position n et retourne la nouvelle liste
list_hash_t list_remove_n(int n, list_hash_t l) ;

// Duplique les n premiers maillons
list_hash_t list_dup_n(list_hash_t l, int n) ;

// Fusionne 2 listes ordre croissant
list_hash_t list_fusion(list_hash_t l1, list_hash_t l2) ;

// Retourne la liste trie par ordre decroissant des frequences
// La liste n'est pas dupliquee
list_hash_t list_sort_value(list_hash_t l ) ;

// Sauvegarde des elemetns dnas un fichier
int list_fprint(list_hash_t l, char* filename) ;

// Duplique les n premiers maillons
list_hash_t list_dup_n(list_hash_t l, int n);
