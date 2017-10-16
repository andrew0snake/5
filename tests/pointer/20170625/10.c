#include <stdio.h>

int & rez ref_min ( int a [], int n );

void main () {

    int i = 0;
    int * min = NULL;
    int b [ 5 ] = { 4, 8, 2, 6, 4 };
    
    min = ref_min ( b, 5 );
    
    for ( i = 0; i < 5; i ++) {
        printf ( "%d; ", b [ i ] );
    }

    printf ( "sizeof { b } = %d;\n", sizeof ( b ) );

}

int & rez ref_min ( int a [], int n ) {

    int i = 0;
    int l = 0;

    for ( i = 0, k = 0; i < n; i ++ ) {
        if ( a [ i ] < a [ k ] ) 
            k = i;
    }

}

