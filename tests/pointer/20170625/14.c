#include <stdio.h>

void f1 ( char * line );

int main ( int argc, char * * argv ) {

    int i = 0;

    for ( i = 0; i < argc; i ++ ) {
        printf ( "at step %d-th * ( argv + i ) = '%s' and %p; ", i, * a );
        f1 ( * ( argv + i ) );
    }
   
    return 0; 

}

void f1 ( char * line ) {

    printf ( "getted string:'%s';\n", line );

}
