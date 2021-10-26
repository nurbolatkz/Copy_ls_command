#include "helper.h"

void my_swap(char** a, char** b){
     char *t = *a;          
         *a = *b;          
         *b = t;  
}