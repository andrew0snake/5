#include <stdio.h>

#define MAX 100

char isnumber ( char * string );
char getline_my  ( char * line );
void entab ( int offset_size, char * line );
void detab ( int offset_size, char * line );    

int main ( int argc, char * argv [] ) {

    int i = 0;
    int offset_size = 0;
    char exit = 1;
    char rez = 0;
    char tmp_line [ MAX ];

    if ( argc == 1 ) {
        offset_size = 4;
        exit = 0;
    }
    else {
        if ( argc != 3 ) {
            printf ( "Usage: detab -n x (wheres x - count of blanks to replace tabs)\n" );
        }
        else {
            * argv ++;
            if ( strcmp ( * argv, "-n") == 0 ) {
                * argv ++;
                if ( isnumber ( * argv ) == 1 ) {
                    offset_size = atoi ( * argv );
                    exit = 0;
                    printf ( "in rezult getted offset_size of tab replacing is: %d.\n", offset_size );
                }
                else {
                    printf ( "Entered argument is not number.\n" );
                }
            }
            else {
                printf ( "Wrong argument name. Needs -n instead %s.\n", * argv );
            }
        }
    }

    while ( exit != 1 ) {
        if ( ( rez = getline_my ( tmp_line ) ) == 0 ) {
            printf ( "getted line   = '%s';\n", tmp_line );
            detab ( offset_size, tmp_line );
            printf ( "detabbed line = '%s';\n", tmp_line );
            for ( i = 0; tmp_line [ i ] != '\0'; i++ ){
                printf ( "tmp_line [ %d ] = '%c' as char and %d as digit.\n", i, tmp_line [ i ], tmp_line [ i ] );
            }
        }
        else {
            exit = 1;
        }
    }

    return 0;
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

char getline_my ( char * line ) {

    char c = 0;
    int i = 0;
    char * p;

    while ( ( c = getchar () ) != '\0' && c != EOF && c != '\n' ) {
        * line ++ = c;
        i ++;
    }

    if ( c == '\n' ) {
        * line  = '\0';
    }
    else {
        if ( c == EOF )
            * line = '\0'; 
            return 1;
    }

    p = line;


    return 0;
}

void entab ( int offset_size, char * line ) {
    
    int count = 0;
    int offset = 0;
    int i = 0;


    while ( * line != '\0' && * line != '\n' ) {
        if ( * line == ' ' ) {
            count ++;
            if ( count == offset_size ) {
                * ( line - offset_size + 1 ) = '\t';
                * line ++;
                while ( * line != '\0' ) {
                    * ( line - offset_size + 1 ) = * line;
                    * line ++;
                    offset ++;
                }
                *  ( line - offset_size + 1 ) = '\0';
                offset += offset_size;
                while ( offset > 0 ) {
                    * line --;
                    offset --;    
                }
                count = 0;
            }
        }
        else {
            count = 0;
        }
        * line ++; 
    }

}

void detab ( int offset_size, char * line ) {
    
    int count = 0;
    int offset = 0;
    int i = 0;


    while ( * line != '\0' ) {
//        printf ( "before check * line = '%c' and %d;\n", * line, * line );
        if ( * line == '\t' ) {
            * line = ' ';
            * line ++;
            while ( * line != '\0' ) {
                count ++;
                * line ++;
            }
//            printf ( "after first while count = %d;\n", count );
            * ( line + offset_size - 1 ) = '\0';
            * line --;
            for ( i = 0; i < count; i ++ ) {
                * ( line + offset_size - 1 ) = * line --;
            }
//            printf ( "point = '%c' and %d;* ( line - 1 ) = '%c' and %d;\n", * line, * line, * ( line - 1 ), * ( line - 1 ) );
            for ( i = 0; i < ( offset_size ); i ++ ) {
                * line ++ = ' ';
            }
            count = 0;
        }
        else {
            * line ++;
        }
    }

}
