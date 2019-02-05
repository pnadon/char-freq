//
//  main.c
//  charfreq
//
//  Created by Philippe Nadon on 2019-02-04.
//  Copyright © 2019 Philippe Nadon. All rights reserved.
//
#include <stdio.h>
#include "charfreq.h"

int main( int argc, char *argv[]) {

    char strBlock[1024];
    int charCount[28];

    if (argc <= 1) {
        readSI( strBlock);
    }
    else {
        readFile( )
    }
}

int readSI( char strBlock[]){
    printf("Enter a value:");
    scanf( "%s", strBlock);
    return 1;
}

void toUpperCaseBlock( char readBlock[], int blockSize){
    for (int i  = 0; i < blockSize; i++){
        if (readBlock[i] >= 'a' && readBlock[i] <='z'){
            readBlock[i] += -32;
        }
    }
}

void blockParser( char readBlock[], int blockSize, int charCount[]){
    for( int i = 0; i < blockSize && readBlock[i] >= 32; i++) {
            charCount[
                    readBlock[i] >= 'A' && readBlock[i] <= 'Z' ?
                    readBlock[i] - 65 : 26
                    ] += 1;
            charCount[27] += 1;
    }
}



