#include <stdio.h>

char * month_name ( int n );

int main () {

    int i = 0;
    char * n = 0;

    i = 5;

    n = month_name ( i );
    
    printf ( "\nmonth name = %s;\n\n", n );

    printf ( "first symbol of %d-th month_name = %c; and it's address ( & n ) = %p;\n\n", i, * n, & n );

    printf ( "'n' as char ( %%c )'%c'; and '* n' as char ( %%c )'%c';\n\n", n, * n );
    printf ( "'n' as digital ( %%d )'%d'; and '* n' as digital ( %%d )'%d';\n\n", n, * n );
    
    printf ( "'n' as string = ( %%s )'%s';\n\n", n );

}

char * month_name ( int n ) {

    char i = 0;
    static char * name [] = {
        "wrong",
        "jan", "feb", "march",
        "apr", "may", "jun", 
        "jul", "aug", "sep", 
        "oct", "nov", "dec",
    };

    printf ( "\nname [ 1 ] = ( %%p ) '%p' as pointer and * name [ 1 ] = ( %%c )'%c' as char;\n\n", name [ 1 ], * name [ 1 ] );
    printf ( "& name [ 1 ] = %p as pointer; and * name [ 1 ] as pointer = %p; amd as * name [ 1 ]  %d \n\n", & name [ 1 ], * name [ 1 ], * name [ 1 ] );

    for ( i = 0; i <= 12; i++ ){
        printf ( "* name [ i = %2d ] = %3d as digital ( %%d ); and name [ %2d ] = %d;\n", i, * name [ i ], i, name [ i ] );
    }

    return ( n < 1 || n > 12 ) ? name [ 0 ] : name [ n ];

}
