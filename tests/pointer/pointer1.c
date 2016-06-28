#include <stdio.h>
#include <ctype.h>

void swap_my ( int *a, int *b );

void main () {

    int a = 5;
    int b = 6;
    int z = 2;
    int *c;   
    int *d;

/*    c = &b;
    printf ( "c = &b and = %d;\n", *c );  

    a = *c;
    printf ( "a = *c and = %d;\n", a );  

    *c = 0;
    printf ( "*c = 0 and = %d;\n", *c );  
    printf ( "b =  %d;\n", b );  

    c=&z;
    printf ( "c = &z and = %d;\n", *c );

    printf ( "-------------------\n" );

    *c = *c + 10;
    printf ( "*c = *c + 10; *c = %d\n", *c );

    a = *c + 1;
    printf ( "a = *c + 1; a = %d;\n", a );

    ++*c;
    printf ( "++*c = %d; c = %u;\n", ++*c, c );

    *c++;
    printf ( "*c++ = %d; c = %u; \n", *c, c );

    *c--;
    printf ( "*c-- = %d; c = %u; \n", *c, c );

    d = c;
    printf ( "*d = %d; d = %u;\n", *d, d );
*/
    c = &a;
    d = &b;
    printf ( "before swap c = %d, and d = %d;\n", *c, *d );
    printf ( "before swap a = %d, and b = %d;\n\n", a, b );
    swap_my ( &a, &b );
    printf ( "after swap c = %d, and d = %d;\n", *c, *d );
    printf ( "after swap a = %d, and b = %d;\n\n", a, b );

}

void swap_my ( int *first, int * second ) {

    int temp = 0;
    temp = *first;
    *first = *second;
    *second = temp;

}
