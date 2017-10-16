#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 1000

void check_string ( char * line, int ( * cmp_f ) ( int c ) );
int getline_my ( char * line );

int main ( int argc, char * argv [] ) {

    char line [ SIZE ];
    char quit = 1;
    char rez = 0;

    printf ( "\n\nHello. Enter your string, and this program will check symbols of string alphabetically.\n" );
    printf ( "Or quit by typing quit.\n" );

    while ( quit ) {
        rez = getline_my ( line );
        quit = strcmp ( line, "quit" );
        if ( quit ) {
            printf ( "rezult of strcmp ( '%s', \"quit\") = %d;\n", line, strcmp ( line, "quit" ) );    
            check_string ( line, isalpha );
        }
        else {
            printf ( "\nBye!\n\n" );
        }
    }

    return 0;

}


void check_string ( char * line, int ( * cmp_f ) ( int c ) ) {

    int i = 0;
    int rez = 0;

    while ( * ( line + i ) != '\0' ) {
        rez = cmp_f ( * ( line + i ) );
        printf ( "rez of '%c' = %d;\n", * ( line + i ), rez );
        i ++;
    }

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



