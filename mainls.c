#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>
#include <sys/stat.h>
#include "helper.h"





int main(int argc, char** argv){

    optn* flags_ls = malloc(sizeof(optn));
    char** dirname = malloc(sizeof(char*) * argc);
    int indx = 0;
    
    flags_ls->a_opt = 0;
    flags_ls->t_opt = 0;

    for(int i = 1; i < argc; i++)
    {
        if(argv[i][0] == '-'){
            int size =  strlen(argv[i]);
            for(int j = 1; j < size; j++)
            {
                if(argv[i][j] == 'a') flags_ls->a_opt = 1;
                if(argv[i][j] == 't') flags_ls->t_opt = 1;
            
            }
         }else{
             if (i >= 2 || (i > 2 && i ==  argc -1) ) dirname[indx++] = argv[i];
        }
        
    }
   
    
    my_ls(dirname, indx, flags_ls);
    free(flags_ls);
    free(dirname);
    return 0;
}