#include <stdio.h>

#define SZ 100

void getline_my ( char * line );
void strcat_my ( char * s, char * d );
int strend_my ( char * s, char * t );
int strlen_my ( char string1 [ SZ ] );
void strncpy_my ( char * dest , char * src , int num );
int strncat_my ( char * dst, char * src, int n );
void clear_string_my ( char * string );
int strncmp_my ( char * dest, char * src, int n );

//char line_src [ SZ ];

void main () {

    char line_dest [ SZ ];
    char line_src [ SZ ];
    char num_s [ SZ ];
    char choise [ SZ ];
    int len_s = 0;
    int len_d = 0;
    int con = 0;
    int i = 0;
    int num = 0;
    int rez = 0;
    int ch = 0;

    printf ( "Choose what you want to do:\n" );
    printf ( "1. Test strncpy function.\n" );
    printf ( "2. Test strncat function.\n" );
    printf ( "3. Test strncmp function.\n" );
    getline_my ( & choise );    
    ch = atoi ( choise );

    switch ( ch ) {
        case 1:
            printf ( "\nInput please string for copiyng:" );
            getline_my ( & line_src );
            printf ( "\nGetted string = %s;\n\n", line_src );

            len_s= strlen_my ( line_src );
            printf ( "lenght of string line_src = %d;\n\n", len_s);

            printf ( "And now input please number of symbols of string2 that you want to place in line_dest:" );
            getline_my ( & num_s );
            num = atoi ( num_s );
            printf ( "Number of symbols = %d;\n\n", num );

            strncpy_my ( & line_dest, & line_src, num);
            printf ( "After strncpy_my destination string = \"%s\";\n", line_dest );

            clear_string_my ( & line_dest );
            clear_string_my ( & line_src );
            break;
        case 2:
            printf ( "Input please string for where concatenate:" );    
            getline_my ( & line_dest );
            printf ( "\nGetted string = %s;\n\n", line_dest );

            printf ( "Input please string, which is for concatenate:" );    
            getline_my ( & line_src );
            printf ( "\nGetted string = %s;\n\n", line_src );

            len_s= strlen_my ( line_src );
            rez = strncat ( & line_dest, & line_src, len_s);
            printf ( "After concatination destination string = \"%s\";\n", line_dest );

            break;
        case 3:
            printf ( "Input please first string for comparison:" );    
            getline_my ( & line_src );
            printf ( "\nGetted string = %s;\n\n", line_src );

            printf ( "Input please second for where comparison:" );    
            getline_my ( & line_dest );
            printf ( "\nGetted string = %s;\n\n", line_dest );

            printf ( "And now input please number of symbols of strings that you want to compare:" );
            getline_my ( & num_s );
            num = atoi ( num_s );
            printf ( "Number of symbols = %d;\n\n", num );

            len_s= strlen_my ( line_src );
            len_d= strlen_my ( line_dest );
            
            if ( len_s != 0 && len_d != 0 ) {
                rez = strncmp_my ( & line_dest, & line_src, num );
                if ( rez == 0 ) {
                    printf ( "Strings are equal. Rez of strncmp_my = %d;\n", rez );
                }
                else {
                    if ( rez > 0 ) {
                        printf ( "First string is more, than second;\n" );
                    } 
                    else {
                        printf ( "Second string is more, than first;\n" );
                    }
                }
            }
            else {
                printf ( "One of compares string is empty.\n" );
            }
            break;
        default :
            printf ( "Invalid value.\n" );
    }

}


void getline_my ( char * line )

{
    int i = 0;
    int c = 0;

    for ( i = 0; ( ( c = getchar () ) != EOF ) && c != '\n' && i < SZ; line ++, i++ ){
        * line = c;
//        printf ( "line [ %d ] = %c; line = %p;\n", i, * line, line );
    };
    * line ++ = '\0';
}

void strcat_my ( char * s, char * d ) {

    int i = 0;

    while ( * s != '\0' ) {
        s ++;
    };

    while ( * d != '\0' ) {
        * s ++ = * d ++;
    };

    * ( ++ s )  = '\0'; 
    
}


