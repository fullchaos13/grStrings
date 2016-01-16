#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "grString.h"

#define BUFFER_SIZE 256

char* getUserString(){

 char* tempString;
 char temp = '\0';
 int counter = 0;

    if(!malloc(BUFFER_SIZE + 1)){
        printf("Error: malloc fail.\n");
        exit(EXIT_FAILURE);
    }else{
        tempString = malloc(BUFFER_SIZE + 1);
    }

    for(char* i = tempString; i < tempString + BUFFER_SIZE; i++){

        scanf("%c", &temp);
        if(temp != '\n'){
            *i = temp;
            counter++;
        }else{
            *i = '\0';
            counter++;
            break;
        }
    }

    realloc(tempString, counter);

    return tempString;
}


int getStringSize(char* a){

 int counter = 0;

    for(;; a++){

        if(*a != '\0'){
            counter++;
        }else{
            break;
        }
    }
    return counter;
}


char* copyString(char* a){

 char* b;

    if(!malloc(getStringSize(a) + 1)){
        printf("Error: malloc fail.\n");
        exit(EXIT_FAILURE);
    }
    b = malloc(getStringSize(a) + 1);

    for(int i = 0; i < getStringSize(a) + 1; i++){

        *(b + i) = *(a + i);

    }
    return b;
}

int stringToInt(char* a){

 int num = 0, negativeFlag = 0, size = 0;

    size = getStringSize(a);

    if(*a == '-'){
        size--;
        negativeFlag = 1;
    }

    for(char* i = a + negativeFlag; size > 0; i++){

        if((*i <= '9') && (*i >= '0')){
            num += (*i - 48) * (int)pow(10.0, (float)size - 1.0);
            size--;
        }else{
            printf("Error: [%c] is not a valid digit.\n", *i);
            exit(EXIT_FAILURE);
        }
    }

    if(negativeFlag == 1){
       num *= -1;
    }

    return num;
}


void printString(char* a){

    for(char* i = a; *i != '\0'; i++){
        printf("%c", *i);
    }
}


