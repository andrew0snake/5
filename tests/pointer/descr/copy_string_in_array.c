#include <stdio.h>

int getline_my ( char * line );
void strcpy_my ( cjar * line_to, char * line_from );

int main () {
    
    char * lineptr [ 100 ];
    char line [ 100 ];
    int len = 0;
    int i = 0;

    for ( i = 0; i < 10; i++ ) { 
        len = getline_my ( line );
        strcpy_my ( lineptr, line );
        * lineptr ++;
    }

    for ( i = 0; i < 10; i ++ ) {
        printf ( "* lineptr = '%s';\n", * lineptr ++ );
    }


}

void strcpy_my ( char * line_to, char * line_from ) {
    
    while ( * * line_from != '\0' ) {
        * * line_to ++ = * * line_from ++ ; 
    }
}


int getline_my ( char * line ) {

    int i = 0;
    char c = 0;

    while ( ( c = getchar () ) != '\0' && c != '\n' ) {
        * line ++ = c;
        i++;
    }

    if ( c == '\n' ) {
        * ++ line = '\n';
        * ++ line = '\0';
        i++;
    }
    
    return i;
}

