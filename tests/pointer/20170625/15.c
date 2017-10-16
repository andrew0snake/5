#include <stdio.h>
#include <string.h>

#define LEN 10

void f1 ( int step );
void strcpy_my ( char * dest, char source [ LEN ] );
void strcpy_my_2 ( char * dest, int pos );
void strcpy_my_3 ( int pos, char * source );

char arr1 [ LEN ] [ LEN ];
char * arr2 [ LEN ];
int arr2_ptr = 0;    
char * * arr3;

int main ( int argc, char * * argv ) {

    int i = 0;
    int j = 0;
//----arr1 fulling    
    for ( i = 0; i < LEN; i ++ ) {
        for ( j = 0; j < LEN; j ++ ) {
            arr1 [ i ] [ j ] = 0;
        }
    }
//----arr1 printing  
    for ( i = 0; i < LEN; i ++ ) {
        for ( j = 0; j < LEN; j ++ ) {
            printf ( "arr1 [ %d ] [ %d ] = '%c' and %d;\n", i, j, arr1 [ i ] [ j ], arr1 [ i ] [ j ] );
        }
        printf ( "\n" );
    }
//----end of arr1 working

//----arr2 fulling
    for ( i = 0; i < LEN; i ++ ) {
        arr2 [ i ] = " 123 ";
    }
//----arr2 printing
    for ( i = 0; i < LEN; i ++ ) {
        printf ( "arr2 [ %d ] = '%s';\n", i, arr2 [ i ] );
    }
//----arr2 second fulling with f1
    for ( i = 0; i < LEN; i ++ ) {
        printf ( "\nstring for f1:'%s';\n", arr2 [ i ] );
        f1 ( i );
    }

    return 0; 

}

void f1 ( int step ) {

    int i = 0;
    char a = ' ';
    char line [ LEN ];

    extern char * arr2 [ LEN ];
    extern int arr2_ptr;    

    printf ( "getted string:'%s';\n", arr2 [ step ] );
    printf ( "a = '%c' and %d;\n", a, a );
//    strcpy ( line, arr2 [ step ] );
//    strcpy_my_2 ( line, step );
    strcpy_my_3 ( step, line );
    printf ( "line before = '%s';\n", line );

    while ( i < LEN ) {
        line [ i ] = 32;
        i ++;
    }
    line [ i ] = '\0';

    printf ( "line after :'%s';\n", line );

    printf ( "arr2 [ %d ] before :'%s';\n", step, arr2 [ step ] );
    strcpy_my ( arr2 [ step ], line );
    printf ( "arr2 [ %d ] after  :'%s';\n", step, arr2 [ step ] );

    printf ( "\n----------\n" );
}

void strcpy_my ( char * dest, char source [ LEN ] ) {

    short int i = 0;

    extern char * arr2 [ LEN ];
    extern int arr2_ptr;    

    dest = source;

//    printf ( "* dest = '%s';\n", * dest );
    printf ( "dest = '%p';\n", dest );

    i = 0;
    while ( * dest != '\0' && i < LEN ) {
        printf ( "* ( dest + %d ) = '%c';\n", i, * ( dest + i ) );
        i ++;
    }
    
    printf ( "dest string:'%s';\n", dest  );

}

void strcpy_my_2 ( char * dest, int pos ) {

    int i = 0;

    extern char * arr2 [ LEN ];
    extern int arr2_ptr;    

    while ( * ( arr2 [ pos ] + i ) != '\0' ) {
        * ( dest + i ) = * ( arr2 [ pos ] + i );       
        printf ( "* ( dest + i ) = * ( arr2 [ pos ] + i ) = %c;\n", * ( dest + i ) = * ( arr2 [ pos ] + i ) );       
        i ++;     
    }
}

void strcpy_my_3 ( int pos, char * source ) {

    int i = 0;

    extern char * arr2 [ LEN ];
    extern int arr2_ptr;    

    printf ( "int strcpy_my_3 ( arr2 [ %d ] ) = '%s';\n", pos, ( arr2 [ pos ] ) );
    printf ( "int strcpy_my_3 source = '%s';\n",source );

    while ( * ( source + i ) != '\0' ) {
        printf ( "* ( source + i ) = '%c';\n", * ( source + i ) );
        * ( arr2 [ pos ] + i ) = * ( source + i );
        i ++;
    } 

}




