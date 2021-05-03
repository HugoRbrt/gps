#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(void)
{
  int nb_space = 0;
  char* chaine = "  defence";
  printf("%s\n", chaine);
  nb_space = count_space(chaine);
  printf("%d\n",nb_space);
  char* station = "station";
  station = add_space(station,nb_space);
  printf("%s\n",station);
}
