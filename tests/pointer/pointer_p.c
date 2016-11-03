#include <stdio.h>

# define SZ 10

void f1 ( char * s1 );
void f2 ( char * s2 );
void f3 ( char * s1 );
void main () {

    char string1 [ SZ ] = "123qweasdzxc";

//    f1 ( & string1 );

//    f2 ( & string1 );

//    f1 ( & string1 );

    printf ( "before f3 strintg1 = %s;\n", string1 );
    f3 ( & string1 );
    printf ( "after f3 string1 = %s;\n", string1 );
}

void f1 ( char * s1 ) {

    int i = 0;

    printf ( "in f1:\n" );
    for ( i = 0; i <= 5; i++ ) {
        printf ( "at step %d * s1 = \"%c\" in char; %d in digital and %p as pointer;\n", i, * s1, * s1, * s1 );
        * s1 ++;
    
    };

    printf ( "end of f1.\n" );

}

void f2 ( char * s2 ) {

    int i = 0;

    printf ( "in f2:\n" );
    for ( i = 0; i <= 9; i++ ) {
        printf ( "at step %d * s2 = \"%c\" in char; %d in digital and %p as pointer;\n", i, * s2, * s2, * s2 );
        * s2 ++;
    };

    printf ( "---in f2---\n---after first cycle---\n" );

    for ( i = 0; i < 5; i++ ) {
        * -- s2 ;
    };

    i = 0;
    while ( * s2 != '\0' ) {
        printf ( "at step %d * s2 = \"%c\" in char and %d in digit; and %p as pointer\n", i, * s2, * s2, * s2 );
        * s2 ++;
        i ++;
    } 

    printf ( "end of f2.\n" );

}


void f3 ( char * string1 ) {

    int i = 0;

    for ( i = 0; i < 5; i ++ ) {
        printf ( "string1 [ %d ] = %c;\n", i, string1 [ i ] );
        string1 [ i ] = string1 [ i ] + 2;
        printf ( "after string1 [ %d ] = %c;\n", i, string1 [ i ] );
    }


}


