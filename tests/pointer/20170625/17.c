#include <stdio.h>

#define LEN 10

char * line [ LEN ];

void main () {

    int i = 0;

    for ( i = 0; i < LEN; i ++ ) {
        printf ( "i = %d;\n", i );
        printf ( "* line [ %d ] = '%s';\n", i, * line [ i ] );
        printf ( "* line [ %d ] = '%s' and %p;\n", i, * line [ i ], * line [ i ] );
        
    } 


}
