#ifndef __heading_h__
#define __heading_h__

#define YY_NO_UNPUT

#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <string>
#include <map>
#include <vector>
#include <cstring>

using namespace std;


struct Generic;

const vector<string> reservedWords = {
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

  const vector<string> ReservedTokens = {
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
#endif