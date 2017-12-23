#include <stdio.h>

int f1 ( int * a );
//int f2 ( int ( * f_p ) ( int * ), int *, int * );
int f2 ( int ( * f_p ) (), int *, int * );


int main () {

    int a = 5;
    int b = 13;
    
    int rez = 0;

    rez = f2 ( f1, & a, & b );
    printf ( "rez = %d;\n\n", rez );

    return 0;

}

int f1 ( int * one ) {

    int tmp = * one;
    int rez = 0;

    printf ( "For the even smalles sence of existing of this function i have to make any operations inside it.\n" );
    printf ( "And now f1 powers getted value %d. tmp = %d;\n", * one, tmp );

//    rez = ( * one ) * ( * one );
    rez = tmp * tmp;
    
    return rez;        

}

int f2 ( int ( * f_p ) (), int * one, int * two ) {

    int rez = 0;
    rez = f_p ( one );

//    printf ( "And the f2 powers getted from f1 value = %d on second value = %d;\n", rez, * two );

    rez = rez * ( * two );

    return ( rez );

}
