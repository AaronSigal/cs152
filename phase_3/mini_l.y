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
} varContainer;

struct StatementContainer{
  char* code;
  char* place;
  char* label;
  char* type;
  char* array_name;
  } statementContainer;

struct ExpressionContainer {
  char* code;
  char* place;
  char* array_name;
  char* type; // VARIABLE, ARRAY, or 2DARRAY
} expressionContainer;
  
struct Generic{
   char* place; // Destination of value
   char* code;  // Code used to get value
} generic;

struct Comparator{
  char* operation;
} comparator;

}

%error-verbose

%token  AND OR NOT TRUE FALSE IF THEN ELSE ENDIF WHILE DO BEGINLOOP ENDLOOP FOR FOREACH IN CONTINUE FUNCTION RETURN BEGIN_PARAMS END_PARAMS BEGIN_LOCALS END_LOCALS BEGIN_BODY END_BODY
%token <ival> INTEGER
%token  ARRAY OF READ WRITE ADD SUB MULT DIV MOD EQ ASSIGN NEQ LT GT LTE GTE L_PAREN R_PAREN L_SQUARE_BRACKET R_SQUARE_BRACKET SEMICOLON COLON COMMA 
%token <sval> IDENT 
%token <ival> NUMBER

%type <generic> program functions function  params locals body
%type <expressionContainer> var term expression relation-expr relation-and-expr declaration expression_chain declarations vars multiplicative_expression multiplicative_expression_0 bool-expr
%type <statementContainer> statement statements
%type <comparator> comp

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
              $$.code = $1.code;
              $$.place = $1.place;
            }
            | /*epsilon*/
            {//printf("statements -> epsilon\n"); 
              $$.code = "";
              $$.place = "";
            }
            | statements SEMICOLON statement
            {//printf("statements -> statements SEMICOLON statement\n");
              ostringstream oss;
              oss << $1.code;
              oss << $3.code;
              $$.code = strdup(oss.str().c_str());
            }
            | statement
            {//printf("statements -> statement\n");
              $$.code = $1.code;
              $$.place = $1.place;

              string label = string($1.label);
                    
              // Fixes a seg-fault by manually setting  to an empty string
              if (label.length() > 0) {
                $$.label = $1.label;
              } else {
                $$.label = "";
              }
            }

