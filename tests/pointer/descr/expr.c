#include <stdio.h>

#define MAXNUM 100

char test_pointer ( char * s  );
void test_pointer_2 ( char * s [ MAXNUM ] );
char isdigit_my ( char * s );

int main (int argc, char * argv [] ) {

    int i = 0;
    char rez = 0;
    char * ptr_1 [ 100 ];
    char * ptr_2;

/*    while ( argc -- > 0 ) {
        if ( * argv )
    }
*/
    * ptr_1 = * argv;
    * ptr_2 = * * argv ;
    printf ( "in main ptr_1 = %p, * ptr_1 = '%s' as string.\n", ptr_1, * ptr_1 );
    printf ( "in main ptr_2 = %p, * ptr_2 = '%c' as char.\n", ptr_2, * ptr_2 );
    rez = test_pointer ( & ptr_2 );
    test_pointer_2 ( & ptr_1 );

    printf ( "1234\n" );

    return 0;
}

char test_pointer ( char * str ) {

    int c = 0;
   
    printf ( "1\n" ); 
    c = * str;
    printf ( "in test_pointer c = %c; and * str = %c;\n", c, * str );
    printf ( "2\n" ); 

    return c;

}

void test_pointer_2 ( char * symb [ MAXNUM ] ) {

    int c = 0;
   
    printf ( "1\n" ); 
    c = * * symb;
    printf ( "in test_pointer_2 c = %c; and * * symb = '%c' as char; and * symb = '%s' as string\n", c, * * symb, * symb );
    printf ( "2;\n" ); 

}




