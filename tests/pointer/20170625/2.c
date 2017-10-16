#include <stdio.h>

void main () {

    int A = 100;
    int * a = & A;
    double B = 2.3;
    double * b = &B;

    printf ( "sizeof ( A ) = %d;\n", sizeof ( A ) );
    printf ( "sizeof ( a ) = %d;\n", sizeof ( a ) );
    printf ( "sizeof ( B ) = %d;\n", sizeof ( B ) );
    printf ( "sizeof ( b ) = %d;\n", sizeof ( b ) );

    getchar ();

}
