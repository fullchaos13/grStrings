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


char* combineStrings(const char* a, const char* b, Bool isSpace){

 int totalSize = 0;
 int counter;
 char* newString;

    if(isSpace == TRUE){
        totalSize++;
    }

    totalSize += getStringSize(a);
    totalSize += getStringSize(b);
    totalSize++;

    if(!malloc(totalSize)){
        printf("Error: malloc failed.\n");
        exit(EXIT_FAILURE);
    }

    newString = (char*) malloc(totalSize);

    for(counter = 0; counter < getStringSize(a); counter++){

        *(newString + counter) = *(a + counter);
    }

    if(isSpace == TRUE){
        *(newString + counter) = ' ';
    counter++;
    }

    for(int i = 0; counter < totalSize; counter++, i++){

        *(newString + counter) = *(b + i);
    }

    *(newString + totalSize) = '\0';

    return newString;
}


void toUpper(char* a){

    for(char *i = a; i < a + getStringSize(a); i++){

        if(*i >= 'a' && *i <= 'z'){
            *i -= 32;
        }
    }
}


void toLower(char* a){

    for(char* i = a; i < a + getStringSize(a); i++){

        if(*i >= 'A' && *i <= 'Z'){
            *i += 32;
        }
    }
}


int compareStrings(const char* a, const char* b){

 int mainCounter = 0;
 char* aLower;
 char* bLower;

    if(getStringSize(a) > getStringSize(b)){
        mainCounter = getStringSize(b);

    }else if(getStringSize(a) < getStringSize(b)){
        mainCounter = getStringSize(a);

    }else{
        mainCounter = getStringSize(a);
    }

    aLower = copyString(a);
    bLower = copyString(b);

    toLower(a);
    toLower(b);

    for(int i = 0; i < mainCounter; i++){


    }
}


