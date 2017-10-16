#include <stdio.h>

#define MAXLINE 100 
/* максимальный размер вводимой строки */

int getl(char line[], int maxline);
void detab(char to[], char from[]);
int getline_my ( char * line, int max );

int main()
{
    int len = 0; /* длина текущей строки */
    char line[MAXLINE]; /* текущая строка */
    char newline[MAXLINE]; /* новая строка */
    int i = 0;

    printf ( "Input, please, lines to detab:\n" );
    while ((len = getline_my(line, MAXLINE)) > 0) {        
        detab(newline, line);
        printf("%s;\n", newline);
        i = 0;
        while ( newline [ i ] != '\0' ) {
            printf ( "newline [ %d ] = '%c' and %d;\n", i, newline [ i ], newline [ i ] );
            i ++;
        }
    }
    return 0;
}

#define TABSIZE 8     /* размер табуляции в пробелах */

void settabs(int []);
int tabpos(int, int []);

/* detab: преобразует символы табуляции из 'from' в пробелы 'to' */
void detab(char to[], char from[])
{
    int i, j;
    int tabstops[MAXLINE];

    settabs(tabstops);

    i = j = 0;
    while ((to[j] = from[i++])) {
        if (to[j] == '\t') {
            do {
                to[j++] = ' ';
            } while (!tabpos(j, tabstops));
        }
        else
            ++j;
    }
}

void settabs(int tabstops[])
{
    int i;
    for (i=0; i < MAXLINE; i++) {
        tabstops[i] = (i % TABSIZE == 0);
        printf ( "tabstops [ %d ] = %d;\n", i, tabstops [ i ] );
    }
}

int tabpos(int col, int tabstops[])
{
    if (col > MAXLINE)
        return 1;
    else
        return tabstops[col];
}


int getline_my ( char * line, int max ) {

    char c = 0;
    int len = 0;

    while ( ( c = getchar () ) != '\0' && c != EOF && c != '\n' && len < max ) {
        * line ++ = c;
        len ++;
    }

    if ( c == '\n' ) {
        * line  = '\0';
    }
    else {
        if ( c == EOF )
            * line = '\0'; 
            return len;
    }

    return len;
}



