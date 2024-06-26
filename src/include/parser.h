#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"
#include "AST.h"
#include <stdio.h>
#include <string.h>
#include "scope.h"

typedef struct PARSER_STRUCT
{
    lexer_T* lexer;
    token_T* currentToken;
    token_T* previousToken;
    scope_T* scope;
} parser_T;

parser_T* initParser(lexer_T* lexer);

parser_T* parserEat(parser_T* parser, int tokenType);

AST_T* parserParse(parser_T* parser, scope_T* scope);

AST_T* parseStatement(parser_T* parser, scope_T* scope);

AST_T* parseStatements(parser_T* parser, scope_T* scope);

AST_T* parseExpr(parser_T* parser, scope_T* scope);

AST_T* parseFactor(parser_T* parser, scope_T* scope);

AST_T* parseTerm(parser_T* parser, scope_T* scope);

AST_T* parseFuncCall(parser_T* parser, scope_T* scope);

AST_T* parseFuncDef(parser_T* parser, scope_T* scope);

AST_T* parseVarDefinition(parser_T* parser, scope_T* scope);

AST_T* parseVar(parser_T* parser, scope_T* scope);

AST_T* parseString(parser_T* parser, scope_T* scope);

AST_T* parseID(parser_T* parser, scope_T* scope);

#endif