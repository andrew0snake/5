#include <stdio.h>

#define LEN 10
#define RLEN 100

//void sort_bubble ( int * arr );
void sort_bubble ( int arr [ LEN ] );
int gen_rand ( unsigned short int size );

char endurance_size = 0;

int main () {

    int i = 0;
    int arr_0 [ LEN ];

    endurance_size = 3;

    printf ( "\nExample of selection sort_bubble algoritm.\n\n" );
    printf ( "Here is array, fulled randomly:\n\n" );
    
    for ( i = 0; i < LEN; i ++ ) {
//        arr_0 [ i ] = rand () % 101;
        arr_0 [ i ] = gen_rand ( RLEN );
        printf ( "arr_0 [ %d ] = %d;\n", i, arr_0 [ i ] );
    }

    printf ( "\n\nAnd here is sorting function working:\n\n");

    sort_bubble ( arr_0 );
    printf ( "\n\nAfter sorting function array seems so:\n\n");

    for ( i = 0; i < LEN; i ++ ) {
        printf ( "arr_0 [ %d ] = %d;\n", i, arr_0 [ i ] );
    }

    printf ( "\nThe end:)\n\n" );
    
    return 0;
}

//void sort_bubble ( int * arr ) {
void sort_bubble ( int arr [ LEN ] ) {

    int i = 0;
    int j = 0;
    int min = 0;
    int temp = 0;
    char exit = 0;

    for ( i = 0; i < LEN - 1; i ++ ) {
        for ( j = i + 1; j < LEN ; j ++ ) {
            if ( arr [ i ] > arr [ j ] ) {
                temp = arr [ j ];
                arr [ j ] = arr [ i ];
                arr [ i ] = temp;
            }
        }
    }

    for ( i = 0; i < LEN; i ++ ) {
        printf ( "arr_0 [ %d ] = %d;\n", i, arr [ i ] );
    }
}


int gen_rand ( unsigned short int size ) {

    unsigned int randval = 0;
    unsigned int devider = 0;
    FILE *f;
//for bsd uncomment this string 
//    f = fopen ( "/dev/random", "r" );

//for linux using urandom
    f = fopen ( "/dev/urandom", "r" );
    fread ( &randval, sizeof ( randval ), 1, f );
    fclose ( f );
 
    if ( endurance_size == 1 ) {
        devider = 11;
    }
    else {
        if ( endurance_size == 2 ) {
            devider = 3;
        }
        else {
            if ( endurance_size == 3 ) {
                devider = 7;
            }
        }
    };

    if ( ( randval % 2 ) == 0 ) {
        devider = 111;
    };
    

    while ( randval > size ) {
        randval /= devider;
    };

    return randval;
}

