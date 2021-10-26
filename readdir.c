#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>
#include <sys/stat.h>
#include "helper.h"


void  read_Dir(char* dirname, optn* flags)
{   
  
    DIR*  dr = opendir(dirname);
    struct dirent* entry;

    char** filenames = malloc(sizeof(char*) * 30);
    
    for(int i = 0; i < 30; i++){
        filenames[i] = malloc(sizeof(char) * 60);
    }
    
    
   
    
    int size = 0;
    
    if (dr == NULL){
        printf("Error in opening DIR\n");
        exit(1);
    }
    
    while( (entry = readdir(dr)) != NULL){

        if(flags->a_opt == 0 && (!strcmp(entry->d_name,".") || !strcmp(entry->d_name,"..") || !strcmp(entry->d_name,".git"))) continue;
        strcpy(filenames[size], entry -> d_name);
        size++;
    }
    
    if((flags -> a_opt == 1 ) || (flags -> a_opt == 0 && flags -> t_opt == 0 ))
    {   
        filenames = sort_lex(filenames, size);
    }
    if(flags -> t_opt == 1){
      
        filenames = sort_time(filenames, size, dirname);

    }
      display_list(filenames, size);
   
    for(int i = 0; i < 30; i++){
       
        free(filenames[i]);
    }
    closedir(dr);
    free(filenames);
}
    