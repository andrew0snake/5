#include <stdio.h>
#include <string.h>

#define MLEN 100

static char daytab [ 2 ] [ 13 ] = {
    { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
    { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
};

int day_of_year ( int year, int moonth, int day );
void month_day ( int year, int yearday, int * pmonth, int * pday ); 
int getline_my ( char * line, int len );

void print_variants ();
void clear_line ( char * line );

int main () {

    char line [ MLEN ];
    char answ [ MLEN ];
    char v = 0;
    char exit = 0;
    int rez = 0;
    int year = 0;
    int yearday = 0;
    char month = 0;
    int day = 0;
    char error = 0;

    print_variants (); 

    while ( exit == 0 ) {
        v = getline_my ( & answ, MLEN );
        v = answ [ 0 ];
//        printf ( "v = %d in digital and '%c' in char.\n", v, v );
        switch ( v ) {
            case 'a':        
                rez = 0;
                error = 0;
                while ( rez == 0 ) {
                    printf ( "Input please year ( from 1 to 2016 ):" );       
                    clear_line ( & line );
                    getline_my ( & line, MLEN );
                    year = atoi ( line );
                    if ( year > 0 && year <= 2016 ) {
                        rez = 1;
                    }
                    else {
                        printf ( "Wrong year, try again.\n" );
                        error = 1;
                    };
                };
                rez = 0;        
                while ( rez == 0 ) {
                    printf ( "Input please month ( from 1 to 12 ):" );       
                    clear_line ( & line );
                    getline_my ( & line, MLEN );
                    month = atoi ( line );
                    if ( month > 0 && month <= 12 ) {
                        rez = 1;
                    }
                    else {
                        printf ( "Wrong month, try again.\n" );
                        error = 1;
                    }
                 };
                rez = 0;
                while ( rez == 0 ) {
                    printf ( "Input please day ( from 1 to 31 ):" );       
                    clear_line ( & line );
                    getline_my ( & line, MLEN );
                    day = atoi ( line );
                    if ( day > 0 && day <= 31 ) {
                        rez = 1;
                    }
                    else {
                        printf ( "Wrong day, try again.\n" );
                        error = 1;
                    }
                };
                
                if ( error == 1 ) {
                    printf ( "Wrong input, try again.\n" );
                }
                else {
                    rez = day_of_year ( year, month, day );
                    if ( rez == -1 ) {
                        printf ( "Because of wrong values operation isn't complete.\nYou may try again.\n" );
                    }
                    else {
                        printf ( "Day of year is %d;\n", rez );
                    }
                }
                break;
            case 'b':
                rez = 0;
                while ( rez == 0 ) {
                    printf ( "Input please day of year ( from 1 to 366 ):" );       
                    clear_line ( & line );
                    getline_my ( & line, MLEN );
                    yearday = atoi ( line );
                    if ( yearday > 0 && yearday < 366 ) {
                        rez = 1;
                    }
                    else {
                        printf ( "Wrong day of year, try again.\n" );
                    };

                };
                rez = 0;        
                while ( rez == 0 ) {
                    printf ( "Input please year ( from 1 to 2016 ):" );       
                    clear_line ( & line );
                    getline_my ( & line, MLEN );
                    year = atoi ( line );
                    if ( year > 0 && year < 2016 ) {
                        rez = 1;
                    }
                    else {
                        printf ( "Wrong year, try again.\n" );
                    };
                };
                month_day ( year, yearday, & month, & day );  
                printf ( "month = %d; day of month = %d;\n", month, day );
                break;
            case 'h':
                print_variants();
                break;
            case 'q':
                exit = 1;
                break;
            default:
                printf ( "Wrong input. To quit press 'q'.\nFor help press 'h'\n" );
        }
    }

}


int day_of_year ( int year, int month, int day ) {

    int i = 0;
    int leap = 0;

    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

    if ( year < 1 || year > 2016 ) {
        printf ( "Error: year is no in [ 1..2016 ] interval.\n" );
        return -1;
    }

    if ( month < 1 || month > 12 ) {
        printf ( "Error: month is no in [ 1..12 ] interval.\n" );
        return -1;
    }

    if ( day < 1 || day > 31 ) {
        printf ( "Error: dey is no in [ 1..31 ] interval.\n" );
        return -1;
    }
    else {
        if ( day > daytab [ leap ] [ month ] ) {
            printf ( "Error: month is longer than may be in this month. ( day = %d and is more than %d )\n", day, daytab [ leap ] [ month ] ); 
            return -1;
        }
    }

    for ( i = 0; i < month; i++ ) {
        day += daytab [ leap ] [ i ]; 
    };

    return day;

}

void month_day ( int year, int yearday, int * pmonth, int * pday ) {

    int i = 0;
    int leap = 0;

    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

    for ( i = 1; yearday > daytab [ leap ] [ i ]; i ++ ) {
        yearday -= daytab [ leap ] [ i ];
    }
    
    * pmonth = i;
    * pday = yearday;

}

int getline_my ( char * line, int len) {

    int i = 0;
    char c = 0;

    while ( len > 0 && ( ( c = getchar () ) != EOF && c != '\n') ) {
        * line ++ = c;
        i ++;
        len --;
    };

    if ( * line == '\n' ) {
        * line ++ = '\n';
        i ++;
    };

    * line = '\0';
    
    return i;
}

void print_variants () {

    printf ( "---============================---\n" );
    printf ( "Choose what you want to do, please.\n" );
    printf ( "You may do it by inputing wariants:\n" ); 
    printf ( "'a' allows you to get day of year after input month and day of month.\n" );
    printf ( "'b' may help you to know month and day from day of year.\n" );
    printf ( "'q' - quit from program.\n" );
    printf ( "---============================---\n" );

}


void clear_line ( char * line ) {

    int len;
    int i = 0;

    while ( line [ i ] < MLEN ) {
        line [ i ++ ] = 0;
    };
    
//    printf ( "lenght of string = %d;\n", i );
}


