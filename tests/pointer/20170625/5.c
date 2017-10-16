#include <stdio.h>

void main () {

    int a [ 5 ] = { 1, 2, 3, 4, 5};
    int * p = a;

    printf ( "* ( a + 1 ) = %d;\n", * ( a + 1 ) );
    printf ( "* ( p + 1 ) = %d;\n", * ( p + 1 ) );
    printf ( "3 [ a ] = %d;\n", 3 [ a ] );


}
