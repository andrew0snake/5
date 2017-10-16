#include <stdio.h>

int f1 ( char * p1 );    

int main () {

    char array_1 [ 10 ] = "123qweasd";
    int i = 0;
    int rez = 0;
    char * p_c;
    char * s;
    printf ( "====================================================\n"); 
       
    printf ( "\n\nHere we have pointers p_c and s; char array array_1 = '%s';\n\n", array_1 );
 
    for ( i = 0; i < 10; i ++ ) {
        printf ( "array_1 [ %d ] = %c;\n", i, array_1 [ i ] );
    }

    p_c = array_1;

    printf ( "\nExamples of pointer operations:\n" );
    
    printf ( "\n* ( p_c = array_1 ) = %c;\n", * p_c );

    printf ( "\np_c [ 2 ] = %c;\n", p_c [ 2 ] );

    printf ( "\n* ( p_c + 2 ) = %c;\n", * ( p_c + 2 ) );

    printf ( "\np_c + 5 = %p; and & array_1 [ 5 ] = %p;\n", p_c + 5, & array_1 [ 5 ] );

    s = p_c; 
    printf ( "\ns = p_c;\n" );
    printf ( "s = %p; and p_c = %p;\n", s, p_c );

    printf ( "====================================================\n"); 
    printf ( "\nFunction f1 counts all non zero symbols and puts rezult in value rez;\n" );
    printf ( "while using this function we check that operations inside function\n" );
    printf ( "do not do any influence at the source array address;\n" );
    printf ( "\nbefore f1 rez = %d; and array_1 = %p;\n", rez, array_1 );
    rez = f1 ( array_1 );
    printf ( "after f1 rez = %d; and array_1 = %p;\n\n", rez, array_1 );
  
    printf ( "====================================================\n"); 
    printf ( "Here we describe all valid operations with pointers:\n\n" );
    printf ( "Assignment of pointers of the same type'\n\n" );
    printf ( "Adding or subtracting a pointer and an integer;\n\n" );
    printf ( "Subtracting or comparing two pointers to members of the same array and assigning or comparing to zero;\n\n");
    
    printf ( "====================================================\n"); 
    printf ( "This operations are NOT legal:\n\n" );
    printf ( "To add two pointers or to multipry or to divide or shift or mask them;\n\n" );
    printf ( "Or to add float or double to them;\n\n");
    printf ( "Or even, except for void *, to assign a pointer of one type to a pointer of another type without a cast;\n\n" );
    printf ( "====================================================\n"); 
 
    return 0;
}

int f1 ( char * p1 ) {
    
    int count = 0;

    while ( * p1 != '\0' ) {
        count ++;
        * p1 ++;
    }

    return count;
}


