#include <stdio.h>
#define LEN 4 
#define HEIGHT 3

void f1 ( char ( * array ) [ LEN ] );

int main () {

    char arr_1 [ HEIGHT ] [ LEN ] = {
        "123", 
        "qwe",
        "asd"
    };

    int i = 0;
    int j = 0;

    printf ( "\nPrint every string of 2d array:\n\n" );

    for ( i = 0; i < HEIGHT; i ++ ) {        
        printf ( "arr_1 [ %d ]  = %s; ", i, arr_1 [ i ] );
        printf ( "\n" );
    }

    printf ( "\nAnd now every symbol on its own string:\n\n" );

    for ( i = 0; i < HEIGHT ; i ++ ) {
        for ( j = 0; j < LEN; j ++ ) {
            printf ( "arr1 [ %d ] [ %d ] = %c;\n", i, j, arr_1 [ i ] [ j] );
        }
        printf ( "==============================\n" );
    }

    printf ( "\nAnd now we will pass 2d array in function f1:\n" );

    f1 ( arr_1 );
    
    return 0;

}

void f1 ( char ( * array ) [ LEN ] ) {

    int i = 0;
    int j = 0;

    printf ( "\nHere, in function f1 we print every string of passed array:\n" );    

    for ( i = 0; i < HEIGHT; i ++ ) {
        printf ( "array [ %d - th string ] = %s;\n", i, array [ i ] );
    }

    printf ( "\nAnd now in function f1 we print every symbol on its own string:\n\n" );

    for ( i = 0; i < HEIGHT ; i ++ ) {
        for ( j = 0; j < LEN; j ++ ) {
            printf ( "array [ %d ] [ %d ] = %c;\n", i, j, array [ i ] [ j ] );
        }
        printf ( "==============================\n\n" );
    }


}



