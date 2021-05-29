#ifndef _SPACE_H
#define _SPACE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// permet de compter les espaces en debut d'un mot
int count_space(char* mot);

// permet d ajouter les espaces au debut
char* add_space(char* mot, int nb_space);
#endif