statement: var ASSIGN expression
         {//printf("statement -> var ASSIGN expression\n");
            ostringstream oss;
            $$.code = "";
            if (!exists(string($1.place))) {
              oss << "Error on line" << lineNum << ":" << linePos << ": variable " << $1.place << " has not been delcared!" << endl;
              cout << oss.str();
              exit(-1);
            }

            
            if(strcmp($1.type, "ARRAY") == 0) {

              oss << $1.code << $3.code;
              oss << "[]= " << $1.array_name << ", " << $1.place << ", " << $3.place << endl;
              $$.code = strdup(oss.str().c_str());
            } else if (strcmp($1.type, "VARIABLE") == 0) {

              oss << $3.code;
              oss << " = " << $1.place << ", " << $3.place << endl;
              $$.code = strdup(oss.str().c_str());

            } else if (strcmp($1.type, "2DARRAY") == 0) {

            }

            $$.label = "";

          }
         | IF bool-expr THEN statements ENDIF
         {//printf("statement -> IF bool-expr THEN statements ENDIF\n");
            $$.code = "";
            $$.label = "";

            string if_label = new_label();
            string skip_label = new_label();

            ostringstream oss;

            oss << $2.code; // if condition code
            oss << "?:= " << if_label << ", " << $2.place << endl; // set the jump to if label
            oss << ":= " << skip_label << endl; // set jump to skip label

            oss << ": " << if_label << endl;    // set if label
            oss << $4.code;                     // if-body code

            oss << ": " << skip_label << endl;  // skip label

            $$.code = strdup(oss.str().c_str());
         }
         | IF bool-expr THEN statements ELSE statements ENDIF
         {//printf("statement -> IF bool-expr THEN statements ELSE statements ENDIF \n");
            $$.code = "";
            $$.label = "";

            string if_label = new_label();
            string else_label = new_label();
            ostringstream oss;
          
            oss << $2.code; // if condition code
            oss << "?:= " << if_label << ", " << $2.place << endl; // set if label
            oss << ":= " << else_label << endl;                        // set else label

            oss << ": " << if_label << endl;                           // mark if label
            oss << $4.code;                                            // if code

            oss << ": " << else_label << endl;                         // mark else label
            oss << $6.code;                                            // else code
            
            $$.code = strdup(oss.str().c_str());                       // dump code to statement
         }
         | WHILE bool-expr BEGINLOOP statements ENDLOOP
         {//printf("statement -> WHILE bool-expr BEGINLOOP statements ENDLOOP \n");
            $$.code = "";
            $$.label = "";
            string while_body = new_label();
            string skip_label = new_label();
            string while_condition = new_label();
            ostringstream oss;
            
            if (string($4.label).length() == 0) { // if there's no labels within the statements block
              oss << ": " << while_condition << endl;
              oss << $2.code;
              oss << "?:= " << while_body << ", " << $2.place << endl;
              oss << ":= " << skip_label << endl;

              oss << ": " << while_body << endl;
              oss << $4.code;

              oss << ":= " << while_condition << endl;
              oss << ": " << skip_label << endl;
            } else {
              oss << ": " << while_condition << endl;
              oss << $2.code;
              oss << "?:= " << while_body << ", " << $2.place << endl;
              oss << ":= " << skip_label << endl;

              oss << ": " << while_body << endl;
              oss << $4.code;
              oss << ": " << $4.label << endl;  

              oss << ":= " << while_condition << endl;
              oss << ": " << skip_label << endl;
              
            }
          

          $$.code = strdup(oss.str().c_str());
         }
         | DO BEGINLOOP statements ENDLOOP WHILE bool-expr
         {//printf("statement -> DO BEGINLOOP statements ENDLOOP WHILE bool-expr\n");
            $$.code = "";
            $$.label = "";
         }
         | FOR var ASSIGN NUMBER SEMICOLON bool-expr SEMICOLON var ASSIGN expression BEGINLOOP statements ENDLOOP
         {//printf("statement -> FOR var ASSIGN NUMBER SEMICOLON bool-expr SEMICOLON var ASSIGN expression BEGINLOOP statements ENDLOOP\n");
            $$.code = "";
            $$.label = "";
         }
         | READ vars
         {//printf("statement -> READ vars\n");
            $$.code = "";
            $$.label = "";
         }
         | WRITE vars
         {//printf("statement -> WRITE vars \n");
            $$.code = "";
            $$.label = "";
         }
         | CONTINUE
         {//printf("statement -> CONTINUE\n");
            $$.code = "";
            $$.label = "";
         }
         | RETURN expression
         {//printf("statement -> RETURN expression\n");
            $$.code = "";
            $$.label = "";
         }

term: var
      {//printf("term -> var\n");
        $$.place = $1.place;
        $$.code = $1.code;
        $$.type = $1.type;
        $$.array_name = $1.array_name;
      }
      | NUMBER
      {//printf("term -> NUMBER: %d\n", $1);
        $$.code = "";
        $$.type = "VARIABLE";
        $$.place = strdup(to_string($1).c_str());
      }
      
      | IDENT L_PAREN expression_chain R_PAREN
      {//printf("term -> IDENT L_PAREN expression_chain R_PAREN\n");
        // Process the function call
        ostringstream oss;
        if (function_calls.count($1) < 1) {
          function_calls.insert($1);
        }

        oss << $3.code;
        $$.place = $3.place;
        $$.type = $3.type;

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
                              $$.code = $1.code;
                              $$.place = $1.place;
                            }


