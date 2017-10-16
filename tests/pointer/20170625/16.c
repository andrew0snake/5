#include <stdio.h>

#define LEN 5

void f1 ( int pos );
void f2 ( int pos );
void f3 ( int pos, char * line );
void f4 ( char * line );
void f5 ();    

char * array [ LEN ];

int main () {

    int i = 0;
    char * line = "137";

    printf ( "\nbefore f1:\n" );
    for ( i = 0; i < LEN; i ++ ) {
        printf ( "array [ %d ] = '%s';\n", i, array [ i ] );
    }

    f1 ( i );

    printf ( "\nafter f1:\n" );
    for ( i = 0; i < LEN; i ++ ) {
        printf ( "array [ %d ] = '%s';\n", i, array [ i ] );
    }

    i = 3;
    
    f2 ( i );

    printf ( "\nafter f2:\n" );
    for ( i = 0; i < LEN; i ++ ) {
        printf ( "array [ %d ] = '%s';\n", i, array [ i ] );
    }
    
    i = 2;
    f3 ( i, line );

    printf ( "\nafter f3:\n" );
    for ( i = 0; i < LEN; i ++ ) {
        printf ( "array [ %d ] = '%s';\n", i, array [ i ] );
    }

    printf ( "\n" );

    f4 ( line );
    printf ( "\nafter f4:\n" );
    for ( i = 0; i < LEN; i ++ ) {
        printf ( "array [ %d ] = '%s';\n", i, array [ i ] );
    }

    f5 ();


    return 0;

}


void f1 ( int pos ) {
    
    int i = 0;

    printf ( "\nin f1.\n" );

    for ( i = 0; i < LEN; i ++ ) { 
        * ( array + i ) = "123";
        printf ( "array [ %d ] = '%s';\n", i, array [ i ] );
    }

}

void f2 ( int pos ) {

    * ( array + pos ) = "456";
    printf ( "\nin f2 array [ %d ] = '%s';.\n", pos, array [ pos ] );

}

void f3 ( int pos, char * line ) {

    * ( array + pos ) = line;
    printf ( "\nin f3 array [ %d ] = '%s';.\n", pos, array [ pos ] );

}

void f4 ( char * line ) {

    int i = 0;    
    char * line1 = "456";
    char * line2 = "rty";
    char * line3 = "fgh";
    char * line4 = "vbn";
    char * line5 = "789";


/*    * ( array + i ) = line1;
    printf ( "in f4 array [ %d ] = '%s' and %p;\n", i, * ( array + i ), * ( array + i ) );
    i ++;
    * ( array + i ) = line2;
    printf ( "in f4 array [ %d ] = '%s' and %p;\n", i, * ( array + i ), * ( array + i ) );
    i ++;
    * ( array + i ) = line3;
    printf ( "in f4 array [ %d ] = '%s' and %p;\n", i, * ( array + i ), * ( array + i ) );
    i ++;
    * ( array + i ) = line4;
    printf ( "in f4 array [ %d ] = '%s' and %p;\n", i, * ( array + i ), * ( array + i ) );
    i ++;
    * ( array + i ) = line5;
    printf ( "in f4 array [ %d ] = '%s' and %p;\n", i, * ( array + i ), * ( array + i ) );
*/

    for ( i = 0; i < LEN; i ++ ) {
        if ( i == 0 ) {
            * ( array + i ) = line1;
            printf ( "in f4 array [ %d ] = '%s' and %p;\n", i, * ( array + i ), * ( array + i ) );
        }
        if ( i == 1 ) {
            * ( array + i ) = line2;
            printf ( "in f4 array [ %d ] = '%s' and %p;\n", i, * ( array + i ), * ( array + i ) );
        }
        if ( i == 2 ) {
            * ( array + i ) = line3;
            printf ( "in f4 array [ %d ] = '%s' and %p;\n", i, * ( array + i ), * ( array + i ) );
        }
        if ( i == 3 ) {
            * ( array + i ) = line4;
            printf ( "in f4 array [ %d ] = '%s' and %p;\n", i, * ( array + i ), * ( array + i ) );
        }
        if ( i == 4 ) {
            * ( array + i ) = line5;
            printf ( "in f4 array [ %d ] = '%s' and %p;\n", i, * ( array + i ), * ( array + i ) );
        }

    }


/*    for ( i = 0; i < LEN; i ++ ) {
        * ( array + i ) = "zxc" + i;
        printf ( "in f4 array [ %d ] = '%s' and %p;\n", i, * ( array + i ), * ( array + i ) );
    }
*/

}
 

void f5 () {

    int i = 0;

    while ( * ( array [ 1 ] + i ) != '\0' ) {
        printf ( "* ( array [ 1 ] + %d ) = '%c';\n", i, * ( array [ 1 ] + i ) );
        i ++;
    }

}


