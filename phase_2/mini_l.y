%{
  #include <stdio.h>
  #include <stddef.h>
  extern FILE * yyin;
  void yyerror(const char * msg);
%}

%token  AND OR NOT TRUE FALSE IF THEN ELSE ENDIF WHILE DO BEGINLOOP ENDLOOP FOREACH IN CONTINUE FUNCTION RETURN BEGIN_PARAMS END_PARAMS BEGIN_LOCALS END_LOCALS BEGIN_BODY END_BODY INTEGER ARRAY OF READ WRITE ADD SUB MULT DIV MOD EQ ASSIGN NEQ LT GT LTE GTE L_PAREN R_PAREN L_SQUARE_BRACKET R_SQUARE_BRACKET SEMICOLON COLON COMMA NUMBER IDENT

%start program

%%

program: functions
          {printf("program -> functions\n");}
          ;

functions: /*epsilon*/
            {printf("functions -> epsilon\n");}
          | function functions
            {printf("functions -> function functions\n");}

function: FUNCTION IDENT SEMICOLON BEGIN_PARAMS declarations END_PARAMS BEGIN_LOCALS declarations END_LOCALS BEGIN_BODY statements END_BODY
          {printf("function -> FUNCTION IDENT SEMICOLON BEGIN_PARAMS declarations END_PARAMS BEGIN_LOCALS declarations END_LOCALS BEGIN_BODY statements END_BODY\n");}

array: R_SQUARE_BRACKET ARRAY L_SQUARE_BRACKET array
        {printf("array -> R_SQUARE_BRACKET  ARRAY L_SQUARE_BRACKET array\n");}
       | /*epsilon*/
        {printf("array -> epsilon\n");}

declarations: declaration SEMICOLON declarations 
              {printf("declarations -> declaration SEMICOLON declarations\n");}
             | /*epsilon*/
              {printf("declarations -> epsilon\n");}

declaration: IDENT COMMA declaration
              {printf("decleration -> IDENT COMMA declaration\n");}
             | IDENT COLON INTEGER
              {printf("declaration -> IDENT COLON NUMBER\n");}
             | IDENT COLON array OF INTEGER
              {printf("declaration -> IDENT COLON array OF INTEGER\n");}

statements: statement statements
            { printf("statements -> statement statements\n");}
            | /*epsilon*/
            {printf("statements -> epsilon\n"); }

statement: var ASSIGN expression
           {printf("statement -> var ASSIGN expression\n");}

term: var
      {printf("term -> var\n");}
      | NUMBER
      {printf("term -> NUMBER\n");}
      | L_PAREN expression R_PAREN
      {printf("term -> L_PAREN expression R_PAREN\n");}
      | IDENT L_PAREN expression_chain R_PAREN
      {printf("term -> IDENT L_PAREN expression_chain R_PAREN\n");}

multiplicative_expression: term MULT multiplicative_expression
                           {printf("multiplicative_expression -> term MULT multiplicative_expression\n");}
                           | term DIV multiplicative_expression
                           {printf("multiplicative_expression -> term DIV multiplicative_expression\n");}
                           | term MOD multiplicative_expression
                           {printf("multiplicative_expression -> term MOD multiplicative_expression\n");}
                           | term
                           {printf("multiplicative_expression -> term\n");}

nots: NOT nots
      {printf("nots -> NOT nots\n");}
      | NOT
      {printf("nots -> NOT\n");}
      | /**/
      {printf("nots -> epsilon\n");}
relation-expr_0: nots relation_expr
                  {printf("relation-expr_0 -> nots relation_expr\n");}

relation_expr: expression comp expression
                {printf("relation_expr -> expression comp expression\n");}
                | TRUE
                {printf("relation_expr -> TRUE\n" );}
                | FALSE
                {printf("relation_expr -> FALSE\n");}
                | L_PAREN bool-expr R_PAREN
                {printf("relation_expr -> L_PAREN bool-expr R_PAREN\n");}

comp: EQ
      {printf("comp -> EQ\n");}
      | NEQ
      {printf("comp -> NEQ\n");}
      | LT
      {printf("comp -> LT\n");}
      | GT
      {printf("comp -> GT\n");}
      | LTE
      {printf("comp -> LTE\n");}
      | GTE
      {printf("comp -> GTE\n");}

expression: multiplicative_expression ADD expression
            {printf("expression -> multiplicative_expression PLUS expression\n");}
            | multiplicative_expression SUB expression
            {printf("expression -> multiplicative_expression SUB expression\n");}
            | multiplicative_expression
            {printf("expression -> multiplicative_expression\n");}

expressions: R_SQUARE_BRACKET expression L_SQUARE_BRACKET expressions
             { printf("expressions ->  R_SQUARE_BRACKET expression L_SQUARE_BRACKET expressions\n");}
             | /*epsilon*/
             { printf("expressions -> epsilon\n");}

expression_chain: expression COMMA expression_chain
                  {printf("expression_chain -> expression COMMA expression_chain\n");}
                  | expression
                  {printf("expression_chain -> expression\n");}

vars: var COMMA vars
      {printf("vars -> var COMMA vars\n");}
      | var
      {printf("vars -> var\n");}

var: IDENT
    {printf("var -> IDENT\n");}
    |
    IDENT R_SQUARE_BRACKET expressions








%%
int main(int argc, char ** argv)
{
   if(argc > 1) {

      yyin = fopen(argv[1], "r"); // open the file

      if(yyin == NULL) yyin = stdin; // If something went wrong default back to stdin

   } else {

      yyin = stdin; // Default to stdin

   }

   yyparse(); // Finally call the parser.
}

void yyerror(const char * msg) {
  printf("Error: %s\n", msg);
}