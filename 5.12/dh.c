 #include <stdio.h>

 #define MAXLINE 72   /* максимальный размер строки табуляций */
 #define TABSIZE 4    /* размер табуляции в пробелах */

 void detab(int []);
 void settabs(int []);

 int main()
 {
     int tabstops[MAXLINE];
    int i = 0;

    
     settabs(tabstops);
    for ( i = 0; i < MAXLINE; i ++ ) { 
        printf ( "tabstops [ %d ] = %d;\n", i, tabstops [ i ] );
    }
     detab(tabstops);

     return 0;
 }

 void settabs(int tabstops[])
 {
     int i;
     for (i=0; i < MAXLINE; i++)
         tabstops[i] = (i % TABSIZE == 0);
 }

 int tabpos(int, int []);

 /* detab: преобразует символы табуляции в пробелы */
 void detab(int tabstops[])
 {
     int col = 0;
     char c;

     while ((c = getchar()) != EOF) {
         if (c == '\t') {
             do
                 putchar(' ');
             while (!tabpos(++col, tabstops));
         }
         else if (c == '\n') {
             putchar(c);
             col = 0;
         }
         else {
             putchar(c);
             ++col;
         }
     }
 }

 int tabpos(int col, int tabstops[])
 {
     if (col > MAXLINE)
         return 1;
     else
         return tabstops[col];
 }