multiplicative_expression: term MULT multiplicative_expression_0
                           {//printf("multiplicative_expression -> term MULT multiplicative_expression\n");
                            ostringstream oss;
                            oss << $1.code << $3.code;
                            string temp = new_temp();
                            oss << ". " << temp << endl;
                            oss << "* " << temp << ", " << $1.place << ", " << $3.place << endl;
                            $$.code = strdup(oss.str().c_str());
                            $$.place = strdup(temp.c_str());

                           }
                           | term DIV multiplicative_expression_0
                           {//printf("multiplicative_expression -> term DIV multiplicative_expression\n");
                              ostringstream oss;
                              string temp = new_temp();
                              oss << $1.code << $3.code;
                              oss << ". " << temp << endl;
                              oss << "/ " << temp << ", " << $1.place << ", " << $3.place << endl;
                              $$.code = strdup(oss.str().c_str());
                              $$.place = strdup(temp.c_str()); 
                           }
                           | term MOD multiplicative_expression_0
                           {//printf("multiplicative_expression -> term MOD multiplicative_expression\n");
                              ostringstream oss;
                              oss << $1.code << $3.code;
                              string temp = new_temp();
                              oss << ". " << temp << endl;
                              oss << "% " << temp << ", " << $1.place << ", " << $3.place << endl;
                              $$.code = strdup(oss.str().c_str());
                              $$.place = strdup(temp.c_str());
                           }
                           | term
                           {//printf("multiplicative_expression -> term\n");
                            if (strlen($1.code) > 0){

                              ostringstream oss;
                              if (strcmp($1.type, "ARRAY") == 0){

                                string temp = new_temp();
                                
                                oss << $1.code;
                                oss << ". " << temp << endl;
                                oss << "=[] " << temp << ", " << $1.array_name << ", " << $1.place << endl;

                                $$.code = strdup(oss.str().c_str());
                                $$.place = strdup(temp.c_str());
                              } else {
                                $$.code = $1.code;
                                $$.place = $1.place;
                              }
                            } else {
                              ostringstream oss;
                              string temp = new_temp();
                              oss << ". " << temp << endl;
                              oss << "= " << temp << ", " << $1.place << endl;
                              $$.code = strdup(oss.str().c_str());
                              $$.place = strdup(temp.c_str());
                            }
                           }

bool-expr: relation-and-expr OR bool-expr
            {//printf("bool-expr -> relation-and-expr OR bool-expr\n");
              ostringstream oss;
              string temp = new_temp();

              oss << $1.code << $3.code;
              oss << ". " << temp << endl;
              oss << "|| " << temp << ", " << $1.place << ", " << $3.place << endl;

              $$.code = strdup(oss.str().c_str());
              $$.place = strdup(temp.c_str());
            }
            | relation-and-expr
            {//printf("bool-expr -> relation-and-expr\n");
              $$.code = $1.code;
              $$.place = $1.place;
            }

relation-and-expr: relation-expr AND relation-and-expr
                    {//printf("relation-and-expr -> relation-expr_0 AND relation-and-expr\n");
                      ostringstream oss;
                      string temp = new_temp();

                      oss << $1.code << $3.code;
                      oss << ". " << temp << endl;
                      oss << "&& " << temp << ", " << $1.place << ", " << $3.place << endl;

                      $$.code = strdup(oss.str().c_str());
                      $$.place = strdup(temp.c_str());
                    }
                    | relation-expr
                    {//printf("relation-and-expr -> relation-expr_0\n");
                      $$.code = $1.code;
                      $$.place = $1.place;
                    }


relation-expr: expression comp expression
                {//printf("relation_expr -> expression comp expression\n");
                  ostringstream oss;
                  string temp = new_temp();

                  oss << $1.code << $3.code;
                  oss << ". " << temp << "\n"; 
                  oss << $2.operation << " " << temp << ", " << $1.place << ", " << $3.place << "\n";

                  $$.code = strdup(oss.str().c_str());
                  $$.place = strdup(temp.c_str());

                }
                | NOT expression comp expression
                {//printf("relation_expr -> NOT expression comp expression\n");
                  ostringstream oss;
                  string temp = new_temp();

                  oss << $2.code << $4.code;
                  oss << "!. " << temp << "\n"; 
                  oss << $3.operation << " " << temp << ", " << $2.place << ", " << $4.place << "\n";

                  $$.code = strdup(oss.str().c_str());
                  $$.place = strdup(temp.c_str());
                }
                | TRUE
                {//printf("relation_expr -> TRUE\n" );
                  $$.code = "";
                  $$.place = "1";
                }
                | FALSE
                {//printf("relation_expr -> FALSE\n");
                  $$.code = "";
                  $$.place = "0";
                }
                | NOT TRUE
                {//printf("relation_expr -> NOT TRUE\n" );
                  $$.code = "";
                  $$.place = "!1";
                }
                | NOT FALSE
                {//printf("relation_expr -> NOT FALSE\n");
                  $$.code = "";
                  $$.place = "!0";
                }
                | L_PAREN bool-expr R_PAREN
                {//printf("relation_expr -> L_PAREN bool-expr R_PAREN\n");
                  $$.code = $2.code;
                  $$.place = $2.place;
                }
                | NOT L_PAREN bool-expr R_PAREN
                {//print f("relation_expr -> NOT L_PAREN bool-expr R_PAREN\n");
                    ostringstream oss;

                    $$.code = $3.code;

                    oss << "!" << $3.place;
                    $$.place = strdup(oss.str().c_str());
                }

