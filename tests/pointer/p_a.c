#include <stdio.h>
#include <string.h>

#define MXL 200
#define SZ 100
#define LIM 50
#define ALLOCSIZE 10000

char * arr [ SZ ];
static char allocbuf [ ALLOCSIZE ];
static char * allocp = allocbuf;

int readlines ( char * arr1 [], int amount );
int getline_my ( char * string );
int atoi_my ( char * string );
char * alloc_my ( int n );

void main () {

    int i = 0;
    int rez = 0;
    int amount = 0;
    char string [ SZ ];

    printf ( "Input please amount of strings:" );
    rez = getline_my ( & string );
    printf ( "rez = %d;\n", rez );
    if ( rez > 0 ) {
        amount = atoi_my ( & string );
        printf ( "Amount of strings:%d.\n", amount );
        rez = readlines ( arr, amount );
        for ( i = 0; i < amount; i++ ) {
            printf ( "%3d - th string, that you inputed,  is:%s;\n", * arr [ i ] );
        };
    }
    else {
        printf ( "String, that you inputed, was too short ( lenght = 0 ).\n" );
    }

}

char * alloc_my ( int n ) {

    if ( allocbuf + ALLOCSIZE - allocp > n ) {
        allocp += n;
        return allocp - n;
    }
    else {
        return 0;
    }

}

void afree ( char * p ) {

    if ( p > allocbuf && p < allocbuf + ALLOCSIZE ) {
        allocp = p;
    }

}

int getline_my ( char * line ) {

    int i = 0;

    char c = 0;

    while ( ( c = getchar () ) != EOF && c != '\n' ) {
        * line ++ = c;
        i++;
    };
    * line = '\0';

    return i;
}

int readlines ( char * arr [ SZ ], int amount ) {

    int i = 0;
    int len = 0;
    char c = 0;
    char * p;
    char line [ SZ ];

    while ( i < amount && ( len = getline_my ( line ) > 0 ) ) {
        line [ len - 1 ] = '\0'; 
        strcpy ( p, line );
        arr [ i ++ ] = p;
    };

    return i;

}



int atoi_my ( char * string ) {

    int i = 0;
    int sum = 0;    

    printf ( "\n----func_atoi_my---\n" );
    
    while ( i < SZ - 1 && * string != '\0' ) {
        printf ( "In step %d sum = %8d; * string = \"%c\" in char, %d as digital and %p as pointer;\n", i, sum, * string, * string, & * string );
        sum = sum * 10 + ( * string - '0' );
        * string ++;
        i++;
        printf ( "In step %d sum = %8d; * string = \"%c\" in char, %d as digital and %p as pointer;\n\n", i, sum, * string, * string, & * string );
    }; 

    printf ( "After cycle sum = %d;\n", sum );

    printf ( "----end_of_func_atoi_my---\n" );

    return sum;
}

