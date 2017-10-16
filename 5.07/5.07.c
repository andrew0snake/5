#include <stdio.h>
#include <string.h>

#define MAXLINES 4000 /* maximal number of strings */
#define MAXLEN 1000 /* maximal lenght of string */
#define ALLOCSIZE MAXLINES*MAXLEN

char * lineptr [ MAXLINES ];
char allocbuf [ ALLOCSIZE ];
char * allocp = allocbuf;

int readlines ( char * lineptr [], int nlines, char * array );
void writelines ( char * lineptr [], int nlines );
void qsort_my ( char * lineptr [], int left, int right );
void swap_my ( char * v [], int i, int j );
int getline_my  ( char line [] , int );
char * alloc_my ( int len );


int main () {

    int nlines = 0;
    char array [ ALLOCSIZE ];
    float position = 0.0;

    if ( ( nlines = readlines ( & lineptr, MAXLINES, & array ) ) >= 0 ) {
        printf ( "in main in if. nlines = %d;\n", nlines );
        qsort_my ( lineptr, 0, nlines - 1 );
        writelines ( lineptr, nlines );
        return 0;
    }
    else {
        printf ( "Error: too much strings.\n" );

        return 1;
    }

}

int readlines ( char * lineptr [], int maxlines, char * array ) {

    int len = 0;
    int nlines = 0;
    char * p = 0;
    char  line [ MAXLEN ];
    int pos = 0;

    while ( ( len = getline_my ( line, MAXLEN ) ) > 0 ) {
        printf ( "in readlines.\n" );
        if ( nlines >= maxlines || ( pos + len ) >= ALLOCSIZE ) {
            printf ( "Error in readlines. nlines = %d; p + len = %d;\n", nlines, p + len );
            return -1;
        }
        else {
            p = & array [ pos ];
            pos += len;
            line [ len - 1 ] = '\0';
            strcpy ( p, line );
            lineptr [ nlines ++ ] = p;  
        }
    }
    printf ( "function readlines ended its work with rezult line = %s; and its lenght = %d;\n", lineptr, nlines );

    return nlines;
}


void writelines ( char * lineptr [], int nlines ) {

    int i = 0;
    
    for ( i = 0; i < nlines; i++ ) {
        printf ( "%d'th line = %s;\n", i, lineptr [ i ] );
    }
} 

int getline_my ( char s [], int maxsize )

{

    int c = 0;
    int i = 0;
    int lim = maxsize;
   
    printf ( "in getline_my.\n" ); 
    while ( ( --lim > 0 ) && ( ( c = getchar () ) != EOF ) && c != '\n' )
        s [ i++ ] = c;

    if ( c == '\n' ){
        s [ i++ ] = '\n';
    };

    s [ i ] = '\0';
    
    return i;

}

void qsort_my ( char * v [], int left, int right ) {

    int i = 0;
    int j = 0;
    int last = 0;

    if ( left > right )
        return;
    printf ( "in qsort .\n" );
    swap_my ( v, left, ( left + right ) / 2 );
    last = left;

    for ( i = left + 1; i <= right; i++ )
        if ( strcmp ( v [ i ], v [ left ] ) < 0 ) 
            swap_my ( v, ++ last, i );

    swap_my ( v, left, last );
    qsort_my ( v, left, last - 1 );
    qsort_my ( v, last + 1, right );
}

void swap_my ( char * v [], int i, int j ) {

    char * temp;

    temp = v [ i ];
    v [ i ] = v [ j ];
    v [ j ] = temp;

}

char * alloc_my ( int len ) {

    if ( allocbuf + ALLOCSIZE - allocp >= len ) {
        allocp += len;
        return ( allocp - len );
    }
    else {
        return 0;
    };
}


