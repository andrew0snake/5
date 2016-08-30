#include <stdio.h>

#define SZ 100
#define LIM 10

int getline_my ( char * string );
int atoi_my ( char * string );
void clear_string ( char * string );
char get_answer ( );
char getch ();
void ungetch ( char c );

char buf [ SZ ];
int bufp = 0;


void main () {

    char string1 [ SZ ];
    int rez = 0;
    char choice = 0;
    
    printf ( "\nChoose please what you want to do:\n" );
    printf ( "1. Test getline function.\n" );
    printf ( "2. Test atoi function.\n" );
    printf ( "3. Test itoa function.\n" );
    printf ( "4. Test reverse function.\n" );
    printf ( "5. Test strindex function.\n" );
    printf ( "6. Test getop function.\n" );

    clear_string ( & string1 );
//    choice = get_answer ( );
    rez = getline_my ( & string1 );
    choice = string1 [ 0 ];
    printf ( "Your choice is \"%c\", and whole string = \"%s\"\n", choice, string1 );

    switch ( choice ) {
        case '1':
            rez = getline_my ( & string1 );
            printf ( "rez = %d; and string1 = \"%s\";\n", rez, string1 );
            break;
        case '2':
            printf ( "\nInput please string of digits that you want \nto convert to integer value: " );
            clear_string ( & string1 );
            rez = getline_my ( & string1  );
            printf ( "Getted string:\"%s\";\n", * string1 );
            rez = atoi ( & string1, LIM );
            printf ( "After atoi result = %d;\n", rez );
            break;
        default:
            printf ( "Wrong input.\n" );
    };
}

int getline_my ( char * string ) {

    int i = 0;
    char exit = 0;
    char c = 0;

    c = getch ();
    exit = 0;
    while ( exit == 0 ) {
       if ( c == EOF ) {
            exit = 1;
            * string ++;
            * string = '\0';
        }
        else {
            * string ++ = c;
            c = getch ();
            i++;
        };
    };
   
    return i; 

}

int atoi_my ( char * string ) {

    int i = 0;
    int sum = 0;    

    printf ( "\n----func_atoi_my---\n" );
    
    while ( i < LIM - 1 && * string != -1 ) {
        printf ( "In step %d sum = %8d; * string = \"%c\" in char, %d as digital and %p as pointer;\n", i, sum, * string, * string, & * string );
        sum = sum * 10 + ( * string - '0' );
        * string ++;
        i++;
    }; 

    printf ( "After cycle sum = %d;\n", sum );

    printf ( "----end_of_func_atoi_my---\n" );

    return sum;
}

void clear_string ( char * string ) {

    int i = 0;
 
    while ( i < SZ - 1 ) {
        * string ++ = 0;
        i ++;
    };
}

char get_answer ( ) {

    int i = 0;
    char exit = 0;
    char symb = 0;

    while ( ( symb = getch () ) == '\t' && symb == ' ' && symb == '\n' )
        ;

    while ( exit == 0 ) {
        if ( ( symb >= '0' && symb <= '9' ) || symb == - 1 ) {
            exit = 1;
        }
        else {
            printf ( "Wrong input (for exit press Ctrl+D). Try again.\n" );
            symb = getchar ();
        }
    };

    if ( symb == - 1 ) {
        return 'e';
    } 
    else {
        return symb;
    };
 
}

char getch () {

    char c = 0;
    int i = 0;


    if ( bufp > 0 ) {
        return ( buf [ bufp -- ] );
    }
    else {
        return getchar ();
    }


}

void ungetch ( char symb ) {

    if ( bufp >= SZ ) {
        printf ( "ungetch:too much symbols.\n" );
    }
    else {
        buf [ bufp ++ ] = symb;
    };

}



