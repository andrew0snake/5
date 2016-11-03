#include <stdio.h>

char * month_name ( int n );

int main () {

    int i = 0;
    char * n = 0;

    i = 5;

    n = month_name ( i );
    printf ( "123\n" );

    printf ( "month name = %s;\n", n );

}

char * month_name ( int n ) {

    static char * name [] = {
        "wrong",
        "jan", "feb", "march",
        "apr", "may", "jun", 
        "jul", "aug", "sep", 
        "oct", "nov", "dec",
    };

    return ( n < 1 || n > 12 ) ? name [ 0 ] : name [ n ];

}
