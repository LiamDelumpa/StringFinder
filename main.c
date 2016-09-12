//
//  main.c
//  StringBinarySearch
//
//  Created by william delumpa on 9/8/16.
//  Copyright © 2016 william delumpa. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>


int main(int argc, const char *argv[]) {
    
    for(int  i=0; i<argc; i++){
        printf("%s\n", argv[i]);
    }
    //variables
    FILE *file = fopen( argv[1], "r" );
    int numLines = 0;
    char line[350];
    char buffer[350][350];
    const char* inputString = NULL;
    inputString = argv[2];
    
    
    //validating file
    if ( file == 0 )
    {
        printf( "Could not open file\n" );
    }
    else{
        printf("File open for reading\n");
    }
    
    //iterate through file, making each element of a file an element in the buffer.
    printf("%d\n",numLines );

    while (fgets(line, sizeof(line), file) != NULL) {
        strcpy(buffer[numLines], line);
        printf("%s %d", line,numLines);
        numLines++;
    }
    printf("Read file complete");
    
    
    int first = 0;
    int last = numLines;
    int middle = (first+last)/2;
    
    //perform binary search
    while (first <= last) {
        int result= strcasecmp(buffer[middle], inputString);
        char* find_input = strstr(buffer[first], inputString);
        

        
        if(result< 0){
            first = middle+1;
        }
        else if (result>0) {
            last = middle - 1;
        }
        else{
            if (find_input != NULL) {
                printf("%s\n", find_input);
                break;
            }
        }
    }
    
    if (first > last) {
        printf("%s not found, insert on line %d\n",inputString, first);
    }
    
    
    return 0;
    
}
