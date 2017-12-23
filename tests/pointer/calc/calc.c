#include <stdio.h>
#include <ctype.h>

#define MAXLEN 1000
#define MAXOPS 20

char exit = 1;
int operands [ MAXOPS ];
char operators [ MAXOPS ];    
char opnd_p = 0;
char oprt_p = 0;

int getline_my ( char * line );
void clear_line ( char * line );
int parse_line ( char * line );
char is_operand ( char c );

int main ( int argc, char * argv [] ) {

    char line [ MAXLEN ];
    int len = 0;
    char rez = 0;
   
    while ( exit ) { 
        exit = 1;
        clear_line ( line );
        len = getline_my ( line );   
        if ( exit ) {
            printf ( "getted line:%s; and lenght = %d;\n", line, len ); 
        }        
        rez = parse_line ( line );
        if ( rez == -1 ) {
            printf ( "Wrong input. Exit.\n\n" );
            return -1;
        }
        else {
            printf ( "All is nice)\n\n" );
        }
    }

    return 0;

}


int parse_line ( char * line ) {

    int i = 0;
    int c = 0;

    while ( ( c = * line + i ) != '\0' ) {
        if ( isblank ( c ) ) {
            i ++;
        }
        else {
            if ( isalpha ( c ) ) {
                return -1;
            }
            else {

            }
        }
    }

}


int getline_my ( char * line ) {

    char c = 0;
    int i = 0;

    while ( ( c = getchar () ) != '\n' && c != EOF && i < MAXLEN - 1 ) {
        * line ++ = c;
        i ++;
    }

    if ( c == EOF ) {
        exit = 0;
    }    
      
    * ++ line = '\0'; 

    return i;
}


void clear_line ( char * line ) {

    int i = 0;

    for ( i = 0; i < MAXLEN; i ++ ) {
        * line ++ = 0;
    }

}


char is_operand ( char c ) {

    if ( c == '+' || c == '-' || c == '*' || c == '/' ) {
        return 1;
    }
    else 
        return 0;

} 



