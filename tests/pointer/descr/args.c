#include <stdio.h>

int main ( int argc, char * argv [] ) {

    while ( argc -- > 1 ) {
        printf ( "* argv = '%s';\n", * ++ argv  );
        printf ( "* ( ++ * argv ) = '%c';\n", * ( ++ * argv ) );
    }

}
