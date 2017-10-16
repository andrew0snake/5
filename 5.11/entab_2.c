#include <stdio.h>

#define MAX 30
#define TABSIZE 4

char isnumber ( char * string );
int getline_my  ( char * line );
void detab ( char * detabbed_line, char * source_line );
void full_tabstops ( char * array, int argc, char * argv [] );    
int tabpos ( int pos, char * line );
void entab ( char * entabbed_line, char * source_line, int argc );
void print_line ( char * line );

char tabline [ MAX ];


int main ( int argc, char * argv [] ) {

    int i = 0;
    char rez = 0;
    char tmp_line [ MAX ];
//    char tabline [ MAX ];
    char dest_line [ MAX ];

    if ( argc == 1 ) {
        printf ( "Usage: entab 0 4 8 12 16 ...  ( wheres every digit is position of tab stop )\n" );        
    }

    full_tabstops ( tabline, argc, argv );
    
    for ( i = 0; i < MAX; i ++ ) {
        printf ( "getted tabstops [ %d ]:'%d';\n", i, tabline [ i ] );
    }
    while ( ( rez = getline_my ( tmp_line ) ) != 0 ) {
        entab ( dest_line, tmp_line, argc );
        printf ( "entabbed_line = '%s';\n", dest_line );
        for ( i = 0; dest_line [ i ] != '\0'; i ++ ) {
            printf ( "dest_line [ %d ] = '%c' as char and %d as digit;\n", i, dest_line [ i ], dest_line [ i ] );
        }
    }

    return 0;
}

void entab ( char * en_line, char * s_line, int argc ) {

    int i = 0;
    int j = 0;
    char pos = 0;
    char space = 0;
    char size = 0;
    char check = 0;
    char start = 0;

    print_line ( s_line );

    while ( s_line [ i ] != '\0' ) {
        if ( s_line [ i ] == ' ' ) {
            pos = i;
            space = start;
            check = 0;
            while ( space < MAX && ! tabpos ( ++ space, tabline ) ) {
                if ( s_line [ ++ pos ] == ' ' ) {
                    check = 0;
                    printf ( "pos = %d;\n", pos );
                }
                else {
                    check = 1;
                }
            } 
            if ( check == 0 ) {
                en_line [ j ++ ] = '\t';
                i = pos + 1;
                start = space;
                printf ( "in check after cycle i = %d;\n", i );
            }
            else {
                en_line [ j ++ ] = s_line [ i ++ ]; 
                space = start;
            }
        }    
        else {
            en_line [ j ++ ] = s_line [ i ++ ];
            printf ( "s_line [ %d ] = '%c' and %d;\n", i - 1, s_line [ i - 1 ], s_line [ i - 1 ] );
        }
    }

}

void detab ( char * detabbed_line, char * source_line ) {

    int pos = 0;

    while ( * source_line != EOF ) {
        if ( * source_line == '\t' ) {
            do {
                * detabbed_line = ' ';
                printf ( "putted detabbed_line = '%c', pos = %d;\n", * detabbed_line, pos );
                * detabbed_line ++;
                pos ++;
            } while ( ( ! tabpos ( pos, tabline ) ) && pos < MAX );  
//            pos ++;
            * source_line ++;
            printf ( "step up;\n" );
        }
        else {
            * detabbed_line ++ = * source_line ++ ;
        }            
    }

}

int tabpos ( int pos, char * line ) {

    if ( pos < MAX ) {
        return tabline [ pos ];
    }
    else {
        return 0;
    }

}

void full_tabstops ( char * tabline, int argc, char * argv [] ) {

    int len = 0;
    int i = 0;
    int col_num = 0;

    for ( i = 0; i < MAX; i++ ) {
        tabline [ i ] = 0;
    }

    tabline [ i ++ ] = '\0';

    if ( argc == 1 ) {
        for ( i = 0; i < MAX; i ++ ) {
            tabline [ i ] = ( i % TABSIZE == 0 );
//            printf ( "tabline [ %d ] = '%d';\n", i, tabline [ i ] );        
        }
    }
    else {
        while ( -- argc > 0 ) {
            col_num = atoi ( * ++ argv );
            tabline [ col_num ] = 1;
        }
    }

}

char isnumber ( char * string ) {

    int i = 0;
    int digit = 0;
    char check = 0;

    while ( string [ i ] != '\0' && check == 0 ) {
        if ( isdigit ( string [ i ] ) != 0 ) {
            check = 0;
            digit = string [ i ] - '0' + digit * 10;
        }
        else { 
            check = 1;
            return 0;
        }
        i ++;
    }

    return 1;
}

int getline_my ( char * line ) {

    char c = 0;
    int i = 0;

    while ( ( c = getchar () ) != '\0' && c != EOF && c != '\n' ) {
        * line ++ = c;
        i ++;
    }

    if ( c == '\n' ) {
        * line  = '\0';
        return i;
    }
    else {
        if ( c == EOF )
            * line = '\0'; 
            return i;
    }

    return i;
}

void print_line ( char * line ) {

    int i = 0;

    while ( line [ i ] != '\0' ) {
        printf ( "line [ %d ] = '%c' and %d;\n", i, line [ i ], line [ i ] );
        i ++;
    }


}
