#include <stdio.h>

#define SZ 100

void getline_my ( char * line );
void strcat_my ( char * s, char * d );
void main () {

    char line1 [ SZ * 2 ];
    char line2 [ SZ ];

    printf ( "Input please first string:\n" );
    getline_my ( & line1 );
    printf ( "Getted string = %s;\n", line1 );

    printf ( "Input please second string:\n" );
    getline_my ( & line2 );
    printf ( "Getted string = %s;\n\n", line2 );

    printf ( "And now we have two strings, line1 = \"%s\" and line2 = \"%s\";\n", line1, line2 );

    strcat_my ( & line1, & line2 );

    printf ( "After concatenation of strings line 1 = \"%s\";\n", line1 );
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



