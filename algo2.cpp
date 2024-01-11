#include <stdio.h>

void remove_spaces(char* s) {
    char* read = s;
    char* write = s;
    while (*read) 
        (*read++ != ' ') ? *write++ = *(read - 1) : 0;
    *write = '\0';
}