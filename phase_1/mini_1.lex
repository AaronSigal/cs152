%{
  int lineNum = 1;
  int linePos = 0;

  static const char* reservedWords[] = {
    "and", 
    "or", 
    "not", 
    "true", 
    "false", 

    "if", 
    "then",
    "else",
    "endif", 
     
    "while", 
    "do", 

    "beginloop", 
    "endloop",

    "foreach", 
    "in", 
    "continue",

    "function", 
    "return",
    "beginparams", 
    "endparams",

    "beginlocals", 
    "endlocals",

    "beginbody", 
    "endbody", 

    "integer", 
    "array", 
    "of", 
    
   
    "read", 
    "write"};

  static const char* ReservedTokens[] = {
    "AND", 
    "OR", 
    "NOT", 
    "TRUE", 
    "FALSE",

    "IF", 
    "THEN",
    "ELSE", 
    "ENDIF",
    
    "WHILE", 
    "DO", 

    "BEGINLOOP", 
    "ENDLOOP",

    "FOREACH", 
    "IN", 
    "CONTINUE",

    "FUNCTION",
    "RETURN",
    "BEGIN_PARAMS", 
    "END_PARAMS", 

    "BEGIN_LOCALS",
    "END_LOCALS",

    "BEGIN_BODY", 
    "END_BODY", 

    "INTEGER", 
    "ARRAY", 
    "OF", 

   
    "READ", 
    "WRITE"};
  
  const int reservedWordNum = 29;
%}

/* Regex */
DIGIT [0-9]
DIGIT_ [0-9_]
LETTER [a-zA-Z]
LETTER_ [a-zA-Z_]
CHARACTER [0-9a-zA-Z_]
CHAR_NO_SCORE [0-9a-zA-Z]
NEWLINE [\n]

COMMENT [##]

NUMBER ({DIGIT}+)|({DIGIT}?\.?{DIGIT}+([eE][+-]{DIGIT}+)?)

%%

"+"  { printf("ADD\n"); linePos++; }

"-"  { printf("SUB\n"); linePos++; }

"*"  { printf("MULT\n"); linePos++;}

"/"  { printf("DIV\n"); linePos++; }

"%"  { printf("MOD\n"); linePos++; }

"==" { printf("EQ\n"); linePos += 2; }

":=" { printf("ASSIGN\n"); linePos += 2; }

"<>" { printf("NEQ\n"); linePos += 2; }

"<" { printf("LT\n"); linePos += 1; }

">" { printf("GT\n"); linePos += 1; }

"<=" { printf("LTE\n"); linePos += 2; }

">=" { printf("GTE\n"); linePos += 2; }

"("  { printf("L_PAREN\n"); linePos++; }

")"  { printf("R_PAREN\n"); linePos++; }

"["  { printf("L_SQUARE_BRACKET\n"); linePos++; }

"]"  { printf("R_SQUARE_BRACKET\n"); linePos++; }

";"  { printf("SEMICOLON\n"); linePos++; }

":"  { printf("COLON\n"); linePos++; }

","  { printf("COMMA\n"); linePos++; }

"\n" { linePos = 0; ++lineNum; }

[\t ]+ { linePos += yyleng; }

{NUMBER} {printf("NUMBER %s\n", yytext); linePos += yyleng; }

{LETTER}({CHARACTER}*{CHAR_NO_SCORE})? {

  char isReservedWord = 0; // defaults to false

  int i; // Counter variable for loop

  for (i = 0; i < reservedWordNum; i++) {

    if (!strcmp(yytext, reservedWords[i])) { // if output is zero, words are same
      isReservedWord = 1; // Reserverd word is set to true
      printf("%s\n", ReservedTokens[i]); // print the token string for the reserved word
    }
  }

  if (!isReservedWord)  printf("IDENT %s\n", yytext);

  linePos += yyleng;
}


{NUMBER}{CHARACTER}+ {

  printf("Error at line %d:%d. Cannot start identifier with a number: %s\n", lineNum, linePos, yytext); exit(-1);
}


{LETTER}{CHARACTER}*_ {
   printf("Error at line %d:%d. Cannot end with an underscode: %s\n", lineNum, linePos, yytext); exit(-1);
}

"##".*{NEWLINE} { lineNum++; linePos = 0;  }


.     {printf("Error at line %d:%d. Unrecognized input: %s\n", lineNum, linePos, yytext); exit(-1); }

%%

int main(int argc, char ** argv)
{
   if(argc > 1) {

      yyin = fopen(argv[1], "r"); // open the file

      if(yyin == NULL) yyin = stdin; // If something went wrong, default back to stdin

   } else {

      yyin = stdin; // Default to stdin

   }

   yylex(); // Finally, call the lexer.
}
