#include <stdio.h>

#define MAX 100
#define MAXL 20
#define ALLOCSIZE 10000

char * line_ptr [ MAXL ];
char allocbuf [ ALLOCSIZE ];
char * allocp = allocbuf;

char * alloc ( int n );
void afree ( char * p );


int getline_my ( char * line, int len );
int readlines ( char * lines_ptr [ MAX ], int count );
void clear_line ( char * line );
char * put_line ( char * line, int len );

int main () {

    int i = 0;
    int rez = 0;
    char line [ MAX ];
    char * ptr;

    clear_line ( line );

    for ( i = 0; i < 5; i ++ ) {
        printf ( "Input, please %d-th string:", i );
        rez = getline_my ( line, MAX );
        if ( rez > 0 ) {
            line_ptr [ i ] = put_line ( line, rez );
        }
    }
    
    for ( i = 0; i < 5; i ++ ) {
        printf ( "line_ptr [ %d ] = %p; and same string = '%s';\n", i, line_ptr [ i ], line_ptr [ i ] );
    }

    return 0;

}

char * put_line ( char * line, int len ) {

    int i = 0;
    char * ptr_0;

    if ( len < MAX ) {
        ptr_0 = alloc ( len );
        while ( * ( ptr_0 + i ) = * ( line + i ) )
            i ++;
    }   
    
    return ptr_0;

}

char * alloc ( int n ) {

    if ( allocbuf + ALLOCSIZE - allocp >= n ) {
        allocp += n;
        return ( allocp - n );
    } 
    else {
        return 0;
    };
}

void afree ( char * p ) {
 
    if ( p >= allocbuf && p < allocbuf + ALLOCSIZE ) {
        allocp = p;
    };
}


void clear_line ( char * line ) {

    int i = 0;

    for ( i = 0; i < MAX; i ++ ) {
        * line ++ = 0; 
    }

}

int getline_my ( char * line, int len) {

    char c = 0;
    int i = 0;

    while ( ( c = getchar () ) != EOF && c != '\n' ) { 
        * line ++ = c;
        if ( i >= len ) {
            return - 1;
        }
        i ++;
    }

    if ( i == 0 && c == EOF ) {
//        printf ( "c = %c; and i = %d;\n", c, i );
        return - 1;
    }         
    
    if ( c == '\n' ) {
        i ++;
    }  

    * line ++ = '\0'; 
    i ++;
 
    return i;
 
}
