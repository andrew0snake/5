#include <ctype.h>
#include <stdio.h>

#define SIZE 5

int getint ( int *pn );
int getch ( void );
void ungetch ( int c );

char buf [ SIZE ];
int bufp = 0;


void main () {

    int k = 0;
    int m = 0;
    int n = 0;
    int array [ SIZE ];
    
    for ( n = 0; n < SIZE && getint ( & array [ n ] ) != EOF; n++ ) {
        printf ( "in main n = %d;\n", n );
        printf ( "in main check bufp = %d; buf [ bufp - 1 = %d ] = '%c' in char and %d in digit;\n", bufp, bufp - 1, buf [ bufp - 1 ], buf [ bufp - 1 ] );
        printf ( "-----------------------\n" );
    }

    printf ( "n = %d;\n", n );  
 
    for ( m = 0; m <= n && m < SIZE; m++ ) {
        printf ( "array [ %d ] = %d; m = %d; n = %d;\n", m, array [ m ], m, n );   
    };

    for ( k = 0; k < bufp; k++ ) {
        printf ( "buf [ %d ] = %d in digit and '%c' in char;\n", k, buf [ k ], buf [ k ] );
    }
}

int getch ( void ) {
  
    if ( bufp > 0 ) {
        printf ( "In getch () bufp = %d; buf [ bufp - 1 = %d ] = %d in digit and '%c' in char;\n", bufp, bufp - 1, buf [ bufp - 1 ], buf [ bufp - 1 ] );
    } 
    return ( ( bufp > 0 ) ? buf [ -- bufp ] : getchar () );

}

void ungetch ( int c ) {

    if ( bufp > SIZE ) {
       printf ( "Ungetch : too much symbols.\n" );
    }
    else {
        printf ( "In ungetch () ungetched symbol is %d in digit and '%c' in char.\n", c, c );
        buf [ bufp ++ ] = c;
    }
}


int getint ( int *pn ) {

    int c = 0;
    int sign = 0;

    printf ( "Start of getint.\n" );

//    while ( isspace ( c = getch () ) || ( c == '\n' ) ) {
    while ( isspace ( c = getch () ) ) {
        printf ( "Skiped in first check c = %c in char and %d in digit.\n", c, c );
    }

    printf ( "After first check c = '%c' in char and %d in digit;\n", c, c );

    if ( ! isdigit ( c ) && c != EOF && c != '+' && c != '-' ) {
        printf ( "In getint () in second check returning %d in digit and '%c' in char;\n", c, c );
        ungetch ( c );
        return 0;
    };

    sign = ( c == '-' ) ? ( -1 ) : 1;

    if ( c == '+' || c == '-' ) {
        c = getch ();
        printf ( "in getint after check for '+' and '-' c = %d in digit and '%c' in char;\n", c, c );
    };
    
    for ( *pn = 0; isdigit ( c ); c = getch () ) {
        *pn = 10 * *pn + ( c - '0' ) ;
        printf ( "in getint in cycle \"isdigit\" c = %d in digit and '%c' in char;\n", c, c );
    };    
    
    *pn *= sign;

    if ( c != EOF ) {
        printf ( "in getint in check \"is EOF\" c = %d in digit and '%c' in char;\n", c, c );
        ungetch ( c ); 
    }

    return c;
}

