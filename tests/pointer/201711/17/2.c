#include <stdio.h>

void f1 ( char * str1 );
void f2 ( void ( f ) ( char * ), char * ); 

int main () {

    char str [] = "123";

    printf ( "in main pointer to str [ 0 ] = %p;\n", & str [ 0 ] );
    printf ( "in main pointer to str =w      %p;\n", str );
    printf ( "str = %s;\n", str );
   
//    f1 ( str );
    f1 ( & str [ 0 ] );
 
    f2 ( f1, str );
    return 0;

}


void f1 ( char * str1 ) {

    printf ( "----------------------------------\n" );
    printf ( "in f1 getted pointer:          %p;\n", str1 ); 
    printf ( "in f1 getted pointer points to: %s;\n", str1 );
    printf ( "----------------------------------\n" );

}


void f2 ( void ( f ) ( char * ), char * str2 ) {


    printf ( "==================================\n" );
    printf ( "in f2 getted pointer:          %p;\n", str2 );

    f ( str2 );
    printf ( "==================================\n" );



}

