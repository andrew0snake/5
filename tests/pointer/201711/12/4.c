#include <stdio.h>

int f1 ( char * );
int f2 ( int ( * f_p ) (), int a );


int main ( int argc, char * argv [] ) {

    char string [] = "123qweasd";

    char * c_p = string;

//    f1 ( & string );
    f1 ( c_p );

    return 0;

}


int f1 ( char * string ) {

    printf ( "getted string:'%s';\n", string );

    return 0;

}

int f2 ( int ( * f_p ) (), int a ) {

    return 0;

}


