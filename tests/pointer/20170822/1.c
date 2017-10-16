#include <stdio.h>

#define LEN 10

void full_arr ( char * arr );
void f1 ( char * arr_1 );

int main () {
    
//    int i = 0;
    char arr [ 100 ];
    
    full_arr ( arr );
    f1 ( arr );        

    return 0;
}

void full_arr ( char * arr ) {

    int i = 0;

    printf ( "\nin full_arr:\n" );
    for ( i = 0; i < LEN; i ++ ) {
        * ( arr + i ) = 0;
        printf ( "arr [ %d ] = '%c' and %d;\n", i, * ( arr + i ), * ( arr + i ) );
    }
    printf ( "after full_arr.\n\n" );
}

void f1 ( char * arr_ins ) {

    int i = 0;

    printf ( "\nin f1:\n" );
    for ( i = 0; i < LEN; i ++ ) {
        printf ( "arr_ins [ %d ] = '%c';\n", i, * ( arr_ins + i ) );
    }
    printf ( "after f1.\n\n" );
}


