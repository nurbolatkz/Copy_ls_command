#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>
#include <sys/stat.h>
#include "helper.h"


void my_ls(char** dirname, int indx, optn* flags_ls){
    
    
    char* path;
    if(indx == 0){
        read_Dir(".", flags_ls);
    }else if( indx == 1){
        path = dirname[0];
        read_Dir(path, flags_ls);
    }else{
        if(flags_ls->a_opt == 1 || (flags_ls->a_opt == 0 && flags_ls->t_opt ==0)){
            dirname = sort_lex(dirname, indx);
        }
        if(flags_ls->t_opt == 1){
            dirname =  sort_timedirs(dirname, indx);
        }
        for(int i = 0; i < indx; i++){
            if(i == 0){
                printf("%s:\n", dirname[i]);
            }else{
                printf("\n%s:\n", dirname[i]);
            }
       
            path = dirname[i];
            read_Dir(path, flags_ls);
        }
    }

}
