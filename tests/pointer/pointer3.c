#include <stdio.h>

#define SZ 100

void f1 ( char * a1, char * a2 );

void main () {

    char ar1 [ SZ ] = "string1";
    char ar2 [ SZ ];
    int i = 0;

    printf ( "Before f1 ar1 = %s;\n", ar1 );
    while ( ar1 != '\0' && i < 30 ) {
        printf ( "At step i = %d ar1 = \"%c\" in char and %p as pointer;\n", i, ar1 [ i ], ar1 [ i ] );
        i++;
    }

    f1 ( & ar2, & ar1 );
   
    printf ( "After f1 ar1 = %s; and ar2 = %s;\n", ar1, ar2 );

}

void f1 ( char * dest, char * src ) {

    int i = 0;

    while ( ( * dest = * src ) != '\0' && i < 10 ) {
        printf ( "in %d-th while step * dest = %c;.\n", i, * dest );
        * dest ++;
        * src ++;
        i++;
    }

}

