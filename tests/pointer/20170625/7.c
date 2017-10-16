#include <stdio.h>

#define STR 3
#define ROW 5    

int main () {

    int a [ 3 ] [ 5 ] = { 
        1,  2,  3,  4,  5,
        6,  7,  8,  9,  10,
        11, 12, 13, 14, 15 
    };
    int c [ 5 ] = { 2, 4, 6, 8, 10 };
    int * p;
    int i = 0;
    int j = 0;

    int  ( * b ) [ 5 ];
    char * d = { "string" };


//    * b [ 0 ] = a [ 0 ] [ 1 ];
//    * b [ 0 ] = a [ 0 ];
//    * b [ 0 ] = 1;
//    b [ 0 ] = & c [ 0 ]; -wrong
    b [ 0 ] = d;

    printf ( "b [ 0 ] = %s;\n", * b [ 0 ] );
    printf ( "b [ 0 ]   = %p;\n", * b [ 0 ] );
    printf ( "& c [ 0 ] = %p;\n", & c [ 0 ] );


    return 0;

}
