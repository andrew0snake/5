#include <stdio.h>

int main () {

//    int a = 0;
    int b = 15;
    int * c = & b;

//    if ( c == a ) {
//    if ( c == 0 ) {
    if ( c == NULL ) {
        printf ( "c = a;\n" );
    }
    else {
        printf ( "c = %d;\n", * c );
    }

    return 0;
}
