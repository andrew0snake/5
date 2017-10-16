#include <ctype.h>
#include <stdio.h>

#define SIZE 5

int getint ( int *pn );
int getfloat ( float *pn );
int getch ( void );
void ungetch ( int c );

char buf [ SIZE ];
int bufp = 0;


void main () {

    int k = 0;
    int m = 0;
    int n = 0;
    int type = 0;
    float array [ SIZE ];
    
    for ( n = 0; n < SIZE && ( type = getfloat ( & array [ n ] ) ) != EOF; n++ ) {
        printf ( "array [ %d ] = %f%s;\n", n, type ? array [ n ] : type, type ? "" : " is not a number" );
        printf ( "-----------------------\n" );
        if ( type == 0 ) {
            array [ n ] = EOF;
        }
    }
 
    for ( m = 0; m <= n && m < SIZE; m++ ) {
        printf ( "array [ %d ] = %f; m = %d; n = %d;\n", m, array [ m ], m, n );   
    };

    for ( k = 0; k < bufp; k++ ) {
        printf ( "buf [ %d ] = %d in digit and '%c' in char;\n", k, buf [ k ], buf [ k ] );
    }
}

int getch ( void ) {
  
    return ( ( bufp > 0 ) ? buf [ -- bufp ] : getchar () );

}

void ungetch ( int c ) {

    if ( bufp > SIZE ) {
       printf ( "Ungetch : too much symbols.\n" );
    }
    else {
        buf [ bufp ++ ] = c;
    }
}


int getint ( int *pn ) {

    int c = 0;
    int sign = 0;

    while ( isspace ( c = getch () ) ) {
    }


    if ( ! isdigit ( c ) && c != EOF && c != '+' && c != '-' ) {
//        ungetch ( c );
        return 0;
    };

    sign = ( c == '-' ) ? ( -1 ) : 1;

    if ( c == '+' || c == '-' ) {
        c = getch ();
        if ( ! isdigit ( c ) ) {
            ungetch ( ( sign == 1 ) ? '+' : '-' );
            return 0;
        }
    };
    
    for ( *pn = 0; isdigit ( c ); c = getch () ) {
        *pn = 10 * *pn + ( c - '0' ) ;
    };    
    
    *pn *= sign;

    if ( c != EOF ) {
        ungetch ( c ); 
    }

    return c;
}

int getfloat ( float *pn ) {

    int c = 0.0;
    int sign = 0;
    float step = 1.0;

    while ( isspace ( c = getch () ) ) {
    };

    if ( ! isdigit ( c ) && c != EOF && c != '+' && c != '-' ) {
        return 0;
    };

    sign = ( c == '-' ) ? ( - 1 ) : 1;

    if ( c == '+' || c == '-' ) {
        c = getch ();
        if ( ! isdigit ( c ) ) {
           ungetch ( ( sign == 1 ) ? 1 : ( - 1 ) );
           return 0;
        };
    };
 
    for ( *pn = 0; isdigit ( c ); c = getch () ) {
        *pn = 10 * *pn + ( c - '0' );
    };

    if ( c == '.' ) {
        c = getchar ();
//        while ( isdigit ( c = getch () ) ) {
        for ( step = 1.0; isdigit ( c ); c = getch () ) {
            *pn = 10.0 * *pn + ( c - '0' );
            step = step * 10.0;
        };    
    };

    *pn = *pn * sign / step;

    printf ( "In the end of getfloat *pn = %f;and c = '%c' in char and %d in digit;\n", *pn, c, c );

    if ( c != EOF && c != '\n' ) {
        ungetch ( c );
    };

    return c;

}


