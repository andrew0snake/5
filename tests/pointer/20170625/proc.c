#include <stdio.h>

int getline_my ( char * line );
void clear_line ( char * line );

int main ( ) {

    int proc = 0;
    int len = 0;
    int dep = 0;
    int dur = 0;
    float sum = 0.0;
    char line [ 100 ];    

    printf ( "Input please amount of money of deposit:" );
    len = getline_my ( line );
    dep = atoi ( line );
    printf ( "Deposit: %d;\n", dep );
    clear_line ( line );

    printf ( "Input please amount of procents of deposit:" );
    len = getline_my ( line );
    proc = atoi ( line );
    printf ( "Amount of procents: %d;\n", proc );
    clear_line ( line );

    printf ( "Input please duration of deposit (in monthes):" );
    len = getline_my ( line );
    dur = atoi ( line );
    printf ( "Duration: %d;\n", dur );
    clear_line ( line );

    sum = ( dep * proc ) / 100 * 30 * dur / 365;
    printf ( "in the end we have: %f.\n ", sum );
}



int getline_my ( char * line ) {

    int i = 0;
    char c = 0;

    while ( ( c = getchar () ) != '\0' && c != '\n' && c != EOF ) {
        * line ++ = c;
        i++;
    }

    if ( c == '\n' ) {
        * ++ line = '\n';
        * ++ line = '\0';
        i += 2;;
    }

     if ( c == EOF ) {
        return 0;
    }
   
    return i;
}

void clear_line ( char * line ) {

    int len = 100;
    int i = 0;

    for ( i = 0; i < len; i ++ ) {
        * ( line + i ) = 0;
    }


}

