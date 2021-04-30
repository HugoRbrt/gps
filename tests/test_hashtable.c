#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "tadhash.h"



int main()
{

  int value;
  hashtable_t t = hashtable_new(2);
  hashtable_put("station_1",1,t);
  hashtable_put("station_1",2,t);
  hashtable_put("station_2",3,t);
  hashtable_put("station_3",4,t);
  hashtable_put("station_2",5,t);

  hashtable_print(t);

  hashtable_get_value("station_1",&value,t);
  printf("la valeur associe a station_1 est : %d\n",value);
  hashtable_get_value("station_4",&value,t);
  printf("la valeur associe a station_4 est : %d\n",value);

  t = hashtable_delete(t);
  hashtable_print(t);
}
