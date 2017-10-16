#include <stdio.h>

#define LEN 100

int getline_my ( char * line );

void main () {

    char * line;
    int len = 0;
   
    printf ( "\ninput please line:\n\n" ); 
    len = getline_my ( line );
    
    printf ( "in rez len = %d; and line = '%s';\n", len, line );

}

int getline_my ( char * line ) {

    int i = 0;
    char c = 0;

    while ( ( c = getchar () ) != '\0' && c != '\n' && c != EOF ) {
        printf ( "c = '%c';\n", c );
        * ( line + i ) = c;
        i++;
    }

    if ( c == '\n' ) {
        * ( line + i ) = '\0';
        i ++; ;
    }

     if ( c == EOF ) {
        return 0;
    }
   
    return i;
}