int strend_my ( char * s, char * t ) {

    int i = 0;
    int j = 0;
    int len1 = 0;
    int len2 = 0;
    char prov = 0;

    len1 = strlen_my ( s ); 
    printf ( "string s = \"%s\", len1 = %d;\n\n", s, len1 );

    len2 = strlen_my ( t ); 
    printf ( "string t = \"%s\", len2 = %d;\n\n", t, len2 );

    printf ( "before check len1 = %d; len2 = %d;\n", len1, len2 );
    
    for ( i = len1, j = len2; j > 0 && prov == 0; j--, i-- ) {
        printf ( "in check s [ i = %d ] = %c; t [ j = %d ] = %c;\n", i, s [ i ], j, t [ j ] );
        if ( s [ i ] != t [ j ] ) {
            prov = 1;
        };
    };

    printf ( "after check in strend_my j = %d; prov = %d;\n", j, prov );
 
    if ( j == 0 && prov == 0 ) {
        return 1;
    }
    else { 
        if ( prov == 1 ) {
            return 0;
        }
    };
}

int strlen_my ( char string1 [ SZ ] ) {

    int n;
    
    for ( n = 0; string1 [ n ] != '\0'; n++ ) {
 
    }

    return n;
}

void strncpy_my ( char * dst , char * src , int num ) {

    int i = 0;
    int len_s = 0;
    int len_d = 0;
    char exit = 0;

    if ( num > SZ - 1 ) {
        printf ( "Warning: number of returning symbols is more, than destination string.\n" );
    };

    len_s = strlen_my ( src );
//    printf ( "Length of source string ( len_s ) = %d;\n", len_s );
//    printf ( "Length of destination string ( SZ ) = %d;\n", SZ );

    if ( num > len_s ) {
        printf ( "Warning: number of returning symbols is more than same string.\n" );
    }; 

    i = 0;
    exit = 0;

    for ( i = 0; i < num && exit == 0; i++ ) {
//        printf ( "before checking i = %d; num = %d;\n", i, num );
        if ( i == ( SZ - 2 ) ) {
//            printf ( "i = %d == len_d - 1 = %d;\n", i, len_d - 1 );
            exit = 1;
            * dst ++ = * src ++;
            i++;
            * dst  = '\0';
        }
        else {
            if ( i == len_s - 1 ) {
//                printf ( " i = len_s - 1 = %d;\n", i );
                exit = 1;
                * dst ++ = * src ++;
                i++;
                * dst = '\0';
            }
            else {
//                printf ( "here i = %d; * src  = \"%c\" in char and %p in pointer; \n",i, * src , * src );
                * dst ++ = * src ++;
//                printf ( "* dst = \"%c\" in char and %p in pointer;\n" );            
           };
        };
//        printf ( "step %d;\n", i );
    };

}

int strncat_my ( char * dst, char * src, int n ) {

    int len_s = 0;
    int len_d = 0;

    len_s = strlen_my ( src );
    len_d = strlen_my ( dst );

    if ( len_d == 0 ) {
        strncpy ( & dst, & src, len_s );
        return 0;
    }
    else {
        while ( * dst ++ != '\0' ) {
        };
        *dst --;
        if ( len_s == 0 ) {
            return 0;
        } 
        else {
            while ( ( * dst ++ = * src ++ ) != '\0' ) {
            };
        };
    };

}


void clear_string_my ( char * string ) {

    int i = 0;

    for ( i = 0; i < SZ; i++ ) {
        * string ++ = 0;
    }
}

int strncmp_my ( char * dest, char * src, int n ) {

    int i = 0;

    while ( ( * dest == * src ) != '\0' && i < n && i < SZ - 1 ) {
        i++;
        * dest ++;
        * src ++;
    }; 

    if ( * dest != * src ) {
        return ( * src - * dest );
    }
    else {
        if ( i == n || i == SZ - 1 ) {
            return 0;
        };
    };
}

