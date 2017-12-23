#include <stdio.h>

int f1 ( int *, int * );

int f_p ( int ( * func ) ( int *, int * ), int * ar1, int * ar2 );


int main () {

    int a = 5;
    int b = 13;

    int rez = f1 ( & a, & b );
    
    printf ( "after f1 rez = %d;\n", rez );

    rez = f_p ( f1, & a, & b );
    printf ( "after f2 rez = %d;\n", rez );

    return 0;
}


int f1 ( int * a1, int * a2 ) {

    printf ( "\n============\n" );
    printf ( "in f1:\n" );

    printf ( "getted values: * a1 = %d; * a2 = %d;\n", * a1, * a2 );
    printf ( "f1 returns power of * a1 and * a2 = %d;\n", ( * a1 ) * ( * a2 ) );

    return ( ( * a1 ) * ( * a2 ) );

}

int f_p ( int ( * func ) ( int * a1, int * a2 ), int * ar1, int * ar2  ) {

    int rez = 0;

    printf ( "\n-----------\n" );
    printf ( "in f_p:\n" );

    rez = func ( ar1, ar2 );
    printf ( "rez = %d;\n", rez );

    return rez;
}



