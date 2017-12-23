#include <stdio.h>

#define MAX 10

int f1 ( int * );
int f2 ( int ( * f_p ) (), int * var );

int main () {

    int var1 = 5;
    int rez = 0;
   
    printf ( "\n\nin main before f1 \naddress of var1 = %p;\n", & var1 ); 
    rez = f1 ( & var1 );
    
    printf ( "int main after f1 rez = %d;\n\n\n", rez );

    rez = f2 ( f1, var1 );

    return 0;

}


int f2 ( int ( * f_p ) (), int * var2 ) {
    
    int rez = 0;

    printf ( "in f2 var2 = %d;\n", var2 ); 

    rez = f_p ( & var2 );

    printf ( "int f2 after f_p rez = %d;\n", rez );

    return 0;

}


int f1 ( int * val1 ) {

//    int rez = 0;
    printf ( "\nin f1:\n" );
    printf ( "* val1 = %d;\n", * val1 );
    printf ( "address of val1 = %p;\n", val1 );
//    rez = 
    
    return * val1;

}


