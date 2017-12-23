#include <stdio.h>

int f1 ( int a, int b );
int f2 ( int *, int * );

int main ( ) {

    int a = 5;
    int b = 13;
    int rez = 0;
    
    rez = f1 ( a, b );

    printf ( "rez = %d;\n", rez );
    printf ( "\nafter f1:\na = %d; b = %d;\n", a, b );

    printf ( "-------------------\n" );

    rez = 0;
    rez = f2 ( & a, & b );
    printf ( "rez = %d;\n", rez );
    printf ( "\nafter f2:\na = %d; b = %d;\n", a, b );

    return 0;    

}


int f2 ( int * frst, int * sec ) {

    printf ( "int f2 getted:\nfrst = %d, b = %d;\n", * frst, * sec );
    printf ( "returning value = %d;\n", * frst + * sec );

//    * frst += 5;
//    * sec += 10;

    ++ * frst;
    ++ * sec; 
    
    return ( * frst + * sec );

}


int f1 ( int a, int b ) {

    printf ( "int f1 getted:\na = %d, b = %d;\n", a, b );
    printf ( "returning value = %d;\n", a + b );

    a += 5;
    b += 10;
    
    return ( a + b );

}


