#include <stdio.h>

#define LIM 100

void parse_input ( int argc, char * argv [] );

int main ( int argc, char * argv [] ) {

    parse_input ( argc, argv );

    return 0;

}



void parse_input ( int argc, char * argv [] ) {


//    char c = 0;
    int i = 0;
<<<<<<< HEAD
    char exit = 1;
=======
    int j = 0;
>>>>>>> b87bc892cc4410d05f490cc3ceb537f1b7904cb0
    char field [ LIM ];

    while ( argc > 0 ) {        
//        if ( ( * ++ argv ) [ 0 ] == '-' ) {
        if ( * argv [ 0 ] == '\"' ) {
<<<<<<< HEAD
            printf ( "* argv [ 0 ] = %c;--\n", * argv [ 0 ] );
            printf ( "* argv [ 1 ] = %c;--\n", ( * argv + 1 ) [ 0 ] );
//            for ( i = 0, j = 1; i < LIM && * argv [ j ] != '\"'; i ++, j ++ ) {                
//                printf ( "* argv [ %d ] = %c;\n", j, * argv [ j ] );
//                field [ i ] = * argv [ j ];
//                printf ( "field [ %d ] = %c;\n", i, field [ i ] );
//            }
            for ( i = 0; i < 10 && exit; i ++ ) {
                printf ( "( * argv + i ) [ %d ] = %c;\n", 0, ( * argv + i ) [ 0 ] );
                if ( i != 0 && ( * argv + i ) [ 0 ] == '\"' ) {
                    exit = 0;   
                }
            }
            * argv ++;
            argc --;
//            printf ( "field = '%s';\n", field );
=======
            printf ( "*  argv [ 0 ] = %c;\n", * argv [ 0 ] );
            for ( i = 0, j = 1; i < LIM && * argv [ j ] != '\"'; i ++, j ++ ) {                
                printf ( "* argv [ %d ] = %c;\n", j, * argv [ j ] );
                field [ i ] = * argv [ j ];
                printf ( "field [ %d ] = %c;\n", i, field [ i ] );
            }
            * argv ++;
            argc --;
            printf ( "field = '%s';\n", field );
>>>>>>> b87bc892cc4410d05f490cc3ceb537f1b7904cb0
        }
        else {    
            printf ( "* argv [ 0 ] = %c;\n", * argv [ 0 ] );
            printf ( "and whole string = %s;\n\n", * argv );
            argv ++;
            argc --;
/*            while ( ( c = * ++ argv [ 0 ]  ) ) {
                switch ( c ) {
                    case 'n':
//                        numeric = 1;
                        printf ( "numeric = 1;\n" );
                        break;
                    case 'r':
//                        reverse = 1;
                        printf ( "reverse = 1;\n" );
                        break;                                                                                                          
                    case 'f':
//                        case_insensitive = 0;
                        printf ( "case_insensitive = 1;\n" );                                    
                        break;
                    case 'd':
//                        directory = 1;
                        printf ( "directory = 1;\n" );
                        break;
                    default:                                                                                                                                
                        printf ( "wrong parameter;\n" );                                                                                                                
                        argc = 0;                                                                                                                                       
                        break;                                                                                                                                          
                }                                                                                                                                                       
                argc --;

            }
*/
        }
    }

}

