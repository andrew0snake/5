#include <stdio.h>

int main ( int argc, char * argv [] ) {

    int num = 0;
    int rev = 0;
    int c = 0; 

    if ( argc > 1 ) {
        printf ( "* argv = '%s';\n", * argv );
        printf ( "* argv [ 0 ] = %c;\n", * argv [ 0 ] );
        printf ( "* ++ argv = '%s';\n", * ++ argv );
        printf ( "* argv [ 0 ] = %c;\n\n", * argv [ 0 ] );
        * -- argv;

        printf ( "* argv = '%s';\n", * argv );
        printf ( "* argv ++ = '%s';\n", * argv ++ );
        printf ( "* argv = '%s';\n\n", * argv );

        printf ( "* argv [ 0 ] = %c;\n", * argv [ 0 ] );
        * ++ argv;
        printf ( "* argv [ 0 ] = %c;\n", * argv [ 0 ] );
//        * ++ argv [ 0 ];
        printf ( "* ++ argv [ 0 ] = %c;\n", * ++ argv [ 0 ] );
        * -- argv;
        * -- argv;

        while ( -- argc > 0 && ( * ++ argv ) [ 0 ] == '-' ) {            
            while ( ( c = * ++ argv [ 0 ]  ) ) {
                switch ( c ) {
                    case 'n':
                        num = 1;
                        printf ( "num = 1;\n" );
                        break;
                    case 'r':
                        rev = 1;
                        printf ( "rev = 1;\n" );
                        break;
                    default:
                        printf ( "wrong parameter;\n" );
                        argc = 0;
                        break;
                }
            }
        }
    }

    return 0;

}
