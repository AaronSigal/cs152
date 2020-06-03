%{
  #include <stdio.h>
  #include <stddef.h>
  #include <cstring>
  #include <string>
  #include <map>
  #include <set>
  #include <vector>
  #include <sstream>
  #include "heading.h"

  // Externs
  extern FILE * yyin;
  extern int lineNum;
  extern int linePos;
  extern "C" int yylex();

  //Function forward declarations
  void yyerror (const char * msg);
  int yylex();
  struct SymbolTable;

  using namespace std;

struct Symbol{
  string type;
  string value;
  string code;
};

struct SymbolTable {
  map<string, Symbol> table = map<string, Symbol>(); // The table in which we insert symbols at the current scope
  SymbolTable* parentTable = nullptr;  // The symbol table for the next-widest scope. This is null only for the global table;
};

bool exists(string name); // Checks if a symbol already exists in the current scope's symboltable
bool exists(string name, SymbolTable* table); // Checks if a symbol already exists in a given symbol table
bool increaseScope();            // Move up in scope by one layer if possible.
bool add(string name, Symbol symbol);  // Attempts to add a symbol to the current scope
string new_label();
string new_temp();



  // Global variables;
  SymbolTable globalTable;   // The top-level table
  SymbolTable* currentScope = &globalTable; // The current table, may not be top-level
  vector<string> param_id;   // List of parameters for current function
  vector<string> param_type; // List of parameters' types for current function
  set<string> functions;
  set<string> function_calls;
  int label_count = 0;
  int temp_count = 0;

%}

%union{
  int ival;
  char* sval;
  double dval;

struct VarContainer{
  char* place;
  char* code;
  char* type;  // can be VARIABLE or ARRAY
  char* index; // index for if this is an array
  char* index2;
} v;

struct StatementContainer{
  char* code;
  char* place;
  char* label;
  char* type;
  char* array_name;
  } s;

struct ExpressionContainer {
  char* code;
  char* place;
  char* array_name;
  char* type; // VARIABLE, ARRAY, or 2DARRAY
} e;
  
struct Generic{
   char* place; // Destination of value
   char* code;  // Code used to get value
} generic;

}

%error-verbose

%token  AND OR NOT TRUE FALSE IF THEN ELSE ENDIF WHILE DO BEGINLOOP ENDLOOP FOR FOREACH IN CONTINUE FUNCTION RETURN BEGIN_PARAMS END_PARAMS BEGIN_LOCALS END_LOCALS BEGIN_BODY END_BODY
%token <ival> INTEGER
%token  ARRAY OF READ WRITE ADD SUB MULT DIV MOD EQ ASSIGN NEQ LT GT LTE GTE L_PAREN R_PAREN L_SQUARE_BRACKET R_SQUARE_BRACKET SEMICOLON COLON COMMA 
%token <sval> IDENT 
%token <ival> NUMBER

%type <generic> program functions function  params locals body
%type <e> var term expression relation_expr relation-and-expr declaration expression_chain declarations vars
%type <s> statement statements

%start program

%%

program: functions
          {//printf("program -> functions\n");

            // Check for any undefined function calls
            for (string call : function_calls) {
              if (functions.count(call) < 1) {
                ostringstream oss;
                oss << "Error at line " << /*lineNum << ":" << linePos <<*/ ": No definition for function " << call << endl;
                 cout << (oss.str().c_str());
                 exit(-1);
              }
            }

            cout << $1.code;
          }
          ;

functions: /*epsilon*/
            {//printf("functions -> epsilon\n");
              $$.code = "";
            }
          | functions function 
            {//printf("functions -> function functions\n");
              ostringstream oss;
              oss << $1.code << endl << $2.code;
              $$.code = strdup(oss.str().c_str());
            }
          | function 
          {
            $$.code = $1.code;
          }


params: BEGIN_PARAMS declarations END_PARAMS
        {$$.code = $2.code;}

locals: BEGIN_LOCALS declarations END_LOCALS
        {$$.code = $2.code;}

body:   BEGIN_BODY statements END_BODY
        {$$.code = $2.code;}

