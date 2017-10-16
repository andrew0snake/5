#include <stdio.h>

char arr [ 2 ] [ 5 ] = {
    { 1, 2, 3, 4, 5 },
    { 2, 4, 6, 8, 10 }
};

void f1 ( char * arr, char str, char pos );

int main () {

    char i = 0;
    char j = 0;
    char str = 0;
    char pos = 0;
    
    for ( i = 0; i < 2; i++ ) {
        printf ( "\nstring i = %d;\n", i );
        for ( j = 0; j < 5; j++ ) {
            printf ( "arr [ i = %d ] [ j = %d ] = %d;\n", i, j, arr [ i ] [ j ] );    
        };
        printf ( "\n" );
    }

/*    for ( i = 0; i < 10; i++ ) {
        printf ( "* arr = %d;\n",  * arr );
        * arr ++;
    };
*/

    str = 1;
    pos = 3;

    f1 ( & arr, str, pos );

    return 1;

}

void f1 ( char * arr, char str, char pos ) {

    int i = 0;
    char count = 0;
    int sum = 0;

    printf ( "str = %d; pos = %d;\n", str, pos );
    
    while ( i < pos ) {
        if ( count < str * 5 ) {
            printf ( "count = %d; * arr = %d;\n", count, * arr );
            count ++;
            * arr ++;
        }
        else {
            sum = sum + * arr;
            * arr ++;
            i ++; 
        };
    };

    printf ( "sum = %d;\n", sum );
 
}
