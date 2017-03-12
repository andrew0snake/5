#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

//int getline ( char * line, int max );
int getline_my ( char * line, int len );

/* find: print lines that match pattern from 1st arg */
int main ( int argc, char * argv [] ) {

    char line [ MAXLINE ];
    long lineno = 0;
    int c= 0;
    int except = 0;
    int number = 0;
    int found = 0;

    while ( -- argc > 0 && ( * ++ argv ) [ 0 ] == '-' ) {
        while ( c = * ++ argv [ 0 ] ) {
            switch ( c ) {
                case 'x':
                    except = 1;
                    break;
                case 'n':
                    number = 1;
                    break;
                default:
                    printf ( "find: illegal option %c;\n", c );
                    argc = 0;
                    found = -1;
                    break;
            }
        }
    }

    if ( argc != 1 ) {
        printf ( "Usage: find -x -n pattern.\n" );
    } 
    else {
        while ( getline_my ( line, MAXLINE ) > 0 ) {
            lineno++;
            if ( ( strstr ( line, * argv ) != NULL ) != except ) {
                if ( number ) {
                    printf ( "%ld:", lineno );
                }
                printf ( "%s\n", line );
                found ++;
            }
        }
    }

    return found;

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

