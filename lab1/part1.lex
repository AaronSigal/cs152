%{
  int lineNum = 1;
  int linePos = 0;
%}

DIGIT [0-9]

%%

"+"  { printf("PLUS\n"); linePos++; }

"-"  { printf("MINUS\n"); linePos++; }

"*" { printf("MULT\n"); linePos++; }

"/"   { printf("DIV\n"); linePos++; }

"("  { printf("L_PAREN\n"); linePos++; }

")"  { printf("R_PAREN\n"); linePos++; }

"="  { printf("EQUAL\n"); linePos++; }

"\n" { lineNum++; linePos = 0; }

[ \t]+  { linePos++;}

{DIGIT}+ {printf("NUMBER %s\n", yytext); linePos += yyleng; }

.     {printf("Error at line %d:%d. Unrecognized input: %s\n", lineNum, linePos, yytext); exit(-1); }

%%

int main(int argc, char ** argv) {
  yylex();
}
