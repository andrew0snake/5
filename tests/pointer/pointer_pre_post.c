#include <stdio.h>

void print_string ( char * string1 );

void main () {
 
    char string1 [ 100 ] = "123qweasd";
 
    printf ( "string before:%s;\n", string1 );

    print_string ( & string1 );

    printf ( "string after:%s;\n", string1 );
}

void print_string ( char * string1 ) {

    int i = 0;

    while ( * string1 != '\0' ) {
        printf ( "at step %4d * string1 = \"%c\" in char; %d in digital and %p as pointer;\n", i, * string1, * string1, * string1 );
        * ++ string1  ;
        i ++;
    }

}


