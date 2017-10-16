/*
    http://www.ProbCOMP.com
    
    String is an array of characters with the last element as '\0'.So whenver a character array is declared
    the size of the arrays should be one more than the actual size of the string so that it contains '\0'.
    2D array of string means a 2D character array. The row specifies the no. of strings and the column the max length of any string in that array
    

*/

#include<stdio.h>

void main()
{
    int i = 0;
    char names[5][20]={
                        "apple",
                        "orange",
                        "banana",
                        "mango",
                        "grapes",
                    };
    // The row repesents no. of strings and col represents length of the string
    
    for( i=0;i<5;i++ )
    {
        printf("%s\n",names[i]);
    }
}                                   
