#include <stdio.h>

int main () {

    char c = 0;

    c = getchar ();

    switch ( c ) {
        case 'a':
            printf ( "case a;\n" );
            break;
        default:
            printf ( "default;\n" );
            break;
    };

}
