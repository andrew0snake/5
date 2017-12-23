#include <stdio.h>

int main ( int argc, char * argv [] ) {

    int i = 0;
    int j = 0;

    for ( i = 0; i < argc; i ++ ) {
        printf ( "* ( argv + %d ) = %s;\n", i, * ( argv + i ) );

        printf ( "( * ( argv + %d ) ) [ 4 ] = %c;\n", i, ( * ( argv + i ) ) [ 4 ] );
        printf ( "( * argv + %d ) [ 2 ] = %c;\n", i, ( * argv + i ) [ 2 ] );
//        printf ( "argv [ %d ] [ 2 ] = %c;\n", i, argv [ i ] [ 2 ] );
//        printf ( "* ( * ( argv + %d ) + 1 ) = %c;\n", i, * ( * ( argv + i ) + 1 ) );
//        printf ( "* ( * ( argv + %d ) + 2 ) = %c;\n", i, * ( * ( argv + i ) + 2 ) );
        printf ( "\n" );
    }

}
