
//
//  main.c
//  charfreq
//
//  Created by Philippe Nadon on 2019-02-04.
//  Copyright © 2019 Philippe Nadon. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#include "charfreq.h"

int main( int argc, char *argv[]) {
    int charCount[28] = {};

    if( argc <= 1){
        readFile( charCount, NULL);
    }
    else for( int i = 1; i < argc; i++){
        readFile( charCount, argv[i]);
    }
    printCounts( charCount);
    exit(EXIT_SUCCESS);
}
/**
 *  Reads the file and updates charCount array with character count
 * @param charCount The array which contains the number of each character
 * @param fileArg The file to read, if any (otherwise standard IO is read)
 */
void readFile( int charCount[], char fileArg[]){
    char inChar;
    if( fileArg == NULL){
        while( (inChar = getc(stdin)) != EOF ) {
            sortChar(charCount, inChar);
        }
    }
    else {
        FILE *file = fopen( fileArg, "r");
        if( file == NULL){
            perror("Error: ");
            exit(EXIT_FAILURE);
        }
        while( (inChar = getc( file)) != EOF ) {
            sortChar(charCount, inChar);
        }
        fclose( file);
    }
}

/**
 * Determines which character count in charCount to increment
 * @param charCount The array which contains the number of each character
 * @param inChar The character to be sorted
 */
void sortChar(int *charCount, char inChar){
    charCount[
            inChar >= 'A' && inChar <= 'Z' ?
            inChar - 65:
            inChar >= 'a' && inChar <= 'z' ?
            inChar - 97:
            26
    ] += 1;
    charCount[27] += 1;
}

/**
 * Prints the resulting count of each character in charCount
 * @param charcount The array which contains the number of each character
 */
void printCounts( int charcount[]){
    for( int i = 0; i < 26; i++){
        printf("\n%c:%8d ( %.1f%%)",
                i+65, charcount[i], (float)charcount[i]*100/charcount[27]);
    }
    printf("\n\nOther characters:%8d ( %.1f%%)",
           charcount[26], (float)charcount[26]*100/charcount[27]);
    printf("\nTotal characters:%9d", charcount[27]);
}
