%{
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <map>
#include "y.tab.h"
#include "heading.h"

extern FILE * yyin;

using namespace std;
// ****Forward Declarations****
void yyerror(const char* s);
int yylex(void);

// ****Structures****
struct Symbol {
  string type;
  string generated_code;
};

// **** Global Variables ****
map<string, Symbol> global_symbol_table;
map<string, Symbol> symbol_table;

int num_labels = 0;
int num_temps  = 0;
int num_params = 0;

const string LABEL_PRE = "__label__";
const string TEMP_PRE  = "__temp__" ; 

// ****Helper Functions****

string newLabel() {
  string result = LABEL_PRE + to_string(num_labels);
  num_labels++;
  return result;
}

string newTemp() {
  string result = TEMP_PRE + to_string(num_temps);
  num_labels++;
  return result;
}

%}

%union{
  int ival;
  char* sval;
  double dval;
}

%error-verbose

%token  AND OR NOT TRUE FALSE IF THEN ELSE ENDIF WHILE DO BEGINLOOP ENDLOOP FOR FOREACH IN CONTINUE FUNCTION RETURN BEGIN_PARAMS END_PARAMS BEGIN_LOCALS END_LOCALS BEGIN_BODY END_BODY INTEGER ARRAY OF READ WRITE ADD SUB MULT DIV MOD EQ ASSIGN NEQ LT GT LTE GTE L_PAREN R_PAREN L_SQUARE_BRACKET R_SQUARE_BRACKET SEMICOLON COLON COMMA 
%token <ival> NUMBER 
%token <sval> IDENT

%start program

%%

program: functions
          {printf("program -> functions\n");}
          ;

functions: /*epsilon*/
            {printf("functions -> epsilon\n");}
          | functions function 
            {printf("functions -> function functions\n");}
          | function

function: FUNCTION IDENT SEMICOLON BEGIN_PARAMS declarations END_PARAMS BEGIN_LOCALS declarations END_LOCALS BEGIN_BODY statements END_BODY
          {printf("function -> FUNCTION IDENT SEMICOLON BEGIN_PARAMS declarations END_PARAMS BEGIN_LOCALS declarations END_LOCALS BEGIN_BODY statements END_BODY\n");}
          ;

declarations: declarations SEMICOLON
              {printf("declarations -> declarations SEMICOLON\n");}
             | /*epsilon*/
              {printf("declarations -> epsilon\n");}
            | declarations SEMICOLON declaration
            {printf("declarations SEMICOLON declaration\n");}
            | declaration
            {printf("declaration\n");} 


declaration: IDENT COMMA declaration
              {printf("decleration -> IDENT COMMA declaration\n");}
             | IDENT COLON INTEGER
              {printf("declaration -> IDENT COLON NUMBER\n");}
             | IDENT COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER
              {printf("declaration -> IDENT COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER\n");}
             | IDENT COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER
              {printf("declaration -> IDENT COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER\n");}
              ;

statements: statements SEMICOLON 
            { printf("statements -> statement SEMICOLON statements\n");}
            | /*epsilon*/
            {printf("statements -> epsilon\n"); }
            | statements SEMICOLON statement
            {printf("statements -> statements SEMICOLON statement\n");}
            | statement
            {printf("statements -> statement\n");}

statement: var ASSIGN expression
           {printf("statement -> var ASSIGN expression\n");}
           | IF bool-expr THEN statements ENDIF
           {printf("statement -> IF bool-expr THEN statements ENDIF\n");}
           | IF bool-expr THEN statements ELSE statements ENDIF
           {printf("statement -> IF bool-expr THEN statements ELSE statements ENDIF \n");}
           | WHILE bool-expr BEGINLOOP statements ENDLOOP
           {printf("statement -> WHILE bool-expr BEGINLOOP statements ENDLOOP \n");}
           | DO BEGINLOOP statements ENDLOOP WHILE bool-expr
           {printf("statement -> DO BEGINLOOP statements ENDLOOP WHILE bool-expr\n");}
           | FOR var ASSIGN NUMBER SEMICOLON bool-expr SEMICOLON var ASSIGN expression BEGINLOOP statements ENDLOOP
           {printf("statement -> FOR var ASSIGN NUMBER SEMICOLON bool-expr SEMICOLON var ASSIGN expression BEGINLOOP statements ENDLOOP\n");}
           | READ vars
           {printf("statement -> READ vars\n");}
           | WRITE vars
           {printf("statement -> WRITE vars \n");}
           | CONTINUE
           {printf("statement -> CONTINUE\n");}
           | RETURN expression
           {printf("statement -> RETURN expression\n");}

