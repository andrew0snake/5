#include <stdio.h>

#define SZ 100

void getline_my ( char * line );
void strcat_my ( char * s, char * d );
int strend_my ( char * s, char * t );
int strlen_my ( char string1 [ SZ ] );
void strncpy_my ( char * dest [ SZ * 2 ], char * src [ SZ ], int num );

//char line2 [ SZ ];

void main () {

    char line1 [ SZ ];
    char line2 [ SZ ];
    char num_s [ SZ ];
    int len = 0;
    int con = 0;
    int i = 0;
    int num = 0;
    int rez = 0;

    printf ( "Input please string for copiyng:\n" );
    getline_my ( & line2 );
    printf ( "\nGetted string = %s;\n\n", line2 );

    len = strlen_my ( line2 );
    printf ( "lenght of string line2 = %d;\n\n", len );

    printf ( "And now input please number of symbols of string2 that you want to place in line1:\n" );
    getline_my ( & num_s );
    num = atoi ( num_s );
    printf ( "\nNumber of symbols = %d;\n\n", num );

    strncpy_my ( & line1, & line2, num);
    printf ( "After strncpy_my destination string = \"%s\";\n", line1 );

}


void getline_my ( char * line )

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

void strncpy_my ( char * dst [ SZ ], char * src [ SZ ], int num ) {

    int i = 0;
    int len_s = 0;
    int len_d = 0;
    char exit = 0;

    if ( num > SZ - 1 ) {
        printf ( "Warning: number of returning symbols is more, than destination string.\n" );
    };

    len_s = strlen_my ( src );
    printf ( "Length of source string ( len_s ) = %d;\n", len_s );
    printf ( "Length of destination string ( SZ ) = %d;\n", SZ );

    if ( num > len_s ) {
        printf ( "Warning: number of returning symbols is more than same string.\n" );
    }; 

    i = 0;
    exit = 0;

    for ( i = 0; i < num && exit == 0; i++ ) {
        if ( i == ( SZ - 2 ) ) {
            printf ( "i = %d == len_d - 1 = %d;\n", i, len_d - 1 );
            exit = 1;
            * dst [ i ] = * src [ i ];
            i++;
            * dst [ i ] = '\0';
        }
        else {
            if ( i == len_s - 1 ) {
                exit = 1;
                * dst [ i ] = * src [ i ];
                i++;
                * dst [ i ] = '\0'; 
            }
            else {
                printf ( "here i = %d; \* dst [ i = %d ] = %c in char and %p in pointer;\n",i, i, * src [ i ], * src [ i ] );
                * dst ++ = * src ++;
            }
        }
        printf ( "step %d;\n", i );
    }

/*    for ( i = 0; i < num && exit == 0; i++ ) {
        printf ( "i = %d; len_d - 1 = %d;\n", i, len_d - 1 );
        if ( i == ( len_d - 1 ) ) {
            printf ( "i = %d; len_d - 1 = %d;\n", i, len_d - 1 );
            exit = 1;
            printf ( "i is eq ( len_d = %d ) - 1 = %d;\n", len_d, i );
            * dst [ i ] = * src [ i ];
            i++;
            *dst [ i ] = '\0';
        }
        else {
            if ( i == len_s ) {
                exit = 1;
                * dst [ i ] = * src [ i ];
                i++;
                * dst [ i ] = '\0';
            }
            else {
                * dst [ i ] = * src [ i ];
            };
        };         
    };
*/

}


