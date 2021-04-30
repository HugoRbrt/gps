#include "tadhash.h"
#include <ctype.h>
#include <string.h>

// Fonction classique efficace
/*unsigned int hash(char* s, int n)
{
  char * p = s;
  unsigned int hashcode = 0;
  while(p != '\0')
  {
    hashcode = (hashcode*31 + (unsigned char) (*p));
    p++
  }
  return hashcode % m;
}*/

unsigned int hash(char* s, int n){
  unsigned int h = 0;
  int i ;
  for(i = strlen(s) - 1 ; i >= 0 ; i-- ) {
    h = h * 31 + s[i];
  }
  return h % n;
}

hashtable_t hashtable_new(int m)
{
  hashtable_t t;
  t.size = 0;
  t.data = calloc(m, sizeof(list_hash_t)) ; // allocation du tableau de m listes
  if(t.data == NULL)
  {
    return t ; // échec de l'allocation => retourne une table vide
  }
  t.size = m;
  return t;
}
//a refaire
int hashtable_put(keys_t k, value_t v, hashtable_t t)
{
  element_hash_t element_to_put = element_new(k,v);
  unsigned int h = hash(k,t.size);
  int new_value;
  int get;
  if(hashtable_contains_key(k,t) == 0)
  {
    //il n y a pas la clef dans le tableau on ajoute l'element a la liste au niveau de hash
    t.data[h] = list_add_first(element_to_put,t.data[h]);
    // verif si la liste contient bien la valeur
    return hashtable_contains_key(k,t);
  }
  else
  {
    //l'element est deja present dans le tableau, on va donc l'actualiser
    t.data[h] = list_delete_key(k,t.data[h]);
    t.data[h] = list_add_first(element_to_put,t.data[h]);
    get = hashtable_get_value(k,&new_value,t);
    if ( new_value == v )
    {
    return 1;
    }
    return 0;
  }
}

int hashtable_contains_key(keys_t k,hashtable_t t)
{
  //on calcule la hash de k
  unsigned int h = hash(k,t.size);
  return (list_find_key(k,t.data[h]) != NULL);
}

int hashtable_get_value(keys_t k, value_t* pv, hashtable_t t)
{
  unsigned int h = hash(k,t.size);
  if(hashtable_contains_key(k,t)== 0)
  {
    *pv = 0;
    return 0;
  }
  //on se place dnas le else donc elle est presente, on recherche sa valeur;
  list_hash_t l = t.data[h];
  while(!key_equal(k,l->val.key))
  {
    //on compare a chaque fois les clefs, si la clefs est mauvais on continue,
    l = l->next;
  }
  //on est au bonne endroit de la liste,
  *pv = l->val.value;
  //on recupere la valeur et on la donne, on retourne 1 pour la reussite
  return 1;
}

int hashtable_delete_key(keys_t k, hashtable_t t)
{
  unsigned int h;
  if(hashtable_contains_key(k,t) == 0)
  {
    return 1;
  }
  else
  {
    h = hash(k,t.size);
    t.data[h] = list_delete_key(k,t.data[h]);
    return 1-hashtable_contains_key(k,t);
  }
}

hashtable_t hashtable_delete(hashtable_t t) {
  int count;

  for(count=0;count<t.size;count++)
  {
    t.data[count] = list_delete(t.data[count]);
  }
//tout est supprime on renvoie la table vide
  return t;
}

void hashtable_print(hashtable_t t) {
  int count;
  for(count = 0; count < t.size ;count++)
  {
    list_print(t.data[count]);
  }
}
