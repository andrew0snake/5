#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SC 10
#define MAXLINES 100
#define MAXLEN 1000
#define ALLOCSIZE 100000


char * lineptr [ MAXLINES ];
char allocbuf [ ALLOCSIZE ];
char * allocp = allocbuf;
char line_count = 0;

char numeric = 0;
char reverse = 0;
char case_insensitive = 0;
char directory = 0;
char fs_cap = 0;
char pos_1 = 0;
char pos_2 = 0;
char pos_1_set = 0;
char pos_2_set = 0;
char * sub_string1;
char * sub_string2;

int readlines ( char * lineptr [], int nlines );
int getline_my ( char * line );
void writelines ( char * lineptr [], int nlines, int rev );

int alloc ( int n );
void afree ( char * p );

void qsort_my ( void * lineptr [], int left, int right, int ( * comp ) ( void *, void * ) );
void swap ( void * v [], int, int );
int numcmp ( char *, char * );
int case_insensitive_cmp ( char *, char * );
int substr_cmp ( char *, char * );
int check_stringlenghts ( );
void substr_my ( char * substr, char * str, int start, int end );

int parse_input ( int argc, char * argv [] );
void print_usage ();
void clear_line ( char * line, int len );
int conv_line ( char * p );


/* sort input lines */
int main ( int argc, char * argv [] ) {

    int rez = 0;

    print_usage ();

    rez = parse_input ( argc, argv );
    
    if ( rez == 0 ) {
        readlines ( lineptr, 10 );
        rez = check_stringlenghts ( );
        if ( rez != 0 ) {            
            printf ( "\nchecking found error: some of strings are shorter than second position in field-searching option\n" );
            printf ( "because of this error this program cannot be continued and finalize its execution with error code (-1).\n\n" );
        }
        else {
            if ( numeric == 1 ) {
                qsort_my ( ( void * * ) lineptr, 0, line_count - 1, numcmp );
            }
            else { 
                if ( pos_2 == 0 ) {
                    qsort_my ( ( void * * ) lineptr, 0, line_count - 1, case_insensitive_cmp );
                }
            }
        }
    }
    else {
        printf ( "wrong input, try another time.\n" );
    }

    writelines ( lineptr , line_count, reverse );

    return 0;

}


void qsort_my ( void * v [], int left, int right, int ( * comp ) ( void * , void * ) ) {

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
        qsort_my ( v, left, last - 1, comp );
        qsort_my ( v, last + 1, right, comp );
    }

}


int numcmp ( char * s1, char * s2 ) {

    double v1 = 0.0;
    double v2 = 0.0;
    char tmp_string_1 [ MAXLEN ];
    char tmp_string_2 [ MAXLEN ];

    if ( fs_cap == 0 ) {
        v1 = atof ( s1 );
        v2 = atof ( s2 );
    }
    else {
        substr_my ( tmp_string_1, s1, pos_1, pos_2 );
//        printf ( "after substr_my tmp_string_1 = '%s';\n", tmp_string_1 );

        v1 = atof ( tmp_string_1 );
//        printf ( "v1:%f, tmp_string_1 = '%s';\n", v1, tmp_string_1 );

        substr_my ( tmp_string_2, s2, pos_1, pos_2 );
//        printf ( "after substr_my tmp_string_2 = '%s';\n", tmp_string_2 );

        v2 = atof ( tmp_string_2 );
//        printf ( "v2:%f; tmp_string_2 = '%s';\n", v2, tmp_string_2 );
    }

//    printf ( "end of numcmp.\n" );

    if ( v1 < v2 ) 
        return -1;
    else 
        if ( v1 > v2 ) 
            return 1;
        else
            return 0;

}


int case_insensitive_cmp ( char * line1 , char * line2 ) {

    char tmp_string_1 [ MAXLEN ];
    char tmp_string_2 [ MAXLEN ];
    char exit = 1;

    int i = 0;
    int j = 0;

    if ( fs_cap ) {
        substr_my ( tmp_string_1, line1, pos_1, pos_2 );
        substr_my ( tmp_string_2, line2, pos_1, pos_2 );
    }
    else {
        strcpy ( tmp_string_1, line1 );
        strcpy ( tmp_string_2, line2 );
    }

    if ( directory ) {
        while ( exit ) {
            if ( isdigit ( tmp_string_1 [ i ] ) && ( isalpha ( tmp_string_1 [ i ] ) ) && ( isspace ( tmp_string_1 [ i ] ) ) ) {
                if ( isdigit ( tmp_string_2 [ j ] ) && ( isalpha ( tmp_string_2 [ j ] ) ) && ( isspace ( tmp_string_2 [ j ] ) ) ) {
                    if ( tolower ( tmp_string_1 [ i ] ) != tolower ( tmp_string_2 [ j ] ) ) {
                        return ( tolower ( tmp_string_1 [ i ] ) - tolower ( tmp_string_2 [ j ] ) );
                    }                     
                }
                else {
                    if ( tmp_string_2 [ j ] != '\0' ) {
//                        tmp_string_2 ++;
                        j ++;
                    }
                    else {
                        exit = 0;
                    }
                }
            }
            else {
                if ( tmp_string_1 [ i ] != '\0' ) {
//                    tmp_string_1 ++;
                    i ++; 
               }
                else {
                    exit = 0;
                }    
            }                        
        }
        return 0;
    }
    else {
        while ( tolower ( tmp_string_1 [ i ] ) == tolower ( tmp_string_2 [ j ] ) ) {
            if ( tmp_string_1 [ i ] == '\0' ) {
                return 0;
            }
//            tmp_string_1 ++;
//            tmp_string_2 ++;
            i ++;    
            j ++;
        }
        return ( tolower ( tmp_string_1 [ i ] ) - tolower ( tmp_string_2 [ j ] ) );
    }

}


