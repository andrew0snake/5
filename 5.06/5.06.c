#include <stdio.h>

#define SZ 100
#define LIM 10

int getline_my ( char * string );
int atoi_my ( char * string );
void clear_string ( char * string );
char get_answer ( );
char getch ();
void ungetch ( char c );
short int check_string_at_digits ( char * string );
void itoa_my ( char * string, int digit );
void print_variants (); 
void reverse_my ( char * source, char * rev );
short int strindex_my ( char * s1, char * s2, int len1, int len2 );
int strlen_my ( char * string );
short int getop_my ( char * string );

char buf [ SZ ];
int bufp = 0;


void main () {

    char string1 [ SZ ];
    char string2 [ SZ ];
    int rez = 0;
    int len1 = 0;
    int len2 = 0;
    int digit = 0;
    char choice = 0;
    short int exit = 0;
    
    print_variants ();
    while ( exit == 0) {
        clear_string ( & string1 );
        rez = getline_my ( & string1 );
        choice = string1 [ 0 ];

         switch ( choice ) {
             case '1':
                 rez = getline_my ( & string1 );
                 printf ( "rez = %d; and string1 = \"%s\";\n", rez, string1 );
                 break;
             case '2':
                 printf ( "\nInput please string of digits that you want \nto convert to integer value: " );
                 clear_string ( & string1 );
                 rez = getline_my ( & string1  );
                 printf ( "--\n-" );
                 printf ( "Getted string:\"%s\";\n", string1 );
                 rez = check_string_at_digits ( & string1 );
                 if ( rez == 0 ) {
                     rez = atoi ( & string1, LIM );
                     printf ( "After atoi result = %d;\n", rez );
                     printf ( "So, what do you want to do now? Enter your choise (1-6,r,q):" );
                 }
                 else {
                     printf ( "String, that you inputed, is not only digital. You may try again.\n" );
                 }
                 break;
             case '3':
                 printf ( "Input please digital value, that you want to convert to character array:" );
                 clear_string ( & string1 );
                 digit = getline_my ( & string1 );
                 rez = check_string_at_digits ( & string1 );
                 if ( rez == 0 ) {
                     itoa_my ( & string1, digit ); 
                     printf ( "After converting string with your inputed digit =\"%s\";\n", string1 );
                 }
                 else {
                     printf ( "Number, that you inputed, is not only digital. You may try again.\n" );
                 }
                 break;
             case '4':
                 clear_string ( & string1 );
                 clear_string ( & string2 );
                 printf ( "Input please string to reverse:" );
                 getline_my ( & string1 );
                 reverse_my ( & string1, & string2 );
                 printf ( "After reverse string =\"%s\";\n", string2 );
                 break;
             case '5':
                 clear_string ( & string1 );
                 clear_string ( & string2 );
                 printf ( "Input please first string, where search would be:" );
                 getline_my ( & string1 );
                 printf ( "Input please second string, which would be searching:" );
                 getline_my ( & string2 );

                 len1 = 0;
                 len2 = 0;
                 len1 = strlen_my ( & string1 );

                 printf ( "Lenght of string_where = %d;\n", len1 );

                 len2 = strlen_my ( & string2 );

                 printf ( "Lenght of string_what = %d;\n", len2 );

                 rez = strindex_my ( & string1, & string2, len1, len2 );
                 if ( rez == -1 ) {
                     printf ( "There is no second string = \"%s\" in first string = \"%s\";\n", string1, string2 );
                 }
                 else {
                     printf ( "Theres is second string = \"%s\"in position %d in first string = \"%s\";\n", string2, rez, string1 );
                 }
                 break;
             case '6':
                 printf ( "Input please operand:" );
                 clear_string ( & string1 );
                 rez = getop_my ( & string1 );
                 switch ( rez ) {
                     case 1:
                         printf ( "Geted operand = \"%s\";\n", string1 ); 
                         break;
                     case 0:
                         printf ( "Inputed symbol(s) is(are) not digital.\n");
                         break;
                 };
                 break;
             case 'q':
                 printf ( "Exit. Goodbye!\n" );
                 exit = 1;
                 break;
             case 'r':
                 print_variants ();
                 break;
             default:
                 printf ( "Wrong input. You may choose next variants:\n" );
                 print_variants ();
         };
    };
}

