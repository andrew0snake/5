#include <stdio.h>

void main () {

    int A [ ] [ 3 ] = { 1, 2, 3, 4, 5, 6 };

    int ( * p ) = A [ 0 ];

    printf ( "p [ 2 ] = %d;\n", p [ 2 ] );

}
