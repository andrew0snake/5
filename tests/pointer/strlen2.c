#include <stdio.h>

int strlen2 ( char * s );

char s [ 100 ] = "string1";
char * p1 = s;

void main () {

    int len = 0;

    len = strlen2 ( p1 );

    printf ( "len if string = %d;\n", len );
}

int strlen2 ( char * s ) {

    char * p2 = s;
    while ( * p2 != '\0' ) {
        p2++;
    }
    return p2 - s;
}

