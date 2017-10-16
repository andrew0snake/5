#include <stdio.h>

#define ALLOCSIZE 10000

char allocbuf [ ALLOCSIZE ];
char * allocp = allocbuf;

char alloc ( int n );
void afree ( char * p );


void main () {




}

char alloc ( int n ) {

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


