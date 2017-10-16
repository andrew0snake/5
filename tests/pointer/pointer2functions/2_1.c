#include <stdio.h>

void add ( int a, int b ) {

    printf ("Addition is %d;\n", a + b );

}

void substract ( int a, int b ) {

    printf ("Substraction is %d;\n", a - b );

}

void multiply ( int a, int b ) {

    printf ("Multiplication is %d;\n", a * b );

}

int main () {

    void ( * func_ptr_arr [] ) ( int, int ) = { add, substract, multiply };

    unsigned int ch = 0;
    unsigned int a = 15;
    unsigned int b = 20;

    printf ( "Enter please your choice of operation:\n\
    0 - for addition;\n\
    1 - for substraction;\n\
    2 - for multiplication;\n" );

    scanf ( "%d", &ch );

    if ( ch > 2 ) {
        return 0;
    }
    
    func_ptr_arr [ ch ] ( a, b );

}




