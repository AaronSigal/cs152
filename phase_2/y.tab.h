/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    AND = 258,
    OR = 259,
    NOT = 260,
    TRUE = 261,
    FALSE = 262,
    IF = 263,
    THEN = 264,
    ELSE = 265,
    ENDIF = 266,
    WHILE = 267,
    DO = 268,
    BEGINLOOP = 269,
    ENDLOOP = 270,
    FOREACH = 271,
    IN = 272,
    CONTINUE = 273,
    FUNCTION = 274,
    RETURN = 275,
    BEGIN_PARAMS = 276,
    END_PARAMS = 277,
    BEGIN_LOCALS = 278,
    END_LOCALS = 279,
    BEGIN_BODY = 280,
    END_BODY = 281,
    INTEGER = 282,
    ARRAY = 283,
    OF = 284,
    READ = 285,
    WRITE = 286,
    ADD = 287,
    SUB = 288,
    MULT = 289,
    DIV = 290,
    MOD = 291,
    EQ = 292,
    ASSIGN = 293,
    NEQ = 294,
    LT = 295,
    GT = 296,
    LTE = 297,
    GTE = 298,
    L_PAREN = 299,
    R_PAREN = 300,
    L_SQUARE_BRACKET = 301,
    R_SQUARE_BRACKET = 302,
    SEMICOLON = 303,
    COLON = 304,
    COMMA = 305,
    NUMBER = 306,
    IDENT = 307
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
