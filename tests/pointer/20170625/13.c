#include <stdio.h>

int main () {

    char line [ 10 ] = "157adk";
    char * p = line;

    printf ( "whole string = '%s';\n", line );

    printf ( "\nbefore p = %p, * p = %c;\n\n", p, * p  );

//    * p ++;    
    * ++ p;
//    * ( p ++ );
//    ( * p ) ++;
//    p ++;

    printf ( "\nafter p = %p, * p = %c;\n\n", p, * p  );
    printf ( "* ( p - 1 ) = %c;\n", * ( p - 1 ) );
    printf ( "\nafter p = %p, * p = %c;\n\n", p, * p  );

    return 0;
}
