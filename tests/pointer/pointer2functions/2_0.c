#include <stdio.h> 


void func ( int a ) {

    printf ( "Value of a is %d;\n", a );

}

int main ( int argc, char * argv [] ) {

    void ( * func_ptr ) ( int ) = func;

    func_ptr ( 10 );

    return 0;
}


