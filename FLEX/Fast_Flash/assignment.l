%{
#include <stdio.h>
#include <stdlib.h>
%}

%option noyywrap

%%

"int"|"float"|"char"|"double"|"if"|"else"|"while"|"for"|"return"|"void"|"do"|"switch"|"case" { printf("C Keyword: %s\n", yytext); }
[A-Z][a-z_*+\-/%^!@#$&]* { printf("Valid ID (Capital start): %s\n", yytext); }
[0-9]+\.[0-9]+ { printf("Floating Point Number: %s\n", yytext); }
[+-]?[0-9]+ { printf("Integer (Positive or Negative): %s\n", yytext); }
[ \t\r\n]+ { /* Do nothing */ }
. { printf("Unknown character: %s\n", yytext); }

%%

int main() {
    printf("Assignment Flex Program Ready! Kichu input dao:\n");
    yylex();
    return 0;
}