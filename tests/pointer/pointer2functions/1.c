#include <stdio.h>

int addInt ( int n, int m );
int ( * funcPtr ) ( int, int ); 

int main ( int argc, char * argv [] ) {

    int sum = 0;

    funcPtr = & addInt;

    sum = ( * funcPtr ) ( 2, 3 );

    printf ( "rez = %d;\n", sum );

    return 0;

}


int addInt ( int n, int m ) {

    return ( n + m );

}

