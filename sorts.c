#include "helper.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>




char** sort_lex(char** my_arr, int size){ 
    for (int i = 0; i < size; ++i){
        for (int j = i + 1; j < size; ++j) {
          
        
         if (strcmp(my_arr[i], my_arr[j]) > 0) {
             my_swap(&my_arr[i], &my_arr[j]);
         }
      }
    }
    return my_arr;
}

char** sort_time(char** my_arr, int size, char* dirname){
    
    
    struct stat sb;
    long int* times =  malloc(sizeof(unsigned long int) * size);

    
    for(int i = 0; i < size; i++){
        
        char* path = malloc(sizeof(char) *  (strlen(my_arr[i]) + strlen(dirname) + 10));
         if( strcmp(dirname, ".") == 0){
            if( strcmp(my_arr[i], ".") == 0 || strcmp(my_arr[i], "..") == 0){
                strcpy(path, my_arr[i]);
            }else{
                strcpy(path, "./");
                strcat(path, my_arr[i]);
            }
        }else{
            strcpy(path, "./");
            strcat(path, dirname);
            strcat(path, "/");
            strcat(path, my_arr[i]);
        }
       
        lstat(path, &sb);
        times[i] = sb.st_mtim.tv_sec * (ONE_BILLION) + sb.st_mtim.tv_nsec;
        free(path);
    }
   
    long int num;
    for(int i = 0; i < size; i++){
        for(int j = i + 1; j < size; j++){
            if (times[i] < times[j]){
                num = times[i];
                times[i] = times[j];
                times[j] = num;
                my_swap(&my_arr[i], &my_arr[j]);
            }
        }
    }
    for(int i = 0; i < size; i++){
        for(int j = i + 1; j < size; j++){
            if (times[i] == times[j]){
                if (strcmp(my_arr[i], my_arr[j]) > 0)
                {
                    my_swap(&my_arr[i], &my_arr[j]);
                }
            }
        }
    }
    
    free(times);
    return my_arr;
    
}

char** sort_timedirs(char** dirname, int size){
    struct stat sb;
    long int* times =  malloc(sizeof(unsigned long int) * size);
    for(int i = 0; i < size; i++)
    {
        char* path = malloc(sizeof(char) *  (strlen(dirname[i]) + 10));
        strcpy(path, "./");
        strcat(path, dirname[i]);
        
        lstat(path, &sb);
        times[i] = (sb.st_mtim.tv_sec * (ONE_BILLION) + sb.st_mtim.tv_nsec);
        free(path);
        
    }
    long int num;
    for(int i = 0; i < size; i++)
    {
        for(int j = i + 1; j < size; j++)
        {
            if (times[i] < times[j])
            {
                num = times[i];
                times[i] = times[j];
                times[j] = num;
                my_swap(&dirname[i], &dirname[j]);
            }
        }
    }

    for(int i = 0; i < size; i++)
    {
        for(int j = i + 1; j < size; j++)
        {
            if (times[i] == times[j])
            {
                if (strcmp(dirname[i], dirname[j]) > 0)
                {
                    my_swap(&dirname[i], &dirname[j]);
                }
            }
        }
    }
    free(times);
    return dirname;
    
}
