
#include "helper.h"
#include <stdio.h>

void display_list(char** file_arr, int size)
{   
    for(int i = 0; i < size; i++)
    {
        if( i == 0){
            printf("%s ",  file_arr[i]);
        }else if( i > 0  && i < size -1){
            printf(" %s ",file_arr[i]);
        }
        if( i == size -1) printf("%s\n",  file_arr[i]);
    }
    
}