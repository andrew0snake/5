#include <stdio.h>

#define MAXNUM 100

char isop ( char s );
char isdigit_my ( char * s );
int calc ( int op_1, int var_2, char op );

int vals [ MAXNUM ];
char ops [ MAXNUM ];
int val_pt = 0;
int op_pt = 0;

int main (int argc, char * argv [] ) {

    int i = 0;
    int digit = 0;
    int var_1 = 0;
    int var_2 = 0;
    int rez = 0;
    char * ptr_1 [ 100 ];
    char * ptr_2;
    char max_count = argc - 2;

    argv ++;

    while ( argc -- > 1 ) {
        if ( ( isop ( * * argv ) ) == 1 ) {
            if ( val_pt >= 1 ) {
                ops [ op_pt ++ ] = * * argv;
            }
            else {
                printf ( "there aren't enough arguments (less than two).\n" );    
            }
        }
        else {
            if ( ( isdigit_my ( * argv ) ) == 1 ) {
                digit = atoi ( * argv );
                vals [ val_pt ++ ] = digit;
            }
            else 
                printf ( "wrong input: value %s is not operator of digit.\n", * argv );
        }
        argv ++;
    }


    if ( val_pt >= 1 && op_pt > 0 ) {
        i = 0;
        while ( i < op_pt ) {
            var_2 = vals [ -- val_pt ];
            var_1 = vals [ -- val_pt ];
            rez = calc ( var_1, var_2, ops [ i ] );
            vals [ val_pt ++ ] = rez;
            i ++;
        }
        printf ( "rezult of all operations: %d;\n", vals [ val_pt - 1 ] );
        
    }
    else {
        printf ( "You've inputed too little values and operands (needs at least one operand and two values).\n" );
    }

    return 0;
}

char isop ( char symb ) {


    if ( symb == '+' || symb == '-' || symb == '*' || symb == '/' ) {
        return 1;
    }
    else {
        return 0;
    }

}

char isdigit_my ( char * s ) {

    int i = 0;
    char not_digit = 0;

    
    while ( s [ i ] != '\0' ) {
        if ( s [ i ] >= '0' && s [ i ] <= '9' ) {            
        }
        else 
            not_digit = 1;
        i++;
    }    

    if ( not_digit == 0 )
        return 1;
    else
        return 0;

}

int calc ( int var_1, int var_2, char op ) {

    int rez = 0;

    if ( op == '+' ) {
        rez = var_1 + var_2;
    }
    else {
        if ( op == '-' ) {
            rez = var_1 - var_2;
        }
        else {
            if ( op == '/' ) {
                rez = var_1 / var_2;
            }
            else {
                if ( op == '*' ) {
                    rez = var_1 * var_2;
                }
            }
        }
    }

    return rez;

}


