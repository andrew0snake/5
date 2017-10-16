#include <stdio.h>


int main () {

    char * arr [ 10 ] = {
        "123",
        "qwe",
        "asd"
    };
    char * ptr;
    int i = 0;
    int rez = 0;

    for ( i = 0; i < 3; i++ ) {
        printf ( "arr [ %d ] = %s;\n", i, arr [ i ] );
    }   

    ptr = arr [ 0 ];

    for ( i = 0; i < 3; i ++ ) {
        printf ( "* arr = %s;\n",  ptr );
        ptr ++;
    }

}



