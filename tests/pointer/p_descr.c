#include <stdio.h>

int main () {
    
    int a = 5;
    int i = 0;
//    int * p = & a;
    int * p;

    int * arr [ 10 ];
    char * strings [ 10 ];

    printf ( "a = %d;\n", a );

//    * p = & a;
    p = & a;
    printf ( "a = %d;\n", a );
    printf ( "* p = %d;\n", * p );

    for ( i = 0; i < 10;  i++ ) {
        * arr = i;
        printf ( "i = %d; * arr = %d;\n", i, * arr );
        ( * arr ) ++;
    }  

}
