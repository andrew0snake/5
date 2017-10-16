#include <stdio.h>

#define STR 3
#define ROW 5    

int main () {

    int a [ 3 ] [ 5 ] = { 
        1,  2,  3,  4,  5,
        6,  7,  8,  9,  10,
        11, 12, 13, 14, 15 
    };
    int * p;
    int i = 0;
    int j = 0;

    printf ( "\nwhole double sized array a:\n" );

    for ( i = 0; i < STR; i ++ ) {
        for ( j = 0; j < ROW; j ++ ) {
            printf ( "%2d ", a [ i ] [ j ] );
        }
        printf ( "\n" );
    }

    printf ( "\n* ( * ( a + 1 ) + 2 ) = %2d;\n", * ( * ( a + 1 ) + 2 ) );
    printf ( "* ( * ( a + 2 ) + 2 ) = %d;\n", * ( * ( a + 2 ) + 2 ) );
    printf ( "* ( * ( a + 2 ) + 3 ) = %d;\n", * ( * ( a + 2 ) + 3 ) );
    printf ( "* ( * a + 3 ) = %d;\n", * ( * a + 3 ) );


    printf ( "\nfirst elements of strings:\n\n" );

    for ( i = 0; i < STR; i ++ ) {
        printf ( "* ( ( * a ) + ROW * ( i = %d ) ) = %2d;\n", i, * ( ( * a ) + ROW * i ) );
    }



    return 0;

}
