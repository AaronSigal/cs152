%{
  int lineNum = 1;
  int linePos = 0;
  #include "y.tab.h"

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

    "for",
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

    "FOR",
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
  
  const int reservedWordNum = 30;
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

"+"  {linePos++; return ADD;}

"-"  { linePos++; return SUB;}

"*"  { linePos++; return MULT;}

"/"  { linePos++; return DIV;}

"%"  { linePos++; return MOD;}

"==" { linePos += 2; return EQ;}

":=" { linePos += 2; return ASSIGN;}

"<>" { linePos += 2; return NEQ;}

"<" { linePos += 1; return LT;}

">" { linePos += 1; return GT;}

"<=" { linePos += 2; return LTE;}

">=" { linePos += 2; return GTE;}

"("  { linePos++; return L_PAREN;}

")"  { linePos++; return R_PAREN;}

"["  { linePos++; return L_SQUARE_BRACKET;}

"]"  { linePos++; return R_SQUARE_BRACKET;}

";"  { linePos++; return SEMICOLON;}

":"  { linePos++; return COLON; }

","  { linePos++; return COMMA; }

"\n" { linePos = 0; ++lineNum;}

[\t ]+ { linePos += yyleng;}

{NUMBER} {linePos += yyleng; yylval.dval = atof(yytext); return NUMBER;}

{LETTER}({CHARACTER}*{CHAR_NO_SCORE})? {

  char isReservedWord = 0; // defaults to false

  int i; // Counter variable for loop

  for (i = 0; i < reservedWordNum; i++) {

    if (!strcmp(yytext, reservedWords[i])) { // if output is zero, words are same
      isReservedWord = 1; // Reserverd word is set to true
      //printf("%s\n", ReservedTokens[i]); // print the token string for the reserved word
      return i + 258;
    }
  }

  if (!isReservedWord)  {
    yylval.ival = (yytext);
    return IDENT; //printf("IDENT %s\n", yytext);
  }

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
