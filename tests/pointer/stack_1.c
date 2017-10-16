#include <stdio.h>

void f1 ( int * arr );
void f2 ( int * p );

void main () {

    int * p = 0;
    int val = 5;
    int i = 0;
    int array_1 [ 10 ];

    for ( i = 0; i < 10; i++ ) {
        array_1 [ i ] = 0;
        printf ( "array_1 [ %d ] = %d;\n", i, array_1 [ i ] );
    };

    p = array_1;

    f1 ( & array_1 );

    for ( i = 0; i < 10; i++ ) {
        printf ( "stack [ %d ] = %d;\n", i, array_1 [ i ] );
    };

    f2 ( & array_1 );

}

void f1 ( int * arr ) {

    int val = 10;
    int i = 0;
    
    for ( i = 0; i < 10; i ++ ) {
        * arr ++ = i;
    };   

    printf ( "---------" );
}

void f2 ( int * p ) {

    int i = 0;
    int val = 0;    
    int after = 0;

    for ( i = 0; i < 10; i ++ ) {
        printf ( "before discreasing * p = %d;\n", * p );
        val = * -- p;
        after = * p;
        printf ( "and after val = %d; * p = %d; after = %d;\n", val, * p, after );
    };

    printf ( "----------");

}