term: var
      {printf("term -> var\n");}
      | NUMBER
      {printf("term -> NUMBER: %d\n", $1);}
      | L_PAREN expression R_PAREN
      {printf("term -> L_PAREN expression R_PAREN\n");}
      | IDENT L_PAREN expression_chain R_PAREN
      {printf("term -> IDENT L_PAREN expression_chain R_PAREN\n");}
      | SUB var
      {printf("term -> SUB var\n");}
      | SUB NUMBER
      {printf("term -> SUB NUMBER\n");}
      | SUB L_PAREN expression R_PAREN
      {printf("term -> SUB L_PAREN expression R_PAREN\n");}
      | SUB IDENT L_PAREN expression_chain R_PAREN
      {printf("term -> SUB IDENT L_PAREN expression_chain R_PAREN\n");}

multiplicative_expression_0: multiplicative_expression
                            {printf("multiplicative_expression_0 -> multiplicative_expression\n");}


multiplicative_expression: term MULT multiplicative_expression_0
                           {printf("multiplicative_expression -> term MULT multiplicative_expression\n");}
                           | term DIV multiplicative_expression_0
                           {printf("multiplicative_expression -> term DIV multiplicative_expression\n");}
                           | term MOD multiplicative_expression_0
                           {printf("multiplicative_expression -> term MOD multiplicative_expression\n");}
                           | term
                           {printf("multiplicative_expression -> term\n");}

bool-expr: relation-and-expr OR bool-expr
            {printf("bool-expr -> relation-and-expr OR bool-expr\n");}
            | relation-and-expr
            {printf("bool-expr -> relation-and-expr\n");}

relation-and-expr: relation-expr AND relation-and-expr
                    {printf("relation-and-expr -> relation-expr_0 AND relation-and-expr\n");}
                    | relation-expr
                    {printf("relation-and-expr -> relation-expr_0\n");}


relation-expr: expression comp expression
                {printf("relation_expr -> expression comp expression\n");}
                | NOT expression comp expression
                {printf("relation_expr -> NOT expression comp expression\n");}
                | TRUE
                {printf("relation_expr -> TRUE\n" );}
                | FALSE
                {printf("relation_expr -> FALSE\n");}
                | NOT TRUE
                {printf("relation_expr -> NOT TRUE\n" );}
                | NOT FALSE
                {printf("relation_expr -> NOT FALSE\n");}
                | L_PAREN bool-expr R_PAREN
                {printf("relation_expr -> L_PAREN bool-expr R_PAREN\n");}
                | NOT L_PAREN bool-expr R_PAREN
                {printf("relation_expr -> NOT L_PAREN bool-expr R_PAREN\n");}

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

expression_chain: expression_chain COMMA expression
                  {printf("expression_chain -> expression_chain COMMA expression\n");}
                  | expression
                  {printf("expression_chain -> expression\n");}

vars: vars COMMA var
      {printf("vars -> vars COMMA var\n");}
      | var
      {printf("vars -> var\n");}

var: IDENT
    {printf("var -> IDENT  %s \n", $1);}
    | IDENT L_SQUARE_BRACKET expression R_SQUARE_BRACKET
    {printf("var -> IDENT L_SQUARE_BRACKET expression R_SQUARE_BRACKET\n");}
    | IDENT L_SQUARE_BRACKET expression R_SQUARE_BRACKET L_SQUARE_BRACKET expression R_SQUARE_BRACKET
    {printf("var -> IDENT L_SQUARE_BRACKET expression R_SQUARE_BRACKET L_SQUARE_BRACKET expression R_SQUARE_BRACKET\n");}

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