function: FUNCTION IDENT SEMICOLON params locals body
          {//printf("function -> FUNCTION IDENT SEMICOLON BEGIN_PARAMS declarations END_PARAMS BEGIN_LOCALS declarations END_LOCALS BEGIN_BODY statements END_BODY\n");
            currentScope->table.clear(); // Clear the scope since we're switching between functions

            ostringstream oss;

            if (functions.count(string($2)) != 0) { // Check for duplicate declarations
              oss << "Error on line " << lineNum << ":" << linePos << ": Redefinition of function " << $2 << endl;

              cout << (oss.str().c_str());
              exit(-1);
            } else {
              functions.insert(string($2));
            }

            // Check for misplaced continues
            if (string($6.code).find("continue") != string::npos) {
              oss << "Error on line " << lineNum << ":" << linePos << ": Misplaced Continue in body of " << $2 << endl;
              cout << (oss.str().c_str());
              exit(-1);
            }

            // Build function code
            string temp = $2;

            oss << "func " << temp << endl;
            oss << $4.code << $5.code << $6.code;

            $$.code = strdup(oss.str().c_str());
          }
          ;

declarations: declarations SEMICOLON
              {//printf("declarations -> declarations SEMICOLON\n");
                $$.place = $1.place;
                $$.code = $1.code;
              }
             | /*epsilon*/
              {//printf("declarations -> epsilon\n");
                $$.code = "";
              }
            | declarations SEMICOLON declaration
            {//printf("declarations SEMICOLON declaration\n");
              ostringstream oss;
              oss << $1.code;
              oss << $3.code;
              $$.code =  strdup(oss.str().c_str());

              ostringstream lss;
              lss << $1.place << "#" << $3.place;
              $$.place = strdup(lss.str().c_str());
            }
            | declaration
            {//printf("declaration\n");
              $$.code  = $1.code;
              $$.place = $1.place;
            } 


declaration: IDENT COMMA declaration
              {//printf("decleration -> IDENT COMMA declaration\n");
            }
             | IDENT COLON INTEGER
              {//printf("declaration -> IDENT COLON NUMBER\n");
                string s($1);
                Symbol sym = Symbol();
                sym.type = "VARIABLE";
                sym.value = "null";
                sym.code  = "";

                ostringstream oss;
                oss << ". " << s << endl;
                sym.code = oss.str();

                $$.code = strdup(oss.str().c_str());

                add($1, sym);
              }
             | IDENT COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER
              {//printf("declaration -> IDENT COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER\n");
                string s($1);
                Symbol sym = Symbol();
                sym.type = "ARRAY";
                sym.value = "null";
                sym.code  = "";

                ostringstream oss;
                if ($5 < 0) {
                  ostringstream oss;
                  oss << "Index out of bounds: " << $1 << "on line " << lineNum << ":" << linePos << endl;
                  cout << (oss.str().c_str());
                }

                oss << ".[] " << $1 << ", " << $5 << endl;

                sym.code = oss.str();

                $$.code = strdup(oss.str().c_str());

                add($1, sym);
              }
             | IDENT COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER
              {//printf("declaration -> IDENT COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER\n");
                string s($1);
                Symbol sym = Symbol();
                sym.type = "2DARRAY";
                sym.value = "null";
                sym.code  = "";

                add($1, sym);
              }
              ;

statements: statements SEMICOLON 
            { //printf("statements -> statement SEMICOLON statements\n");
          }
            | /*epsilon*/
            {//printf("statements -> epsilon\n"); 
          }
            | statements SEMICOLON statement
            {//printf("statements -> statements SEMICOLON statement\n");
          }
            | statement
            {//printf("statements -> statement\n");
          }

