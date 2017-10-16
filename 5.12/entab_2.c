#include <stdio.h>

#define MAX 30
#define TABSIZE 4

char isnumber ( char * string );
int getline_my  ( char * line );
void detab ( char * detabbed_line, char * source_line );
void full_tabstops ( char * array, int argc, char * argv [], int tab_stop, int start_pos );    
int tabpos ( int pos, char * line );
void entab ( char * entabbed_line, char * source_line, int argc );
void print_line ( char * line );
int atoi_my ( char * line );

char tabline [ MAX ];


int main ( int argc, char * argv [] ) {

    int i = 0;
    char rez = 0;
    char check = 0;
    char tab_stop = 0;
    int start_pos = 0;    
    char tmp_line [ MAX ];
    char dest_line [ MAX ];

    if ( argc == 1 ) {
        printf ( "Usage: entab -m -n ...  ( which means set tab stops every n columns, starting from m position )\n" );        
    }

    while ( argc > 1 && check == 0 ) {
        * argv ++;
        if ( * * argv == '-' ) {
            printf ( "* ( ++ * argv ) = '%c';\n", * ( ++ * argv ) );
            start_pos = atoi_my ( * argv );
            printf ( "start_pos = %d;\n", start_pos );
        }
        else {
            printf ( "* argv = '%s';\n", * argv );
            printf ( "Wrong input. Exiting.\n" );
            check = 1;
        }

        if ( check == 0 ) {
            * argv ++;
            if ( * * argv == '-' ) {
                printf ( "* ( ++ * argv ) = '%c'; \n", * ( ++ * argv ) );
                tab_stop = atoi_my ( * argv );
                printf ( "tab_stop = %d;\n", tab_stop );
            }
            else {
                printf ( "* argv = '%s';\n", * argv );
                printf ( "Wrong input. Exiting.\n" );
                check = 1;
            }
        }
        argc --;
        argc --;
        printf ( "argc = %d;\n", argc );    
    }

    printf ( "step 2;\n" );

    if ( check == 1 ) {
        return 0;
    }

    full_tabstops ( tabline, argc, argv, tab_stop, start_pos );
    
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

void full_tabstops ( char * tabline, int argc, char * argv [], int tab_stop, int start_pos ) {

    int len = 0;
    int i = 0;
    int col_num = 0;

    for ( i = 0; i < MAX; i++ ) {
        tabline [ i ] = 0;
    }

    tabline [ i ++ ] = '\0';

    if ( tab_stop == 0 ) {
        for ( i = 0; i < MAX; i ++ ) {
            tabline [ i + start_pos ] = ( i % TABSIZE == 0 );
            printf ( "tabline [ %d ] = '%d';\n", i, tabline [ i ] );        
        }
    }
    else {
        for ( i = 0; i < MAX; i ++ ) {
            tabline [ i + start_pos ] = ( i % tab_stop == 0 );
            printf ( "tabline [ %d ] = '%d';\n", i, tabline [ i ] );        
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


int atoi_my ( char * line ) {

    int i = 0;

    while ( * line != '\0' && * line != '\n' ) {
        if ( * line == '-' ) {
            ;
        }
        else {
            printf ( "* line = '%c' and %d;i = %d;\n", * line, * line, i );
            i = * line - '0' + i * 10;
            printf ( "i = %d;\n", i );
        }
        * line ++;
    }

    return i;
}
