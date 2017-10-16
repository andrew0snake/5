#include <stdio.h>
#include <strings.h>

char * array [ 10 ];

void getline_my ( char * line );
void clear_line ( char * line );    


int main () {

    int i = 0;
    char line [ 100 ];

    for ( i = 0; i < 5; i++ ) {    
        getline_my ( & array );    
        printf ( "getted line '%s';\n", array [ i ] );        
    }

    return 0;

}

void getline_my ( char line [ 100 ] ) {

    char c = 0;
    int i = 0;

    while ( ( c = getchar () ) != '\0' && c != EOF && c != '\n' ) {
        * line [ i ]= c;
        printf ( "c = '%c'; * line = '%c';\n", * line [ i ] );
        i ++;
    }

    if ( c == '\n' || c == EOF ) {
//        * line ++ = '\n';
        * line = '\0';
    }

}

void clear_line ( char * line ) {

    int i = 0;

    for ( i = 0; i < 100; i ++ ) {
        * line ++ = 0;
    } 

}