comp: EQ
      {//printf("comp -> EQ\n");
        $$.operation = "==";
      }
      | NEQ
      {//printf("comp -> NEQ\n");
        $$.operation = "!=";
      }
      | LT
      {//printf("comp -> LT\n");
        $$.operation = "<";
      }
      | GT
      {//printf("comp -> GT\n");
        $$.operation = ">";
      }
      | LTE
      {//printf("comp -> LTE\n");
        $$.operation = "<=";
      }
      | GTE
      {//printf("comp -> GTE\n");
        $$.operation = ">=";
      }

expression: multiplicative_expression ADD expression
            {//printf("expression -> multiplicative_expression PLUS expression\n");
              ostringstream oss;
              string temp = new_temp();

              oss << $1.code << $3.code;   // append code for both expressions
              oss << ". " << temp << endl; // create temp var
              oss << "+ " << temp << ", " << $1.place << ", " << $3.place << endl; // Add call
              $$.code      = strdup( oss.str().c_str() ); // Set code
              $$.place     = strdup( temp.c_str()      ); // Set value
            }
            | multiplicative_expression SUB expression
            {//printf("expression -> multiplicative_expression SUB expression\n");
              ostringstream oss;
              string temp = new_temp();

              oss << $1.code << $3.code;   // append code for both expressions
              oss << ". " << temp << endl; // create temp var
              oss << "- " << temp << ", " << $1.place << ", " << $3.place << endl; // Sub call
              $$.code      = strdup( oss.str().c_str() ); // Set code
              $$.place     = strdup( temp.c_str()      ); // Set value

            }
            | multiplicative_expression
            {//printf("expression -> multiplicative_expression\n");
              $$.place = $1.place;
              $$.code = $1.code;
            }

expression_chain: expression_chain COMMA expression
                  {//printf("expression_chain -> expression_chain COMMA expression\n");
                    ostringstream oss;
                    oss << $1.code << $3.code;
                    $$.code = strdup(oss.str().c_str());
                    //$$.place = ""; // Tries to avoid any seg-faults from null values. This may, however, hide some incorrect logic.
                  }
                  | expression
                  {//printf("expression_chain -> expression\n");
                    $$.code = $1.code;
                    $$.place = $1.place;
                  }

vars: vars COMMA var
      {//printf("vars -> vars COMMA var\n");
        ostringstream oss;
        oss << $1.place << "#" << $3.place;
        $$.place = strdup(oss.str().c_str());
        $$.code = "";
      }
      | var
      {//printf("vars -> var\n");
        if(strcmp($1.type, "ARRAY") == 0) {
          $$.code = $1.code;
          $$.place = $1.place;
          $$.type == $1.type;
        }

        if (strcmp($1.type, "ARRAY2D") == 0) {
          $$.code = $1.code;
          $$.place = $1.place;
          $$.type == $1.type;
        }

        if (strcmp($1.type, "VARIABLE") == 0) {
          $$.code = $1.code;
          $$.place = $1.place;
        }
      }

var: IDENT
    {//printf("var -> IDENT  %s \n", $1);
      $$.code = "";
      $$.type = "VARIABLE";
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