void print_variants () {

    printf ( "\nChoose please what you want to do:\n" );
    printf ( "1. Test getline function.\n" );
    printf ( "2. Test atoi function.\n" );
    printf ( "3. Test itoa function.\n" );
    printf ( "4. Test reverse function.\n" );
    printf ( "5. Test strindex function.\n" );
    printf ( "6. Test getop function.\n" );
    printf ( "Repeat. To repeat variants enter \"r\".\n" );
    printf ( "Exit. Fot quit enter \"q\".\n" );

}


int getline_my ( char * string ) {

    int i = 0;
    char exit = 0;
    char c = 0;

    c = getch ();
    exit = 0;
    while ( exit == 0 ) {
       if ( c == EOF || c == '\n' ) {
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


short int check_string_at_digits ( char * string ) {

    int i = 0;
    short int check = 0;

    while ( * string != '\0' && check == 0 ) {
        if ( * string >= '0' && * string <= '9' ) {
            check = 0;
        }
        else {
            return 1;
        };
        * string ++;
    };
    if ( check == 0 ) {
        return 0;
    }
}


void itoa_my ( char * string, int digit ) {

    int i = 0;

    while ( ( digit /= 10 ) > 0 ) {
        * string ++ = digit % 10 + '0';
    };   

}

void reverse_my ( char * source, char * rev ) {

    int i = 0;

    while ( * source != '\0' ) {
        i++;
        printf ( "int first while * source = %c;\n", * source );
        * source ++;
    };

    * source --;
     printf ( "before second while cycle * source = \"%c\" in char and %d in digit;\n", * source, * source );

    while ( i > 0 ) {
        * rev ++ = * source --;
        i --;
        * rev --;
        printf ( "in second while * rev = %c;\n", * rev );
        * rev ++;
    };

    * rev = '\0';

}

short int strindex_my ( char * s_where, char * s_what, int len1, int len2 ) {

    int i = 0;
    int p1 = 0;
    int p2 = 0;
    int diff = 0;
    short int check1 = 0;  

    diff = len1 - len2;

    if ( diff < 0 ) {
        printf ( "Second string is less than first.\n" );
        return -1;
    };

    while ( * s_where != '\0' && p1 <= diff ) {
        check1 = 0;
        p2 = 0;
        while ( * s_what != '\0' && check1 == 0 ) {
            if ( * s_where == * s_what ) {
                printf ( "* s_what = \"%c\" in char, %d in digit and %p as pointer;\n", * s_what, * s_what, * s_what );
                printf ( "* s_where = \"%c\" in char, %d in digit and %p as pointer;\n", * s_where, * s_where, * s_where );
                p2 ++;
                * s_what ++;
                * s_where ++;
            }
            else {
                check1 = 1;
                for ( i = 0; i < p2; i++ ) {
                    * s_what --;
                    * s_where --;
                }; 
                p2 = 0;
            };            
        }
        if ( * s_what == '\0' && check1 == 0 ) {
            return ( p1 );
        }
        * s_where ++;
        p1 ++; 
    };

    return ( - 1 );
}


int strlen_my ( char * string ) {

    int i = 0;

    while ( * string != '\0' ) {
        printf ( "at step %d * string = %c in char, %d in digit and %p as point;\n", i, * string, * string, * string );
        i ++;
        * string ++;
    };

    return i;

}

short int getop_my ( char * string ) {

    int i = 0;

    while ( ( * string = getch () ) == ' ' || * string == '\t' ) {
        ;
    };
    * string ++;
    * string = '\0';
    * string --;

    if ( * string != '.' && ( ! isdigit ( * string ) ) ) {
        return 0;
    };

    if ( isdigit ( * string ) ) {
        while ( isdigit ( * ++ string = getch () ) ) {
            ;
        };
    };
    
    if ( * string == '.' ) {
        while ( isdigit ( * ++ string = getch () ) ) {
            ;
        };
    };

    * string = '\0';

    return 1;

}


