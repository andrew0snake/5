#include <stdio.h>

int f1 ( int *, int * );
int f2 ( int *, int * );
int f_r ( int ( * ptr ) ( int * , int * ), int first, int sec );

int main ( int argc, char * argv [] ) {

    int a = 5; 
    int b = 17;
    int c = 31;
    int d = 29;

    int rez = 0;

    printf ( "before:\na = %d, b = %d;\nc = %d, d = %d;\n", a, b, c, d );

    if ( a > c ) {
//        rez = f_r ( int ( * ) ( int *, int * ) ( f1 ), a, b );
        rez = f_r ( f1 , a, b );
    }
    else {
//        rez = f_r ( int ( * ) ( int *, int * ) ( f2 ), c, d );
        rez = f_r ( f2 , & c, & d );
    }        
    
    printf ( "rez = %d;\n", rez );
    printf ( "\nafter:\na = %d, b = %d;\nc = %d, d = %d;\n", a, b, c, d );

    return 0;
}


int f_r ( int ( * ptr ) ( int *, int * ), int first, int sec ) {

    int rez = 0;

    rez = ( ( * ptr ) ( & first, & sec ) ); 

    return rez;
}


int f1 ( int * a, int * b ) {

    printf ( "\nin f1:\n" );
    printf ( "* a = %d; * b = %d;\nf1 returns = %d;\n", * a, * b, ( * a + * b ) );

    * a += 1;    
    * b += 3;
 
    return ( ( * a ) + ( * b ) );

}


int f2 ( int * c, int * d ) {

    printf ( "\nin f2:\n" );
    printf ( "c = %d; d = %d;\nf2 returns = %d;\n", & c, & d, ( & c + & d ) );

    * c += 1;
    * d += 3;

    return ( ( * c ) + ( * d ) );

}