statement: var ASSIGN expression
           {//printf("statement -> var ASSIGN expression\n");
         }
           | IF bool-expr THEN statements ENDIF
           {//printf("statement -> IF bool-expr THEN statements ENDIF\n");
         }
           | IF bool-expr THEN statements ELSE statements ENDIF
           {//printf("statement -> IF bool-expr THEN statements ELSE statements ENDIF \n");
         }
           | WHILE bool-expr BEGINLOOP statements ENDLOOP
           {//printf("statement -> WHILE bool-expr BEGINLOOP statements ENDLOOP \n");
         }
           | DO BEGINLOOP statements ENDLOOP WHILE bool-expr
           {//printf("statement -> DO BEGINLOOP statements ENDLOOP WHILE bool-expr\n");
         }
           | FOR var ASSIGN NUMBER SEMICOLON bool-expr SEMICOLON var ASSIGN expression BEGINLOOP statements ENDLOOP
           {//printf("statement -> FOR var ASSIGN NUMBER SEMICOLON bool-expr SEMICOLON var ASSIGN expression BEGINLOOP statements ENDLOOP\n");
         }
           | READ vars
           {//printf("statement -> READ vars\n");
         }
           | WRITE vars
           {//printf("statement -> WRITE vars \n");
         }
           | CONTINUE
           {//printf("statement -> CONTINUE\n");
         }
           | RETURN expression
           {//printf("statement -> RETURN expression\n");
         }

term: var
      {//printf("term -> var\n");
        $$.place = $1.place;
      }
      | NUMBER
      {//printf("term -> NUMBER: %d\n", $1);
        $$.code = "";
        $$.place = strdup(to_string($1).c_str());
      }
      
      | IDENT L_PAREN expression_chain R_PAREN
      {//printf("term -> IDENT L_PAREN expression_chain R_PAREN\n");
        // Process the function call
        ostringstream oss;
        if (function_calls.count($1) < 1) {
          function_calls.insert($1);
        }

        $$.code = $3.code;
        $$.place = $3.place;

        string temp = new_temp();
        oss << "param " << $3.place << endl;
        oss << ". " << temp << endl;
        oss << "call " << $1 << ", " << temp << endl;

        $$.code = strdup(oss.str().c_str());
        $$.place = strdup(temp.c_str());
      }
      | SUB var
      {//printf("term -> SUB var\n");
    }
      | SUB NUMBER
      {//printf("term -> SUB NUMBER\n");
    }
      | SUB L_PAREN expression R_PAREN
      {//printf("term -> SUB L_PAREN expression R_PAREN\n");
    }
      | SUB IDENT L_PAREN expression_chain R_PAREN
      {//printf("term -> SUB IDENT L_PAREN expression_chain R_PAREN\n");
    }

multiplicative_expression_0: multiplicative_expression
                            {//printf("multiplicative_expression_0 -> multiplicative_expression\n");
                          }


multiplicative_expression: term MULT multiplicative_expression_0
                           {//printf("multiplicative_expression -> term MULT multiplicative_expression\n");
                         }
                           | term DIV multiplicative_expression_0
                           {//printf("multiplicative_expression -> term DIV multiplicative_expression\n");
                         }
                           | term MOD multiplicative_expression_0
                           {//printf("multiplicative_expression -> term MOD multiplicative_expression\n");
                         }
                           | term
                           {//printf("multiplicative_expression -> term\n");
                         }

bool-expr: relation-and-expr OR bool-expr
            {//printf("bool-expr -> relation-and-expr OR bool-expr\n");
          }
            | relation-and-expr
            {//printf("bool-expr -> relation-and-expr\n");
          }

relation-and-expr: relation-expr AND relation-and-expr
                    {//printf("relation-and-expr -> relation-expr_0 AND relation-and-expr\n");
                  }
                    | relation-expr
                    {//printf("relation-and-expr -> relation-expr_0\n");
                  }


relation-expr: expression comp expression
                {//printf("relation_expr -> expression comp expression\n");
              }
                | NOT expression comp expression
                {//printf("relation_expr -> NOT expression comp expression\n");
              }
                | TRUE
                {//printf("relation_expr -> TRUE\n" );
              }
                | FALSE
                {//printf("relation_expr -> FALSE\n");
              }
                | NOT TRUE
                {//printf("relation_expr -> NOT TRUE\n" );
              }
                | NOT FALSE
                {//printf("relation_expr -> NOT FALSE\n");
              }
                | L_PAREN bool-expr R_PAREN
                {//printf("relation_expr -> L_PAREN bool-expr R_PAREN\n");
              }
                | NOT L_PAREN bool-expr R_PAREN
                {//printf("relation_expr -> NOT L_PAREN bool-expr R_PAREN\n");
              }

