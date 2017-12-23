#include <stdio.h>

#define LIM 100

void parse_input ( int argc, char * argv [] );

int main ( int argc, char * argv [] ) {

    parse_input ( argc, argv );

    return 0;

}



void parse_input ( int argc, char * argv [] ) {

    
    char exit = 1;
    int i = 0;
    int j = 0;

    for ( j = 0; j < argc; j ++ ) {
        printf ( "* ( argv + %d ) = %s;\n", j, * ( argv + j ) );
    }

    printf ( "----\n" );

    while ( i <= argc ) {       
        printf ( "before first check * ( * argv + %d ) = %c;\n", i, * ( * argv + i ) ); 
        if ( * ( * argv + i ) == '\"' ) {
            printf ( "before cycle argc = %d;\n", argc );
            exit = 1;
            for ( j = 0; exit; j ++ ) {                
                if ( ( * ( * argv + i ) + j ) == '\"' || ( * ( * argv + i ) + j ) == '\0' ) {
                    exit = 0;                               
                }
                else {
                    printf ( "( ( * argv + %d ) + %d ) = %c; argc = %d; argv = %s;\n", j, i, ( * ( * argv + j ) + i ), argc, argv );
                }
            }
            argv ++;
            argc --;            
        }
        else {    
            printf ( "* argv [ %d ] = %c;\n", 0, * argv [ 0 ] );
            printf ( "and whole string = %s;\n\n", * argv );
            argv ++;
            argc --;
        }
        i ++;
    }

}

