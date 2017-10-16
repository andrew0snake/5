#include <stdio.h>

int main ( int argc, char * argv [] ) {

    char * arr1 [ 10 ];
    int a = 0;
    
    a = argc;
    * argv ++;

    while ( a -- ) {
        printf ( " * argv = %s;\n", * argv );
        * argv ++;
    }

//    a = argc;
//    while ( a -- ) {
//        * argv --;
//    }
    argv -= argc;

    a = argc;

    while ( a -- > 1 ) {
        printf ( "* * argv = %c;\n", * * argv );
        * argv ++;
    }

}
