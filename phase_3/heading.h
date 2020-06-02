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

struct SymbolTable;

bool exists(string name); // Checks if a symbol already exists in the current scope's symboltable
bool exists(string name, SymbolTable* table); // Checks if a symbol already exists in a given symbol table
bool increaseScope();						 // Move up in scope by one layer if possible.