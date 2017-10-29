#include <stdio.h>

int main ( int argc, char * argv [] ) {

//    int i = 0;

    if ( argc > 1 ) {
        while ( argc > 1 ) {
//            printf ( "* ++ argv [ 0 ] = '%c';\n", * ++ argv [ 0 ] );
//            printf ( "( * ++ argv ) [ 0 ] = '%c';\n", ( * ++ argv ) [ 0 ] );
            printf ( "* ( ++ argv ) [ 0 ] = '%c'; argc = %d;\n", * ( ++  argv ) [ 0 ], argc );
            argc --;
        }
    

    }

    return 0;

}
