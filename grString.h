#ifndef CUSTRING_H

struct grString{

 char* word;
 int length;
};

/*****************************
* getUserString: Dynamically *
* allocates storage for a    *
* string of 512 bytes, then  *
* removes any empty remaining*
* bytes after user input.    *
* returns string without any *
* wasted space.              *
*****************************/
char* getUserString();

/*****************************
* getStringSize: Returns the *
* size of the string         *
* excluding the NULL char.   *
*****************************/
int getStringSize(char* a);

/*****************************
* copyString: Returns a copy *
* of the parametized string. *
*****************************/
char* copyString(char* a);

/*****************************
* stringToInt: Returns       *
* parametized string as int. *
* Program terminates if      *
* the string is not a valid  *
* integer.                   *
*****************************/
int stringToInt(char* a);

/*****************************
* printString: Prints the    *
* dynamically allocated      *
* string on the console      *
* window.                    *
*****************************/
void printString(char* a);

#endif // CUSTRING_H