comp: EQ
      {//printf("comp -> EQ\n");
    }
      | NEQ
      {//printf("comp -> NEQ\n");
    }
      | LT
      {//printf("comp -> LT\n");
    }
      | GT
      {//printf("comp -> GT\n");
    }
      | LTE
      {//printf("comp -> LTE\n");
    }
      | GTE
      {//printf("comp -> GTE\n");
    }

expression: multiplicative_expression ADD expression
            {//printf("expression -> multiplicative_expression PLUS expression\n");
          }
            | multiplicative_expression SUB expression
            {//printf("expression -> multiplicative_expression SUB expression\n");
          }
            | multiplicative_expression
            {//printf("expression -> multiplicative_expression\n");
          }

expression_chain: expression_chain COMMA expression
                  {//printf("expression_chain -> expression_chain COMMA expression\n");
                }
                  | expression
                  {//printf("expression_chain -> expression\n");

                  }

vars: vars COMMA var
      {//printf("vars -> vars COMMA var\n");
        ostringstream oss;
        oss << $1.place << "#" << $3.place;
        $$.place = strdup(oss.str().c_str());
      }
      | var
      {//printf("vars -> var\n");
        if($1.type == "ARRAY") {
          $$.code = $1.code;
          $$.place = $1.place;
          $$.type == $1.type;
        }

        if ($1.type == "ARRAY2D") {
          $$.code = $1.code;
          $$.place = $1.place;
          $$.type == $1.type;
        }

        if ($1.type == "VARIABLE") {
          $$.code = $1.code;
          $$.place = $1.place;
        }
      }

var: IDENT
    {//printf("var -> IDENT  %s \n", $1);
      $$.code = "";
      $$.place = $1;

    }
    | IDENT L_SQUARE_BRACKET expression R_SQUARE_BRACKET
    {//printf("var -> IDENT L_SQUARE_BRACKET expression R_SQUARE_BRACKET\n");
      $$.place = $3.place;
      $$.array_name = $1;
      $$.type  = "ARRAY";
      $$.code  = $3.code;
    }
    | IDENT L_SQUARE_BRACKET expression R_SQUARE_BRACKET L_SQUARE_BRACKET expression R_SQUARE_BRACKET
    {//printf("var -> IDENT L_SQUARE_BRACKET expression R_SQUARE_BRACKET L_SQUARE_BRACKET expression R_SQUARE_BRACKET\n");
     // Not implemented yet (2D array)
    }

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

void yyerror (const char * msg) {
  printf("Error: %s\n", msg);
}

bool exists(string name) {
  auto itr = currentScope->table.find(name);

  if (itr == currentScope->table.end()) {
    return false;
  } else {
    return true;
  }
}

// Checks if a symbol already exists in a given symbol table
bool exists(string name, SymbolTable* table) {
   if (table == nullptr) cout << ("Internal error: cannot check null symbol table");

  auto itr = table->table.find(name);
  if (itr == table->table.end()) {
    return false;
  } else {
    return true;
  }
}

// Attempts to add a symbol to the current scope
bool add(string name, Symbol symbol) {
  stringstream ss;
 
  if (exists(name)) {
    ss << "Error on line " << to_string(lineNum) << ":" << to_string(linePos) << " : Redefinition of " << name << "\n";
    cout << (ss.str().c_str());
    cout << ss.str();
    exit(-1);
  }
  if (currentScope == nullptr) cout << ("Internal error: scope not set");

  currentScope->table.insert(make_pair(name, symbol));

  return true;
}

string new_label(){
  string temp = "__label__";
  temp += to_string(label_count);
  label_count += 1;
  return temp;
}

string new_temp(){
  string temp = "__temp__";
  temp += to_string(temp_count);
  temp_count += 1;
  return temp;
}