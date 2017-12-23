#include <stdio.h>

int main ( int argc, char * argv [] ) {

    int i = 0;

    for ( i = 0; * argv [ 0 ] != '\0'; i ++ ) {
        printf ( "* ++ argv [ 0 ] = %c;\n", * ++ argv [ 0 ] );
    }
    * ++ argv [ 0 ];

    printf ( "\n\nand now in reverse order:\n\n" );

    for ( i = 0; i < 8; i ++ ) {
        printf ( "* -- argv [ 0 ] = %c;\n", * -- argv [ 0 ] );
    }


    printf ( "\n----------\n" );
    i = 0;
    while ( i < argc ) {    
        printf ( "argv [ %d ] = %s;\n", i, argv [ i ] );
        i ++;  
    }

    printf ( "\n----------\n" );

    for ( i = 0; * argv [ 1 ] + i != '\0'; i ++ ) {
        printf ( "* argv [ %d ] + %d = %c;\n", 1, i, * argv [ 1 ] + i );
    }


    return 0;
}
