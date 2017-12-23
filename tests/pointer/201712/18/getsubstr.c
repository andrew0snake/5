#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 1000

int getline_my ( char * line );
char * substr_my ( char * str, int start, int end );

int main ( int argc, char * argv [] ) {

    char string [ 100 ];
    char substr [ 100 ];
    char * substr_p = substr;

    getline_my ( string );
    printf ( "getted string:'%s';\n", string );

//    memcpy ( substr, & string [ 2 ], 7 );
//    substr [ 10 ] = '\0';
    substr_p = substr_my ( string, 2, 7);   

    printf ( "getted substring = '%s';\n", substr_p );


    return 0;

}


char * substr_my ( char * str, int start, int end ) {

    char substr [ 100 ];

    memcpy ( substr, & str [ start ], end );
    substr [ end ] = '\0';
   
    return substr; 

}


int getline_my ( char * line ) {

    int i = 0;
    char c = 0;


    while ( ( c = getchar () ) != '\0' && c != '\n' && c != EOF ) {
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



