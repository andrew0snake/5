#include <stdio.h>

int addInt ( int n, int m );
int ( * funcPtr ) ( int, int ) = & addInt; 

int func_ret ( int ( * func2 ) ( int x, int y ) );

int main ( int argc, char * argv [] ) {

    int sum = 0;
    int a = 2;
    int b = 3;
    int sum2 = 0;

    funcPtr = & addInt;

    sum = ( funcPtr ) ( a, b );
    printf ( "\nsum of a and b = %d;\n\n", sum );

    sum2 = func_ret ( ( funcPtr ) ( a, b ) );

    return 0;

}


int addInt ( int n, int m ) {

    return ( n + m );

}

int func_ret ( int ( * func2 ) ( int x, int y ) ) {

    int rez = 0;

    rez = ( * func2 ) ( x, y );

    return rez;

}


