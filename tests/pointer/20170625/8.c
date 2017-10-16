#include <stdio.h>

#define STR 3
#define ROW 5    

void strcpy_my ( char * s, char * argv ) ;
void pr_argv ( char * argv );
void arr_ops ( char * * arr, int argc, char * * argv );    

int main ( int argc, char * argv [] ) {
//int main ( int argc, char * * argv ) {

    int i = 0;
    int j = argc;

//    char f [ 10 ];
    char * f;
    char * * arr;

    while ( j -- > 0 ) {
        printf ( "* argv = '%s';\n", * argv );        
        pr_argv ( * argv ++ );
    }
    printf ( "end of first cycle.\n" );
    printf ( "\nafter ending of first cycle argc = %d, and * argv = '%s';\n", argc, * argv );

    for ( i = 0; i < argc; i ++, * argv -- ) {
    }
    printf ( "before begining of second cycle argc = %d, and * argv = '%s';\n", argc, * argv );

    for ( i = 0; i < argc; i ++ ) {
        strcpy_my ( f, * argv ++ );
        printf ( "result string = '%s';\n", f );
    }

    printf ( "end of second cycle.\n\n" );

    for ( i = 0; i < argc; i ++, * argv -- ) {
    }
    
    arr_ops ( arr, argc, argv );

    return 0;

}

void arr_ops ( char * * arr, int argc, char * * argv ) {

    int i = 0;
    int j = 0;
    char tmp [ 100 ];

/*    while ( * argv ) {
        strcpy_my ( * arr ++, * argv ++ ); 
    }
*/
    
    for ( i = 0; i < argc; i ++ ) {
        printf ( "* ( argv + ( i = %d ) ) = '%s' _whole string_;\n\n", i, * ( argv + i )  );
        j = 0;
        while ( * ( * ( argv + i ) + j ) != '\0' ) {
            printf ( "* ( * ( argv + i ) + j ) = '%c';\n", * ( * ( argv + i ) + j ) );
            j ++;
        }        
        strcpy_my ( tmp, * ( argv + i ) );
        printf ( "getted string tmp:'%s'\n", tmp ); 
        strcpy_my ( * ( arr + i ), tmp );
        printf ( "-------------------\n" );    
    }

}


void pr_argv ( char * argv ) {

    int i = 0;

    while ( argv [ i ] != '\0' ) {
        printf ( "argv [ i = %d ] = %c;\n", i, argv [ i ] );
        i ++;
    }

} 


void strcpy_my ( char * s, char * argv ) {

//    int i = 0;
    char exit = 0;

    printf ( "\n" );

    while ( exit == 0 ) {
        printf ( "( * s = * t ) = '%c'; * t = '%c';\n", ( * s = * argv ), * argv );
        * s ++ = * argv ++ ;
        if ( * argv == '\0' ) {
            * s ++ = * argv ++ ;
            exit = 1;
        }
    };

/*    while ( exit == 0 ) {
        printf ( "s [ i  = %d ] = argv [ i ] = %c;\n", i, argv [ i ] );
        s [ i ] = argv [ i ];
        if ( argv [ i ] == '\0' ) {
            exit = 1;
        }
        i ++;
    };
*/

}





