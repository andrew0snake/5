#include <stdio.h>

int main () {

    char line [ 10 ] = "string";
    char * p = line;

    printf ( "\nbefore p = %p, * p = %c;\n\n", p, * p  );

//    * p ++;    
//    * ++ p;
//    * ( p ++ );
//    ( * p ) ++;
    p ++;

    printf ( "\nafter p = %p, * p = %c;\n\n", p, * p  );

    return 0;
}
