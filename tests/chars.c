#include <stdio.h>

void main () {

    int i = 0;
    char end = '\0';
    char space = ' ';
    char tab = '\t';
    char * one;

    while ( i <= 127 ) {
        printf ( "i = %d in digital and \"%c\" in char;\n", i, i );
        i++;
    }

    printf ( "And EOF = \"%c\" in char and %d in digital.\n", end, end );

    end = EOF;
    one = & end;

    printf ( "pointer at EOF = %c in char; %d in digital and %p as pointer;\n", * one, * one, * one);

    if ( * one != EOF ) {
        printf ( "* one != EOF;\n" );
    }
    else {
        printf ( "* one = EOF;\n" );
    }
    
    printf ( "space = \"%c\" in char and %d in digit;\n", space, space );
    printf ( "tab = \"%c\" in char and %d in digit;\n", tab, tab );

    i = 1;

    if ( i ) {
        printf ( "i.\n" );
    }
    else {
        printf ( "Not i.\n" );
    }


}

