#include <stdio.h>

#define SIZE 10

void test1 ( int *arr );

void main () {

    int arr1 [ SIZE ];

    int n = 0;
    int i = 0;

    int *p1;

    for ( i = 0; i < SIZE; i++ ) {
        arr1 [ i ] = i * 7;
        printf ( "at step %d arr1 [ %d ] = %d;\n", i, i, arr1 [ i ] );
    }
    
    p1 = & arr1 [ 1 ];
    printf ( "p1 = %d; and *p1 = %d;\n", p1, *p1 );
    printf ( "p1 + 1 = %d; and * ( p1 + 1 ) = %d;\n", p1 + 1, * ( p1 + 1 ) );

    for () {

    };

}


