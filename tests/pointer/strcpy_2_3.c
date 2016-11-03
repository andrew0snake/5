#include <stdio.h>

#define SIZE 20

void strcpy_2 ( char * s, char * t );

void main () {

    char string_1 [ SIZE ] = "123qweasd";
    char string_2 [ SIZE ];
    
    printf ( "string_1 = %s;\n", string_1 );
    printf ( "string_2 = %s;\n", string_2 );

    strcpy_2 ( & string_2, & string_1 );

    printf ( "after copying string_2 = %s;\n", string_2 );

}

void strcpy_2( char * s, char * t ) {

    int i = 0;

    while ( * s ++ = * t ++ ) {
    };

}

