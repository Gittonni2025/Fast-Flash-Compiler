%{
#include <stdio.h>
#include <stdlib.h>
%}

%option noyywrap

%%

"calc"          { printf("Keyword pelam: calc\n"); }
"convert"       { printf("Keyword pelam: convert\n"); }
"finance"       { printf("Keyword pelam: finance\n"); }
"health"        { printf("Keyword pelam: health\n"); }
"print"         { printf("Keyword pelam: print\n"); }
[0-9]+          { printf("Number pelam: %s\n", yytext); }
[a-zA-Z_][a-zA-Z0-9_]* { printf("Identifier pelam: %s\n", yytext); }
[ \t\r\n]+      { /* Do nothing */ }
.               { printf("Unknown character: %s\n", yytext); }

%%

int main() {
    printf("Fast Flash Lexer ready! Kichu ekta likhe enter dao:\n");
    yylex();
    return 0;
}