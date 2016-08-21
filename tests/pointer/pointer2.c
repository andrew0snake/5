#include <stdio.h>

#define SIZE 10
#define STRSIZE 100

void test1 ( int * arr );
int strlen_other ( char * );
void print_part ( int * arr );

void main () {

    int arr1 [ SIZE ];

    int n = 0;
    int i = 0;

    int *p1;
    int *p2;
//    double *p1;

    char string1 [ STRSIZE ] = "test";
    int len = 0;

    for ( i = 0; i < SIZE; i++ ) {
        arr1 [ i ] = i * 7;
        printf ( "at step %d arr1 [ %d ] = %2d; & arr1 [ i ] = %p;\n", i, i, arr1 [ i ], & arr1 [ i ] );
    }
    
    p1 = & arr1 [ 0 ];
    printf ( "\np1 = %p; and *p1 = %d;\n\n", p1, *p1 );
    printf ( "p1 + 1 = %p; and * ( p1 + 1 ) = %d;\n\n", p1 + 1, * ( p1 + 1 ) );

    printf ( "p1 + 5 = %p; and * ( p1 + 5 ) = %d;\n\n", p1 + 5, * ( p1 + 5 ) );

    p1 = arr1;
    printf ( "p1 = a = %p;\n\n", p1 );

    i = 1;
    printf ( "arr1 [ i = 1 ] = %d; * ( arr1 + i = arr1 + 1 ) = %d;\n\n", arr1 [ i ], * ( arr1 + i ) );

    i = 2;
    printf ( "& arr1 [ i = 2 ] = %p; arr1 + ( i = 2 ) = %p;\n\n", & arr1 [ i ], arr1 + i );

    p1 = arr1;
    i = 2;
    printf ( "p1 [ i = 2 ] = %d; * ( p1 + i ) = %d;\n\n", p1 [ i ], * ( p1 + i ) );
    printf ( "& p1 [ i = 2 ] = %p; & ( * ( p1 + i ) ) = %p;\n\n", & p1 [ i ], & ( * ( p1 + i ) ) );
    printf ( "* ( & p1 [ i = 2 ] ) = %d; * ( & ( * ( p1 + i ) ) ) = %d;\n\n", * ( & p1 [ i ] ), * ( & ( * ( p1 + i ) ) ) );



    p1 = * string1;
    len = strlen_other ( & string1 );
    printf ( "lenght of string1 = %d;\n\n", len );


    print_part ( & arr1 [ 3 ] );

    p1 = arr1;
    for ( i = 0; i < SIZE; i++ ) {
        printf ( "p1 + i = %2d point at address %p;\n", * ( p1 + i ), ( p1 + i ) );
    };

    p1 = arr1 [ 0 ];
    p2 = arr1 [ 1 ];
    
    if ( p1 > p2 ) {
        printf ( "p2 is earlier than p1;\n");
    }
    else {
        printf ( "p1 is earlier than p2;\n");
    }

}

int strlen_other ( char * s ) {

    int n = 0;
    
    for ( n = 0; * s != '\0';  s++ ) {
        n++;
    };

    return n;

}


void print_part ( int * arr ) {


    int i = 0;

    printf ( "----in func print_part----\n" );
    for ( i = 0; i < 5; i++ ) {
       printf ( "array [ i = %d ] = %d;\n", i, arr [ i ] );
    };

}
