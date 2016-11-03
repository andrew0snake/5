#include <stdio.h>



void main () {

    int * p = 0;

    int val1 = 100;
    int i = 0;
    int arr1 [ 100 ];

    for ( i = 0; i < 30; i++ ) {
        arr1 [ i ] = i ; 
    };
     
    p = arr1;    
    printf ( "p = %p as pointer and %d as digital;\n\n", p, * p );

    for ( i = 0; i < 3; i++ ) {
        p ++;
        printf ( "p = %p as pointer and %d as digital;\n", p, *p );
    };

    printf ( "-----------\n" );

    for ( i = 0; i < 3; i++ ) {
        p += 1;
        printf ( "p = %p as pointer and %d as digital;\n", p, *p );
    };

    printf ( "-----------\n" );

    for ( i = 0; i < 3; i++ ) {
        p += 5;
        printf ( "p = %p as pointer and %d as digital;\n", p, *p );
    };

    printf ( "-----------\n" );

}
