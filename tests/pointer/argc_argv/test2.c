#include <stdio.h>

void f1 ( int argc, char * argv [] );


int main ( int argc, char * argv [] ) {

    printf ( "And now we will se a work of f1!!!;\n" );

    f1 ( argc, argv );

}

void f1 ( int argc, char * argv [] ){

    int i = 0;

    while ( argc > 1 ) {
        printf ( "( * argv + 1 ) [ 0 ] = %c;\n", ( * argv + 1 ) [ 0 ] );
        i += 1;
        argc --;
//        * argv += 1;
        * argv ++;
    }

    printf ( "Number of arguments of f1 is:%3d;\n", i );

}

