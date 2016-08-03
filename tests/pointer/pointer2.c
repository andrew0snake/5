#include <stdio.h>

#define SIZE 10

void test1 ( int *arr );

void main () {

    int arr1 [ SIZE ];

    int n = 0;
    int i = 0;

    int *p1;
//    double *p1;

    for ( i = 0; i < SIZE; i++ ) {
        arr1 [ i ] = i * 7;
        printf ( "at step %d arr1 [ %d ] = %d;\n", i, i, arr1 [ i ] );
    }
    
    p1 = & arr1 [ 0 ];
    printf ( "\np1 = %p; and *p1 = %d;\n\n", p1, *p1 );
    printf ( "p1 + 1 = %p; and * ( p1 + 1 ) = %d;\n\n", p1 + 1, * ( p1 + 1 ) );

    printf ( "p1 + 5 = %p; and * ( p1 + 5 ) = %d;\n\n", p1 + 5, * ( p1 + 5 ) );

    p1 = arr1;
    printf ( "p1 = a = %p;\n\n", p1 );

    i = 1;
    printf ( "arr1 [ i = 1 ] = %d; * ( arr1 + i = arr1 + 1 ) = %d;\n\n", arr1 [ i ], * ( arr1 + i ) );


/*    for () {
        printf ( "" );
    };
*/
}


