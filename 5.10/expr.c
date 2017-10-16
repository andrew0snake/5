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
        printf ( "\nin main argc = %d;\n", argc + 1 );
        if ( ( isop ( * * argv ) ) == 1 ) {
            if ( val_pt >= 1 ) {
                ops [ op_pt ++ ] = * * argv;
                printf ( "ops [ op_pt - 1 = %d ] = %c;\n", op_pt - 1, ops [ op_pt - 1 ] );
            }
            else {
                printf ( "there aren't enough arguments (less than two).\n" );    
                printf ( "argc = %d; val_pt = %d;\n", argc, val_pt );
            }
        }
        else {
            if ( ( isdigit_my ( * argv ) ) == 1 ) {
                printf ( "in main * argv = '%s' is digit.\n", * argv );
                digit = atoi ( * argv );
                printf ( "after atoi digit = %d;\n", digit );
                vals [ val_pt ++ ] = digit;
                printf ( "vals [ val_pt = %d ] = %d;\n", val_pt - 1, vals [ val_pt - 1 ] );
            }
            else 
                printf ( "wrong input: value %s is not operator of digit.\n", * argv );
        }
        argv ++;
    }

    for ( i = 0; i < max_count; i++ ) {
        printf ( "vals [ i = %d ] = %d;\n", i, vals [ i ] );       
    }

    for ( i = 0; i < op_pt; i ++ ) {
        printf ( "ops [ %d ] = %c;\n", i, ops [ i ] );
    }

    printf ( "\nbefore check val_pt = %d, op_pt = %d;\n", val_pt, op_pt );

    if ( val_pt >= 1 && op_pt > 0 ) {
        i = 0;
        while ( i < op_pt ) {
            printf ( "forwarded to calc are: vals [ %d ] = %d, vals [ %d ] = %d, ops [ %d ] = %c.\n", \
            val_pt - 1, vals [ val_pt - 1 ], val_pt - 2, vals [ val_pt - 2 ], i, ops [ i ]);
            var_2 = vals [ -- val_pt ];
            var_1 = vals [ -- val_pt ];
            rez = calc ( var_1, var_2, ops [ i ] );
            vals [ val_pt ++ ] = rez;
            i ++;
        }
        printf ( "rezult of all operations:%d = vals [ val_pt - 1 = %d ] ;\n", vals [ val_pt - 1 ], val_pt - 1 );
        
    }
    else {
        printf ( "You've inputed too little values and operands (needs at least one operand and two values).\n" );
        printf ( "val_pt = %d, op_pt = %d;\n", val_pt, op_pt );
    }

    return 0;
}

char isop ( char symb ) {

    printf ( "in isop symb = %c;\n", symb );

    if ( symb == '+' || symb == '-' || symb == '*' || symb == '/' ) {
        printf ( "in isop forwarded symbol is operator.\n\n" );
        return 1;
    }
    else {
        printf ( "in isop forwarded symbol is not operator.\n\n" );
        return 0;
    }

}

char isdigit_my ( char * s ) {

    int i = 0;
    char not_digit = 0;

    printf ( "in isdigit forwarded string: '%s'.\n\n", s );   
    
    while ( s [ i ] != '\0' ) {
//        printf ( "s [ i = %d ] = %c;\n", i, s [ i ] );
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

    printf ( "\nforwarded to calc var_1 = %d, var_2 = %d, op = %c;\n", var_1, var_2, op );

    if ( op == '+' ) {
        rez = var_1 + var_2;
        printf ( "op = '+', var_1 = %d; var_2 = %d; rez = %d;\n", var_1, var_2, rez );
    }
    else {
        if ( op == '-' ) {
            rez = var_1 - var_2;
            printf ( "op = '-', var_1 = %d; var_2 = %d; rez = %d;\n", var_1, var_2, rez );
        }
        else {
            if ( op == '/' ) {
                rez = var_1 / var_2;
                printf ( "op = '/', var_1 = %d; var_2 = %d; rez = %d;\n", var_1, var_2, rez );
            }
            else {
                if ( op == '*' ) {
                    rez = var_1 * var_2;
                    printf ( "op = '*', var_1 = %d; var_2 = %d; rez = %d;\n", var_1, var_2, rez );
                }
            }
        }
    }

    return rez;

}


