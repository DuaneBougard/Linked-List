/* 
 * File:   main.c
 * Author: Duane Bougard
 * Student Number: 3566258
 * Created on 30 August 2018, 10:07 AM
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Header.h"
//#include "LinkedList.c"
#include <ctype.h>

/*
 * 
 */
int main(int argc, char** argv) {

    char const* const filename=argv[1];
    FILE *fp=fopen(filename,"r");
    char str[500];
    while(fgets(str,sizeof(str),fp))
    {
        str[strcspn(str,"\r\n")]=0;
        char *command=strtok(str," ");
        if(command!=NULL)
        {
            int func=Function(command);
            char *string=strtok(NULL," ");
            compute(func,string);
        }
        else
        {
            error();
        }
    }
    fclose(fp);
    return 0;
}
