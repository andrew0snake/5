#include <stdio.h>

void f1 ( int * p1 );
void f2 ( void f_p ( int * ), int * p2 );


int main ( int argc, char * argv [] ) {


    int a = 5;

    printf ( "\nin main a = %d;\n\n", a );

    f1 ( & a );

    f2 ( f1, & a );

    return 0;

}


void f1 ( int * p1 ) {

    printf (  "in f1 getted pointer p1 = %p and its value is:%d;\n\n", p1, * p1 );

}


void f2 ( void f_p ( int * ), int * p2 ) {

    printf ( "\nin f2 getted pointer p2 = %p, and * p2 = %d;\n", p2, * p2 );

    f_p ( p2 );

    printf ( "end of f2;\n\n" );

}


