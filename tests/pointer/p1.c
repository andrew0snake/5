#include <stdio.h>

void main () {

    int i = 0;
    int * p;
    

    i = 123;
    printf ( "i = %d;\n", i );

    p = & i ;
    printf ( "p = & ( i = %d ) = %d as digital, %p as pointer;\n\n", i, p, p ); 

    printf ( "* p = %d as digital, %p as pointer.\n", *p, *p );

    * p = * p + 100; 

    printf ( "after adding *p = %d; i = %d;\n", *p, i );

}
