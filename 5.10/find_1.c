#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

//int getline ( char * line, int max );
int getline_my ( char * line, int len );

/* find: print lines that match pattern from 1st arg */
int main ( int argc, char * argv [] ) {

    char line [ MAXLINE ];

    int found = 0;

    if ( argc != 2 ) {
        printf ( "Usage: find pattern.\n" );
    }
    else {
        while ( getline_my ( line, MAXLINE ) > 0 ) {
            if ( strstr (line, argv [ 1 ] ) != NULL ) {
                printf ( "pattern fount in string = %s\n", line );
                found ++;
            }
        }
    return found;
    }
}

int getline_my ( char * line, int len ) {

    int i = 0;
    char c = 0;

    while ( len > 0 && ( ( c = getchar () ) != EOF && c != '\n') ) {
        * line ++ = c;
        i ++;
        len --;
    };

    if ( * line == '\n' ) {
        * line ++ = '\n';
        i ++;
    };

    * line = '\0';
    
    return i;
}

