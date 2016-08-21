#include <stdio.h>

#define SZ 100

void getline_my ( char * line );
void strcat_my ( char * s, char * d );
int strend_my ( char * s, char * t );
int strlen_my ( char * s );

void main () {

    char line1 [ SZ * 2 ];
    char line2 [ SZ ];
    int len = 0;
    int con = 0;

    printf ( "Input please first string:\n" );
    getline_my ( & line1 );
    printf ( "Getted string = %s;\n", line1 );

    printf ( "Input please second string:\n" );
    getline_my ( & line2 );
    printf ( "Getted string = %s;\n\n", line2 );

    printf ( "And now we have two strings, line1 = \"%s\" and line2 = \"%s\";\n", line1, line2 );

    len = strlen_my ( line1 );
    printf ( "lenght of string 1 = %d;\n", len );
    len = strlen_my ( line2 );
    printf ( "lenght of string 2 = %d;\n", len );

    con = strend_my ( & line1, & line2 );
    if ( con == 1 ) {
        printf ( "line 1 contains in itself line2;\n" );
    }
    else {
        printf ( "line 1 does not contain in itself line2;\n" );
    }

}


void getline_my ( char * line  )

{
    int i = 0;
    int c = 0;

    for ( i = 0; ( ( c = getchar () ) != EOF ) && c != '\n' && i < SZ; line ++, i++ ){
        * line = c;
        printf ( "line [ %d ] = %c; line = %p;\n", i, * line, line );
    };
    * line ++ = '\0';
}

void strcat_my ( char * s, char * d ) {

    int i = 0;

    while ( * s != '\0' ) {
//        printf ( "in first while * s = %c;\n", * s );
        s ++;
    };

//    s ++;

    while ( * d != '\0' ) {
//        printf ( "in second while * d = %c;\n", * d );
        * s ++ = * d ++;
//        printf ( "after addition * s = %c;\n", * ( s - 1 ) );
    };

    * ( ++ s )  = '\0'; 
    
}


int strend_my ( char * s, char * t ) {

    int i = 0;
    int j = 0;
    int len1 = 0;
    int len2 = 0;
    char prov = 0;

    len1 = strlen_my ( & s ); 
    len2 = strlen_my ( & t ); 
    printf ( "before check len1 = %d; len2 = %d;\n", len1, len2 );
    
    for ( i = len1, j = len2; j > 0 && prov == 0; j--, i-- ) {
        printf ( "in check s [ i = %d ] = %c; t [ j = %d ] = %c;\n", i, s [ i ], j, t [ j ] );
        if ( s [ i ] != t [ j ] ) {
            prov = 1;
        };
    };

    printf ( "aftrr check in strend_my j = %d; prov = %d;\n", j, prov );
 
    if ( j == 0 && prov == 0 ) {
        return 1;
    }
    else { 
        if ( prov == 1 ) {
            return 0;
        }
    };
}

int strlen_my ( char * s ) {

    char * p = s;

    while ( * p != '\0' ) {
        p++;
    };

    return p - s;
}
