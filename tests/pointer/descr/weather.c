// C program to store temperature of two cities for a week and display it.
#include <stdio.h>

//const int CITY = 2;
//const int WEEK = 7;

int main()
{
    int CITY = 2;
    int WEEK = 7;
    int i = 0;
    int j = 0;

    int temperature[CITY][WEEK];
    for ( i = 0; i < CITY; ++i ) {
        for( j = 0; j < WEEK; ++j ) {
            printf ( "i = %d; j = %d;\n", i, j );
            printf("City %d, Day %d: ", i+1, j+1);
            scanf("%d", &temperature[i][j]);
        }
    }

    printf("\nDisplaying values: \n\n");
    for ( i = 0; i < CITY; ++i ) {
        for( j = 0; j < WEEK; ++j )
        {
            printf("City %d, Day %d = %d\n", i+1, j+1, temperature[i][j]);
        }
    }
    return 0;
}

