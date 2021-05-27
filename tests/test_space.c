#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "space.h"

//pas de fuite memoire

int main(void)
{
  int nb_space = 0;
  char chaine[9] = "\tdefence";
  printf("fonction pour compter le nombre de tabulation dans un chaine de caractere : \n");
  printf("la chaine de catactere '%s' contient ", chaine);
  nb_space = count_space(chaine);
  printf("%d tabulations.\n",nb_space);
  char* station = "station";
  //station = add_space(station,nb_space);
  printf("fonction pour ajouter nb_space espaces avant une chaine de caractère et un retour a la ligne a la fin :\n");
  printf("normalement affichage de '\nstation' :'\n%s' \n",station);
}
