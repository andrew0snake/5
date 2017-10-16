#include <stdio.h>

int strlen_my ( char * s );

void main () {

    int * p = 0;
    int i = 0;
    int arr1 [ 20 ];
    
    char line1 [ 100 ] = "123qweasd";

    for ( i = 0; i < 20; i++ ) {
        arr1 [ i ] = i * 3;
        printf ( "arr [ %2d ] = %p as pointer and %2d as digital;\n", i, & arr1 [ i ], arr1 [ i ] );
    };
    printf ( "------------\n" );


    p = & arr1 [ 0 ];

    printf ( "p = %p as pointer and %d as digital;\n\n", p, * p );

    printf ( "p [ 5 ] = %p as pointer and %2d as digital;\n\n", & p [ 5 ], p [ 5 ] );

    printf ( "* ( p + 5 ) = %p as pointer and %2d as digital;\n\n", & ( * ( p + 5 ) ), * ( p + 5 ) );

    i = strlen_my ( & line1 );
    printf ( "lenght of line1 = %d;\n", i );

    p = line1;
    i = strlen_my ( p );
    printf ( "lenght of line1 = %d;\n", i );

}

int strlen_my ( char * s ) {

    int i = 0; 

    for ( i = 0; * s != '\0'; s++ ) {
        printf ( "in strlen_my s = %c in char; %d in digital;\n", s, s );
        printf ( "in strlen_my * s = %c in char; %d in digital;\n\n", * s, * s );
        i++;
    };

    return i;

}
