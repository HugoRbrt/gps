#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//permet de compter les espaces
int count_space(char* mot)
{
  int nb_space = 0;
  int count = 0;
  while(mot[count]=='\t')
  {
    nb_space++;
    count++;
  }
  return nb_space;
}


//permet d'ajouter les espaces
char* add_space(char* mot, int nb_space)
{
  int count = 0;
  int size = nb_space+1+strlen(mot);
  while(count<nb_space)
  {
    strcat(mot,"\t");
    count++;
  }
  strcat(mot,"\n");
  return mot;
}
