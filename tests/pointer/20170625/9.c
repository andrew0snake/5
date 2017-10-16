#include <stdio.h>

#define STR 3
#define ROW 5    

void strcpy_argv ( char * s, char * argv ) ;
void strcpy_my ( char * dest, char * source ) ;
void pr_argv ( char * argv );
void arr_ops ( char * * array, int argc, char * * argv );    

//int main ( int argc, char * argv [] ) {
int main ( int argc, char * * argv ) {

    char * arr [ 100 ];
   
    arr_ops ( arr, argc, argv );

    return 0;

}

void arr_ops ( char * * array, int argc, char * * argv ) {

    int i = 0;
    int j = 0;
    char tmp [ 100 ];

   
    for ( i = 0; i < argc; i ++ ) {
        printf ( "* ( argv + ( i = %d ) ) = '%s' _whole string_;\n\n", i, * ( argv + i )  );
        j = 0;
        while ( * ( * ( argv + i ) + j ) != '\0' ) {
            printf ( "* ( * ( argv + i ) + j ) = '%c';\n", * ( * ( argv + i ) + j ) );
            j ++;
        }        
        strcpy_argv ( tmp, * ( argv + i ) );
        printf ( "getted string tmp:'%s'\n", tmp ); 
        printf ( "string * ( arr + i ):'%s'\n", * ( array + i ) ); 
        strcpy_my ( * ( array + i ), tmp );
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


void strcpy_argv ( char * dest, char * source ) {

    int i = 0;
    char exit = 0;

    printf ( "__\n" );

    while ( exit == 0 ) {
        * ( dest + i ) = * ( source + i ) ;       
        printf ( "( * dest = * source ) == '%c'; * source = '%c'; i = %d;\n", * ( dest + i ), * ( source + i ), i );
//        if ( * source == '\0' ) {
        if ( * ( source + i ) == '\0' ) {
            i ++;
            * dest = * source;
            exit = 1;
        }
        i ++;
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

void strcpy_my ( char * dest, char * source ) {

    int i = 0;
    char exit = 0;

    printf ( "--\n" );

    while ( exit == 0 ) {
        printf ( "* ( source + i ) = %c;\n", * ( source + i ) );
        * ( dest + i ) = * ( source + i );
        printf ( "* ( dest + %d ) = * ( source + %d ) = %c;\n", i, i, * ( dest + i ) );
        if ( * ( source + i ) == '\0' ) {
            i ++;
            * ( dest + i ) = * ( source + i );
            exit = 1;
        }
        i ++;
    };


}






