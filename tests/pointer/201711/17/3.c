#include <stdio.h>



int main ( int argc, char * argv [] ) {

    char arr1 [] = "123";
    char arr2 [] = "qwe";
    char arr3 [] = "asd";

    int i = 0;

    char * arr [ 3 ] = { arr1, arr2, arr3 };

    for ( i = 0; i < 3; i ++ ) {
        printf ( "* arr [ %d ] = %s;\n", i,  arr [ i ] );
            
    }   

    return 0;

}
