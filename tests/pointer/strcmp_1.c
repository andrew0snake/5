#include <stdio.h>

#define SIZE 20

int strcmp_1 ( char * s, char * t );

void main () {

    int rez = 0;

    char string_1 [ SIZE ] = "123qweasd";
    char string_2 [ SIZE ] = "123qwevbn";
    
    printf ( "string_1 = %s;\n", string_1 );
    printf ( "string_2 = %s;\n", string_2 );

    rez = strcmp_1 ( & string_2, & string_1 );

    printf ( "after comparing string_1 string_2 rez = %d;\n", rez );

}

int strcmp_1 ( char * s, char * t ) {

    int i = 0;

    for ( i = 0; s [ i ] == t [ i ]; i ++ ) {
        if ( s [ i ] = '\0' ) {
            return 0;
        };
    };

    return ( s [ i ] - t [ i ] );
}

