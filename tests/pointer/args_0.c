#include <stdio.h>

#define MAX 100 

int main () {

    int i = 0;
    int a = 5;
    int * p_0 = & a;
    int * p_1;

    int arr_0 [ 5 ] = { 1, 2, 3, 5, 7 };
    int arr_1 [ ] = { 1, 200, 546, 90, 22 };
    int * arr_2 [ MAX ];
    char arr_3 [ MAX ] = { "123 qwe asd" };
    char * arr_4 [ MAX ] = { "123", "qwe", "asd" };

    
    printf ( "a = %d;\n* ( p_0 = & a ) = %d;\np_0 = %p;\n", a, * p_0, p_0 );

    p_0 = arr_0;
    printf ( "\np_0 = arr_0   = %p;\n& arr_0 [ 0 ] = %p;\n* p_0 = %d;\n", p_0, & arr_0 [ 0 ],* p_0 );

    for ( i = 0; i < 5; i ++ ) {
        printf ( "arr_0 [ %d ] = * p_0 ++ = %d;\n", i, * p_0 ++ );

    }

    p_0 = arr_1;
    printf ( "\np_0 = arr_1 = %p;\n", p_0 );

    for ( i = 0; arr_1 [ i ]; i ++ ) {
        * ( arr_2 + i ) = arr_1 [ i ];  
    }

    for ( i = 0; arr_2 [ i ]; i ++ ) {
        printf ( "arr_2 [ %d ] = %d;\n", i, arr_2 [ i ] );
    }

}
