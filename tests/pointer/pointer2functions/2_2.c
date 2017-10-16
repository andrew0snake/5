#include <stdio.h>

void fun_1 () {

    printf ( "Fun_1;\n" );

}

void fun_2 () {

    printf ( "Fun_2;\n" );

}

void wrapper ( void ( * fun ) () ) {

    fun ();

} 


int main () {

    printf ( "\n\n" );
    
    wrapper ( fun_1 );
    wrapper ( fun_2 );

    printf ( "\n\n" );

    return 0;
}



