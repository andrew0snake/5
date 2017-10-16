#include <stdio.h>
#include <string.h>

#define MAXL 10
#define LEN 100 
#define MAXLINES 1000
#define ALLOCSIZE 10000 

char allocbuf [ ALLOCSIZE ];                                                                                                                                                
int alloc ( int n );
void afree ( char * p );
int getline_my ( char * line );
void tail_my ( int output_count );
void strcpy_my ( char * dest, char * source );    
void sorting ();

int output_count = 0;
short int line_count = 0;
char * allocp = allocbuf;                                                                                                                                                 
char * lineptr [ MAXLINES ];
short int line_pos = 0;

int main ( int argc, char * argv [] ) {

    int i = 0;

    if ( argc > 2 ) {
        printf ( "usage: tail -n ( where n - number of strings, which will be printed from the end of file )\n" );
        printf ( "or just simple tail with default n = 10.\n" );
    }
    else {
        if ( argc == 1 ) {
            output_count = 10;
        }
        else {
            * ++ argv;
            output_count = - atoi ( * argv );
        }

        tail_my ( output_count );

        printf ( "\n\nafter tail lineptr:\n" );

        for ( i = 0; i < output_count; i ++ ) {
            printf ( "* ( lineptr +%3d ) = '%s'; and %p;\n", i, * ( lineptr + i ), * ( lineptr + i ) );
        }
    };
 
    printf ( "line_pos = %d;\n", line_pos );   

    if ( line_pos > 0 ) {
        sorting ();
        printf ( "\n\nafter sorting lineptr:\n" );
        
        if ( line_count < output_count ) {
            printf ( "line_count = %d;\n", line_count );
            for ( i = 0; i < line_count; i ++ ) {
                printf ( "* ( lineptr +%3d ) = '%s';\n", output_count - line_count + i, * ( lineptr + ( output_count - line_count + i ) ) );
            }
        }
        else {
            for ( i = 0; i < output_count; i ++ ) {
                printf ( "* ( lineptr +%3d ) = '%s';\n", i, * ( lineptr + i ) );
            }
        }
    }

    printf ( "final.\n" );

    return 0;
}

void tail_my ( int output_count ) {

    int i = 0;
    int len = 0;
    int * cur_p = NULL; 
    char line [ LEN ];
   
    
    while ( ( len = getline_my ( line ) ) > 0 ) {
        cur_p = alloc ( len );
        strcpy_my ( cur_p, line );
        lineptr [ i ] = cur_p;
        i ++;           
        line_count ++;
        if ( i >= output_count ) {
            i = 0;
        }
    }

    line_pos = i;

}



int getline_my ( char * line ) {

    int i = 0;
    char c = 0;


    while ( ( c = getchar () ) != '\0' && c != '\n' && c != EOF ) {
        * ( line + i ) = c;
        i++;
    }

    if ( c == '\n' ) {
        * ( line + i ) = '\0';
        i ++; ;
    }

     if ( c == EOF ) {
        return 0;
    }
   
    return i;
}


void strcpy_my ( char * dest, char * source ) {

    int i = 0;
    
    while ( * ( source + i ) != '\0' ) {
        * ( dest + i ) = * ( source + i );
        i ++;
    }

}

int alloc ( int n ) {

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
    }
}

void sorting () {

    char * line_tmp;
    int i = 0;

    while ( line_pos > 0 ) {

        line_tmp = lineptr [ 0 ]; 

        for ( i = 0; i < output_count - 1; i ++ ) { 
            * ( lineptr + i ) = * ( lineptr + i + 1 );
        }         

        lineptr [ i ] = line_tmp;
        line_pos --;        
    }

}


