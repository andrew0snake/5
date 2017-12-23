#include <stdio.h>
#include <stdlib.h>

int compare ( const void * a, const void * b ) {

    return ( * ( int * ) a - * ( int * ) b );

}


int main () {

    int i = 0;
    int arr [] = { 10, 5, 15, 12, 90, 80 };
    int array_size_in_bytes= sizeof ( arr );
    int size_of_first_element_in_bytes= sizeof ( arr [ 0 ] );
    int amount_of_array_elements= sizeof ( arr ) / sizeof ( arr [ 0 ] );
    int n = amount_of_array_elements;


    for ( i = 0; i < amount_of_array_elements; i ++ ) {
        printf ( "arr [ %d ] = %d;\n", i, arr [ i ] );
    }

    printf ( "\narray_size_in_bytes = %d;\n\n", array_size_in_bytes);
    printf ( "size_of_first_element_in_bytes = %d;\n\n", size_of_first_element_in_bytes);
    printf ( "amount_of_array_elements = %d;\n\n", amount_of_array_elements);

    qsort ( arr, n, sizeof ( int ), compare );
    
    for ( i = 0; i < amount_of_array_elements; i ++ ) {
        printf ( "arr [ %d ] = %2d;\n", i, arr [ i ] );
    }

    return 0;
}



