#include <stdio.h>

#define MAX 100
#define TABSIZE 4

char isnumber ( char * string );
int getline_my  ( char * line );
void detab ( int offset_size, char * line );
void full_tabstops ( char array );    

int main ( int argc, char * argv [] ) {

    int i = 0;
    int offset_size = 0;
    char exit = 1;
    char rez = 0;
    char tmp_line [ MAX ];
    char tabline [ MAX ];

    if ( argc == 1 ) {
        printf ( "Usage: entab 0 4 8 12 16 ...  ( wheres every digit is position of tab stop )\n" );        
    }
    else {
        full_tabstops ( tabline );
        while ( ( rez = getline ( tmp_line ) ) != 0 ) {
            detab 
        }
    }

    return 0;
}

void detab ( char * detabbed_line, char source_line ) {

    int pos = 0;

    while ( * source_line != EOF ) {
        if ( * source_line == '\t' ) {
            while ( ! tabpos ( pos, tabline ) ) {
                * detabbed_line ++ = ' ';
                pos ++;
            }
            pos ++;
        }
        else {
            * detabbed_line ++ = * source_line ++ ;
        }            
    }

}

void full_tabstops ( char tabline ) {

    int len = 0;

    while ( len < MAXLINE ) {
        tabstops [ len ] = ( len % TABSIZE == 0 );
        len ++;
    }

}

char isnumber ( char * string ) {

    int i = 0;
    int digit = 0;
    char check = 0;

    while ( string [ i ] != '\0' && check == 0 ) {
        if ( isdigit ( string [ i ] ) != 0 ) {
            check = 0;
            digit = string [ i ] - '0' + digit * 10;
        }
        else { 
            check = 1;
            return 0;
        }
        i ++;
    }

    return 1;
}

int getline_my ( char * line ) {

    char c = 0;
    int i = 0;

    while ( ( c = getchar () ) != '\0' && c != EOF && c != '\n' ) {
        * line ++ = c;
        i ++;
    }

    if ( c == '\n' ) {
        * line  = '\0';
        return i;
    }
    else {
        if ( c == EOF )
            * line = '\0'; 
            return i;
    }

    return 0;
}

void entab ( int offset_size, char * line ) {
    
    int count = 0;
    int offset = 0;
    int i = 0;


    while ( * line != '\0' && * line != '\n' ) {
        if ( * line == ' ' ) {
            count ++;
            if ( count == offset_size ) {
                * ( line - offset_size + 1 ) = '\t';
                * line ++;
                while ( * line != '\0' ) {
                    * ( line - offset_size + 1 ) = * line;
                    * line ++;
                    offset ++;
                }
                *  ( line - offset_size + 1 ) = '\0';
                offset += offset_size;
                while ( offset > 0 ) {
                    * line --;
                    offset --;    
                }
                count = 0;
            }
        }
        else {
            count = 0;
        }
        * line ++; 
    }

}
