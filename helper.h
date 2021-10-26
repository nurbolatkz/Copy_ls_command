#ifndef HELPER_H_
#define HELPER_H_

#define ONE_BILLION 100000000
typedef struct flag {

    int a_opt;
    int t_opt;

} optn;

void read_Dir(char* dir, optn* flags) ; 

void display_list(char** filenames, int size);

char** sort_lex(char** my_arr, int size);

char** sort_time(char** my_arr, int size, char* dirname);

void my_swap(char** a, char** b);

char** sort_timedirs(char** dirname, int size);

void my_ls(char** dirname, int indx, optn* flags_ls);

#endif //Header