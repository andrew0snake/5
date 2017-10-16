#include <stdio.h>
#include <string.h>

#define MAXLINES 5000
#define MAXLEN 1000
#define ALLOCSIZE 10000


char * lineptr [ MAXLINES ];
char allocbuf [ ALLOCSIZE ];
char * allocp = allocbuf;

char numeric = 0;
char reverse = 0;
char case_insensitive = 0;
char directory = 0;

int readlines ( char * lineptr [], int nlines );
void writelines ( char * lineptr [], int nlines, int rev );
int alloc ( int n );
void afree ( char * p );
int getline_my ( char * line );
void qsort ( void * lineptr [], int left, int right, int ( * comp ) ( void *, void * ) );
int numcmp ( char *, char * );
void swap ( void * v [], int, int );
void print_usage ();
int case_insensitive_cmp ( char *, char * );

/* sort input lines */
int main ( int argc, char * argv [] ) {

    int nlines;
    char c = 0;

    print_usage ();

    if ( argc > 1 ) { 
        while ( -- argc > 0 && ( * ++ argv ) [ 0 ] == '-' ) {            
            while ( ( c = * ++ argv [ 0 ]  ) ) {
                switch ( c ) {
                    case 'n':
                        numeric = 1;
                        printf ( "numeric = 1;\n" );
                        break;
                    case 'r':
                        reverse = 1;
                        printf ( "reverse = 1;\n" );
                        break;                                                                                                          
                    case 'f':
                        case_insensitive = 0;
                        printf ( "case_insensitive = 1;\n" );                                    
                        break;
                    case 'd':
                        directory = 1;
                        printf ( "directory = 1;\n" );
                        break;
                    default:                                                                                                                                
                        printf ( "wrong parameter;\n" );                                                                                                                    
                        argc = 0;                                                                                                                                           
                        break;                                                                                                                                              
                }                                                                                                                                                           
            }                                                                                                                                                               
        }                                                                                                                                                                   

    }
    if ( ( nlines = readlines (lineptr, MAXLINES ) ) >= 0 ) {
        if ( numeric ) {
            qsort ( ( void * * ) lineptr, 0, nlines - 1, ( int ( * ) ( void *, void * ) ) ( numcmp ) );
        }
        else {
            if ( case_insensitive || directory ) {
                qsort ( ( void * * ) lineptr, 0, nlines - 1, ( int ( * ) ( void *, void * ) ) case_insensitive_cmp );
            }
            else {
//                qsort ( ( void * * ) lineptr, 0, nlines - 1, ( int ( * ) ( void *, void * ) ) ( strcmp ) );
                qsort ( ( void * * ) lineptr, 0, nlines - 1, strcmp );
            }    
                
        }
        writelines ( lineptr, nlines, reverse );
        return 0;
    }
    else {
        printf ( "input too big to sort;\n" );
        return 1;
    }        

    return 0;

}

void qsort ( void * v [], int left, int right, int ( * comp ) ( void * , void * ) ) {

    int i = 0;
    int last = 0;

    if ( left >= right ) 
        return;
    swap ( v, left, ( left + right ) / 2 );
    last = left;
    for ( i = left + 1; i <= right; i ++ ) {
        if ( ( ( * comp ) ( v [ i ], v [ left ] ) ) < 0 )
            swap ( v, ++ last, i );
        swap ( v, left, last );
        qsort ( v, left, last - 1, comp );
        qsort ( v, last + 1, right, comp );
    }

}


int numcmp ( char * s1, char * s2 ) {

    double v1 = 0.0;
    double v2 = 0.0;

    v1 = atof ( s1 );
    v2 = atof ( s2 );

    if ( v1 < v2 ) 
        return -1;
    else 
        if ( v1 > v2 ) 
            return 1;
        else
            return 0;

}


int case_insensitive_cmp ( char * line1 , char * line2 ) {

    char exit = 1;

    if ( directory ) {
        while ( exit ) {
            if ( isdigit ( * line1 ) && ( isalpha ( * line1 ) ) && ( isspace ( * line1 ) ) ) {
                if ( isdigit ( * line2 ) && ( isalpha ( * line2 ) ) && ( isspace ( * line2 ) ) ) {
                    if ( tolower ( * line1 ) != tolower ( * line2 ) ) {
                        return ( tolower ( * line1 ) - tolower ( * line2 ) );
                    }                     
                }
                else {
                    if ( * line2 != '\0' ) {
                        line2 ++;
                    }
                    else {
                        exit = 0;
                    }
                }
            }
            else {
                if ( * line1 != '\0' ) {
                    line1 ++;
                }
                else {
                    exit = 0;
                }    
            }                        
        }
        return 0;
    }
    else {
        while ( tolower ( * line1 ) == tolower ( * line2 ) ) {
            if ( * line1 == '\0' ) {
                return 0;
            }
            line1 ++;
            line2 ++;
        }
        return ( tolower ( * line1 ) - tolower ( * line2 ) );
    }

}


int readlines ( char * lineptr [], int maxlines ) {

    int len = 0;
    int nlines = 0;
    char * p;
    char line [ MAXLEN ];

    while ( ( len = getline_my ( line ) ) > 0 ) {
        if ( nlines > maxlines || ( ( p = alloc ( len ) ) == NULL ) ) 
            return -1;
        else {
            line [ len - 1 ] = '\0';
            strcpy ( p, line );
            lineptr [ nlines ++ ] = p;
        }
    }

    return nlines;

}
                                                                                                                                                                            
int alloc ( int n ) {                                                                                                                                                 
    if ( allocbuf + ALLOCSIZE - allocp >= n ) {                                                                                                                       
        allocp += n;                                                                                                                                                        
        return ( allocp - n );                                                                                                                                              
    }                                                                                                                                                                       
    else {                                                                                                                                                                  
        return 0;                                                                                                                                                            
    };                                                                                                                                                                      
}

void afree ( char * p ) {
 
    if ( p >= allocbuf && p < allocbuf + ALLOCSIZE ) {
        allocp = p;
    };
}

void writelines ( char * lineptr [], int nlines, int reverse ) {

    int i = 0;

    if ( ! reverse ) {
        for ( i = 0; i < nlines;  i ++ ) {
            printf ( "'%s', and %ld;\n", lineptr [ i ], atof ( lineptr [ i ] ) );        
        }
    }
    else {
        for ( i = 1; i <= nlines; i ++ ) {
            printf ( "'%s', and %f;\n", lineptr [ nlines - i ], lineptr [ nlines - i ] );
        }
    }

}


int getline_my ( char * line ) {

    int i = 0;
    char c = 0;


    while ( ( c = getchar () ) != '\0' && c != '\n' && c != EOF ) {
//        printf ( "c = '%c';\n", c );
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


void swap ( void * v [], int i, int j ) {

    char * temp;    

    temp = v [ i ];
    v [ i ] = v [ j ];
    v [ j ] = temp;

}

void print_usage () {

    printf ( "\n\n=============================\n");
    printf ( "Good time of day, dear user!\n" );
    printf ( "This is qsort program. Using it you can sort arrays of strings in increase order without flags.\n" );
    printf ( "Or in decrease order with -r flag.\n" );
    printf ( "Also it's possible to disable case sensetivity with flag -f;\n" );   
    printf ( "Or set by -d the directory order option, which makes comparasion only on letters, numbers or blanks.\n" );
    printf ( "=============================\n\n");


}



