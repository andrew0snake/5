#include <stdio.h>

#define STR 3
#define ROW 5    

void strcpy_my ( char * dest, char * source ) ;
void arr_ops ( char * * arr, int argc, char * * argv );
int getline_my  ( char * line );

char * array_1 [ 100 ];

//int main ( int argc, char * argv [] ) {
int main ( int argc, char * * argv ) {

    char * arr [ 100 ];
   
    arr_ops ( arr, argc, argv );

    return 0;

}

void arr_ops ( char * * arr, int argc, char * * argv ) {
    
    int i = 0;
    int j = 0;
    int len = 0;
    char line [ 100 ];
    char tmp [ 100 ];

    while ( ( len = getline_my ( line ) ) != 0 ) {
//        strcpy_my ( tmp, line );
//        * ( array_1 + i ) = NULL;
        * ( array_1 + i ) = "zxc";
        strcpy_my ( * ( array_1 + i ), line );
        i ++;
//        printf ( "line tmp = '%s';\n", tmp );
        printf ( "line * ( array_1 + %d ) = '%s';\n", j, * ( array_1 + j ) );
    } 

    for ( j = 0; j < i; j ++ ) {
        printf ( "* ( array_1 + %d ) = '%s';\n", j, * ( array_1 + j ) );
    }

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

void strcpy_my ( char * dest, char * source ) {

    int i = 0;
    char exit = 0;

    printf ( "--\n" );

    while ( exit == 0 ) {
//        printf ( "* ( source + i ) = %c;\n", * ( source + i ) );
        * ( dest + i ) = * ( source + i );
//        printf ( "* ( dest + %d ) = * ( source + %d ) = %c;\n", i, i, * ( dest + i ) );
        if ( * ( source + i ) == '\0' ) {
            i ++;
            * ( dest + i ) = * ( source + i );
            exit = 1;
        }
        i ++;
    };


}






