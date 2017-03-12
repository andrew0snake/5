#include <stdio.h>


int getline_my ( char * line );


int main () {

    int i = 0;
    char line [ 100 ];

//    i = getline_my ( line );
    i = getline_my ( & line [ 0 ] );    

    printf ( "getted line:'%s'\n", line );

    return 0;

}

int getline_my ( char * line ) {

    char c = 0;

    while ( ( c = getchar () ) != '\0' && c != EOF && c != '\n' ) {
        * line = c;
        printf ( "c = '%c'; * line = '%c';\n", * line );
        * line ++;
    }

    if ( c == '\n' || c == EOF ) {
//        * line ++ = '\n';
        * line = '\0';
    }

}