int substr_cmp ( char * first, char * sec ) {

//    if 
    



    return 0;

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
            line_count ++;
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
            printf ( "'%s', and %f;\n", lineptr [ i ], atof ( lineptr [ i ] ) );        
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
    printf ( "This is qsort_my program. Using it you can sort arrays of strings in increase order without flags.\n" );
    printf ( "Or in decrease order with -r flag.\n" );
    printf ( "Also it's possible to disable case sensetivity with flag -f;\n" );   
    printf ( "Or set by -d the directory order option, which makes comparasion only on letters, numbers or blanks.\n" );
    printf ( "Also you can set field-searching by setting fields by setting -1 +3, which makes field starts from first symbol and ends on third.\n" );
    printf ( "Each field sorted according independent set of options;\n" );
    printf ( "=============================\n\n");


}


int parse_input ( int argc, char * argv [] ) {

    char c = 0;
    int i = 1;

    while ( i > 0 && i < argc ) {
        if ( * ( * ( argv + i ) ) == '-' ) {            
            while ( i != 0 && i < argc && ( c = * ( * ( argv + i ) ) ) == '-' ) {
                c = * ( * ( argv + i ) + 1 );
                switch ( c ) {
                    case 'n':
                        numeric = 1;
                        break;
                    case 'r':
                        reverse = 1;
                        break;                                                                                                          
                    case 'f':
                        case_insensitive = 0;
                        break;
                    case 'd':
                        directory = 1;
                        break;
                    default:
                        if ( isdigit ( c ) ) {
                            if ( pos_1_set != 0 ) {
                                printf ( "wrong input: start position is set yet.\n" );    
                            }
                            else {
                                pos_1_set = 1;
                                pos_1 = conv_line ( * ( argv + i ) + 1 );    
                            }
                        }
                        else {
                            printf ( "wrong parameter;\n" );                                                                                                                
                            i = -5;
                        }
                        break;                                                                                                                                          
                }        
                    i ++;
            }                                                                                                                                               
        } 
        else {
            if ( * ( * ( argv + i ) ) == '+' ) {            
                if ( isdigit ( c = * ( * ( argv + i ) + 1 ) ) ) {
                    if ( pos_2_set != 0 ) {
                        printf ( "wrong input: end position is set yet.\n" );    
                        i = 0;
                    }
                    else {
                        pos_2_set = 1;
                        pos_2 = conv_line ( * ( argv + i ) + 1 );    
                    }
                }
                    i ++;
            
            }
            else {
                return -1;
                i = 0;
            }
        }

    }

    if ( pos_2 < pos_1 ) {
        printf ( "pos_2 < pos_1.\n" );
        return -1;
    }
    else 
        if ( pos_2 == pos_1 && ( pos_2 != 0 && pos_1 != 0 ) ) {
            printf ( "pos_2 == pos_1.\n" );
            return -1;
        }
        else {
            if ( pos_1 < 0 || pos_2 < 0 ) {
                printf ( "pos_1 < 0 or pos_2 < 0.\n" );
                return -1;
            }
            else {
                if ( pos_2 > 0 ) {
                    fs_cap = 1;
                }

                printf ( "after parsing of input:\n\n" );
                printf ( "pos_1           = %d; \npos_2           = %d;\n\n", pos_1, pos_2 );
                printf ( "fs_cap          = %d;\n", fs_cap );
                printf ( "numeric         = %d;\n", numeric );
                printf ( "reverse         = %d;\n", reverse );
                printf ( "directory       = %d;\n", directory );
                printf ( "case_insensitive = %d;\n\n", case_insensitive );

                return 0;

                }                            
            }

}


int conv_line ( char * p ) {

    int i = 0;
    char line [ MAXLEN ];
    char c = 0;

    clear_line ( line, MAXLEN );

    while ( isdigit ( c = *  ( p + i ) ) && c != '\0' && c != '\n' ) {
        line [ i ] = c;
        i ++;
    }

    return ( atoi ( line ) );
}


void clear_line ( char * line, int len ) {

    int i = 0;

//    printf ( "in clear_line line = '%s', len = %d;\n", line, len );

    for ( i = 0; i < len; i ++ ) {
        * ( line + i ) = '\0';
    }

}



int check_stringlenghts ( ) {

    char error = 0;
    int i = 0;

    for ( i = 0; i < line_count; i ++ ) {
        printf ( "getted line for check:'%s';", * ( lineptr + i ) );
        printf ( "and its lenght = %d;", strlen ( * ( lineptr + i ) ) );
        printf ( " and its pointer is %p;\n", * ( lineptr + i ) );
        if ( strlen ( * ( lineptr + i ) ) < pos_2 ) {
            error = 1;
            printf ( "\nfound error in lenght of string '%s': its lenght = %d and is less then pos_2 = %d;\n", * ( lineptr + i ), strlen ( * ( lineptr + i ) ), pos_2  );
            return ( 1 );
        }
    }

    return 0;

}

void substr_my ( char * sub_string, char * str, int start, int end ) {

    clear_line ( sub_string, strlen ( sub_string ) );
    memcpy ( sub_string, & str [ pos_1 ], pos_2 - pos_1 );
    sub_string [ pos_2 - pos_1 ] = '\0';

}



